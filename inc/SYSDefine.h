#ifndef SYSDEFINE_H
# define SYSDEFINE_H

# define FT_LINUX 0 // Linux is use
# define FT_WIN   1 // Windows is use
# define FT_MAC   2 // Mac is use

# if (unix || __unix || __unix__ || __linux__)
#  define SYSTYPE FT_LINUX
# elif (_WIN32 || _WIN64 || __CYGWIN__)
#  define SYSTYPE FT_WIN
# elif (__APPLE__ || __MACH__)
#  define SYSTYPE FT_MAC
# else
#  define SYSTYPE -1
# endif


# if (SYSTYPE == FT_LINUX)
#  define TESTVAL "|"
# endif

# if (SYSTYPE == FT_MAC)
#  define TESTVAL "\\"
# endif

# if (SYSTYPE == FT_WIN)
#  define TESTVAL "/"
# endif

# ifdef LOCALLIB
#  include "../raylib/src/raylib.h"
#  include "../raylib/src/raymath.h"
# else
#  include <raylib.h>
#  include <raymath.h>
# endif

#endif // SYSDEFINE_H
