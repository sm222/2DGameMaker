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

# define PROJECT_NAME "name"
# define PROJECT_W    1000
# define PROJECT_H    1000
# define PROJECT_FPS  60

# ifndef GAMECOLORS
#  define GAMECOLORS
#  define G_START        "\001" //*start code
#  define G_END          "\002" //*end   code
#  define G_RED         G_START "\e[31m"         G_END
#  define G_GRN         G_START "\e[32m"         G_END
#  define G_YEL         G_START "\e[33m"         G_END
#  define G_BLU         G_START "\e[34m"         G_END
#  define G_MAG         G_START "\e[35m"         G_END
#  define G_CYN         G_START "\e[36m"         G_END
#  define G_WHT         G_START "\e[37m"         G_END
#  define G_ORG         G_START "\e[38;5;202m"   G_END
#  define G_PIK         G_START "\e[38;5;176m"   G_END
#  define G_TOX         G_START "\e[38;5;51m"    G_END
#  define G_RESET       G_START "\e[0m\022"      G_END
#  define G_CLE         G_START "\e[1;1H\x1b[2J" G_END
#  define G_GIT         G_START "\e[38;5;82m"    G_END
#  define G_GIT_B       G_START "\e[38;5;94m"    G_END
#  define G_UNDERLINE   G_START "\e[4m"          G_END
#  define G_BOLD        G_START "\e[1m"          G_END
# endif

typedef enum DEV_LV {
    none__,
    term__,
    consol__,
}   DEV_LV;

# ifndef DEV_LOG
#  define DEV_LOG none__
# endif

#endif // SYSDEFINE_H
