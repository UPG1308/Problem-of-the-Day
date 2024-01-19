class Space{
	int val;
	int frequency;
	Space(int val,int frequency){
		this.val = val;
		this.frequency = frequency;
	}
}

class Solution {
    public static ArrayList<ArrayList<Integer>> kTop(int[] arr, int n, int k) {
        Map<Integer,Integer> map = new HashMap<>();
		ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
		ArrayList<Integer> list ;
		
		PriorityQueue<Space> pq = new PriorityQueue<>(new Comparator<Space>() {
			@Override
			public int compare(Space a,Space b) {
				if(a.frequency == b.frequency) {
					return a.val-b.val;//if frequency is same then sort based on the value
				}else if(a.frequency<b.frequency) {
					return 1;//son't swap
				}else {
					return -1;//swap
				}
			}
		});
		
		int dist = 0;
		for(int i=0;i<n;i++) {
		    dist = k;
			list = new ArrayList<>();
			for(int j=0;j<=i;j++) {
				if(!map.containsKey(arr[j])) {
					map.put(arr[j], 1);
				}else {
					map.put(arr[j], map.get(arr[j])+1);
				}
			}
			map.forEach((e1,e2)->{
				pq.add(new Space(e1,e2));
			});
			map.clear();
			while(!pq.isEmpty()) {
				Space curr = pq.poll();
				if(dist>0){//consider the value for first k time
				    list.add(curr.val);
				}
				dist--;
			}
			ans.add(list);
		}
		return ans;
    }
}
