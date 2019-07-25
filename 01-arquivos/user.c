#include <stdio.h>
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
    printf ("Press any key to continue... ");

    getc (stdin);

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

  printf ("Press any key to continue... ");

  getc (stdin);

  close_file (file);
}

void create_user (char name[], int age)
{
  FILE *file = open_file ("file.txt", "a");

  fprintf (file, "%s\t%d\n", name, age);

  close_file (file);
}
