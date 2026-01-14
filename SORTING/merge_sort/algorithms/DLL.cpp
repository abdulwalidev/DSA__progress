#include<iostream>
using namespace std;

// Define doubly linked list node

struct DD{
    int data;   // Data of the node
    DD* prev;   // Pointer to previous node
    DD* next;   // Pointer to next node
    
}
int head=NULL;
// Function to insert a node at the end (defined inside main, logically invalid in C++)
    void insertatend(int data){

        // Create a new node
        DD* NDD = new DD;
        NDD->data = data;
        

        // Check if the list is empty
        if(head==NULL)
        {
            NDD->prev = NULL;   // Previous of new node is NULL
            NDD->next = NULL;   // Next of new node is NULL
            head = NDD;         // Set head to new node
        }

        else{
            // Create a new node for traversal (unnecessary logically)
            DD* current = head; // Intended to start from head

            // Traverse to the end of the list
            while(current->next != NULL){
                
                current = current->next;
            }

            // Insert the new node at the end
            current->next = NDD;
            NDD->prev = current;
        }
    }
int main(){

    insertatend(5);

}
