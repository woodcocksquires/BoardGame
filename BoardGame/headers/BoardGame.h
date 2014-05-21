#ifndef BOARDGAME_H_
#define BOARDGAME_H_

#include <lua.h>
#include <string>
#include <IBoardGame.h>
#include <vector>
#include <IGameDetail.h>
#include <GameDetail.h>
#include <Board.h>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class BoardGame : public IBoardGame {
		  private:
			const char * _scriptPath = "scripts";
			string _gamePath;
			lua_State * _luaState;
			vector<IGameDetail *> * _gameList;
			Board * _board;

			vector<IGameDetail *> * LoadGameList();
			GameDetail * LoadGameSummary(string path);
			void LoadBoardDefinition(IGameDetail * detail);
			vector<BoardState *> * LoadBoardState(IGameDetail * detail);
		  public:
			BoardGame();
			virtual ~BoardGame();
			virtual vector<IGameDetail *> * GetGameList();
			virtual bool LoadGame(IGameDetail * detail);
		};
	}
}

#endif
