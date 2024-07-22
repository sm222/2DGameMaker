//********************************************/
//*                                          */
//*                    h.h                   */
//*                                          */
//*                                          */
//*                                          */
//********************************************/

#ifndef  GAME_H_H_
# define GAME_H_H_

//*---------------*//
//*    include    *//
//*---------------*//


# include "../inc/CDefine.h"


//*---------------*//
//*     enum      *//
//*---------------*//

// !! Only set manually if you go into negative value

typedef enum Example {
  e_Example1,
  e_Example2,
  e_Example3,
} e_Example;

//*--------------*//
//*    define    *//
//*--------------*//

# define EXAMPLE_A

# ifdef EXAMPLE_A
#  define EXAMPLE_B
# endif

# define EXAMPLE_INT 42

# if (EXAMPLE_INT == 42)
#  define EXAMPLE_CHAR "true"
# else
#  define EXAMPLE_CHAR "false"
# endif

//*----------------*//
//*     struct     *//
//*----------------*//

struct ExampleH {
  int               i;
  char              c;
  float             f;
  double            d;
  char*             Msg;
  struct ExampleH*  Next;
  char*             ObjName;
};


//*---------------*//
//*   fonctions   *//
//*---------------*//

//	!! Don't not confuse define / enum / struct with fonctions

int         example_int(void);
void        example_void(void);
double      example_double(void);
e_Example   example_custum(void);
ssize_t     example_var_edit(char c, char* s);

#endif