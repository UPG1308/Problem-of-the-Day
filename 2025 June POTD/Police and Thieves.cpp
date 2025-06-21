class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        // Step 1: Extract positions of police and thieves
        vector<int> police, thieves;
        
        // Collect positions (indices) of all police officers and thieves
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P') {
                police.push_back(i);
            } else {
                thieves.push_back(i);
            }
        }
        
        // Step 2: Use two pointers for optimal matching
        int policePtr = 0, thiefPtr = 0;
        int catches = 0;
        
        // Greedy matching using two pointers
        while (policePtr < police.size() && thiefPtr < thieves.size()) {
            int policePos = police[policePtr];
            int thiefPos = thieves[thiefPtr];
            
            // Check if current police can catch current thief
            if (abs(policePos - thiefPos) <= k) {
                // Match found! Police catches thief
                catches++;
                policePtr++;  // Move to next police officer
                thiefPtr++;   // Move to next thief (this one is caught)
            }
            // If thief is too far to the left, try next thief
            else if (policePos > thiefPos) {
                thiefPtr++;
            }
            // If thief is too far to the right, try next police officer
            else {
                policePtr++;
            }
        }
        
        return catches;
    }
};
