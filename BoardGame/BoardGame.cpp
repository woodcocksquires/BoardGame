#include <IGameDetail.h>
#include <lua.hpp>
#include <LuaUtility.h>
#include <BoardGame.h>
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
	if(!LuaUtility::GlobalExists(_luaState, "Wsq")){
		LuaUtility::SetGlobal(_luaState, "Wsq", EmptyTable());
	}
	lua_getglobal(_luaState, "Wsq");
	if(!LuaUtility::FieldExists(_luaState, "BoardGame")){
		LuaUtility::SetField(_luaState, "BoardGame", EmptyTable());
	}
	LuaUtility::LoadAndExecuteFile(_luaState, FileSystemUtility::CombinePath(_scriptPath, "config.lua"));
	_gamePath = LuaUtility::FieldToString(_luaState, "BoardGame.Config.GamePath");
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
	vector<string> * games = FileSystemUtility::GetDirectories(FileSystemUtility::CombinePath(_scriptPath, _gamePath));

	for(int g = 0; g < (int)games->size(); g++){
		LoadGame(games->at(g));
	}

	delete games;
	return 0;
}

void BoardGame::LoadGame(string path){
	LuaUtility::LoadAndExecuteFile(_luaState, FileSystemUtility::CombinePath(path, "summary.lua"));
}
