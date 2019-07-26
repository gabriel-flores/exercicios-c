#include <stdio.h>
#include "input.h"

int get_char (void)
{
  int input;
  int result;

  while ((input = getchar ()) != EOF && input != '\n')
  {
    result = input;
  }

  return result;
}

void press_any_key_to_continue (void)
{
  printf ("Press any key to continue... ");
  get_char ();
}
