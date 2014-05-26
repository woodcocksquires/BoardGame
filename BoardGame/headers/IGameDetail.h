#ifndef IGAMEDETAIL_H_
#define IGAMEDETAIL_H_

#include<string>

using namespace std;

namespace Wsq {
	namespace BoardGame {
		class IGameDetail {
		  public:
			virtual string Name() = 0;
			virtual string Description() = 0;
			virtual string Path() = 0;
			virtual string ShortPath() = 0;
			virtual int MaxPlayers() = 0;
			virtual int MinPlayers() = 0;
			virtual ~IGameDetail() {};
		};
	}
}

#endif
