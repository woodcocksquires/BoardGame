/*
 * IBoardStateFactory.h
 *
 *  Created on: 28 May 2014
 *      Author: andrew.squires
 */
/*
#ifndef IBOARDSTATEFACTORY_H_
#define IBOARDSTATEFACTORY_H_

#include <IBoardState.h>

namespace Wsq {
	namespace BoardGame {
		class IBoardStateFactory {
		  public:
			IBoardStateFactory() {}
			virtual ~IBoardStateFactory() {}
			virtual IBoardState * Create(int value, char identifier, string name, string valueString) = 0;
		};
	}
}



#endif /* IBOARDSTATEFACTORY_H_ */
