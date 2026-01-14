Node* i = head;

while (i && i->next) {
    Node* minNode = i;
    Node* j = i->next;

    // Find minimum node in remaining list
    while (j) {
        if (j->data < minNode->data)  // "<" for ascending
            minNode = j;
        j = j->next;
    }

    // Swap data of current node and minNode
    if (minNode != i)
        swap(i->data, minNode->data);

    i = i->next;
}
