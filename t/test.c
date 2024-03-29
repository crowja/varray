#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "varray.h"
#include "t/tinytest.h"

#ifdef  COLOR_CODE
#undef  COLOR_CODE
#endif
#define COLOR_CODE       0x1B

#ifdef  COLOR_RED
#undef  COLOR_RED
#endif
#define COLOR_RED        "[1;31m"

#ifdef  COLOR_GREEN
#undef  COLOR_GREEN
#endif
#define COLOR_GREEN      "[1;32m"

#ifdef  COLOR_YELLOW
#undef  COLOR_YELLOW
#endif
#define COLOR_YELLOW     "[1;33m"

#ifdef  COLOR_RESET
#undef  COLOR_RESET
#endif
#define COLOR_RESET      "[0m"


static void
printf_test_name(char *name, char *info)
{
   printf("%c%s%s%c%s", COLOR_CODE, COLOR_YELLOW, name, COLOR_CODE, COLOR_RESET);

   if (NULL != info)
      printf(" [%s]\n", info);
   else
      printf("\n");
}


static int
two_doubles_equal(double x, double y)
{
   double    t = fabs(x) + fabs(y);
   return fabs(x - y) < 4 * DBL_EPSILON * t ? 1 : 0;
}


static void
test_constr(void)
{
   struct varray *z;

   printf_test_name("test_constr", "varray_new, varray_free");

   z = varray_new();
   ASSERT("Constructor test", z);
   varray_free(&z);
   ASSERT_EQUALS(NULL, z);
}

static void
test_all(void)
{
   unsigned  i;
   unsigned  nums = 200000;
   struct varray *z;

   printf_test_name("test_all", "varray_new, varray_free");

   z = varray_new();
   ASSERT("Constructor test", z);

   for (i = 0; i < nums; i++) {
      /* TODO */
      int      *nump = (int *) malloc(sizeof(int));
      *nump = i + 3141;
      varray_insert(z, nump);
   }

   ASSERT_EQUALS(nums, varray_len(z));

   for (i = 0; i < varray_len(z); i++) {
      int       n = i + 3141;
      ASSERT_EQUALS(n, *(int *) varray_get(z, i));
   }

   for (i = 0; i < nums; i++)
      free(varray_get(z, i));

   varray_reset(z);
   ASSERT_EQUALS(0, varray_len(z));

   for (i = 0; i < nums; i++) {
      int      *nump = (int *) malloc(sizeof(int));
      *nump = -i;
      varray_insert(z, nump);
   }

   ASSERT_EQUALS(nums, varray_len(z));

   for (i = 0; i < varray_len(z); i++) {
      int       n = -i;
      ASSERT_EQUALS(n, *(int *) varray_get(z, i));
   }

   for (i = 0; i < nums; i++)
      free(varray_get(z, i));

   varray_reset(z);
   ASSERT_EQUALS(0, varray_len(z));

   varray_free(&z);
   ASSERT_EQUALS(NULL, z);
}

#if 0                                            /* 15 yy */
static void
test_stub(void)
{
   struct varray *z;
   double    x = 1.23;                      /* TODO */

   printf_test_name("test_stub", NULL);

   z = varray_new();
   ASSERT("Constructor test, pt 1", z);
   ASSERT("Here's a test ...", two_doubles_equal(x, 1.23));

   varray_free(&z);
   ASSERT_EQUALS(NULL, z);
}
#endif


int
main(void)
{
   printf("%s\n", varray_version());

   RUN(test_constr);
   RUN(test_all);

   return TEST_REPORT();
}
