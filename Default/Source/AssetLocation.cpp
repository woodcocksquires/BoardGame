/*
 * AssetLocation.cpp
 *
 *  Created on: 21 Jun 2014
 *      Author: Andrew
 */

#include<string>
#include<StringUtility.h>
#include<AssetLocation.h>

using namespace std;
using namespace Wsq::Text;
using namespace Wsq::BoardGame::Default;

AssetLocation::AssetLocation(string path){
	_path = path;
	_shortPath = StringUtility::ToLower(path.substr(path.find_last_of('\\') + 1));
}

string AssetLocation::AbsoluteLocation(){
	return _path;
}

string AssetLocation::RelativeLocation(){
	return _shortPath;
}

