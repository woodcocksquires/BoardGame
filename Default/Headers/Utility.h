/*
 * Utility.h
 *
 *  Created on: 20 Jun 2014
 *      Author: Andrew.squires
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include<BoardGameManager.h>

using Wsq::BoardGame;

namespace Wsq {
	namespace BoardGame {
		namespace Default {
			class Utility {
			  public:
				static BoardGameManager * MakeDefaultBoardGameManager();
			};
		}
	}
}



#endif /* UTILITY_H_ */
