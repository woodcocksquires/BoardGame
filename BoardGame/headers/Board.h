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
			int _height, _width;
			vector<BoardState *> * _boardState;
			vector<BoardLocation *> * _boardLocation;
		  public:
			Board(int height, int width, vector<BoardState *> * boardState, vector<BoardLocation *> * boardLocation);
			~Board();
			virtual int GetHeight();
			virtual int GetWidth();
			virtual IBoardLocation * GetBoardLocation(int position);
			virtual IBoardLocation * GetBoardLocation(int row, int col);
		};
	}
}


#endif /* BOARD_H_ */
