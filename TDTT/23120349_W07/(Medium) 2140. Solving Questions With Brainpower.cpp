class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        /*
            mấy chiều thì được đây -> 2 chieu
            
            mình nghĩ là đi ngược lại :

        */
        long long n = questions.size();
        
        vector<vector<long long>> dp(n, vector<long long>(2,0));
        
        dp[n-1][0] = 0; dp[n-1][1] = questions[n-1][0];
        for(long long i = n - 2; i >= 0; i--){
            dp[i][1] = questions[i][0];
            long long id = i + 1 + questions[i][1];
            if( id < n){
                dp[i][1] += dp[id][1];
            }
            dp[i][0] = max(dp[i+1][0], dp[i+1][1]);
            
            dp[i][0] = dp[i][1] = max(dp[i][0], dp[i][1]);
        }
        for(long long i = 0; i < n; i++) cout << dp[i][0] << " " << dp[i][1] << endl;
        return max(dp[0][0], dp[0][1]);
    }
};