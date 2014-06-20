/*
 * BoardGameLoader.cpp
 *
 *  Created on: 18 Jun 2014
 *      Author: Andrew.squires
 */

#include<vector>

#include<IBoardGameDetails.h>
#include<BoardGameLoader.h>

using namespace std;
using namespace Wsq::BoardGame;
using namespace Wsq::BoardGame::Default;

vector<IBoardGameDetails *> * BoardGameLoader::LoadGames(){
	return new vector<IBoardGameDetails *>();
}
