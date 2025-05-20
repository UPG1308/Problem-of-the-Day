class Solution {
  public:
    int ans = 0;
     int solve(Node *root,int target)
    {
        if(root==NULL)
        return 0;
        
        int lh =solve(root->left,target);
        int rh = solve(root->right,target);
        
        if(root->data  == target)
        {
            ans = max(lh,rh);
            return -1;
        }else if(lh>=0 && rh>=0)
        {
            return max(lh,rh)+1;
        }else
        {
            ans = max((abs(lh)+abs(rh)),ans);
            return min(lh,rh)-1;
        }
        return 0;
    }
    int minTime(Node* root, int target) {
        // code here
       solve(root,target);
       return ans;
    }
};
