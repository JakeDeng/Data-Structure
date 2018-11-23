#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


int main()
{
    Linked_List list;
    list.Insert_Begin(10);
    list.Print_List();
    list.Insert_Begin(5);
    list.Print_List();

    return 0;
}