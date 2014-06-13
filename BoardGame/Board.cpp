/*
 * Board.cpp
 *
 *  Created on: 19 May 2014
 *      Author: andrew.squires
 */
/*
#include <Board.h>

using namespace Wsq::BoardGame;

Board::Board(int height, int width, vector<IBoardState *> * boardState, vector<IBoardLocation *> * boardLocation):
		_height(height), _width(width), _boardState(boardState), _boardLocation(boardLocation) {}

Board::~Board(){
	for(int l=0; l<(int)_boardLocation->size(); l++){
		delete _boardLocation->at(l);
	}

	for(int s=0; s<(int)_boardState->size(); s++){
		delete _boardState->at(s);
	}
	delete _boardState;
	delete _boardLocation;
}

unsigned Board::GetHeight() { return _height; }
unsigned Board::GetWidth() { return _width; }

IBoardLocation * Board::GetBoardLocation(int position){
	if(position >= 0 && position < (int)_boardLocation->size()){
		return dynamic_cast<IBoardLocation *>(_boardLocation->at(position));
	}
	return nullptr;
}

IBoardLocation * Board::GetBoardLocation(int row, int col){
	return GetBoardLocation(row * _width + col);
}
*/



