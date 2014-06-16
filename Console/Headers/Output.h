/*
 * Output.h
 *
 *  Created on: 16 Jun 2014
 *      Author: Andrew.squires
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include<string>

using namespace std;

namespace Wsq {
	namespace Console {
		class Output {
			static void WriteLine();
			static void WriteLine(int lines);
			static void WriteLine(string output);
			static void WriteLine(int numeric, string output);
			static int GetNumericOption(string message, unsigned maxOption);
		};
	}
}



#endif /* OUTPUT_H_ */
