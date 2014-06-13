/*
 * GameDetail.h
 *
 *  Created on: 12 May 2014
 *      Author: Andrew.squires
 */
/*
#ifndef GAMEDETAIL_H_
#define GAMEDETAIL_H_

#include <string>
#include <IGameDetail.h>
#include <Lua.hpp>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class GameDetail: public IGameDetail {
		  friend class GameDetailFactory;
		  private:
			string _name;
			string _description;
			string _path;
			string _shortPath;
			int _maxPlayers;
			int _minPlayers;
			GameDetail(lua_State * L, string path);
		  public:
			virtual ~GameDetail() {};
			virtual string Name(){ return _name; }
			virtual string Description(){ return _description; }
			virtual string Path(){ return _path; }
			virtual string ShortPath(){ return _shortPath; }
			virtual int MaxPlayers(){ return _maxPlayers; }
			virtual int MinPlayers(){ return _minPlayers; }
		};
	}
}



#endif /* GAMEDETAIL_H_ */
