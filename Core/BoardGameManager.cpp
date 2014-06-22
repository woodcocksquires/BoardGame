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

using namespace std;
using namespace Wsq::BoardGame;

BoardGameManager::BoardGameManager(){
	_boardGameLoader = nullptr;
	_boardGameDetailsFactory = nullptr;
	_boardGames = nullptr;
}

BoardGameManager::~BoardGameManager(){
	delete _boardGameLoader;
	delete _boardGameDetailsFactory;
	for(unsigned g = 0; g < _boardGames->size(); g++){
		delete _boardGames->at(g);
	}
	delete _boardGames;
}

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


IBoardGameDetailsFactory * BoardGameManager::BoardGameDetailsFactory(){
	return _boardGameDetailsFactory;
}

void BoardGameManager::BoardGameDetailsFactory(IBoardGameDetailsFactory * detailsFactory){
	if(_boardGameDetailsFactory != nullptr){
		try {
			delete _boardGameDetailsFactory;
		}
		catch(...){
			throw Errors::SetBoardGameDetailsFactoryException();
		}
	}

	_boardGameDetailsFactory = detailsFactory;
}

/* ### Private methods ### */

bool BoardGameManager::configurationIsValid(){
	if(_boardGameLoader == nullptr
		|| _boardGameDetailsFactory == nullptr){
		return false;
	}

	return true;
}


/* ### Public methods ### */

void BoardGameManager::LoadBoardGames(){
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

	_boardGames = _boardGameLoader->LoadGamesDetails(_boardGameDetailsFactory);
}

