class Solution {
    static ArrayList<Integer> recamanSequence(int n) {
        ArrayList<Integer> list = new ArrayList<>();
        HashSet<Integer> set = new HashSet<>();
        
        helper(n, list, set);
        return list;
    }

    private static int helper(int n, ArrayList<Integer> list, HashSet<Integer> set) {
        if (n == 0) {
            list.add(0);
            set.add(0);
            return 0;
        }
        
        int prevElement = helper(n - 1, list, set);
        int element = prevElement - n;

        if (element <= 0 || set.contains(element)) {
            element = prevElement + n;
        }

        list.add(element);
        set.add(element);
        return element;
    }
}
