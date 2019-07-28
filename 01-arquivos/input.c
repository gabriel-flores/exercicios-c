#include <stdio.h>
#include <string.h>
#include "input.h"

char get_last_char (char *str)
{
  return str[strlen (str) - 1];
}

void get_user_input (char *target)
{
  fgets (target, sizeof (target), stdin);
  clear_buffer (target);

  if (get_last_char (target) == '\n')
    target[strlen (target) - 1] = '\0';
}

void clear_buffer (char *str)
{
  if (get_last_char (str) != '\n')
  {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
  }
}

void prompt_enter_key (void)
{
  int ch;
  printf ("Press <Enter> to continue... ");

  while ((ch = getchar ()) != '\n' && ch != EOF);
}
