/*
 * IBoard.h
 *
 *  Created on: 19 May 2014
 *      Author: andrew.squires
 */

#ifndef IBOARD_H_
#define IBOARD_H_

#include <IBoardState.h>
#include <IBoardLocation.h>

namespace Wsq {
	namespace BoardGame {
		class IBoard {
		  public:
			IBoard() {}
			virtual ~IBoard() {}
			virtual int GetHeight() = 0;
			virtual int GetWidth() = 0;
			virtual IBoardLocation * GetBoardLocation(int position) = 0;
			virtual IBoardLocation * GetBoardLocation(int row, int col) = 0;
		};
	}
}



#endif /* IBOARD_H_ */
