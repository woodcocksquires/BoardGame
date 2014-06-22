/*
 * BoardGameDetails.h
 *
 *  Created on: 21 Jun 2014
 *      Author: Andrew
 */

#ifndef BOARDGAMEDETAILS_H_
#define BOARDGAMEDETAILS_H_

#include<string>
#include<IAssetLocation.h>
#include<BoardGameDetailsFactory.h>

using namespace std;
using namespace Wsq::BoardGame;

namespace Wsq {
	namespace BoardGame {
		namespace Default {
			class BoardGameDetails: public IBoardGameDetails {
			  friend class BoardGameDetailsFactory;
			  private:
				string _name;
				string _description;
				IAssetLocation * _assetLocation;
				int _maxPlayers;
				int _minPlayers;

				BoardGameDetails(IAssetLocation * location);

			  public:
				~BoardGameDetails(){};
				virtual string Name();
				virtual string Description();
				virtual IAssetLocation * AssetLocation();
				virtual int MaxPlayers();
				virtual int MinPlayers();
			};
		}
	}
}



#endif /* BOARDGAMEDETAILS_H_ */
