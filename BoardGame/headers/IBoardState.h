/*
 * IBoardState.h
 *
 *  Created on: 19 May 2014
 *      Author: andrew.squires
 */
/*
#ifndef IBOARDSTATE_H_
#define IBOARDSTATE_H_

#include <string>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class IBoardState {
		  public:
			IBoardState() {}
			virtual ~IBoardState() {}
			virtual int GetValue() = 0;
			virtual char GetIdentifier() = 0;
			virtual string GetName() = 0;
			virtual string GetValueString() = 0;
		};
	}
}

#endif /* IBOARDSTATE_H_ */
