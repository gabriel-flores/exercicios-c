#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>

FILE * open_file (char filepath[], char mode[]);
void close_file (FILE *file);

#endif /* __FILE_H__ */
