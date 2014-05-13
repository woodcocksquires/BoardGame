/*
 * main.cpp
 *
 *  Created on: 25 Apr 2014
 *      Author: Andy
 */

#include <iostream>
#include <BoardGame.h>
#include <IGameDetail.h>
#include <vector>


using namespace std;
using namespace Wsq::BoardGame;

int main(){
	BoardGame bg = BoardGame();
	vector<IGameDetail *> * list = bg.GetGameList();

	for(int i=0; i<(int)list->size(); i++){
		IGameDetail * gameDetail = list->at(i);
		cout << "\n\n" << gameDetail->Name();
		cout << "\n" << gameDetail->Description();
	}

	return 0;
}
