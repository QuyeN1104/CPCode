class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        // 1. Sort the array
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int ans = 0;
        int MOD = 1e9 + 7;
        
        // 2. Precompute powers of 2 to handle the large numbers
        // pows[i] will store 2^i % MOD
        vector<int> pows(n, 1);
        for (int i = 1; i < n; ++i) {
            pows[i] = (pows[i - 1] * 2) % MOD;
        }
        
        // 3. Two Pointers approach
        while (left <= right) {
            // If the sum of min (left) and max (right) is valid
            if (nums[left] + nums[right] <= target) {
                // If we fix 'left' as the minimum, every element between left and right
                // can either be included or excluded.
                // The number of such subsequences is 2^(right - left).
                ans = (ans + pows[right - left]) % MOD;
                
                // Move left pointer to try a larger minimum
                left++;
            } else {
                // The sum is too large, we must decrease the maximum
                right--;
            }
        }
        
        return ans;
    }
};