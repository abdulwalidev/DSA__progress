#insertion sort code here:
Node* sorted = nullptr;
Node* curr = head;

while (curr) {
    Node* next = curr->next;

    if (!sorted || curr->data < sorted->data) {
        curr->next = sorted;
        sorted = curr;
    } else {
        Node* temp = sorted;
        while (temp->next && temp->next->data <= curr->data)
            temp = temp->next;

        curr->next = temp->next;
        temp->next = curr;
    }

    curr = next;
}

head = sorted;


//convert this later
