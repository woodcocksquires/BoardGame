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
#include <ConsoleUtility.h>

using namespace std;
using namespace Wsq::BoardGame;
using namespace Wsq::Console;

int main(){
	ConsoleUtility::WriteLine("Welcome to the WoodcockSquires BoardGame Console emporium!");
	ConsoleUtility::WriteLine(2);
	ConsoleUtility::WriteLine("Please choose the game you would like to play from the list below:");
	ConsoleUtility::WriteLine();

	BoardGame bg = BoardGame();
	vector<IGameDetail *> * list = bg.GetGameList();

	if(list->size() > 1){
		for(unsigned i=0; i<list->size(); i++){
			IGameDetail * gameDetail = list->at(i);
			ConsoleUtility::WriteLine(i+1, gameDetail->Name());
			ConsoleUtility::WriteLine(gameDetail->Description());
			ConsoleUtility::WriteLine();
		}
		int gameOption = ConsoleUtility::GetNumericOption("Please choose a game to play", list->size()+1);
	}
	else if(list->size() == 1){
		// Load the only game available;
		BoardGame.LoadGame(list->at(0));
	}
	else{
		ConsoleUtility::WriteLine("No games were found!");
	}

	return 0;
}
