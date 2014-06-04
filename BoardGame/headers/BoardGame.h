#ifndef BOARDGAME_H_
#define BOARDGAME_H_

#include <lua.h>
#include <string>
#include <IBoardGame.h>
#include <vector>
#include <IGameDetail.h>
#include <IGameDetailFactory.h>
#include <IBoardState.h>
#include <IBoardStateFactory.h>
#include <IBoardLocation.h>
#include <Board.h>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class BoardLocationState: public exception{
			virtual const char * what() const throw(){
				return "The board location has no board state defined.";
			}
		};
		class BoardGame : public IBoardGame {
		  private:
			const char * _scriptPath = "scripts";
			string _gamePath;
			lua_State * _luaState;
			vector<IGameDetail *> * _gameList;
			IBoard * _board;
			IGameDetailFactory * _gameDetailFactory;
			IBoardStateFactory * _boardStateFactory;


			vector<IGameDetail *> * LoadGameList();
			//IGameDetail * LoadGameSummary(string path);
			void LoadBoardDefinition(IGameDetail * detail);
			vector<IBoardState *> * LoadBoardState();
			vector<IBoardLocation *> * InitialiseBoard(vector<IBoardState *> * boardState);

		  public:
			BoardGame();
			virtual ~BoardGame();
			virtual vector<IGameDetail *> * GetGameList();
			virtual bool LoadGame(IGameDetail * detail);
			virtual IBoard * GetBoard();

			virtual IBoardStateFactory * GetBoardStateFactory();
			virtual void SetBoardStateFactory(IBoardStateFactory * factory);
			virtual IGameDetailFactory * GetGameDetailFactory();
			virtual void SetGameDetailFactory(IGameDetailFactory * factory);
		};
	}
}

#endif
