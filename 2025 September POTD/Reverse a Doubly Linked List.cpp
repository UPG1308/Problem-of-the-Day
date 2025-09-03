class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* right = head;
        int cnt = 1;
        while(right != NULL && right -> next != NULL) right = right -> next, cnt++;
        Node* left = head;
        
        int l = 1, r = cnt;
        while(l < r){
            swap(left -> data, right -> data);
            left = left -> next;
            right = right -> prev;
            l++, r--;
        }
        return head;
    }
};
