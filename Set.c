#include "Set.h"

#if !defined(MANY) || MANY < 1
#define MANY 10
#endif

static const size_t _Set = sizeof(struct Set);
static const size_t _Object = sizeof(struct Object);

const void *Set = &_Set;
const void *Object = &_Object;

static int heap[MANY];

void *new(const void *_type, ...)
{
    const size_t size = *(const size_t *)_type;
    void *p = calloc(1, size);

    assert(p);
    return p;
}

void delete(void *_item)
{
    int *item = _item;

    if (item)
    {
        assert(item > heap && item < heap + MANY);
        *item = 0;
    }
}

void *add(void *_set, const void *_element)
{
    struct Set *set = _set;
    struct Object *element = (void *) _element;

    assert(set);
    assert(element);

    if (!element->in)
        element->in = set;
    else
        assert(element->in == set);
    ++element->count, ++set->count;

    return element;
}

void *find(const void *_set, const void *_element)
{
    const struct Object *element = _element;

    assert(element);
    assert(_set);

    return element->in == _set ? (void *)element : NULL;
}

bool contains(const void *_set, const void *_element)
{
    return find(_set, _element) != NULL;
}

void *drop(void *_set, const void *_element)
{
    struct Set *set = _set;
    struct Object * element = find(_set, _element);

    if (element)
    {
        if (--element->count == 0)
            element->in = 0;
        --set->count;
    }
    return element;
}

unsigned count(const void *_set)
{
    const struct Set *set = _set;

    assert(set);
    return set->count;
}

 int differ(const void *a, const void *b)
 {
     return a != b;
 }
