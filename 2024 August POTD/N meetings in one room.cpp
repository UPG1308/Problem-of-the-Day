class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int, int>> meet;
        for(int i = 0; i < n; i++) meet.push_back({start[i], end[i]});
        sort(meet.begin(), meet.end(), [&](pair<int,int>& a, pair<int,int>& b){
            if(a.second < b.second) return true;
            else if(a.second > b.second) return false;
            return a.first >= b.first;
        });
        int count = 0, meetEnd = 0;
        for(int i = 0; i < n; i++){
            if(meet[i].first > meetEnd){
                count++;
                meetEnd = meet[i].second;
            }
        }
        return count;
    }
};
