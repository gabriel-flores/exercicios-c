#ifndef __INPUT_H__
#define __INPUT_H__

/*
 * A shorthand for str[strlen (str) - 1]
 */
char get_last_char (char *str);

/*
 * Gets an input from stdin through fgets (), clears the buffer if needed and
 * removes the trailing new line character of `target`.
 */
void get_user_input (char *target, unsigned int size);

/*
 * Clears the buffer through getchar () if needed.
 */
void clear_buffer (char *str);

/*
 * Asks the user to press the <Enter> key, gets the user input and clears the
 * buffer.
 */
void prompt_enter_key (void);

#endif /* __INPUT_H__ */
