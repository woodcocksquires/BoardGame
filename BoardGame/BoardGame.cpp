#include <BoardGame.h>
#include <IGameDetail.h>
#include <lua.hpp>
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace Wsq::BoardGame;

BoardGame::BoardGame(){
	_gameList = LoadGameList();
}

BoardGame::~BoardGame(){
	for(int g=0; g<(int)_gameList->size(); g++){
		delete _gameList->at(g);
	}

	delete _gameList;
}

vector<IGameDetail *> * BoardGame::GetGameList(){
	return _gameList;
}

vector<IGameDetail *> * BoardGame::LoadGameList(){
	cout << "\nhere goes\n";
	lua_State * L = luaL_newstate();
	luaL_openlibs(L);

	if(luaL_loadfile(L, "scripts\\games.lua") || lua_pcall(L, 0, 0 ,0)){
		throw runtime_error("Cannot load games list.");
	}

	lua_close(L);

	return 0;
}
