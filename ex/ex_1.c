#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "varray.h"

char       *words[] = { "ant", "cat", "dog", "horse", "mouse", "pig" };

int
main(int argc, char *argv[])
{
   struct varray *p = varray_new();
   unsigned    i;

   for (i = 0; i < 6; i++) {
      char       *cp = malloc(30);
      strcpy(cp, words[i]);
      varray_insert(p, cp);
   }

   for (i = 0; i < varray_len(p); i++) {
      char       *cp = varray_get(p, i);
      printf("%d--%s\n", i, cp);
      free(cp);
   }

   varray_free(p);
   return 0;
}
