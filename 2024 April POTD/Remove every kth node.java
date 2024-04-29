class Solution
{ 
    Node delete(Node head, int k)
    {
        if(k==1){
            return null;
        }
    	 int count = 1;
    	 Node p = head;
    	 while(p.next!=null){
    	     if(count == k-1){
    	         if(p.next.next!=null){
    	            p.next = p.next.next;
    	         }else{
    	             p.next = null;
    	             break;
    	         }
    	         count = 1;
    	         p = p.next;
    	     }else{
        	     count++;
        	     p = p.next;
    	     }
    	 }
    	 return head;
    }
}
