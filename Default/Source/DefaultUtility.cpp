/*
 * Utility.cpp
 *
 *  Created on: 20 Jun 2014
 *      Author: Andrew.squires
 */

#include<IBoardGameLoader.h>
#include<BoardGameManager.h>
#include<BoardGameLoader.h>
#include<BoardGameDetailsFactory.h>
#include<DefaultUtility.h>

using namespace Wsq::BoardGame;
using namespace Wsq::BoardGame::Default;

BoardGameManager * DefaultUtility::MakeDefaultBoardGameManager(){
	BoardGameManager * manager = new BoardGameManager();
	manager->BoardGameLoader(new BoardGameLoader());
	manager->BoardGameDetailsFactory(new BoardGameDetailsFactory());
	return manager;
}
