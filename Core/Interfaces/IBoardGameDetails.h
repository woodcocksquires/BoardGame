/*
 * IBoardGameDetails.h
 *
 *  Created on: 17 Jun 2014
 *      Author: Andrew.squires
 */

#ifndef IBOARDGAMEDETAILS_H_
#define IBOARDGAMEDETAILS_H_

#include<string>

#include<IAssetLocation.h>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class IBoardGameDetails {
		  public:
			virtual ~IBoardGameDetails(){}
			virtual string Name() = 0;
			virtual string Description() = 0;
			virtual IAssetLocation * AssetLocation() = 0;
			virtual int MaxPlayers() = 0;
			virtual int MinPlayers() = 0;
		};
	}
}



#endif /* IBOARDGAMEDETAILS_H_ */
