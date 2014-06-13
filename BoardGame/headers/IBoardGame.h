/*#ifndef IBOARDGAME_H_
#define IBOARDGAME_H_

#include <IGameDetail.h>
#include <IBoardStateFactory.h>
#include <IGameDetailFactory.h>
#include <IBoard.h>
#include <vector>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class IBoardGame {
		  public:
			virtual ~IBoardGame() {};
			virtual vector<IGameDetail *> * GetGameList() = 0;
			virtual bool LoadGame(IGameDetail * detail) = 0;
			virtual IBoard * GetBoard() = 0;
			virtual IBoardStateFactory * GetBoardStateFactory() = 0;
			virtual void SetBoardStateFactory(IBoardStateFactory * factory) = 0;
			virtual IGameDetailFactory * GetGameDetailFactory() = 0;
			virtual void SetGameDetailFactory(IGameDetailFactory * factory) = 0;
		};
	}
}


#endif
