class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCombination = 0;

        // Loop through each bit position up to 30 (sufficient for 32-bit integers)
        for (int bit = 0; bit < 30; bit++) {
            int count = 0;

            // Count how many candidates have the current bit set
            for (int num : candidates) {
                if (num & (1 << bit)) {
                    count++;
                }
            }
            
            // Update the maximum combination size
            maxCombination = max(maxCombination, count);
        }
        
        return maxCombination;
    }
};
