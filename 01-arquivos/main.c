#include <stdio.h>
#include "user.h"

int main (int argc, char *argv[])
{
  int user_choice;

  do
  {
    printf ("[H[2J");
    printf ("Welcome!\n\n");
    printf ("Type one of below:\n\n");
    printf ("l - List Users\n");
    printf ("c - Create User\n");
    printf ("q - Quit\n\n");
    printf ("> ");

    user_choice = getchar ();
    getchar (); /* eat up the like break */

    switch (user_choice)
    {
      case 'c':
      {
        char name[50];
        int age;

        printf ("Type the user name: ");
        scanf ("[^\n]", name);
        printf ("Type the user age: ");
        scanf ("%d", &age);

        create_user (name, age);

        break;
      }

      case 'l':
        list_users ();
        break;

      default:
        printf ("Invalid option!");
        break;
    }
  }
  while (user_choice != 'q');

  return 0;
}
