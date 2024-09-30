class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorderTraversal(Node* root, vector<int>& arr){
        if(!root){
            return;
        }
        inorderTraversal(root->left,arr);
        arr.push_back(root->data);
        inorderTraversal(root->right,arr);
    }
    
    vector<int> mergeTwoSortedArray(vector<int> arr1,vector<int> arr2){
        vector<int> temp;
        
        int i=0,j=0;
        
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<=arr2[j]){
                temp.push_back(arr1[i]);
                i++;
            }else{
                temp.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i<arr1.size()){
            temp.push_back(arr1[i]);
            i++;
        }
        while(j<arr2.size()){
            temp.push_back(arr2[j]);
            j++;
        }
        return temp;
    }
    
    
    
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> arr1;
        vector<int> arr2;
        inorderTraversal(root1,arr1);
        inorderTraversal(root2,arr2);
        
        return mergeTwoSortedArray(arr1,arr2);
    }
};
