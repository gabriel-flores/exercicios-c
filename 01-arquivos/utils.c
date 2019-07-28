#include <string.h>

int is_char_numeric (char c)
{
  return c >= 48 && c <= 57;
}

int is_string_numeric (char *string)
{
  for (int i = 0; i < (int) strlen (string); i++)
  {
    if (!is_char_numeric (string[i]))
      return 0;
  }

  return 1;
}
