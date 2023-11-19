class Solution
{
    public static void fun(Node res, Node head1, Node head2) {
        if(head1==null || head2==null) return;
        if(head1.data == head2.data) {
            res.next = new Node(head1.data);
            fun(res.next, head1.next, head2.next);
        } else if(head1.data < head2.data) {
            fun(res, head1.next, head2);
        } else {
            fun(res, head1, head2.next);
        }
    }
   public static Node findIntersection(Node head1, Node head2)
    {
        // code here.
        Node res = new Node(-1);
        fun(res, head1, head2);
        return res.next;
    }
}
