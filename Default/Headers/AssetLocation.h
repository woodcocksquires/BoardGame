/*
 * AssetLocation.h
 *
 *  Created on: 21 Jun 2014
 *      Author: Andrew
 */

#ifndef ASSETLOCATION_H_
#define ASSETLOCATION_H_

#include<string>
#include<IAssetLocation.h>

using namespace std;
using namespace Wsq::BoardGame;

namespace Wsq {
	namespace BoardGame {
		namespace Default {
			class AssetLocation: public IAssetLocation {
			  private:
				string _path;
				string _shortPath;
			  public:
				AssetLocation(string path);
				virtual ~AssetLocation(){}

				virtual string AbsoluteLocation();
				virtual string RelativeLocation();
			};
		}
	}
}



#endif /* ASSETLOCATION_H_ */
