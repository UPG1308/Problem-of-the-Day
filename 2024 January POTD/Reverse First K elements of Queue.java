class GfG {
    // Function to reverse first k elements of a queue.
    public Queue<Integer> modifyQueue(Queue<Integer> q, int k) {
        // add code here.
        Deque<Integer> dq = new ArrayDeque<>();
        
        for(int i = 0;i<k;i++){
            dq.offerFirst(q.poll());
        }
        
        while(!q.isEmpty()){
            dq.offerLast(q.poll());
        }
        
        return dq;
        
    }
}
