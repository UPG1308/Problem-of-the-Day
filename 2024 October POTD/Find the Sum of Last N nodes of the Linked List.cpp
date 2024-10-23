class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
     int sumOfLastN_Nodes(struct Node* head, int n) {
        // Code here
        int z = 1;
        Node* curr = head;
        while(curr)
        {
            z++;
            curr = curr->next;
        }
        int i = 1, ans = 0;
        curr = head;
        while(curr)
        {
            if(i >= z-n)
            {
                ans += curr->data;
            }
            curr = curr->next;
            i++;
        }
        return ans;
    }
};
