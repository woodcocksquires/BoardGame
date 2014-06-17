/*
 * BoardGameManager.cpp
 *
 *  Created on: 17 Jun 2014
 *      Author: Andrew.squires
 */

#include<BoardGameManager.h>
#include<BoardGameManagerErrors.h>

using namespace Wsq::BoardGame;

IBoardGameLoader * BoardGameManager::BoardGameLoader(){
	return _boardGameLoader;
}

void BoardGameManager::BoardGameLoader(IBoardGameLoader * loader){
	if(_boardGameLoader != nullptr){
		try {
			delete _boardGameLoader;
		}
		catch(...){
			throw Errors::BoardGameLoaderException();
		}
	}
	_boardGameLoader = loader;
}

