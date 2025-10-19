class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int dp[1004][1004] = {0};

        int maxLen = 0;

        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]] = i;
            for(int j = 0; j < i; j++){

                int diff = arr[i] - arr[j];
                int prevId = (mp.find(diff) != mp.end()) ? mp[diff] : -1;

                if (diff  < arr[j] && prevId >= 0){
                    dp[i][j] = dp[j][prevId] + 1;
                } else {
                    dp[i][j] = 2;
                }

                maxLen = max(maxLen, dp[i][j]);

            }
        }

        return maxLen > 2 ? maxLen : 0;
        

    }
};