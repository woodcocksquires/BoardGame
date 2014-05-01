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

vector<string> * FileSystemUtility::GetFilesInDirectory(string directory){
	vector<string> * list = new vector<string>();
	DIR * dir;
	struct dirent * ent;
	dir = opendir(directory.c_str());
	if(dir != NULL){
		ent = readdir(dir);
		while(ent != NULL){
			string name = string(ent->d_name);
			if(name.substr(name.find_last_of(".") + 1) == "lua"){
				list->push_back(directory + "\\" + name);
			}
			ent = readdir(dir);
		}
		closedir(dir);
	}
	return list;
}




