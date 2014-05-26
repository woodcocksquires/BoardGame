/*
 * LuaUtility.cpp
 *
 *  Created on: 1 May 2014
 *      Author: Andrew.squires
 */

#include <LuaUtility.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using namespace Wsq::Lua;
using namespace std;

lua_State * LuaUtility::GetNewState(){
	lua_State * L = luaL_newstate();
	luaL_openlibs(L);
	return L;
}

int LuaUtility::LoadAndExecuteFile(lua_State * L, string path){
	return luaL_dofile(L, path.c_str());
}

void LuaUtility::CloseState(lua_State * L){
	lua_close(L);
}

bool LuaUtility::GlobalExists(lua_State * L, string name){
	lua_getglobal(L, name.c_str());
	if(lua_isnil(L, -1)){
		lua_pop(L, 1);
		return false;
	}
	lua_pop(L, 1);
	return true;
}

bool LuaUtility::FieldExists(lua_State * L, string name){
	if(lua_istable(L, -1)){
		lua_getfield(L, -1, name.c_str());
		if(lua_isnil(L, -1)){
			lua_pop(L, 1);
			return false;
		}

		lua_pop(L, 1);
		return true;
	}
	return false;
}

void LuaUtility::SetGlobal(lua_State * L, string name, bool value){
	LuaUtility::SetGlobal(L, name, value, false);
}

void LuaUtility::SetGlobal(lua_State * L, string name, bool value, bool keepOnStack){
	lua_pushboolean(L, value);
	lua_setglobal(L, name.c_str());
	if(keepOnStack){
		lua_getglobal(L, name.c_str());
	}
}

void LuaUtility::SetGlobal(lua_State * L, string name, double value){
	LuaUtility::SetGlobal(L, name, value, false);
}

void LuaUtility::SetGlobal(lua_State * L, string name, double value, bool keepOnStack){
	lua_pushnumber(L, value);
	lua_setglobal(L, name.c_str());
	if(keepOnStack){
		lua_getglobal(L, name.c_str());
	}
}

void LuaUtility::SetGlobal(lua_State * L, string name, char * value){
	LuaUtility::SetGlobal(L, name, value, false);
}

void LuaUtility::SetGlobal(lua_State * L, string name, char * value, bool keepOnStack){
	lua_pushstring(L, value);
	lua_setglobal(L, name.c_str());
	if(keepOnStack){
		lua_getglobal(L, name.c_str());
	}
}

void LuaUtility::SetGlobal(lua_State * L, string name, EmptyTable value){
	LuaUtility::SetGlobal(L, name, value, false);
}

void LuaUtility::SetGlobal(lua_State * L, string name, EmptyTable value, bool keepOnStack){
	lua_newtable(L);
	lua_setglobal(L, name.c_str());
	if(keepOnStack){
		lua_getglobal(L, name.c_str());
	}
}

void LuaUtility::SetGlobal(lua_State * L, string name, int value){
	LuaUtility::SetGlobal(L, name, value, false);
}

void LuaUtility::SetGlobal(lua_State * L, string name, int value, bool keepOnStack){
	lua_pushinteger(L, lua_Integer(value));
	lua_setglobal(L, name.c_str());
	if(keepOnStack){
		lua_getglobal(L, name.c_str());
	}
}

void LuaUtility::SetField(lua_State * L, string name, bool value){
	LuaUtility::SetField(L, name, value, false);
}

void LuaUtility::SetField(lua_State * L, string name, bool value, bool keepOnStack){
	lua_pushboolean(L, value);
	lua_setfield(L, -2, name.c_str());
	if(keepOnStack){
		lua_getfield(L, -1, name.c_str());
	}
}

void LuaUtility::SetField(lua_State * L, string name, double value){
	LuaUtility::SetField(L, name, value, false);
}

void LuaUtility::SetField(lua_State * L, string name, double value, bool keepOnStack){
	lua_pushnumber(L, value);
	lua_setfield(L, -2, name.c_str());
	if(keepOnStack){
		lua_getfield(L, -1, name.c_str());
	}
}

void LuaUtility::SetField(lua_State * L, string name, char * value){
	LuaUtility::SetField(L, name, value, false);
}

void LuaUtility::SetField(lua_State * L, string name, char * value, bool keepOnStack){
	lua_pushstring(L, value);
	lua_setfield(L, -2, name.c_str());
	if(keepOnStack){
		lua_getfield(L, -1, name.c_str());
	}
}

void LuaUtility::SetField(lua_State * L, string name, EmptyTable value){
	LuaUtility::SetField(L, name, value, false);
}

void LuaUtility::SetField(lua_State * L, string name, EmptyTable value, bool keepOnStack){
	lua_newtable(L);
	lua_setfield(L, -2, name.c_str());
	if(keepOnStack){
		lua_getfield(L, -1, name.c_str());
	}
}

void LuaUtility::SetField(lua_State * L, string name, int value){
	LuaUtility::SetField(L, name, value, false);
}

void LuaUtility::SetField(lua_State * L, string name, int value, bool keepOnStack){
	lua_pushinteger(L, value);
	lua_setfield(L, -2, name.c_str());
	if(keepOnStack){
		lua_getfield(L, -1, name.c_str());
	}
}

bool LuaUtility::FieldToBool(lua_State * L, string path){
	int depth = GetTablePath(L, path);
	if(!lua_isboolean(L, -1)){
		lua_pop(L, depth);
		throw BadLuaFieldCastException();
	}
	bool output = lua_toboolean(L, -1);
	lua_pop(L, depth);
	return output;
}

int LuaUtility::FieldToInt(lua_State * L, string path){
	int depth = GetTablePath(L, path);
	if(!lua_isnumber(L, -1)){
		lua_pop(L, depth);
		throw BadLuaFieldCastException();
	}
	int output = lua_tointeger(L, -1);
	lua_pop(L, depth);
	return output;
}

double LuaUtility::FieldToDouble(lua_State * L, string path){
	int depth = GetTablePath(L, path);
	if(!lua_isnumber(L, -1)){
		lua_pop(L, depth);
		throw BadLuaFieldCastException();
	}
	int output = lua_tonumber(L, -1);
	lua_pop(L, depth);
	return output;
}

string LuaUtility::FieldToString(lua_State * L, string path){
	int depth = GetTablePath(L, path);
	if(!lua_isstring(L, -1)){
		lua_pop(L, depth);
		throw BadLuaFieldCastException();
	}
	const char * luaValue = lua_tostring(L, -1);
	char output[strlen(luaValue)];
	strcpy(output, luaValue);
	lua_pop(L, depth);
	return output;
}

bool LuaUtility::GetTable(lua_State * L, string name){
	if(lua_istable(L, -1)){
		lua_getfield(L, -1, name.c_str());
		if(!lua_istable(L, -1)){
			lua_pop(L, 1);
			return false;
		}
		return true;
	}
	return false;
}

int LuaUtility::GetTablePath(lua_State * L, string path){
	stringstream ss(path);
	string item;
	string next;
	int counter = 0;
	getline(ss, item, '.');
	while(getline(ss, next, '.')){
		if(!GetTable(L, item.c_str())){
			lua_pop(L, counter);
			throw NotALuaTableException();
		}
		else{
			counter++;
		}
		item = next;
	}
	lua_getfield(L, -1, item.c_str());
	if(lua_isnil(L, -1)){
		if(counter > 0){
			lua_pop(L, counter);
		}
		throw LuaFieldIsNilException();
	}
	return counter+1;
}

int LuaUtility::GetField(lua_State * L, string path){
	return GetTablePath(L, path);
}



