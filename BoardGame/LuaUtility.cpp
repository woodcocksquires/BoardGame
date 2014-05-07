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
		SetGlobal(L, "Wsq", EmptyTable());
	}
	lua_getglobal(L, "Wsq");
	if(FieldExists(L, "BoardGame")){
		SetField(L, "BoardGame", EmptyTable());
	}
	/*lua_getfield(L, -1, "BoardGame");
	SetField(L, "Version", 4);
	/*lua_getfield(L, -1, "Version");
	lua_Number version = lua_tonumber(L, -1);
	lua_pop(L, -1);
	lua_pop(L, -1);
	lua_pop(L, -1);
	cout << "Version: " << version << "\n";*/
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

void LuaUtility::SetGlobal(lua_State * L, string name, bool value){
	lua_pushboolean(L, value);
	lua_setglobal(L, name.c_str());
}

void LuaUtility::SetGlobal(lua_State * L, string name, double value){
	lua_pushnumber(L, value);
	lua_setglobal(L, name.c_str());
}

void LuaUtility::SetGlobal(lua_State * L, string name, char * value){
	lua_pushstring(L, value);
	lua_setglobal(L, name.c_str());
}

void LuaUtility::SetGlobal(lua_State * L, string name, EmptyTable value){
	lua_newtable(L);
	lua_setglobal(L, name.c_str());
}

void LuaUtility::SetGlobal(lua_State * L, string name, int value){
	lua_pushinteger(L, lua_Integer(value));
	lua_setglobal(L, name.c_str());
}

void LuaUtility::SetField(lua_State * L, string name, bool value){
	lua_pushboolean(L, value);
	lua_setfield(L, -1, name.c_str());
}

void LuaUtility::SetField(lua_State * L, string name, double value){
	lua_pushnumber(L, value);
	lua_setfield(L, -1, name.c_str());
}

void LuaUtility::SetField(lua_State * L, string name, char * value){
	lua_pushstring(L, value);
	lua_setfield(L, -1, name.c_str());
}

void LuaUtility::SetField(lua_State * L, string name, EmptyTable value){
	lua_newtable(L);
	lua_setfield(L, -1, name.c_str());
}

void LuaUtility::SetField(lua_State * L, string name, int value){
	lua_pushinteger(L, lua_Integer(value));
	lua_setfield(L, -1, name.c_str());
}


