#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "menu.h"
#include "input.h"

int main ()
{
  char user_choice[2];

  do
  {
    print_menu ();

    get_user_input (user_choice, 2);
    switch (user_choice[0])
    {
      case 'c':
      {
        char *name = malloc (sizeof (char) * 51);
        char *age = malloc (sizeof (char) * 3);

        get_input_user_property ("name", name, 51);
        get_input_user_property ("age", age, 3);

        save_user (name, age);

        break;
      }

      case 'l':
        list_users ();
        break;

      case 'q':
        printf ("Goodbye!\n");
        break;

      default:
        printf ("Invalid option!\n");
        prompt_enter_key ();
        break;
    }
  }
  while (user_choice[0] != 'q');

  return 0;
}
