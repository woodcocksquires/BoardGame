/*
 * BoardGameDetails.cpp
 *
 *  Created on: 21 Jun 2014
 *      Author: Andrew
 */

#include<string>
#include<FileSystem.h>
#include<APIUtility.h>
#include<BoardGameDetails.h>
#include<IAssetLocation.h>


using namespace std;
using namespace Wsq::Lua;
using namespace Wsq::File;
using namespace Wsq::BoardGame::Default;

BoardGameDetails::BoardGameDetails(IAssetLocation * location){
	APIUtility * luaUtility = APIUtility::GetUtility();
	luaUtility->LoadAndExecuteFile(FileSystem::CombinePath(location->AbsoluteLocation(), "summary.lua"));
	int depth = luaUtility->GetField(location->RelativeLocation());
	_name = luaUtility->FieldToString("name");
	_description = luaUtility->FieldToString("description");
	_assetLocation = location;
	_minPlayers = luaUtility->FieldToInt("minplayers");
	_maxPlayers = luaUtility->FieldToInt("maxplayers");
	luaUtility->Pop(depth);
}

string BoardGameDetails::Name(){
	return _name;
}

string BoardGameDetails::Description(){
	return _description;
}

IAssetLocation * BoardGameDetails::AssetLocation(){
	return _assetLocation;
}

int BoardGameDetails::MinPlayers(){
	return _minPlayers;
}

int BoardGameDetails::MaxPlayers(){
	return _maxPlayers;
}
