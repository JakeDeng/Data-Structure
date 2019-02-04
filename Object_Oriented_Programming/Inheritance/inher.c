#include <stdio.h>
#include <stdlib.h>
#include "inher.h"


static void base_func1(struct base * self)
{
    printf("this is base::func1\n");
}

static void derived_func2(struct derived * self)
{
    printf("this is derived::func2, base::a = %d\n", self->parent.a);
    self->parent.func1(&(self->parent));
}

//constructor for base class
struct base * new_base()
{
    struct base* b = malloc(sizeof(struct base));//malloc in the heap
    b->a = 0;
    b->func1 = base_func1;
    return b;
}

struct derived * new_derived()
{
    struct derived* d = malloc(sizeof(struct derived));//malloc in the heap
    d->b = 0;
    d->func2 = derived_func2;
    return d;
}

 
//struct derived *p = new_derived();
//((struct base *)p)->func1(p);