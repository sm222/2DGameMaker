#ifndef TOOLS_H
# define TOOLS_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include "color.h"

# define SIZE_BUFF    200
# define BUFF_MUL     2
# define TMP_BUFF_SIZE 30

enum Dflag {
    DflagBase = 0b00000000,
    DflagOut  = 0b00000001,
    DflagLog  = 0b00000010,
    DflagExit = 0b00000100,
};

typedef struct s_buff
{
  ssize_t   len;
  ssize_t   dest;
  char*     str;
  char*     outfile;
}           t_buff;

const char* const colorName = "RGYBMCWOrz";
// those 2 need to be sink
const char* const colorList[] = {
  RED,
  GRN,
  YEL,
  BLU,
  MAG,
  CYN,
  WHT,
  ORG,
  RESET,
  CLE,
};

# define HEX_TABLE "0123456789abcdef"

/// @brief 
/// @param s 
/// @attention % s c i p x u f?
/// @attention R B G W Y M C O P T Z F
///                    reset color ^ ^ outfile
/// @param  
/// @return 
ssize_t    debugInfo(const char* s, ...);

# ifdef DEBUG_FLAG
#  undef DEBUG_FLAG
# endif
# define DEBUG_FLAG (DflagOut | DflagLog)

# if (DEBUG_FLAG != DflagBase)
#  define DEBUGOUT(msg, va_arg)   debugInfo(msg, va_arg)
# else
#  define DEBUGOUT(msg, va_arg)   (void)msg, (void)va_arg
# endif

#endif // TOOLS_H