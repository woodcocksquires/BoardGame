#ifndef LUAUTILTIY_H_
#define LUAUTILITY_H_

#include <string>
#include <lua.hpp>

using namespace std;

namespace Wsq {
	namespace Lua {
		class LuaUtility {
		  public:
			static lua_State * GetNewState();
			static int LoadAndExecuteFile(lua_State * L, string path, string table);
			static void CloseState(lua_State * L);
		};
	}
}

#endif
