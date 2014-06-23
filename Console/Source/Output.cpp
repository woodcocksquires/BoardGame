/*
 * Output.cpp
 *
 *  Created on: 16 Jun 2014
 *      Author: Andrew.squires
 */

#include<iostream>
#include<string>
#include<cstdlib>
#include<output.h>

using namespace std;
using namespace Wsq::Console;

void Output::WriteLine(string output){
	cout << output << endl;
}

void Output::WriteLine(int numeric, string output){
	cout << numeric << ". " << output << endl;
}

void Output::WriteLine(){
	cout << endl;
}

void Output::WriteLine(int lines){
	for(int l=0; l<lines; l++){
		WriteLine();
	}
}

int Output::GetNumericOption(string message, unsigned maxOption){
	int value = 0;
	if(maxOption < 2){
		return maxOption;
	}
	string input;
	while(value == 0){
		cout << message << ": ";
		cin >> input;
		value = strtol(input.c_str(), nullptr, 10);
		if(value == 0 || value > (int)maxOption){
			value = 0;
			WriteLine("Invalid entry, please try again.");
		}
	}
	return value;
}

