/*
 * IBoardGameLoader.h
 *
 *  Created on: 17 Jun 2014
 *      Author: Andrew.squires
 */

#ifndef IBOARDGAMELOADER_H_
#define IBOARDGAMELOADER_H_

#include<vector>

#include<IBoardGameDetails.h>
#include<IBoardGameDetailsFactory.h>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class IBoardGameLoader {
		  public:
			IBoardGameLoader(){}
			virtual ~IBoardGameLoader(){}
			virtual vector<IBoardGameDetails *> * LoadGamesDetails(IBoardGameDetailsFactory * detailsFactory) = 0;
		};
	}
}

#endif /* IBOARDGAMELOADER_H_ */
