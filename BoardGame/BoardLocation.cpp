/*
 * BoardLocation.cpp
 *
 *  Created on: 19 May 2014
 *      Author: andrew.squires
 */

#include <BoardLocation.h>
#include <IBoardState.h>

using namespace Wsq::BoardGame;

BoardLocation::BoardLocation(IBoardState * state, int value): _state(state), _value(value) {
	_piece = nullptr;
}
BoardLocation::~BoardLocation(){}

IBoardState * BoardLocation::GetState() { return _state; }

IBoardPiece * BoardLocation::GetPiece() { return _piece; }

bool BoardLocation::SetPiece(IBoardPiece * piece){
	if(_piece != nullptr && piece != nullptr){
		return false;
	}

	_piece = piece;
	return true;
}

int BoardLocation::GetValue() { return _value; }



