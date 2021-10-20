#ifndef SET_H
#define SET_H

#include "new.h"
#include "Object.h"

#include <stdbool.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

struct Set
{
    unsigned count;
};

extern const void *Set;

void *add(void *_set, const void *_element);
void *add(void *_set, const void *_element);
void *drop(void *_set, const void *_element);
bool contains(const void *_set, const void *_element);
unsigned count(const void *_set);

#endif
