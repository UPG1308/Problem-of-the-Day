class Solution {
    private static void inorder(Node root, List<Integer> ls){
        if (root == null) return;
        inorder(root.left, ls);
        ls.add(root.data);
        inorder(root.right, ls);
    }
    
    private static void mergeSort(int[] arr, int low, int high, int[] ans){
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid, ans);
        mergeSort(arr, mid + 1, high, ans);
        merge(arr, low, mid, high, ans);
    }
    
    private static void merge(int[] arr, int low, int mid, int high, int[] ans){
        int[] temp = new int[high - low + 1];
        int ptr1 = low, ptr2 = mid + 1, ptr3 = 0;
        while(ptr1 <= mid || ptr2 <= high){
            if(ptr1 == mid + 1){
                temp[ptr3++] = arr[ptr2++];
            }else if(ptr2 == high + 1){
                temp[ptr3++] = arr[ptr1++];
            }else if(arr[ptr1] <= arr[ptr2]){
                temp[ptr3++] = arr[ptr1++];
            }else{
                ans[0] += mid - ptr1 + 1;
                temp[ptr3++] = arr[ptr2++];
            }
        }
        
        
        for(int i = 0; i < temp.length; ++i){
            arr[low + i] = temp[i]; 
        }
    }
    
    public static int pairsViolatingBST(int n, Node root) {
        List<Integer> ls = new ArrayList<>();
        inorder(root, ls);
        int[] ans = new int[1];
        int[] temp = new int[ls.size()];
        for(int i = 0; i < temp.length; ++i) {
            temp[i] = ls.get(i);
        }
        mergeSort(temp, 0, temp.length - 1, ans);
        return ans[0];
    }
}
