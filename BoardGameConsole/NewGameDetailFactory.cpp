/*
 * NewGameDetail.cpp
 *
 *  Created on: 3 Jun 2014
 *      Author: Andrew.squires
 */


#include<NewGameDetailFactory.h>
#include<NewGameDetail.h>
#include<IGameDetail.h>
#include<lua.hpp>

using namespace Wsq::Test;
using namespace Wsq::BoardGame;
using namespace std;

IGameDetail * NewGameDetailFactory::Create(lua_State * L, string path){
	return (IGameDetail *)(new NewGameDetail(L, path));
}


