class Solution {
    public static double findSmallestMaxDist(int stations[], int k) {
        // code here
        int n = stations.length;
        double low = 0, high = 0, diff = 1e-6;
        for(int i = 1; i < n; i++) high = Math.max(high, stations[i] - stations[i - 1]);
        while(high - low > diff){
            double mid = low + (high - low)/2;
            if(isPossible(mid, stations, k)) high = mid;
            else low = mid;
        }
        return high;
    }
    public static boolean isPossible(double maxdis, int stations[], int extStation){
        int extra = 0;
        for(int i = 1; i < stations.length; i++){
            int distance = stations[i] - stations[i - 1];
            extra += distance/maxdis;
        }
        return extra <= extStation;
    }
}
