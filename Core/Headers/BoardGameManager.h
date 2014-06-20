/*
 * BoardGameManager.h
 *
 *  Created on: 17 Jun 2014
 *      Author: Andrew.squires
 */

#ifndef BOARDGAMEMANAGER_H_
#define BOARDGAMEMANAGER_H_

#include<vector>
#include<IBoardGameLoader.h>
#include<IBoardGameDetails.h>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class BoardGameManager final {
		  private:
			IBoardGameLoader * _boardGameLoader;
			vector<IBoardGameDetails *> * _boardGames;

			bool configurationIsValid();

		  public:
			BoardGameManager();
			~BoardGameManager();

			bool LoadGames();

			IBoardGameLoader * BoardGameLoader();
			void BoardGameLoader(IBoardGameLoader * loader);
		};
	}
}

#endif /* BOARDGAMEMANAGER_H_ */
