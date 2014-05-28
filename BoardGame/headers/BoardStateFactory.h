/*
 * BoardStateFactory.h
 *
 *  Created on: 28 May 2014
 *      Author: andrew.squires
 */

#ifndef BOARDSTATEFACTORY_H_
#define BOARDSTATEFACTORY_H_

#include <IBoardState.h>
#include <IBoardStateFactory.h>

namespace Wsq {
	namespace BoardGame {
		class BoardStateFactory: public IBoardStateFactory {
		  public:
			BoardStateFactory() {}
			virtual ~BoardStateFactory() {}
			virtual IBoardState * Create(int value, char identifier, string name, string valueString);
		};
	}
}



#endif /* BOARDSTATEFACTORY_H_ */
