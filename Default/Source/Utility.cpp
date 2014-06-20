/*
 * Utility.cpp
 *
 *  Created on: 20 Jun 2014
 *      Author: Andrew.squires
 */


#include<BoardGameManager.h>
#include<BoardGameLoader.h>
#include<Utility.h>

using namespace Wsq::BoardGame;
using namespace Wsq::BoardGame::Default;

BoardGameManager * Utility::MakeDefaultBoardGameManager(){
	BoardGameManager * manager = new BoardGameManager();
	manager->BoardGameLoader(new BoardGameLoader());

	return manager;
}




