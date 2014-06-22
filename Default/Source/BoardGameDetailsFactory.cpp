/*
 * BoardGameDetailsFactory.cpp
 *
 *  Created on: 21 Jun 2014
 *      Author: Andrew
 */

#include<string>
#include<IBoardGameDetails.h>
#include<BoardGameDetails.h>
#include<BoardGameDetailsFactory.h>

using namespace std;
using namespace Wsq::BoardGame;
using namespace Wsq::BoardGame::Default;

IBoardGameDetails * BoardGameDetailsFactory::Create(IAssetLocation * location){
	return (IBoardGameDetails *) new BoardGameDetails(location);
}
