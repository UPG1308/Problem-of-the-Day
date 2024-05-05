class Solution{
    public ArrayList <Integer> verticalSum(Node root) {
        ArrayList<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        
        // Use TreeMap to automatically sort keys (vertical lines)
        TreeMap<Integer, Integer> verticalSumMap = new TreeMap<>();
        verticalSumUtil(root, 0, verticalSumMap);
        
        // Traverse the sorted map and add sums to the result array
        for (Map.Entry<Integer, Integer> entry : verticalSumMap.entrySet()) {
            result.add(entry.getValue());
        }
        
        return result;
    }
    
    private void verticalSumUtil(Node root, int verticalLine, TreeMap<Integer, Integer> verticalSumMap) {
        if (root == null) {
            return;
        }
        
        // Update the sum for the current vertical line
        verticalSumMap.put(verticalLine, verticalSumMap.getOrDefault(verticalLine, 0) + root.data);
        
        // Recursively traverse left and right subtrees with updated vertical lines
        verticalSumUtil(root.left, verticalLine - 1, verticalSumMap);
        verticalSumUtil(root.right, verticalLine + 1, verticalSumMap);
    }
}
