//a cpp class that implments linked list data structure
//with proper modifications, it can be used in different applications

#include <stdlib.h>
#include <stdio.h>

//Node structure for linked list
struct Node{
    int data;   //data in the node
    Node* next; //address to next node
};
//Linked list class
class Linked_List
{
public:
    //Constrcutor
    Linked_List(){
        //create a head node
        Node* head = NULL;
    }

    //Insert at the beginning of the linked list
    void Insert_Begin(int input){

    Node* temp = new Node;  //create a new node from heap
    temp->data = input;
    temp->next = head;
    head = temp;    
    }

    //Print out the entire list
    void Print_List(){
    Node* temp = head;
    printf("List = ");
    //traverse to the end of the list
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next; 
    }
    printf("\n");
    }

private:
    Node* head;
};


