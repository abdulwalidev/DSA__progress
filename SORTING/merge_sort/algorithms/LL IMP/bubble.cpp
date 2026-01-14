bool swapped;
Node* end = nullptr;  // Marks last sorted node

do {
    swapped = false;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr->next != end) {
        if (curr->data > curr->next->data) {
            // Swap nodes by relinking
            Node* tmp = curr->next;
            curr->next = tmp->next;
            tmp->next = curr;
            if (prev) prev->next = tmp;
            else head = tmp;

            prev = tmp;  // Update prev to new first node
            swapped = true;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    end = curr;  // Reduce traversal range
} while (swapped);
