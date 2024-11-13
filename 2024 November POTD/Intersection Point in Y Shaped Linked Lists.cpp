class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        set<Node*> st;
        Node* curr = head1;
        while(curr != NULL){
            st.insert(curr);
            curr = curr -> next;
        }
        Node* curr1 = head2;
        while(curr1 != NULL){
            if(st.find(curr1) != st.end()) return curr1 -> data;
            curr1 = curr1 -> next;
        }
        return -1;
    }
};
