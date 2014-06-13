/*
 * NewGameDetailFactory.h
 *
 *  Created on: 3 Jun 2014
 *      Author: Andrew.squires
 */
/*
#ifndef NEWGAMEDETAILFACTORY_H_
#define NEWGAMEDETAILFACTORY_H_

#include<string>
#include<lua.hpp>
#include<IGameDetailFactory.h>
#include<IGameDetail.h>

using namespace std;
using namespace Wsq::BoardGame;

namespace Wsq {
	namespace Test {
		class NewGameDetailFactory: public IGameDetailFactory {
		  public:
			NewGameDetailFactory() {}
			virtual ~NewGameDetailFactory() {}
			virtual IGameDetail * Create(lua_State * L, string path);
		};
	}
}



#endif /* NEWGAMEDETAILFACTORY_H_ */
