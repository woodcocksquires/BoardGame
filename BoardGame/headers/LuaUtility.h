#ifndef LUAUTILTIY_H_
#define LUAUTILITY_H_

#include <string>
#include <lua.hpp>

using namespace std;

namespace Wsq {
	namespace Lua {
		struct EmptyTable {
			operator double(){
				return 0.0;
			}
			operator int(){
				return 0;
			}
			operator bool(){
				return false;
			}
			operator char*(){
				return "";
			}
			operator string(){
				return string();
			}
		};

		template<typename A, typename B>
		struct isSame { static const bool value = false; };
		template<typename A>
		struct isSame<A, A> { static const bool value = true; };


		class LuaUtility {
		  private:
			template<typename A, typename B>
			static bool _isSame(A a, B b) { return isSame<A, B>::value; };
			template <typename T>
			static void _pushValue(lua_State * L, T value){
				if(_isSame(value, true)){
					lua_pushboolean(L, true);
				}
				else if(_isSame(value, 1)){
					lua_pushinteger(L, (lua_Integer)1);
				}
				else if(_isSame(value, 1.0)){
					lua_pushnumber(L, (double)value);
				}
				else if(_isSame(value, EmptyTable())){
					lua_newtable(L);
				}
				else if(_isSame(value, "")){
					lua_pushstring(L, value);
				}
				else if(_isSame(value, string())){
					lua_pushstring(L, ((string)*value).c_str());
				}
			}
		  public:
			static lua_State * GetNewState();
			static int LoadAndExecuteFile(lua_State * L, string path, string table);
			static void CloseState(lua_State * L);
			static bool GlobalExists(lua_State * L, string name);
			static bool FieldExists(lua_State * L, string name);

			template <class T>
			static void SetGlobal(lua_State * L, string name, T value) {
				_pushValue(L, value);
				lua_setglobal(L, name.c_str());
			};

			template <class T>
			static void SetField(lua_State * L, string name, T value) {
				_pushValue(L, value);
				lua_setfield(L, -1, name.c_str());
			};
		};
	}
}

#endif
