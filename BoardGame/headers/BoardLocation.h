/*
 * BoardLocation.h
 *
 *  Created on: 19 May 2014
 *      Author: andrew.squires
 */
/*
#ifndef BOARDLOCATION_H_
#define BOARDLOCATION_H_

#include <IBoardLocation.h>
#include <IBoardState.h>
#include <IBoardPiece.h>

namespace Wsq {
	namespace BoardGame {
		class BoardLocation: public IBoardLocation {
		  private:
			IBoardState * _state;
			IBoardPiece * _piece;
			int _value;
		  public:
			BoardLocation(IBoardState * state, int value);
			virtual ~BoardLocation();
			virtual IBoardState * GetState();
			virtual IBoardPiece * GetPiece();
			virtual bool SetPiece(IBoardPiece * piece);
			virtual int GetValue();
		};
	}
}




#endif /* BOARDLOCATION_H_ */
