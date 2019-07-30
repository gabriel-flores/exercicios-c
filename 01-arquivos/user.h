/*
 * Prints all users in the database file.
 */
void list_users (void);

/*
 * Validates the input of `name` and `age`, converts them and if valid stores
 * the user into the database file.
 */
void create_user (char *name, char *age);

/*
 * Checks whether the user name is valid.
 *
 * Returns the error message if invalid,
 * or NULL if valid.
 */
char * is_user_name_valid (char *name);

/*
 * Checks whether the user age is valid.
 *
 * Returns the error message if invalid,
 * or NULL if valid.
 */
char * is_user_age_valid (char *age);
