class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int ans = 0;

        while(i < j){
            while( i < n && nums[i] != 0){
                i++;
            }
            while(j > 0 && nums[j] == 0){
            j--;
            }
            if(i>=j){
            break;
            }
        
        swap(nums[i],nums[j]);
        ans++;
        i++;
        j--;
        }
        return ans;
    }
};