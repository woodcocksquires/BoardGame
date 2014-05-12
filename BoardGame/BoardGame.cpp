#include <lua.hpp>
#include <LuaUtility.h>
#include <BoardGame.h>
#include <IGameDetail.h>
#include <GameDetail.h>
#include <stdexcept>
#include <iostream>
#include <FileSystemUtility.h>
#include <cstring>

using namespace std;
using namespace Wsq::Lua;
using namespace Wsq::BoardGame;
using namespace Wsq::FileSystem;

BoardGame::BoardGame(){
	_luaState = LuaUtility::GetNewState();
	if(!LuaUtility::GlobalExists(_luaState, "wsq")){
		LuaUtility::SetGlobal(_luaState, "wsq", EmptyTable());
	}
	lua_getglobal(_luaState, "Wsq");
	if(!LuaUtility::FieldExists(_luaState, "boardgame")){
		LuaUtility::SetField(_luaState, "boardgame", EmptyTable());
	}
	LuaUtility::LoadAndExecuteFile(_luaState, FileSystemUtility::CombinePath(_scriptPath, "config.lua"));
	_gamePath = LuaUtility::FieldToString(_luaState, "boardgame.config.gamepath");
	_gameList = LoadGameList();
}

BoardGame::~BoardGame(){
	for(int g=0; g<(int)_gameList->size(); g++){
		delete _gameList->at(g);
	}

	delete _gameList;
	LuaUtility::CloseState(_luaState);
}

vector<IGameDetail *> * BoardGame::GetGameList(){
	return _gameList;
}

vector<IGameDetail *> * BoardGame::LoadGameList(){
	vector<GameDetail *> * gameList = new vector<GameDetail *>();
	LuaUtility::GetField(_luaState, "boardgame");
	if(!LuaUtility::GlobalExists(_luaState, "games")){
		LuaUtility::SetField(_luaState, "games", EmptyTable());
	}
	vector<string> * games = FileSystemUtility::GetDirectories(FileSystemUtility::CombinePath(_scriptPath, _gamePath));
	for(int g = 0; g < (int)games->size(); g++){
		gameList->push_back(LoadGameSummary(games->at(g)));
	}

	lua_pop(_luaState, 1);

	delete games;
	return 0;
}

GameDetail * BoardGame::LoadGameSummary(string path){
	int depth = LuaUtility::GetField(_luaState, "games." + path.substr(path.find_last_of('\\') + 1));
	LuaUtility::LoadAndExecuteFile(_luaState, FileSystemUtility::CombinePath(path, "summary.lua"));
	GameDetail * gameDetail = new GameDetail(LuaUtility::FieldToString(_luaState, "name"),
			LuaUtility::FieldToString(_luaState, "description"),
			path,
			LuaUtility::FieldToInt(_luaState, "maxplayers"),
			LuaUtility::FieldToInt(_luaState, "minplayers"));
	lua_pop(_luaState, depth);
	return gameDetail;
}
