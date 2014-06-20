/*
 * BoardGameManager.cpp
 *
 *  Created on: 17 Jun 2014
 *      Author: Andrew.squires
 */

#include<vector>

#include<IBoardGameLoader.h>
#include<BoardGameManager.h>
#include<BoardGameManagerErrors.h>
#include<BoardGameLoader.h>

using namespace std;
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


/* ### Private methods ### */

bool BoardGameManager::configurationIsValid(){
	if(_boardGameLoader == nullptr){
		return false;
	}
}


/* ### Public methods ### */

bool BoardGameManager::LoadGames(){
	if(!configurationIsValid()){
		throw Errors::IncorrectConfigurationException();
	}

	if(_boardGames != nullptr){
		try{
			for(unsigned g = 0; g< _boardGames->size(); g++){
				delete _boardGames->at(g);
			}
			delete _boardGames;
		}
		catch(...){
			throw Errors::LoadGamesException();
		}
	}

	_boardGames = _boardGameLoader->LoadGames();
}

