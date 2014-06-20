/*
 * IAssetLocation.h
 *
 *  Created on: 18 Jun 2014
 *      Author: Andrew.squires
 */

#ifndef IASSETLOCATION_H_
#define IASSETLOCATION_H_

#include<string>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class IAssetLocation {
		  public:
			virtual ~IAssetLocation(){}
			virtual string AbsoluteLocation() = 0;
			virtual string RelativeLocation() = 0;
		};
	}
}



#endif /* IASSETLOCATION_H_ */
