/*
 * BoardLocation.h
 *
 *  Created on: 19 May 2014
 *      Author: andrew.squires
 */

#ifndef BOARDLOCATION_H_
#define BOARDLOCATION_H_

#include <IBoardLocation.h>
#include <IBoardState.h>
#include <BoardState.h>

namespace Wsq {
	namespace BoardGame {
		class BoardLocation: public IBoardLocation {
		  private:
			BoardState * _state;
			int _value;
		  public:
			BoardLocation(BoardState * state, int value);
			virtual ~BoardLocation();
			virtual IBoardState * GetState();
			virtual int GetValue();
		};
	}
}




#endif /* BOARDLOCATION_H_ */
