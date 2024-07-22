#ifndef  GM_CPPDEFINE_H
# define GM_CPPDEFINE_H

extern "C" {
    # include "CDefine.h"
}

// C++ - defines
#include <string>
#include <map>

using std::string;
using std::map;

#define Cams    map<string, Camera2D>


#endif // CPPDEFINE_H
