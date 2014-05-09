#include <IGameDetail.h>
#include <lua.hpp>
#include <LuaUtility.h>
#include <BoardGame.h>
#include <stdexcept>
#include <iostream>
#include <FileSystemUtility.h>

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
	lua_getfield(_luaState, -1, "BoardGame");
	lua_getfield(_luaState, -1, "Config");
	lua_getfield(_luaState, -1, "GamePath");
	_gamePath = lua_tostring(_luaState, -1);
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

	vector<string> * files = Wsq::FileSystem::FileSystemUtility::GetFilesInDirectory(FileSystemUtility::CombinePath(_scriptPath, _gamePath), "lua");

	for(int f = 0; f < (int)files->size(); f++){
		cout << "\n" << files->at(f);
	}

	lua_State * L = _luaState;
	for(int f = 0; f < (int)files->size(); f++){
		LuaUtility::LoadAndExecuteFile(L, files->at(f));
	}

	return 0;
}
