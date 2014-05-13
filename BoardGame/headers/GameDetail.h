/*
 * GameDetail.h
 *
 *  Created on: 12 May 2014
 *      Author: Andrew.squires
 */

#ifndef GAMEDETAIL_H_
#define GAMEDETAIL_H_

#include <string>
#include <IGameDetail.h>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class GameDetail: public IGameDetail {
		  private:
			string _name;
			string _description;
			string _path;
			int _maxPlayers;
			int _minPlayers;
		  public:
			GameDetail(string name, string description, string path, int maxPlayers, int minPlayers):
				_name(name), _description(description), _path(path), _maxPlayers(maxPlayers), _minPlayers(minPlayers){}
			virtual ~GameDetail() {};
			virtual string Name(){ return _name; }
			virtual string Description(){ return _description; }
			virtual string Path(){ return _path; }
			virtual int MaxPlayers(){ return _maxPlayers; }
			virtual int MinPlayers(){ return _minPlayers; }
		};
	}
}



#endif /* GAMEDETAIL_H_ */
