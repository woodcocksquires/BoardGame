/*
 * GameDetail.cpp
 *
 *  Created on: 12 May 2014
 *      Author: Andrew.squires
 */

#include <Lua.hpp>
#include <string>
#include <LuaUtility.h>
#include <StringUtility.h>
#include <FileSystemUtility.h>
#include <GameDetail.h>

using namespace std;
using namespace Wsq::Lua;
using namespace Wsq::BoardGame;
using namespace Wsq::FileSystem;
using namespace Wsq::Text;

GameDetail::GameDetail(lua_State * L, string path){
	LuaUtility::LoadAndExecuteFile(L, FileSystemUtility::CombinePath(path, "summary.lua"));
		string shortPath = StringUtility::ToLower(path.substr(path.find_last_of('\\') + 1));
		int depth = LuaUtility::GetField(L, shortPath);
		_name = LuaUtility::FieldToString(L, "name");
		_description = LuaUtility::FieldToString(L, "description");
		_path = path;
		_shortPath = shortPath;
		_minPlayers = LuaUtility::FieldToInt(L, "minplayers");
		_maxPlayers = LuaUtility::FieldToInt(L, "maxplayers");

		lua_pop(L, depth);
}


