class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto &it : mp) {
            vector<int> &pos = it.second;
            int m = pos.size();

            vector<long long> prefix(m);
            prefix[0] = pos[0];

            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i-1] + pos[i];
            }

            for (int i = 0; i < m; i++) {
                long long left = (long long)pos[i] * i - (i > 0 ? prefix[i-1] : 0);
                long long right = (prefix[m-1] - prefix[i]) - (long long)pos[i] * (m - i - 1);

                ans[pos[i]] = left + right;
            }
        }

        return ans;
    }
};