#include <BoardGame.h>
#include <IGameDetail.h>
#include <lua.hpp>
#include <stdexcept>
#include <iostream>
#include <FileSystemUtility.h>
#include <LuaUtility.h>

using namespace std;
using namespace Wsq::BoardGame;
using namespace Wsq::Lua;
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
	lua_pop(_luaState, 1);
	LuaUtility::LoadAndExecuteFile(_luaState, FileSystemUtility::CombinePath(_scriptPath, "config.lua"));
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

	vector<string> * files = Wsq::FileSystem::FileSystemUtility::GetFilesInDirectory("scripts\\games", "lua");

	for(int f = 0; f < (int)files->size(); f++){
		cout << "\n" << files->at(f);
	}

	lua_State * L = _luaState;
	for(int f = 0; f < (int)files->size(); f++){
		LuaUtility::LoadAndExecuteFile(L, files->at(f));
	}

	return 0;
}
