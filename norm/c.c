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
	//code here :)
}

double      example_double(void) {
	return (double)EXAMPLE_INT;
}


e_example   example_custum(void) {
  __int32_t i = e_example1 % EXAMPLE_INT;

  switch (i)
  {
  case e_example2:
    printf("%s\n", EXAMPLE_CHAR);
    break;
  default:
    break;
  }
  return e_example3;
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
