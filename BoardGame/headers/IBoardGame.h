#ifndef IBOARDGAME_H_
#define IBOARDGAME_H_

#include <IGameDetail.h>
#include <vector>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class IBoardGame {
		  public:
			virtual ~IBoardGame() {};
			virtual vector<IGameDetail *> * GetGameList() = 0;
			virtual bool LoadGame(IGameDetail * detail) = 0;
		};
	}
}


#endif
