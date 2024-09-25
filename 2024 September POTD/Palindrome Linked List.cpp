class Solution {
  public:
    // Function to check whether the list is palindrome.
     bool isPalindrome(Node *head) {
        if(head->next==NULL) return 1;
        if(head->next->next==NULL && head->data==head->next->data) return 1;
        if(head->next->next==NULL && head->data!=head->next->data) return 0;
        
        // Your code here
        Node *fast=head;
        Node*curr=head;
        Node *fr=head->next;
        Node *prev=NULL;
        
        
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            curr->next=prev;
            prev=curr;
            curr=fr;
            fr=fr->next;
        }
        // prev=fr;  
        if(fast!=NULL)
         curr=fr;
         
         
        while(prev!=NULL)
        {
            if(prev->data!=curr->data)
            return 0;
            
            prev=prev->next;
            curr=curr->next;
            
        }
       
        
        return 1;
        
    }
};
