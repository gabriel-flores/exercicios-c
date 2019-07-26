#include <stdio.h>
#include <stdio_ext.h>
#include "user.h"
#include "menu.h"
#include "input.h"

int main ()
{
  int user_choice;

  do
  {
    print_menu ();

    user_choice = get_char ();
    switch (user_choice)
    {
      case 'c':
      {
        char name[50];
        int age;

        printf ("Type the user name: ");
        __fpurge (stdin);
        fgets (name, 50, stdin);

        printf ("Type the user age: ");
        __fpurge (stdin);
        scanf ("%d", &age);

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
  while (user_choice != 'q');

  return 0;
}
