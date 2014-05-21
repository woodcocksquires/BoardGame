/*
 * BoardLocation.cpp
 *
 *  Created on: 19 May 2014
 *      Author: andrew.squires
 */

#include <BoardLocation.h>
#include <IBoardState.h>

using namespace Wsq::BoardGame;

BoardLocation::BoardLocation(BoardState * state, int value): _state(state), _value(value) {}
BoardLocation::~BoardLocation(){}

IBoardState * BoardLocation::GetState() { return dynamic_cast<IBoardState *>(_state); }
int BoardLocation::GetValue() { return _value; }



