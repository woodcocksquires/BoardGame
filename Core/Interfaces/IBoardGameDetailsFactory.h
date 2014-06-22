/*
 * IBoardGameDetailsFactory.h
 *
 *  Created on: 21 Jun 2014
 *      Author: Andrew
 */

#ifndef IBOARDGAMEDETAILSFACTORY_H_
#define IBOARDGAMEDETAILSFACTORY_H_

#include<IAssetLocation.h>
#include<IBoardGameDetails.h>

namespace Wsq {
	namespace BoardGame {
		class IBoardGameDetailsFactory {
		  public:
			IBoardGameDetailsFactory(){}
			virtual ~IBoardGameDetailsFactory() {}
			virtual IBoardGameDetails * Create(IAssetLocation * location) = 0;
		};
	}
}

#endif /* IBOARDGAMEDETAILSFACTORY_H_ */
