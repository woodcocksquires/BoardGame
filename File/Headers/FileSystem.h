/*
 * FileSystem.h
 *
 *  Created on: 16 Jun 2014
 *      Author: Andrew.squires
 */

#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

#include<string>
#include<vector>

using namespace std;

namespace Wsq {
	namespace File {
		class FileSystem {
		  public:
			static vector<string> * GetFilesInDirectory(string directory, string extension);
			static vector<string> * GetDirectories(string directory);
			static string CombinePath(string path, string append);
			static string CombinePath(string path, string append, char separator);
		};
	}
}



#endif /* FILESYSTEM_H_ */
