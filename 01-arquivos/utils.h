/*
 * Shorthand for `strlen (string) == 0`.
 */
int is_string_empty (char *string);

/*
 * Checks whether a given string has only numeric characters.
 */
int is_string_numeric (char *string);

/*
 * Checks whether the string contains only a-z, A-Z characters and spaces.
 */
int is_string_textual (char *string);
