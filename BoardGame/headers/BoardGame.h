#ifndef BOARDGAME_H_
#define BOARDGAME_H_

#include <lua.h>
#include <string>
#include <IBoardGame.h>
#include <vector>
#include <GameDetail.h>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class BoardGame : public IBoardGame {
		  private:
			const char * _scriptPath = "scripts";
			string _gamePath;
			lua_State * _luaState;
			vector<IGameDetail *> * _gameList;
			vector<IGameDetail *> * LoadGameList();
			GameDetail * LoadGameSummary(string path);
		  public:
			BoardGame();
			virtual ~BoardGame();
			virtual vector<IGameDetail *> * GetGameList();
		};
	}
}

#endif
