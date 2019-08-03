#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "file.h"
#include "user.h"
#include "utils.h"

#define DATABASE_FILE_NAME "database.txt"

void get_input_user_property (char *property_name,
                              char *property_value,
                              unsigned int size)
{
  char *error_message;

  do
  {
    printf ("Type the user %s: ", property_name);
    get_user_input (property_value, size);

    error_message = is_user_property_valid (property_name, property_value);

    if (error_message)
      printf ("%s\n\n", error_message);

  } while (error_message != NULL);
}

char * is_user_property_valid (char *property_name, char *property_value)
{
  if (is_string_empty (property_value))
    return "Please provide a value.";

  if (strcmp (property_name, "name") == 0 &&
      !is_string_textual (property_value))
    return "Please provide only alphabetical characters and spaces.";

  if (strcmp (property_name, "age") == 0 &&
      !is_string_numeric (property_value))
    return "Please provide a numeric value.";

  return NULL;
}

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
    printf ("No users found in database.\n\n");
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

void save_user (char *name, char *age)
{
  FILE *file = open_file (DATABASE_FILE_NAME, "a");

  fprintf (file, "%s\t%d\n", name, atoi (age));

  close_file (file);

  printf ("User %s saved successfuly!\n\n", name);
  prompt_enter_key ();
}
