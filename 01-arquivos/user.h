#ifndef __USER_H__
#define __USER_H__

/*
 * Loop for getting an user property.
 */
void get_input_user_property (char *property_name,
                              char *property_value,
                              unsigned int size);

/*
 * Checks whether an user property is valid.
 */
char * is_user_property_valid (char *property_name, char *property_value);

/*
 * Prints all users in the database file.
 */
void list_users (void);

/*
 * Stores the user into the database file.
 */
void save_user (char *name, char *age);

#endif /* __USER_H__ */
