#include <stdio.h>
#include "menu.h"

void print_menu (void)
{
  printf ("[H[2J");
  printf ("\
Welcome!\n\
\n\
Type one of below:\n\
\n\
  l - List Users\n\
  c - Create User\n\
  q - Quit\n\
\n\
> \
");
}
