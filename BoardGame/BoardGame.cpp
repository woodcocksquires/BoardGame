#include <lua.hpp>
#include <LuaUtility.h>
#include <IGameDetail.h>
#include <BoardGame.h>
#include <BoardState.h>
#include <GameDetail.h>
#include <stdexcept>
#include <iostream>
#include <FileSystemUtility.h>
#include <Board.h>
#include <cstring>
#include <vector>
#include <string>

using namespace std;
using namespace Wsq::Lua;
using namespace Wsq::BoardGame;
using namespace Wsq::FileSystem;

BoardGame::BoardGame(){
	_luaState = LuaUtility::GetNewState();
	if(!LuaUtility::GlobalExists(_luaState, "wsq")){
		LuaUtility::SetGlobal(_luaState, "wsq", EmptyTable());
	}
	lua_getglobal(_luaState, "wsq");
	if(!LuaUtility::FieldExists(_luaState, "boardgame")){
		LuaUtility::SetField(_luaState, "boardgame", EmptyTable());
	}

	LuaUtility::LoadAndExecuteFile(_luaState, FileSystemUtility::CombinePath(_scriptPath, "config.lua"));

	_gamePath = LuaUtility::FieldToString(_luaState, "boardgame.config.gamepath");
	_gameList = LoadGameList();
	_board = nullptr;
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
	vector<IGameDetail *> * gameList = new vector<IGameDetail *>();
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
	return gameList;
}

GameDetail * BoardGame::LoadGameSummary(string path){
	LuaUtility::LoadAndExecuteFile(_luaState, FileSystemUtility::CombinePath(path, "summary.lua"));
	int depth = LuaUtility::GetField(_luaState, "games." + path.substr(path.find_last_of('\\') + 1));
	GameDetail * gameDetail;

		 gameDetail = new GameDetail(LuaUtility::FieldToString(_luaState, "name"),
				LuaUtility::FieldToString(_luaState, "description"),
				path,
				LuaUtility::FieldToInt(_luaState, "maxplayers"),
				LuaUtility::FieldToInt(_luaState, "minplayers"));



	lua_pop(_luaState, depth);
	return gameDetail;
}

bool BoardGame::LoadGame(IGameDetail * detail){
	LuaUtility::GetField(_luaState, detail->Name());
	LoadBoardDefinition(detail);
	return true;
}

void BoardGame::LoadBoardDefinition(IGameDetail * detail){
	int depth = LuaUtility::GetField(_luaState, "board");
	vector<BoardState *> * boardState = LoadBoardState(detail);
	//_board = new Board()
	lua_pop(_luaState, depth);
}

vector<BoardState *> * BoardGame::LoadBoardState(IGameDetail * detail){
	int depth = LuaUtility::GetField(_luaState, "state");
	vector<BoardState *> * boardState = new vector<BoardState *>();

	lua_pushnil(_luaState);
	while(lua_next(_luaState, -2) != 0){
		int value = LuaUtility::FieldToInt(_luaState, "value");
		char identifier = LuaUtility::FieldToString(_luaState, "identifier")[0];
		string name = LuaUtility::FieldToString(_luaState, "name");
		string valueString = LuaUtility::FieldToString(_luaState, "valueString");
		BoardState * newState = new BoardState(value, identifier, name, valueString);
		boardState->push_back(newState);
		lua_pop(_luaState, 1);
	}
	lua_pop(_luaState, 1);

	return boardState;
}

