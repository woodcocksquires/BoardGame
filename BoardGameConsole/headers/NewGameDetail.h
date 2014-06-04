/*
 * NewGameDetail.h
 *
 *  Created on: 3 Jun 2014
 *      Author: Andrew.squires
 */

#ifndef NEWGAMEDETAIL_H_
#define NEWGAMEDETAIL_H_

#include<IGameDetail.h>
#include<Lua.hpp>
#include<string>

using namespace Wsq::BoardGame;
using namespace std;

namespace Wsq {
	namespace Test {
		class NewGameDetail: public IGameDetail {
		  friend class NewGameDetailFactory;
		  private:
			string _name;
			string _description;
			string _path;
			string _shortPath;
			int _maxPlayers;
			int _minPlayers;
			string _someProperty;
			NewGameDetail(lua_State * L, string path);
		  public:
			virtual ~NewGameDetail() {};
			virtual string Name(){ return _name; }
			virtual string Description(){ return _description; }
			virtual string Path(){ return _path; }
			virtual string ShortPath(){ return _shortPath; }
			virtual int MaxPlayers(){ return _maxPlayers; }
			virtual int MinPlayers(){ return _minPlayers; }
			string SomeProperty(){ return _someProperty; }
		};
	}
}


#endif /* NEWGAMEDETAIL_H_ */
