/*
 * main.cpp
 *
 *  Created on: 25 Apr 2014
 *      Author: Andy
 */

#include <iostream>
#include <Game.h>

using namespace std;
using namespace Wsq::BoardGame;

int main(){
	cout << "Hell yeah";
	Game g = Game();
	cout << g.Test() << endl;
}
