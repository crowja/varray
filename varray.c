/**
 *  @file varray.c
 *  @version 0.1.0-dev0
 *  @date Tue Dec 10 12:06:00 CST 2019
 *  @copyright %COPYRIGHT%
 *  @brief FIXME
 *  @details FIXME
 */

#include <stdlib.h>
#include <stdio.h>
#include "varray.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  _FREE
#undef  _FREE
#endif
#define _FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

struct varray {
   unsigned    size;
   unsigned    len;
   unsigned    extend;
   void      **x;
};

struct varray *
varray_new(void)
{
   struct varray *tp;

   tp = (struct varray *) malloc(sizeof(struct varray));
   if (_IS_NULL(tp))
      return NULL;

   tp->size = 0;
   tp->len = 0;
   tp->extend = 1024;
   tp->x = NULL;

   return tp;
}

void
varray_free(struct varray **pp)
{
   _FREE((*pp)->x);
   _FREE(*pp);
}

int
varray_init(struct varray *p, void *x)
{

   /* Do some magic here ... */
   p->x = x;                                     /* FIXME */

   return 0;
}

const char *
varray_version(void)
{
   return "0.1.0-dev0";
}

void       *
varray_get(struct varray *p, unsigned idx)
{
   if (idx < p->len)
      return (p->x)[idx];
   else
      return NULL;
}

int
varray_insert(struct varray *p, void *e)
{
   if (p->len == p->size) {                      /* extend? */
      unsigned    need = p->len + p->extend;
      void      **tmp = realloc(p->x, need * sizeof(void *));
      if (_IS_NULL(tmp))                         /* FIXME */
         exit(1);
      p->x = tmp;
      p->size = need;
   }

   (p->x)[p->len] = e;
   p->len += 1;

   {
      unsigned    i;
      for (i = 0; i < p->len; i++)
         printf("%d--%p\n", i, (p->x)[i]);
   }


   return 0;
}

unsigned
varray_len(struct varray *p)
{
   return p->len;
}


#undef  _IS_NULL
#undef  _FREE
