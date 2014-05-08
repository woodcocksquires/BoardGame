/*
 * FileSystemUtility.cpp
 *
 *  Created on: 30 Apr 2014
 *      Author: Andrew.squires
 */

#include <FileSystemUtility.h>
#include <dirent.h>
#include <iostream>
#include <sys/stat.h>

using namespace Wsq::FileSystem;
using namespace std;

vector<string> * FileSystemUtility::GetFilesInDirectory(string directory, string extension){
	vector<string> * list = new vector<string>();
	DIR * dir;
	struct dirent * ent;
	dir = opendir(directory.c_str());
	if(dir != NULL){
		ent = readdir(dir);
		while(ent != NULL){
			string name = string(ent->d_name);
			if(name.substr(name.find_last_of(".") + 1) == extension){
				list->push_back(directory + "\\" + name);
			}
			ent = readdir(dir);
		}
		closedir(dir);
	}
	return list;
}

string FileSystemUtility::CombinePath(string path, string append){
	if(path.empty() || append.empty()){
		//throw bad_exception;
	}
	string output = path;
	if(output.find_last_of('\\') != output.length()-1){
		output.push_back('\\');
	}

	if(append.find_last_of('\\') == append.length()-1){
		output += append.substr(0, (int)append.length() -1);
	}
	else{
		output += append;
	}

	return output;
}




