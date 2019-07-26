#include <stdio.h>
#include <string.h>
#include "input.h"
#include "user.h"
#include "file.h"

void list_users (void)
{
  FILE *file = open_file ("file.txt", "r");
  char name[50];
  int age;

  fseek (file, 0, SEEK_END);
  int filesize = ftell (file);

  if (filesize == 0)
  {
    close_file (file);

    printf ("No entries found yet :)\n\n");

    press_any_key_to_continue ();

    return;
  }

  rewind (file);

  while (!feof (file))
  {
    fscanf (file, "%s\t%d", name, &age);
    printf ("-------\n");
    printf ("Name: %s\n", name);
    printf ("Age: %d\n", age);
  }

  press_any_key_to_continue ();

  close_file (file);
}

void create_user (char name[], int age)
{
  if (strlen (name) == 0)
  {
    printf ("Name must not be empty.\n");
    press_any_key_to_continue ();

    return;
  }

  if (age < 0)
  {
    printf ("Age must be a number greater than zero.\n");
    press_any_key_to_continue ();

    return;
  }

  FILE *file = open_file ("file.txt", "a");

  fprintf (file, "%s\t%d\n", name, age);

  close_file (file);
}
