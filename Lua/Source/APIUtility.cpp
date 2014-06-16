/*
 * APIUtility.cpp
 *
 *  Created on: 12 Jun 2014
 *      Author: Andrew.squires
 */

#include<string>
#include<sstream>
#include<cstring>
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


void APIUtility::SetField(string name, bool value){
	APIUtility::SetField(name, value, false);
}

void APIUtility::SetField(string name, bool value, bool keepOnStack){
	lua_pushboolean(_luaState, value);
	lua_setfield(_luaState, -2, name.c_str());
	if(keepOnStack){
		lua_getfield(_luaState, -1, name.c_str());
	}
}

void APIUtility::SetField(string name, double value){
	APIUtility::SetField(name, value, false);
}

void APIUtility::SetField(string name, double value, bool keepOnStack){
	lua_pushnumber(_luaState, value);
	lua_setfield(_luaState, -2, name.c_str());
	if(keepOnStack){
		lua_getfield(_luaState, -1, name.c_str());
	}
}

void APIUtility::SetField(string name, char * value){
	APIUtility::SetField(name, value, false);
}

void APIUtility::SetField(string name, char * value, bool keepOnStack){
	lua_pushstring(_luaState, value);
	lua_setfield(_luaState, -2, name.c_str());
	if(keepOnStack){
		lua_getfield(_luaState, -1, name.c_str());
	}
}

void APIUtility::SetField(string name, EmptyTable value){
	APIUtility::SetField(name, value, false);
}

void APIUtility::SetField(string name, EmptyTable value, bool keepOnStack){
	lua_newtable(_luaState);
	lua_setfield(_luaState, -2, name.c_str());
	if(keepOnStack){
		lua_getfield(_luaState, -1, name.c_str());
	}
}

void APIUtility::SetField(string name, int value){
	APIUtility::SetField(name, value, false);
}

void APIUtility::SetField(string name, int value, bool keepOnStack){
	lua_pushinteger(_luaState, value);
	lua_setfield(_luaState, -2, name.c_str());
	if(keepOnStack){
		lua_getfield(_luaState, -1, name.c_str());
	}
}


bool APIUtility::FieldToBool(string path){
	int depth = GetTablePath(path);
	if(!lua_isboolean(_luaState, -1)){
		lua_pop(_luaState, depth);
		throw BadLuaFieldCastException();
	}
	bool output = lua_toboolean(_luaState, -1);
	lua_pop(_luaState, depth);
	return output;
}

int APIUtility::FieldToInt(string path){
	int depth = GetTablePath(path);
	if(!lua_isnumber(_luaState, -1)){
		lua_pop(_luaState, depth);
		throw BadLuaFieldCastException();
	}
	int output = lua_tointeger(_luaState, -1);
	lua_pop(_luaState, depth);
	return output;
}

double APIUtility::FieldToDouble(string path){
	int depth = GetTablePath(path);
	if(!lua_isnumber(_luaState, -1)){
		lua_pop(_luaState, depth);
		throw BadLuaFieldCastException();
	}
	int output = lua_tonumber(_luaState, -1);
	lua_pop(_luaState, depth);
	return output;
}

string APIUtility::FieldToString(string path){
	int depth = GetTablePath(path);
	if(!lua_isstring(_luaState, -1)){
		lua_pop(_luaState, depth);
		throw BadLuaFieldCastException();
	}
	const char * luaValue = lua_tostring(_luaState, -1);
	char output[strlen(luaValue)];
	strcpy(output, luaValue);
	lua_pop(_luaState, depth);
	return output;
}

bool APIUtility::GetTable(string name){
	if(lua_istable(_luaState, -1)){
		lua_getfield(_luaState, -1, name.c_str());
		if(!lua_istable(_luaState, -1)){
			lua_pop(_luaState, 1);
			return false;
		}
		return true;
	}
	return false;
}

int APIUtility::GetTablePath(string path){
	stringstream ss(path);
	string item;
	string next;
	int counter = 0;
	getline(ss, item, '.');
	while(getline(ss, next, '.')){
		if(!GetTable(item.c_str())){
			lua_pop(_luaState, counter);
			throw NotALuaTableException();
		}
		else{
			counter++;
		}
		item = next;
	}
	lua_getfield(_luaState, -1, item.c_str());
	if(lua_isnil(_luaState, -1)){
		if(counter > 0){
			lua_pop(_luaState, counter);
		}
		throw LuaFieldIsNilException();
	}
	return counter+1;
}

int APIUtility::GetField(string path){
	return GetTablePath(path);
}
