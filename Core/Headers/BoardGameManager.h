/*
 * BoardGameManager.h
 *
 *  Created on: 17 Jun 2014
 *      Author: Andrew.squires
 */

#ifndef BOARDGAMEMANAGER_H_
#define BOARDGAMEMANAGER_H_

#include<vector>
#include<IBoardGame.h>
#include<IBoardGameLoader.h>
#include<IBoardGameDetailsFactory.h>
#include<IBoardGameDetails.h>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class BoardGameManager final {
		  private:
			IBoardGameLoader * _boardGameLoader;
			IBoardGameDetailsFactory * _boardGameDetailsFactory;
			vector<IBoardGameDetails *> * _boardGames;

			bool configurationIsValid();

		  public:
			BoardGameManager();
			~BoardGameManager();

			vector<IBoardGameDetails *> * BoardGames();

			void LoadBoardGames();
			IBoardGame * StartGame(IBoardGameDetails * details);

			IBoardGameLoader * BoardGameLoader();
			void BoardGameLoader(IBoardGameLoader * loader);
			IBoardGameDetailsFactory * BoardGameDetailsFactory();
			void BoardGameDetailsFactory(IBoardGameDetailsFactory * detailsFactory);
		};
	}
}

#endif /* BOARDGAMEMANAGER_H_ */
