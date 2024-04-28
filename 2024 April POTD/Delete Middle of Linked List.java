class Solution {
    public Node deleteMid(Node start) {
        if(start.next == null){//if only 1 node.
            return null;
        }
        if(start.next.next == null){//if only 2 node.
            start.next = null;
            return start;
        }
        Node slow = start, first = start;
        int size = even_odd(start);
        Node temp = null;
        while(first.next!=null && first.next.next!=null){
            temp = slow;
            slow = slow.next;
            first = first.next.next;
        }
        if(size%2==0){
            temp = temp.next;
            temp.next = temp.next.next;
        }else{
            temp.next = temp.next.next;
        }
        return start;
    }
    public static int even_odd(Node start){
        int count = 0;
        Node p = start;
        while(p!=null){
            p = p.next;
            count++;
        }
        return count;
    }
}
