#include <stdio.h>
#include <stdlib.h>
#include "inher.h"

int main(){

    struct base * b1 = new_base();//return the base class pointer
    b1->a=10;
    b1->func1(b1);
    
    struct derived * d1 = new_derived();
    d1->parent=*b1;//*b1解引用,返回b1指针所指的对象, inherit from base instance b1
    printf("parent a : %d \n",d1->parent.a);

    return 0;
}