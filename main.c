#include "Set.h"

#include <stdio.h>

int main(void)
{
    void *s = new(Set);
    void *a = add(s, new(Object));
    void *b = add(s, new(Object));
    void *c = new(Object);

    if (contains(s, a) && contains(s, b))
        puts("Ok.");

    if (contains(s, c))
        puts("Contains?");

    if (differ(a, add(s, a)))
        puts("Differ?");

    if (contains(s, drop(s, a)))
        puts("Drop?");
    
    delete(drop(s, b));
    delete(drop(s, c));

    return 0;
}
