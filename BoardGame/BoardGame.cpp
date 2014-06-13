/*
#include <lua.hpp>
#include <LuaUtility.h>
#include <cstring>
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <IGameDetail.h>
#include <IBoardGame.h>
#include <BoardGame.h>
#include <BoardState.h>
#include <GameDetail.h>
#include <GameDetailFactory.h>
#include <FileSystemUtility.h>
#include <Board.h>
#include <StringUtility.h>

using namespace std;
using namespace Wsq::Lua;
using namespace Wsq::BoardGame;
using namespace Wsq::FileSystem;
using namespace Wsq::Text;

BoardGame::BoardGame(){
	_luaState = LuaUtility::GetState();
	if(!LuaUtility::GlobalExists(_luaState, "wsq")){
		LuaUtility::SetGlobal(_luaState, "wsq", EmptyTable(), true);
	}

	if(!LuaUtility::FieldExists(_luaState, "boardgame")){
		LuaUtility::SetField(_luaState, "boardgame", EmptyTable(), true);
	}

	LuaUtility::LoadAndExecuteFile(_luaState, FileSystemUtility::CombinePath(_scriptPath, "config.lua"));

	_gamePath = LuaUtility::FieldToString(_luaState, "config.gamepath");
	_gameList = nullptr;
	_board = nullptr;

	_gameDetailFactory = nullptr;
	_boardStateFactory = nullptr;
	_loadGameList = &LoadGameList;
}

BoardGame::~BoardGame(){
	for(int g=0; g<(int)_gameList->size(); g++){
		delete _gameList->at(g);
	}

	delete _gameList;
	delete _gameDetailFactory;
	delete _boardStateFactory;

	LuaUtility::CloseState();
}

vector<IGameDetail *> * BoardGame::GetGameList(){
	if(_gameList == nullptr){
		_gameList = _loadGameList();
	}
	return _gameList;
}

vector<IGameDetail *> * BoardGame::LoadGameList(){
	if(!LuaUtility::FieldExists(_luaState, "games")){
		LuaUtility::SetField(_luaState, "games", EmptyTable(), true);
	}
	vector<string> * games = FileSystemUtility::GetDirectories(FileSystemUtility::CombinePath(_scriptPath, _gamePath));
	for(int g = 0; g < (int)games->size(); g++){
		//_gameList->push_back(GetGameDetailFactory()->Create(LuaUtility::GetState(), games->at(g)));
	}

	delete games;
	return _gameList;
}

bool BoardGame::LoadGame(IGameDetail * detail){
	LuaUtility::GetField(_luaState, detail->ShortPath());
	LoadBoardDefinition(detail);
	return true;
}

void BoardGame::LoadBoardDefinition(IGameDetail * detail){
	LuaUtility::LoadAndExecuteFile(_luaState, FileSystemUtility::CombinePath(detail->Path(), "board.lua"));
	int depth = LuaUtility::GetField(_luaState, "board");
	vector<IBoardState *> * boardState = LoadBoardState();
	vector<IBoardLocation *> * boardLocation = InitialiseBoard(boardState);
	int height = LuaUtility::FieldToInt(_luaState, "height");
	int width = LuaUtility::FieldToInt(_luaState, "width");
	_board = new Board(height, width, boardState, boardLocation);
	lua_pop(_luaState, depth);
}

vector<IBoardState *> * BoardGame::LoadBoardState(){
	int depth = LuaUtility::GetField(_luaState, "state");

	vector<IBoardState *> * boardState = new vector<IBoardState *>();

	lua_pushnil(_luaState);
	while(lua_next(_luaState, -2) != 0){
		int value = LuaUtility::FieldToInt(_luaState, "value");
		char identifier = LuaUtility::FieldToString(_luaState, "identifier")[0];
		string name = LuaUtility::FieldToString(_luaState, "name");
		string valueString = string();
		try{
			string valueString = LuaUtility::FieldToString(_luaState, "valueString");
		}
		catch(Wsq::Lua::LuaFieldIsNilException& e){
			lua_pop(_luaState, 1);
		}

		IBoardState * newState = GetBoardStateFactory()->Create(value, identifier, name, valueString);
		boardState->push_back(newState);
		lua_pop(_luaState, 1);
	}
	lua_pop(_luaState, depth);

	return boardState;
}

vector<IBoardLocation *> * BoardGame::InitialiseBoard(vector<IBoardState *> * boardState){
	int depth = LuaUtility::GetField(_luaState, "locations");
	vector<IBoardLocation *> * boardLocation = new vector<IBoardLocation *>();

	lua_pushnil(_luaState);
	while(lua_next(_luaState, -2) != 0){
		char stateIdentifier = LuaUtility::FieldToString(_luaState, "state.identifier")[0];
		IBoardState * state = nullptr;
		for(unsigned s = 0; s < boardState->size(); s++){
			if(boardState->at(s)->GetIdentifier() == stateIdentifier){
				state = boardState->at(s);
				break;
			}
		}

		if(state == nullptr){
			throw BoardLocationState();
		}

		BoardLocation * newLocation = new BoardLocation(state, LuaUtility::FieldToInt(_luaState, "value"));
		boardLocation->push_back(newLocation);
		lua_pop(_luaState, 1);
	}
	lua_pop(_luaState, depth);

	return boardLocation;
}

IBoard * BoardGame::GetBoard(){
	return (IBoard *)_board;
}

IBoardStateFactory * BoardGame::GetBoardStateFactory(){
	return _boardStateFactory;
}

void BoardGame::SetBoardStateFactory(IBoardStateFactory * factory){
	if(_boardStateFactory != nullptr){
		delete _boardStateFactory;
	}
	_boardStateFactory = factory;
}

IGameDetailFactory * BoardGame::GetGameDetailFactory(){
	if(_gameDetailFactory == nullptr){
		_gameDetailFactory = new GameDetailFactory();
	}

	return _gameDetailFactory;
}

void BoardGame::SetGameDetailFactory(IGameDetailFactory * factory){
	if(_gameDetailFactory != nullptr){
		delete _gameDetailFactory;
	}
	_gameDetailFactory = factory;
}

void BoardGame::SetGameListLoader(vector<IGameDetail *> * (*loadGameList)()){
	_loadGameList = loadGameList;
}
*/
