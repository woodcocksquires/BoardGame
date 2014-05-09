#ifndef FILESYSTEMUTILITY_H_
#define FILESYSTEMUTILITY_H_

#include <vector>
#include <string>

using namespace std;

namespace Wsq {
	namespace FileSystem {
		class FileSystemUtility {
		  public:
			static vector<string> * GetFilesInDirectory(string directory, string extension);
			static string CombinePath(string path, string append);
			static string CombinePath(string path, string append, char separator);
		};
	}
}

#endif
