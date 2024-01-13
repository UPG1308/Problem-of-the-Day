class Solution
{
    public static Node insertionSort(Node head_ref)
    {
        if(head_ref==null &&head_ref.next==null)
            return head_ref;
        Node prev=head_ref;
        Node curr=head_ref.next;
        Node forward=null;
        while(curr!=null)
        {
            forward=curr.next;
            if(prev.data>curr.data)
            {
                prev.next=curr.next;
                curr.next=null;
                if(curr.data <= head_ref.data)
                {
                    curr.next=head_ref;
                    head_ref=curr;
                }
                else
                {
                    Node temp=head_ref.next;
                    Node p=head_ref;
                    while(temp.data < curr.data)
                    {
                        p=temp;
                        temp=temp.next;
                    }
                    p.next=curr;
                    curr.next=temp;
                }
            }
            else
                prev=curr;
            curr=forward;
        }
        return head_ref;
    }
}
