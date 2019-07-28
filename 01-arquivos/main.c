#include <stdio.h>
#include "user.h"
#include "menu.h"
#include "input.h"

int main ()
{
  char user_choice[2];

  do
  {
    print_menu ();

    get_user_input (user_choice);
    switch (user_choice[0])
    {
      case 'c':
      {
        char name[51];
        char age[4];

        printf ("Type the user name: ");
        get_user_input (name);

        printf ("Type the user age: ");
        get_user_input (age);

        create_user (name, age);

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
        printf ("Press <Enter> to continue... ");
        getchar ();
        break;
    }
  }
  while (user_choice[0] != 'q');

  return 0;
}
