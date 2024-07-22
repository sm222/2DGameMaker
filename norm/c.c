//********************************************/
//*                                          */
//*                    c.c                   */
//*                                          */
//*                                          */
//*                                          */
//********************************************/

#include "h.h"

int         example_int(void) {
	return EXAMPLE_INT;
}


void        example_void(void) {
	//	write code here :)
}

double      example_double(void) {
	return (double)EXAMPLE_INT;
}


e_Example   example_custum(void) {
  __int32_t i = e_Example1 % EXAMPLE_INT;

  switch (i)
  {
  case e_Example2:
    printf("%s\n", EXAMPLE_CHAR);
    break;
  default:
    break;
  }
  return e_Example3;
}


ssize_t     example_var_edit(char c, char* s)
{
  ssize_t len = -1;
  if (s)
  {
    while (s[++len])
      s[(len - 1)] = c;
  }
  return len;
}
