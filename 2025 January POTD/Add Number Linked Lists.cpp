class Solution {
    Node* reverse(Node* head){
        if(!head || !head->next){
            return head;
        }
        
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr){
            Node* right = curr->next;
            curr->next = prev;
            prev = curr;
            curr = right;
        }
        return prev;
    }
    
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        int carry = 0;
        Node* preHead = new Node(-1);    
        Node* curr = preHead;
        while(num1->next && num1->data == 0) num1 = num1->next;
        while(num2->next && num2->data == 0) num2 = num2->next;
        //reverse the lists to sum correctly
        Node* curr1 = reverse(num1);
        Node* curr2 = reverse(num2);
        
        while(curr1 && curr2){
            int sum = curr1->data + curr2->data + carry;
            Node* newNode = new Node(sum % 10);
            carry = sum/10;
            
            curr->next = newNode;
            curr = curr->next;
            
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1){
            int sum = curr1->data + carry;
            Node* newNode = new Node(sum % 10);
            carry = sum/10; 
            
            curr->next = newNode;
            curr = curr->next;
            curr1 = curr1->next;
        }
        //if(num2 length > num1 length)
        while(curr2){
            int sum = curr2->data + carry;
            Node* newNode = new Node(sum % 10);
            carry = sum/10; 
            
            curr->next = newNode;
            curr = curr->next;
            curr2 = curr2->next;
        }
        if(carry != 0){
            Node* newNode = new Node(carry);
            
            curr->next = newNode;
        }
        
        Node* ans = preHead->next;
        delete preHead;       //delete the memory for extra node
        
        return reverse(ans);
        
    }
};
