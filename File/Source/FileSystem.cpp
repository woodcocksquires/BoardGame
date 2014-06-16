/*
 * FileSystem.cpp
 *
 *  Created on: 16 Jun 2014
 *      Author: Andrew.squires
 */

#include <dirent.h>
#include<FileSystem.h>

using namespace std;
using namespace Wsq::File;

vector<string> * FileSystem::GetDirectories(string directory){
	return GetFilesInDirectory(directory, string());
}

vector<string> * FileSystem::GetFilesInDirectory(string directory, string extension){
	vector<string> * list = new vector<string>();
	DIR * dir = opendir(directory.c_str());

	struct dirent * ent;
	if(dir != NULL){
		ent = readdir(dir);
		while(ent != NULL){
			string name = string(ent->d_name);

			if((extension.empty() && (int)name.find_last_of('.') == -1) || (!extension.empty() && name.substr(name.find_last_of('.') + 1) == extension)){
				list->push_back(directory + "\\" + name);
			}
			ent = readdir(dir);
		}
		closedir(dir);
		delete ent;
	}
	return list;
}


string FileSystem::CombinePath(string path, string append){
	return CombinePath(path, append, '\\');
}

string FileSystem::CombinePath(string path, string append, char separator){
	if(path.empty() || append.empty()){
		//throw bad_exception;
	}
	string output = path;
	if(output.find_last_of(separator) != output.length()-1){
		output.push_back(separator);
	}
	if(append.find_last_of(separator) == append.length()-1){
		output += append.substr(0, (int)append.length() -1);
	}
	else{
		output += append;
	}
	return output;
}


