/*
/* * IGameDetailFactory.h
 *
 *  Created on: 30 May 2014
 *      Author: andrew.squires
 */
/*
#ifndef IGAMEDETAILFACTORY_H_
#define IGAMEDETAILFACTORY_H_

#include <string>
#include <IGameDetail.h>
#include <Lua.hpp>


namespace Wsq {
	namespace BoardGame {
		class IGameDetailFactory {
		 public:
			IGameDetailFactory(){}
			virtual ~IGameDetailFactory() {}
			virtual IGameDetail * Create(lua_State * L, string path) = 0;
		};
	}
}



#endif /* IGAMEDETAILFACTORY_H_ */
