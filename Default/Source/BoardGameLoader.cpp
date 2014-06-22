/*
 * BoardGameLoader.cpp
 *
 *  Created on: 18 Jun 2014
 *      Author: Andrew.squires
 */

#include<vector>

#include<IBoardGameDetails.h>
#include<IBoardGameDetailsFactory.h>
#include<APIUtility.h>
#include<FileSystem.h>
#include<StringUtility.h>
#include<BoardGameLoader.h>
#include<AssetLocation.h>


using namespace std;
using namespace Wsq::Lua;
using namespace Wsq::File;
using namespace Wsq::Text;
using namespace Wsq::BoardGame;
using namespace Wsq::BoardGame::Default;

BoardGameLoader::BoardGameLoader(){
	APIUtility * luaUtility = APIUtility::GetUtility();
	if(!luaUtility->GlobalExists("wsq")){
		luaUtility->SetGlobal("wsq", EmptyTable(), true);
	}

	if(!luaUtility->FieldExists("boardgame")){
		luaUtility->SetField("boardgame", EmptyTable(), true);
	}

	luaUtility->LoadAndExecuteFile(FileSystem::CombinePath(BASEPATH, "config.lua"));
	_gamePath = luaUtility->FieldToString("config.gamepath");
}

vector<IBoardGameDetails *> * BoardGameLoader::LoadGamesDetails(IBoardGameDetailsFactory * detailsFactory){
	vector<IBoardGameDetails *> * gameList = new vector<IBoardGameDetails *>();
	APIUtility * luaUtility = APIUtility::GetUtility();

	if(!luaUtility->FieldExists("games")){
		luaUtility->SetField("games", EmptyTable(), true);
	}

	vector<string> * games = FileSystem::GetDirectories(FileSystem::CombinePath(BASEPATH, _gamePath));
	for(unsigned g = 0; g < games->size(); g++){
		AssetLocation * asset = new AssetLocation(games->at(g));
		gameList->push_back(detailsFactory->Create(asset));
	}
	return gameList;
}
