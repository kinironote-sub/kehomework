#if defined _MSC_VER
#include <direct.h>
#elif defined __GNUC__
#include <sys/types.h>
#include <sys/stat.h>
#endif

namespace std{
	void createDir(std::string dir){
#if defined _MSC_VER
		_mkdir(dir.data());
#elif defined __GNUC__
		mkdir(dir.data(),0777);
#endif
	}
}
