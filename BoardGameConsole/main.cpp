/*
 * main.cpp
 *
 *  Created on: 25 Apr 2014
 *      Author: Andy
 */
/*
#include <iostream>
#include <IBoardGame.h>
#include <IBoard.h>
#include <IBoardGameCreator.h>
#include <IGameDetail.h>
#include <vector>
#include <ConsoleUtility.h>
#include <NewGameDetailFactory.h>
#include <IGameDetailFactory.h>
#include <NewGameDetail.h>

using namespace std;
using namespace Wsq::BoardGame;
using namespace Wsq::Console;
using namespace Wsq::Test;

int main(){
	ConsoleUtility::WriteLine("Welcome to the WoodcockSquires BoardGame Console emporium!");
	ConsoleUtility::WriteLine(2);
	ConsoleUtility::WriteLine("Please choose the game you would like to play from the list below:");
	ConsoleUtility::WriteLine();


	IBoardGame * bg = IBoardGameCreator::MakeBoardGame();
	bg->SetGameDetailFactory((IGameDetailFactory *)(new NewGameDetailFactory()));
	vector<IGameDetail *> * list = bg->GetGameList();
	if(list->size() > 1){
		for(unsigned i=0; i<list->size(); i++){
			IGameDetail * gameDetail = list->at(i);
			ConsoleUtility::WriteLine(i+1, gameDetail->Name());
			ConsoleUtility::WriteLine(gameDetail->Description());
			ConsoleUtility::WriteLine(((NewGameDetail *)gameDetail)->SomeProperty());
			ConsoleUtility::WriteLine();
		}
		int gameOption = ConsoleUtility::GetNumericOption("Please choose a game to play", list->size()+1);
		bg->LoadGame(list->at(gameOption-1));
	}
	else if(list->size() == 1){
		// Load the only game available;
		bg->LoadGame(list->at(0));
	}
	else{
		ConsoleUtility::WriteLine("No games were found!");
	}

	cout << "\n\n";
	IBoard * board = bg->GetBoard();
	for(int h = board->GetHeight()-1; h >= 0; h--){
		for(unsigned w = 0; w < board->GetWidth(); w++){
			IBoardLocation * ibl = board->GetBoardLocation(h, w);
			cout << "(" << ibl->GetState()->GetIdentifier() << ":" << ibl->GetValue() << "),";
		}
		cout << "\n";
	}

	return 0;
}
*/


#include<BoardGameManager.h>
#include<Utility.h>

using namespace Wsq::BoardGame;
using namespace Wsq::BoardGame::Default;

int main() {
	BoardGameManager * manager = new Utility::MakeDefaultBoardGameManager();
	manager->LoadBoardGames();
}
