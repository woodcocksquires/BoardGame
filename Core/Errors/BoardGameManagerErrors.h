/*
 * BoardGameManagerErrors.h
 *
 *  Created on: 17 Jun 2014
 *      Author: Andrew.squires
 */

#ifndef BOARDGAMEMANAGERERRORS_H_
#define BOARDGAMEMANAGERERRORS_H_

#include <exception>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		namespace Errors {
			class BoardGameLoaderException: public exception{
				virtual const char * what() const throw(){
					return "There was a problem setting the BoardGameLoader.";
				}
			};

			class LoadGamesException: public exception{
				virtual const char * what() const throw(){
					return "Error occurred loading games.";
				}
			};

			class IncorrectConfigurationException: public exception{
				virtual const char * what() const throw(){
					return "BoardGameManager properties not configured correctly.";
				}
			};
		}
	}
}

#endif /* BOARDGAMEMANAGERERRORS_H_ */
