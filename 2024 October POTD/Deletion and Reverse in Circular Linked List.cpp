class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // Handle the case for an empty or single-node list
        if(head == NULL || head->next == head) {
            return head;
        }

        Node *curr = head->next;
        Node *prev = head;
        Node *next = NULL;

        // Reverse the linked list
        while(curr != head) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Fix the circular connection
        head->next = prev;
        head = prev;  // Update the head to the new head of the reversed list

        return head;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        if(head == NULL) {
            return NULL;
        }

        Node *temp = head;
        Node *prev = NULL;

        // Case where the head needs to be deleted
        if(head->data == key) {
            // If there is only one node in the list
            if(head->next == head) {
                delete head;
                return NULL;
            }

            // Find the last node to update its 'next' pointer
            temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }

            // Last node's next should point to the new head
            temp->next = head->next;
            Node* newHead = head->next;
            delete head;  // Free the memory of the old head
            return newHead;
        }

        // For deleting a node other than the head
        temp = head;
        while(temp->next != head && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // If key is found
        if(temp->data == key) {
            prev->next = temp->next;
            delete temp;
        }

        return head;
    }
};
