class Solution {
  public:
    bool compute(Node* head) {
        // Your code goes here
        if(head == nullptr) return true;
        string s = "";
        Node* curr = head;
        while(curr != nullptr){
            s = s.append(curr -> data);
            curr = curr -> next;
        }
        int i = 0, n = s.size();
        while(i < n/2){
            if(s[i] != s[n - 1 - i]) return false;
            i++;
        }
        return true;
    }
};
