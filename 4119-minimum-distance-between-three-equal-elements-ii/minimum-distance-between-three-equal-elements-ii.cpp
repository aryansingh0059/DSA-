class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> positions;
        
        for (int i = 0; i < nums.size(); i++) {
            positions[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        for (auto& [val, idx] : positions) {
            if (idx.size() < 3) continue;
            
            // Slide window of size 3 over sorted indices
            for (int p = 0; p + 2 < idx.size(); p++) {
                // distance = 2 * (k - i) since i < j < k
                ans = min(ans, 2 * (idx[p+2] - idx[p]));
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};