Node* RemoveHalfNodes(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        
        // Recursively remove half nodes from left and right subtrees
        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);

        // If the node is a half node with only left or only right child
        if (root->left == NULL && root->right != NULL) {
            Node* new_root = root->right;
            delete root;
            return new_root;
        }
        
        if (root->right == NULL && root->left != NULL) {
            Node* new_root = root->left;
            delete root;
            return new_root;
        }

        return root; // Return the original root if it's a full node or a leaf node
    }
