#ifndef LUAUTILTIY_H_
#define LUAUTILITY_H_

#include <string>
#include <lua.hpp>

using namespace std;

namespace Wsq {
	namespace Lua {
		struct EmptyTable {};

		class LuaUtility {
		  private:
			template <class T>
			static void _pushValue(lua_State * L, T * value){
				if(dynamic_cast<bool>(value)){
					lua_pushboolean(L, value);
				}
				else if(dynamic_cast<int>(value)){
					lua_pushinteger(L, value);
				}
				else if(dynamic_cast<double>(value)){
					lua_pushnumber(L, value);
				}
				else if(dynamic_cast<string *>(value)){
					lua_pushstring(L, dynamic_cast<string>(value).c_str());
				}
				else if(dynamic_cast<char *>(value)){
					lua_pushstring(L, value);
				}
				else if(dynamic_cast<EmptyTable>(value)){
					lua_newtable(L);
				}
			}
		  public:
			static lua_State * GetNewState();
			static int LoadAndExecuteFile(lua_State * L, string path, string table);
			static void CloseState(lua_State * L);
			static bool GlobalExists(lua_State * L, string name);
			static bool FieldExists(lua_State * L, string name);

			template <class T>
			static void SetGlobal(lua_State * L, string name, T * value) {
				_pushValue(L, value);
				lua_setglobal(L, name.c_str());
			};

			template <class T>
			static void SetField(lua_State * L, string name, T * value) {
				_pushValue(L, value);
				lua_setfield(L, -1, name.c_str());
			};
		};
	}
}

#endif
