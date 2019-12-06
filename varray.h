/**
 *  @file varray.h
 *  @version 0.1.0-dev0
 *  @date Wed Nov 27 18:50:23 CST 2019
 *  @copyright %COPYRIGHT%
 *  @brief FIXME
 *  @details FIXME
 */

#ifndef _VARRAY_H_
#define _VARRAY_H_

#ifdef  _PACKAGE_NAME
#undef  _PACKAGE_NAME
#endif
#define _PACKAGE_NAME "varray"

struct varray;

/**
 *  @brief Create and return a new varray object.
 *  @details FIXME longer description here ...
 */

struct varray *varray_new(void);

/**
 *  @brief Clean up and free a varray structure.
 *  @details FIXME longer description here ...
 */

void        varray_free(struct varray *p);

/**
 *  @brief Initialize a varray object.
 *  @details FIXME longer description here ...
 *  @param p Pointer to a varray object
 *  @param x FIXME
 */

int         varray_init(struct varray *p, void *x);

/**
 *  @brief Return the version of this package.
 *  @details FIXME longer description here ...
 */

const char *varray_version(void);

void       *varray_get(struct varray *p, unsigned idx);
int         varray_insert(struct varray *p, void *e);
unsigned    varray_len(struct varray *p);


#endif
