#ifndef LUAUTILTIY_H_
#define LUAUTILITY_H_

#include <string>
#include <lua.hpp>

using namespace std;

namespace Wsq {
	namespace Lua {
		struct EmptyTable {};
		class LuaUtility {
		  public:
			static lua_State * GetNewState();
			static int LoadAndExecuteFile(lua_State * L, string path, string table);
			static void CloseState(lua_State * L);
			static bool GlobalExists(lua_State * L, string name);
			static bool FieldExists(lua_State * L, string name);
			static void SetGlobal(lua_State * L, string name, bool value);
			static void SetGlobal(lua_State * L, string name, int value);
			static void SetGlobal(lua_State * L, string name, double value);
			static void SetGlobal(lua_State * L, string name, char * value);
			static void SetGlobal(lua_State * L, string name, string value);
			static void SetGlobal(lua_State * L, string name, EmptyTable value);
			static void SetField(lua_State * L, string name, bool value);
			static void SetField(lua_State * L, string name, int value);
			static void SetField(lua_State * L, string name, double value);
			static void SetField(lua_State * L, string name, char * value);
			static void SetField(lua_State * L, string name, string value);
			static void SetField(lua_State * L, string name, EmptyTable value);
		};
	}
}

#endif
