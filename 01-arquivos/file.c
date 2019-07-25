#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * open_file (char filepath[], char mode[])
{
  FILE *file = fopen (filepath, mode);

  if (strcmp (mode, "r") == 0 && file == NULL)
  {
    file = fopen (filepath, "w");
    fclose (file);
    open_file (filepath, mode);
  }

  if (file == NULL)
  {
    printf ("Could not open file.\n");
    exit (1);
  }

  return file;
}

void close_file (FILE *file)
{
  fclose (file);
}
