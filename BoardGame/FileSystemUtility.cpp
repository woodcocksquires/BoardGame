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

vector<string> * FileSystemUtility::GetFilesInDirectory(string directory){
	vector<string> * list = new vector<string>();
	DIR * dir;
	struct dirent * ent;
	dir = opendir(directory.c_str());
	if(dir != NULL){
		ent = readdir(dir);
		while(ent != NULL){
			list->push_back(ent->d_name);
			const char * c = (directory + string("\\") + string(ent->d_name)).c_str();
			struct stat * s = NULL;
			stat(c, s);
			if(s == NULL){
				cout << "\noops";
			}
			else{
				cout << "\n" << s->st_mode;
			}
			//cout << "\n" << ent->d_ino;
			ent = readdir(dir);

		}
		closedir(dir);
	}
	return list;
}




