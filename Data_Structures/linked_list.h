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

    //General Insertion
    void Insert(int input, int index){
        Node* temp1 = new Node;
        temp1->data = input;
        temp1->next = NULL;
        //first node : at the beginning
        if (index==1){
            temp1->next = head;
            head = temp1;
            return;
        }
        //other positions
        Node* temp2 = head;
        for (int i = 0; i<index-2; i++){
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }
    //delete a node at position n
    void Delete(int index){
        Node* temp1 = head;//already point to the first node
        //delete the head node
        if(index ==1 ){
            head = temp1->next;//head points to second node
            free(temp1);
            return;
        }
        //temp1 points to (n-1)th node
        for(int i=0; i<index-2; i++){
            temp1 = temp1->next;
        }
        Node* temp2 = temp1->next;//n th node
        temp1->next = temp2->next;//fix the link
        free(temp2);//free the address of n th node
        
    }

    //reverse a linked list
    void Reverse_It(){
        Node *current, *prev, *next;
        current = head;
        prev = NULL;
        while(current != NULL){
            next = current->next; //store the address of the next node
            current->next = prev; //reverse the connection
            prev = current;       //update the prev node address
            current = next;       //update the current node address
        }
        head = prev;//update the head, point to the last node
    }

    void Reverse_Re(Node* p){
        //Exit condition
        if(p->next ==NULL)
        {
            head = p;
            return;
        }
        Reverse_Re(p->next);
        Node* q = p->next;
        q->next = p;
        p->next = NULL;

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
    Node* head;//store the address of the 
};


