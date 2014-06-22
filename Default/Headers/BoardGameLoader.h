/*
 * BoardGameLoader.h
 *
 *  Created on: 18 Jun 2014
 *      Author: Andrew.squires
 */

#ifndef BOARDGAMELOADER_H_
#define BOARDGAMELOADER_H_

#include<vector>
#include<string>

#include<IBoardGameLoader.h>
#include<IBoardGameDetails.h>
#include<IBoardGameDetailsFactory.h>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		namespace Default {
			class BoardGameLoader : public IBoardGameLoader {
			  private:
				const string BASEPATH = "scripts";
				string _gamePath;

				IBoardGameDetails * LoadGameDetails(string path);
			  public:
				BoardGameLoader();
				virtual ~BoardGameLoader(){}

				virtual vector<IBoardGameDetails *> * LoadGamesDetails(IBoardGameDetailsFactory * detailsFactory);
			};
		}
	}
}



#endif /* BOARDGAMELOADER_H_ */
