#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "file.h"
#include "user.h"
#include "utils.h"

void list_users (void)
{
  FILE *file = open_file ("file.txt", "r");
  char name[51];
  int age;

  fseek (file, 0, SEEK_END);
  int filesize = ftell (file);

  if (filesize == 0)
  {
    close_file (file);
    printf ("No entries found yet :)\n\n");
    prompt_enter_key ();

    return;
  }

  rewind (file);

  while (!feof (file))
  {
    fscanf (file, "%s\t%d\n", name, &age);

    printf ("-------\n");
    printf ("Name: %s\n", name);
    printf ("Age: %d\n", age);
  }

  prompt_enter_key ();

  close_file (file);
}

void create_user (char *name, char *age)
{
  if (strlen (name) == 0)
  {
    printf ("User name must not be empty.\n");
    prompt_enter_key ();

    return;
  }

  if (strlen (age) == 0)
  {
    printf ("User age must not be empty.\n");
    prompt_enter_key ();

    return;
  }

  if (!is_string_numeric (age))
  {
    printf ("User age must be a numeric value.\n");
    prompt_enter_key ();

    return;
  }

  FILE *file = open_file ("file.txt", "a");

  fprintf (file, "%s\t%d\n", name, atoi (age));

  close_file (file);
}
