/*
 * StringUtility.h
 *
 *  Created on: 10 Jun 2014
 *      Author: Andrew.squires
 */

#ifndef STRINGUTILITY_H_
#define STRINGUTILITY_H_

#include<string>

using namespace std;

namespace Wsq {
	namespace Text {
		class StringUtility {
		  public:
			static string ToLower(string input);
			static string ToUpper(string input);
		};
	}
}

#endif /* STRINGUTILITY_H_ */
