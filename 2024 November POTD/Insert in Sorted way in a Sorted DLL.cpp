Node* sortedInsert(Node* head, int x) {
    Node* newNode = new Node();
    newNode->data = x;
    
    // Insert at the beginning if the list is empty or `x` is less than the head's data
    if (!head || head->data >= x) {
        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        return newNode;
    }
    
    Node* curr = head;
    while (curr->next && curr->next->data < x) {
        curr = curr->next;
    }

    Node* nextNode = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
    newNode->next = nextNode;

    // Update `prev` pointer of `nextNode` if it exists
    if (nextNode) {
        nextNode->prev = newNode;
    }
    
    return head;
}
