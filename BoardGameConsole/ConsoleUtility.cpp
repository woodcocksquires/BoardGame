/*
 * ConsoleUtility.cpp
 *
 *  Created on: 13 May 2014
 *      Author: Andy
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include <ConsoleUtility.h>

using namespace std;
using namespace Wsq::Console;

void ConsoleUtility::WriteLine(string output){
	cout << output << endl;
}

void ConsoleUtility::WriteLine(int numeric, string output){
	cout << numeric << ". " << output << endl;
}

void ConsoleUtility::WriteLine(){
	cout << endl;
}

void ConsoleUtility::WriteLine(int lines){
	for(int l=0; l<lines; l++){
		WriteLine();
	}
}

int ConsoleUtility::GetNumericOption(string message, unsigned maxOption){
	int value = 0;
	if(maxOption < 2){
		return maxOption;
	}
	string input;
	while(value == 0){
		cout << message << ": ";
		cin >> input;
		value = strtol(input.c_str(), nullptr, 10);
		if(value == 0 || value > maxOption){
			value = 0;
			WriteLine("Invalid entry, please try again.");
		}
	}
	return value;
}


