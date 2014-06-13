/*
 * BoardState.h
 *
 *  Created on: 19 May 2014
 *      Author: andrew.squires
 */
/*
#ifndef BOARDSTATE_H_
#define BOARDSTATE_H_

#include <string>
#include <IBoardState.h>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class BoardState: public IBoardState {
		  friend class BoardStateFactory;
		  private:
			int _value;
			char _identifier;
			string _name;
			string _valueString;
			BoardState(int value, char identifier, string name, string valueString);
			~BoardState() {}
		  public:
			virtual int GetValue();
			virtual char GetIdentifier();
			virtual string GetName();
			virtual string GetValueString();
		};
	}
}




#endif /* BOARDSTATE_H_ */
