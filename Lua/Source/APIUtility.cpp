/*
 * APIUtility.cpp
 *
 *  Created on: 12 Jun 2014
 *      Author: Andrew.squires
 */

#include<string>
#include<lua.hpp>
#include<APIUtility.h>

using namespace std;
using namespace Wsq::Lua;

APIUtility * APIUtility::_APIUtility = nullptr;

APIUtility::APIUtility(){
	_luaState = luaL_newstate();
	luaL_openlibs(_luaState);
}

APIUtility::~APIUtility(){
	if(_luaState != nullptr){
		lua_close(_luaState);
		_luaState = nullptr;
	}
}

APIUtility * APIUtility::GetUtility(){
	if(_APIUtility == nullptr){
		_APIUtility = new APIUtility();
	}
	return _APIUtility;
}

int APIUtility::LoadAndExecuteFile(string path){
	return luaL_dofile(_luaState, path.c_str());
}

bool APIUtility::GlobalExists(string name){
	lua_getglobal(_luaState, name.c_str());
	if(lua_isnil(_luaState, -1)){
		lua_pop(_luaState, 1);
		return false;
	}
	lua_pop(_luaState, 1);
	return true;
}

bool APIUtility::FieldExists(string name){
	if(lua_istable(_luaState, -1)){
		lua_getfield(_luaState, -1, name.c_str());
		if(lua_isnil(_luaState, -1)){
			lua_pop(_luaState, 1);
			return false;
		}

		lua_pop(_luaState, 1);
		return true;
	}
	return false;
}

void APIUtility::SetGlobal(string name, bool value){
	SetGlobal(name, value, false);
}

void APIUtility::SetGlobal(string name, bool value, bool keepOnStack){
	lua_pushboolean(_luaState, value);
	lua_setglobal(_luaState, name.c_str());
	if(keepOnStack){
		lua_getglobal(_luaState, name.c_str());
	}
}

void APIUtility::SetGlobal(string name, double value){
	SetGlobal(name, value, false);
}

void APIUtility::SetGlobal(string name, double value, bool keepOnStack){
	lua_pushnumber(_luaState, value);
	lua_setglobal(_luaState, name.c_str());
	if(keepOnStack){
		lua_getglobal(_luaState, name.c_str());
	}
}

void APIUtility::SetGlobal(string name, char * value){
	SetGlobal(name, value, false);
}

void APIUtility::SetGlobal(string name, char * value, bool keepOnStack){
	lua_pushstring(_luaState, value);
	lua_setglobal(_luaState, name.c_str());
	if(keepOnStack){
		lua_getglobal(_luaState, name.c_str());
	}
}

void APIUtility::SetGlobal(string name, EmptyTable value){
	SetGlobal(name, value, false);
}

void APIUtility::SetGlobal(string name, EmptyTable value, bool keepOnStack){
	lua_newtable(_luaState);
	lua_setglobal(_luaState, name.c_str());
	if(keepOnStack){
		lua_getglobal(_luaState, name.c_str());
	}
}

void APIUtility::SetGlobal(string name, int value){
	SetGlobal(name, value, false);
}

void APIUtility::SetGlobal(string name, int value, bool keepOnStack){
	lua_pushinteger(_luaState, lua_Integer(value));
	lua_setglobal(_luaState, name.c_str());
	if(keepOnStack){
		lua_getglobal(_luaState, name.c_str());
	}
}
