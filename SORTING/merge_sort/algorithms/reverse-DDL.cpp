                                        #include <iostream>
using namespace std;

// Node structure
struct DD {
    int data;
    DD* next;
    DD* prev;
};

// Function to reverse DLL
void reverseDLL(DD*& head) {
    DD* curr = head;
    DD* temp = nullptr;

    while (curr != nullptr) {
        // Swap next and prev
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // Move to next node (which is old prev)
        curr = curr->prev;
    }

    // Update head to the new first node
    if (temp != nullptr) head = temp->prev;
}

// Function to display DLL
void display(DD* head) {
    DD* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Creating DLL: 10 <-> 20 <-> 30 <-> 40
    DD* head = new DD{10, nullptr, nullptr};
    DD* n2 = new DD{20, nullptr, head}; head->next = n2;
    DD* n3 = new DD{30, nullptr, n2}; n2->next = n3;
    DD* n4 = new DD{40, nullptr, n3}; n3->next = n4;

    cout << "Original DLL: ";
    display(head);

    reverseDLL(head);

    cout << "Reversed DLL: ";
    display(head);

    return 0;
}
