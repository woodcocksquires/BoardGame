/*
 * IBoardGameCreator.h
 *
 *  Created on: 20 May 2014
 *      Author: andrew.squires
 */

#ifndef IBOARDGAMECREATOR_H_
#define IBOARDGAMECREATOR_H_

#include <IBoardGame.h>
#include <BoardGame.h>

namespace Wsq {
	namespace BoardGame {
		class IBoardGameCreator {
		  public:
			static IBoardGame * MakeBoardGame(){
				return (IBoardGame *)(new BoardGame());
			}
		};
	}
}



#endif /* IBOARDGAMECREATOR_H_ */
