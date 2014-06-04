/*
 * GameDetailFactory.h
 *
 *  Created on: 30 May 2014
 *      Author: andrew.squires
 */

#ifndef GAMEDETAILFACTORY_H_
#define GAMEDETAILFACTORY_H_

#include<string>
#include<IGameDetailFactory.h>
#include<IGameDetail.h>
#include<Lua.hpp>

namespace Wsq {
	namespace BoardGame {
		class GameDetailFactory: public IGameDetailFactory {
		  public:
			GameDetailFactory(){}
			virtual ~GameDetailFactory(){}
			virtual IGameDetail * Create(lua_State * L, string path);
		};
	}
}




#endif /* GAMEDETAILFACTORY_H_ */
