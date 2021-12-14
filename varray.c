/**
 *  @file varray.c
 *  @version 0.3.0-dev0
 *  @date Sun Feb 16, 2020 07:24:22 PM CST
 *  @copyright 2018-2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#include <stdlib.h>
#include <stdio.h>
#include "varray.h"

#ifdef  IS_NULL
#undef  IS_NULL
#endif
#define IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  FREE
#undef  FREE
#endif
#define FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

struct varray {
   unsigned  size;
   unsigned  len;
   unsigned  extend;
   void    **x;
};

struct varray *
varray_new(void)
{
   struct varray *tp;

   tp = (struct varray *) malloc(sizeof(struct varray));
   if (IS_NULL(tp))
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
   FREE((*pp)->x);
   FREE(*pp);
   *pp = NULL;
}

const char *
varray_version(void)
{
   return "0.3.0-dev0";
}

void     *
varray_get(struct varray *p, unsigned idx)
{
   if (idx < p->len)
      return (p->x)[idx];
   else
      return NULL;
}

int
varray_init(struct varray *p, void *x)
{

   /* Do some magic here ... */
   p->x = x;                                     /* FIXME */

   return 0;
}

int
varray_insert(struct varray *p, void *e)
{
   if (p->len == p->size) {                      /* extend? */
      unsigned  need = p->len + p->extend;
      void    **tmp = realloc(p->x, need * sizeof(void *));
      if (IS_NULL(tmp))                          /* FIXME */
         exit(1);
      p->x = tmp;
      p->size = need;
   }

   (p->x)[p->len] = e;
   p->len += 1;

   /*
      {
      unsigned  i;
      for (i = 0; i < p->len; i++)
      printf("%d--%p\n", i, (p->x)[i]);
      }
    */


   return 0;
}

unsigned
varray_len(struct varray *p)
{
   return p->len;
}

void
varray_reset(struct varray *p)
{
   p->len = 0;
}


#undef  IS_NULL
#undef  FREE
