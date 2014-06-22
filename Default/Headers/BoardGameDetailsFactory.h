/*
 * BoardGameDetailsFactory.h
 *
 *  Created on: 21 Jun 2014
 *      Author: Andrew
 */

#ifndef BOARDGAMEDETAILSFACTORY_H_
#define BOARDGAMEDETAILSFACTORY_H_

#include<IAssetLocation.h>
#include<IBoardGameDetailsFactory.h>
#include<IBoardGameDetails.h>

using namespace Wsq::BoardGame;

namespace Wsq {
	namespace BoardGame {
		namespace Default {
			class BoardGameDetailsFactory: public IBoardGameDetailsFactory {
			  public:
				BoardGameDetailsFactory(){}
				~BoardGameDetailsFactory(){}
				virtual IBoardGameDetails * Create(IAssetLocation * location);
			};
		}
	}
}



#endif /* BOARDGAMEDETAILSFACTORY_H_ */
