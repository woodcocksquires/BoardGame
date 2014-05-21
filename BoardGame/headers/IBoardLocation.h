/*
 * IBoardLocation.h
 *
 *  Created on: 19 May 2014
 *      Author: andrew.squires
 */

#ifndef IBOARDLOCATION_H_
#define IBOARDLOCATION_H_

#include <IBoardState.h>

namespace Wsq {
	namespace BoardGame {
		class IBoardLocation {
		  public:
			IBoardLocation() {}
			virtual ~IBoardLocation() {}
			virtual IBoardState * GetState() = 0;
			virtual int GetValue() = 0;
		};
	}
}



#endif /* IBOARDLOCATION_H_ */
