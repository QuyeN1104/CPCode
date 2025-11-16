class Solution {
public:
    static bool comp(const pair<int, int>& x, const pair<int, int>& y) {
        if (x.second == y.second) return x.first < y.first;
        return x.second < y.second;   
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) p[i] = {scores[i], ages[i]};
        sort(p.begin(), p.end(), comp);

        for (int i = 0; i < n; i++) scores[i] = p[i].first;
        
        vector<int> dp(n, 0);
        
        // Base case
        for(int i = 0; i < n; i++) dp[i] = scores[i];
        
        // DP Transition
        for(int i = 0; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(scores[i] >= scores[j]){
                    dp[i] = max(dp[i],dp[j] + scores[i]);
                }
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};
/*
    f[i] là tổng lớn nhất khi xét tới i
    sort theo tuổi
    f[i]:
        Duyệt j 0 - > i - 1:
*/