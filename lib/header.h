/* RPM - Copyright (C) 1995 Red Hat Software
 * 
 * header.h - routines for managing rpm tagged structures
 */

#ifndef _header_h
#define _header_h
#include <stdio.h>

#if defined(__alpha__)
typedef long int int_64;
typedef int int_32;
typedef short int int_16;
typedef char int_8;

typedef unsigned int uint_32;

#else

typedef long long int int_64;
typedef long int int_32;
typedef short int int_16;
typedef char int_8;

typedef unsigned int uint_32;
#endif

typedef struct headerToken *Header;

/* read and write a header from a file */
Header readHeader(FILE *f);
Header mmapHeader(int fd, long offset);
void writeHeader(FILE *f, Header h);

/* load and unload a header from a chunk of memory */
Header loadHeader(void *p);
void *unloadHeader(Header h);

Header newHeader(void);
void freeHeader(Header h);

/* dump a header to a file, in human readable format */
void dumpHeader(Header h, FILE *f, int flags);

#define DUMP_INLINE   1
#define DUMP_SYMBOLIC 2

int getEntry(Header h, int_32 tag, int_32 *type, void **p, int_32 *c);
int addEntry(Header h, int_32 tag, int_32 type, void *p, int_32 c);

/* Entry Types */

#define NULL_TYPE 0
#define CHAR_TYPE 1
#define INT8_TYPE 2
#define INT16_TYPE 3
#define INT32_TYPE 4
#define INT64_TYPE 5
#define STRING_TYPE 6

#endif _header_h
