/* fstat.c -- get status of a file.
 *
 * Copyright (c) 1995 Cygnus Support
 *
 * The authors hereby grant permission to use, copy, modify, distribute,
 * and license this software and its documentation for any purpose, provided
 * that existing copyright notices are retained in all copies and that this
 * notice is included verbatim in any distributions. No written agreement,
 * license, or royalty fee is required for any of the authorized uses.
 * Modifications to this software may be copyrighted by their authors
 * and need not follow the licensing terms described here, provided that
 * the new terms are clearly indicated on the first page of each file where
 * they apply.
 */
#include <sys/stat.h>
#include "glue.h"

/*
 * fstat -- Since we have no file system, we just return an error.
 */
int
#if defined(__mips__) && defined(__mips16)
__attribute__((nomips16))
#endif
fstat (int fd,
       struct stat *buf)
{
  buf->st_mode = S_IFCHR;	/* Always pretend to be a tty */
  buf->st_blksize = 0;

  return (0);
}
