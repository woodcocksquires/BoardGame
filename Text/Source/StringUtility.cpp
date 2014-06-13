/*
 * StringUtility.cpp
 *
 *  Created on: 10 Jun 2014
 *      Author: Andrew.squires
 */

#include<StringUtility.h>

using namespace Wsq::Text;

string StringUtility::ToLower(string input){
	for(unsigned c = 0; c < sizeof(input); c++){
		input[c] = tolower(input[c]);
	}
	return input;
}

string StringUtility::ToUpper(string input){
	for(unsigned c = 0; c < sizeof(input); c++){
		input[c] = toupper(input[c]);
	}
	return input;
}

