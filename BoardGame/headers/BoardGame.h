#ifndef BOARDGAME_H_
#define BOARDGAME_H_

#include <lua.h>
#include <IBoardGame.h>

namespace Wsq {
	namespace BoardGame {
		class BoardGame : public IBoardGame {
		  private:
			const char * _scriptPath = "scripts";
			const char * _gamePath;
			lua_State * _luaState;
			vector<IGameDetail *> * _gameList;
			vector<IGameDetail *> * LoadGameList();
		  public:
			BoardGame();
			virtual ~BoardGame();
			virtual vector<IGameDetail *> * GetGameList();
		};
	}
}

#endif
