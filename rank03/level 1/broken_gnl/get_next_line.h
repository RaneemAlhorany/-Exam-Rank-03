#ifndef GNL
#define GNL


#  define BUFFER_SIZE 10

// add the follwing includes 
#include <stdlib.h> // for malloc() and free()
#include <stdio.h> // for debugging, remove it later
#include <unistd.h> // for read() and close()
#include <sys/types.h> // for open() and O_RDONLY
#include <fcntl.h> // for open() and O_RDONLY


char    *get_next_line(int fd);


#endif