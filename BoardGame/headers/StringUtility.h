/*
 * StringUtility.h
 *
 *  Created on: 26 May 2014
 *      Author: Andy
 */

#ifndef STRINGUTILITY_H_
#define STRINGUTILITY_H_

#include <cctype>

namespace Wsq {
	namespace Text {
		class StringUtility {
		  public:
			static string ToLower(string input){
				for(unsigned c = 0; c < sizeof(input); c++){
					input[c] = tolower(input[c]);
				}
				return input;
			}

			static string ToUpper(string input){
				for(unsigned c = 0; c < sizeof(input); c++){
					input[c] = toupper(input[c]);
				}
				return input;
			}
		};
	}
}



#endif /* STRINGUTILITY_H_ */
