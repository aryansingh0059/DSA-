class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int remaining, int start,
                   vector<int>& current, vector<vector<int>>& result) {
        if (remaining == 0) {
            result.push_back(current);  // Found valid combination
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates at the same level
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // Prune: no point going further if candidate exceeds remaining
            if (candidates[i] > remaining) break;

            current.push_back(candidates[i]);
            backtrack(candidates, remaining - candidates[i], i + 1, current, result);
            current.pop_back();  // Undo choice (backtrack)
        }
    }
};