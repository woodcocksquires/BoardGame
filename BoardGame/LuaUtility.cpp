/*
 * LuaUtility.cpp
 *
 *  Created on: 1 May 2014
 *      Author: Andrew.squires
 */

#include <LuaUtility.h>
#include <algorithm>

using namespace Wsq::Lua;
using namespace std;

lua_State * LuaUtility::GetNewState(){
	lua_State * L = luaL_newstate();
	luaL_openlibs(L);

	lua_getglobal(L, "Wsq");
	if(lua_isnil(L, -1)){
		lua_pop(L, -1);
		lua_newtable(L);
		lua_setglobal(L, "Wsq");
	}
	lua_newtable(L);
	lua_setfield(L, -2, "BoardGame");
	return L;
}

int LuaUtility::LoadAndExecuteFile(lua_State * L, string path, string table){
	return luaL_dofile(L, path.c_str());
}

void LuaUtility::CloseState(lua_State * L){
	lua_close(L);
}


