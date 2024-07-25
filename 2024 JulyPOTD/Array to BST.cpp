class Solution {
  public:
    Node* helper(int i, int j,vector<int>&nums)
    {
        if(i>j) return NULL;
        if (i==j) return new Node(nums[i]);
        int mid=i+(j-i)/2;
        Node* newNode=new Node(nums[mid]);
        newNode->left=helper(i,mid-1,nums);
        newNode->right=helper(mid+1,j,nums);
        return newNode;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
       return helper(0,nums.size()-1,nums);
    }
};
