/*
 * BoardGameLoader.h
 *
 *  Created on: 18 Jun 2014
 *      Author: Andrew.squires
 */

#ifndef BOARDGAMELOADER_H_
#define BOARDGAMELOADER_H_

#include<vector>

#include<IBoardGameLoader.h>
#include<IBoardGameDetails.h>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		namespace Default {
			class BoardGameLoader : public IBoardGameLoader {
			  public:
				BoardGameLoader(){}
				virtual ~BoardGameLoader(){}

				virtual vector<IBoardGameDetails *> * LoadGames();
			};
		}
	}
}



#endif /* BOARDGAMELOADER_H_ */
