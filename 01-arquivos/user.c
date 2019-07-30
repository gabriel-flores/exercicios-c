#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "file.h"
#include "user.h"
#include "utils.h"

#define DATABASE_FILE_NAME "database.txt"

void list_users (void)
{
  FILE *file = open_file (DATABASE_FILE_NAME, "r");
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
    fscanf (file, "%[A-Za-z ]\t%d\n", name, &age);

    printf ("-------\n");
    printf ("Name: %s\n", name);
    printf ("Age: %d\n", age);
  }
  printf ("\n");

  prompt_enter_key ();

  close_file (file);
}

void create_user (char *name, char *age)
{
  char *error_message = is_user_name_valid (name);
  if (error_message)
  {
    printf ("%s\n\n", error_message);
    prompt_enter_key ();
    return;
  }

  error_message = is_user_age_valid (age);
  if (error_message)
  {
    printf ("%s\n\n", error_message);
    prompt_enter_key ();
    return;
  }

  FILE *file = open_file (DATABASE_FILE_NAME, "a");

  fprintf (file, "%s\t%d\n", name, atoi (age));

  close_file (file);

  printf ("User %s saved successfuly!\n\n", name);
  prompt_enter_key ();
}

char * is_user_name_valid (char *name)
{
  if (is_string_empty (name))
    return "User name must not be empty.";

  if (!is_string_textual (name))
    return "User name must contain only alphabetical characters and spaces.";

  return NULL;
}

char * is_user_age_valid (char *age)
{
  if (is_string_empty (age))
    return "User age must not be empty.";

  if (!is_string_numeric (age))
    return "User age must be a numeric value.";

  return NULL;
}
