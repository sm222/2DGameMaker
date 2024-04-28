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

// only set manualy if you go in negativ value

typedef enum example {
  e_example1,
  e_example2,
  e_example3,
} e_example;

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

struct exampleH {
  int        i;
  char       c;
  float      f;
  double     d;
  char*      msg;
  exampleH*  next;
};


//*---------------*//
//*   fonctions   *//
//*---------------*//

// !you shoud not mix (define, enum, struct) and fonctions

int         example_int(void);
void        example_void(void);
double      example_double(void);
e_example   example_custum(void);
ssize_t     example_var_edit(char c, char* s);

#endif