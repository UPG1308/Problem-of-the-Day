public static Node reverseDLL(Node head)

{

    //Your code here

    Node curr = head, next = head;

    while(curr!=null){

        next = curr.next;

        curr.next = curr.prev;

        curr.prev = next;

        if(next==null)

            break;

        curr = next;

    }

    return curr;

}
