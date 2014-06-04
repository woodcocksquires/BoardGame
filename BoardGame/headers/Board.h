/*
 * Board.h
 *
 *  Created on: 19 May 2014
 *      Author: andrew.squires
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <string>
#include <vector>
#include <IBoardLocation.h>
#include <IBoard.h>
#include <BoardState.h>
#include <BoardLocation.h>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class Board: public IBoard {
		  private:
			unsigned _height, _width;
			vector<IBoardState *> * _boardState;
			vector<IBoardLocation *> * _boardLocation;
		  public:
			Board(int height, int width, vector<IBoardState *> * boardState, vector<IBoardLocation *> * boardLocation);
			~Board();
			virtual unsigned GetHeight();
			virtual unsigned GetWidth();
			virtual IBoardLocation * GetBoardLocation(int position);
			virtual IBoardLocation * GetBoardLocation(int row, int col);
		};
	}
}


#endif /* BOARD_H_ */
