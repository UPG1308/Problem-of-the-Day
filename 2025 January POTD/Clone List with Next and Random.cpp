class Solution {
  public:
    Node *cloneHelper(Node*head, unordered_map<Node*, Node*> &mp) {
    if (head == nullptr) {
        return nullptr;
    }

    // If the node is already cloned, return the cloned node
    if (mp.find(head) != mp.end()) {
        return mp[head];
    }

    // Create a new node with the same data
    Node *clonedNode = new Node(head->data);
    mp[head] = clonedNode; 
  
    // Recursively clone the next and random pointers
    clonedNode->next = cloneHelper(head->next, mp);
    clonedNode->random = cloneHelper(head->random, mp);

    return clonedNode;
}

// Function to clone the linked list
Node *cloneLinkedList(Node *head) {
    unordered_map<Node *, Node *> mp;
    return cloneHelper(head, mp);
}
};
