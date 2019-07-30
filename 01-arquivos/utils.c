#include <ctype.h>
#include <string.h>

int is_string_empty (char *string)
{
  return (int) strlen (string) == 0;
}

int is_string_numeric (char *string)
{
  int length = (int) strlen (string);

  for (int i = 0; i < length; i++)
  {
    if (!isdigit (string[i]))
      return 0;
  }

  return 1;
}

int is_string_textual (char *string)
{
  int length = (int) strlen (string);

  for (int i = 0; i < length; i++)
  {
    char current_char = string[i];

    if (!isalpha (current_char) && !isblank (current_char))
      return 0;
  }

  return 1;
}
