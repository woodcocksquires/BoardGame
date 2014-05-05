/*
 * LuaUtility.cpp
 *
 *  Created on: 1 May 2014
 *      Author: Andrew.squires
 */

#include <LuaUtility.h>
#include <algorithm>
#include <iostream>

using namespace Wsq::Lua;
using namespace std;

lua_State * LuaUtility::GetNewState(){
	lua_State * L = luaL_newstate();
	luaL_openlibs(L);
	if(!GlobalExists(L, "Wsq")){
		SetGlobal(L, string("Wsq"), EmptyTable());
	}
	lua_getglobal(L, "Wsq");
	if(FieldExists(L, "BoardGame")){
		SetField(L, string("BoardGame"), EmptyTable());
	}
	return L;
}

int LuaUtility::LoadAndExecuteFile(lua_State * L, string path, string table){
	return luaL_dofile(L, path.c_str());
}

void LuaUtility::CloseState(lua_State * L){
	lua_close(L);
}

bool LuaUtility::GlobalExists(lua_State * L, string name){
	lua_getglobal(L, name.c_str());
	if(lua_isnil(L, -1)){
		lua_pop(L, -1);
		return false;
	}
	lua_pop(L, -1);
	return true;
}

bool LuaUtility::FieldExists(lua_State * L, string name){
	if(lua_istable(L, -1)){
		lua_getfield(L, -1, name.c_str());
		if(lua_isnil(L, -1)){
			lua_pop(L, -1);
			return false;
		}

		lua_pop(L, -1);
		return true;
	}
	return false;
}


