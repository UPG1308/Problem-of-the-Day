class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        Node* temp = new Node(0);
        Node* ans = temp;
        while(head) {
            int c = 0;
            Node* cur = head;
            while(head && cur->data == head->data) {
                c++;
                head = head->next;
            }
            if(c == 1) {
                temp->next = cur;
                cur->next = nullptr;
                temp = temp->next;
            }
        }
        return ans->next;
    }
};
