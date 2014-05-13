/*
 * ConsoleUtility.h
 *
 *  Created on: 13 May 2014
 *      Author: Andy
 */

#ifndef CONSOLEUTILITY_H_
#define CONSOLEUTILITY_H_

#include <string>

using namespace std;

namespace Wsq {
	namespace Console {
		class ConsoleUtility {
			public:
			static void WriteLine();
			static void WriteLine(int lines);
			static void WriteLine(string output);
			static void WriteLine(int numeric, string output);
			static int GetNumericOption(string message, unsigned maxOption);
		};
	}
}

#endif /* CONSOLEUTILITY_H_ */
