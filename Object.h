#ifndef OBJECT_H
#define OBJECT_H

struct Object
{
    unsigned count;
    struct Set *in;
};

extern const void *Object;

int differ(const void *a, const void *b);

#endif /* OBJECT_H */
