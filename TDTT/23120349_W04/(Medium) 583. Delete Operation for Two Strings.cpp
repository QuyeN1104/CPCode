class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[502][502];
        int n1 = word1.size(), n2 = word2.size();
        for(int i = 0; i <= n1; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i <= n2; i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return n1 + n2 - 2 * dp[n1][n2];        
    }
};