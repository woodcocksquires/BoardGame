#ifndef LUAUTILTIY_H_
#define LUAUTILITY_H_

#include <string>
#include <stream>
#include <lua.hpp>
#include <typeinfo>
#include <cfloat>

using namespace std;

namespace Wsq {
	namespace Lua {
		struct EmptyTable {
			operator double(){
				return -1.0;
			}
			operator int(){
				return -1;
			}
			operator bool(){
				return false;
			}
			operator char*(){
				return nullptr;
			}
		};

		template<typename A, typename B>
		struct isSame { static const bool value = false; };
		template<typename A>
		struct isSame<A, A> { static const bool value = true; };


		class LuaUtility {
		  private:
			template <typename T>
			static double _toDouble(T value){
				ostringstream ss;
				ss << value;
				string str = ss.str();

				bool period = false;
				int factor = 1;
				double output = 0;
				for(int c=str.length(); c>=0; c--){
					if(isdigit(str[c])){
						output += factor*(((int)c)+48);
						factor *= 10;
						continue;
					}
					if(period){
						return DBL_MIN;
					}
					if(str[c] == '.'){
						output /= (factor^2);
						factor = 1;
						continue;
					}
				}

				return output;
			}

			template<typename A, typename B>
			static bool _isSame(A a, B b) { return isSame<A, B>::value; };
			template <typename T>
			static void _pushValue(lua_State * L, T value){
				if(typeid(value) == typeid(true)){
					lua_pushboolean(L, (bool)value);
				}
				else if(typeid(value) == typeid(1)){
					lua_pushinteger(L, (lua_Integer)value);
				}
				else if(typeid(value) == typeid(1.0)){
					lua_pushnumber(L, _toDouble(value));
				}
				else if(_isSame(value, EmptyTable())){
					lua_newtable(L);
				}
				else if(_isSame(value, "")){
					lua_pushstring(L, (char *)value);
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
