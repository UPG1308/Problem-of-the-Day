class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
  
    // Fast and slow pointers initially points to the head
    Node *slow = head, *fast = head;

    // Loop that runs while fast and slow pointer are not
    // nullptr and not equal
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // If fast and slow pointer points to the same node,
        // then the cycle is detected
        if (slow == fast) {
            return true;
        }
    }
    return false;
}