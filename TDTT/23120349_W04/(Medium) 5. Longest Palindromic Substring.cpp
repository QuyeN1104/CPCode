class Solution {
public:
    string longestPalindrome(string s) {
        /*
            f[i] là chuỗi con lớn nhất kết thúc tại i
            f[0] = 1
            f[1] = f[0] + 

            Kết quả là f[0][n-1]
        */
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, 0));

        pair<int,int> ans = {};

        for(int i = 0; i < n; i++){
            f[i][i] = 1;
            ans = {i, i};
        }

        for(int i = 0; i < n - 1; i++){
            if (s[i] == s[i+1]) {
                f[i][i+1] = 1;
                ans = {i,i+1};
            } else {
                f[i][i+1] = 0;
            }
        }

        for(int diff = 2; diff < n; diff++){
            for(int i = 0; i < n - diff; i++) {
                int j = i + diff;
                if(s[i] == s[j] && f[i+1][j-1]){
                    f[i][j] = 1;
                    ans = {i, j};
                } else {
                    f[i][j] = 0;
                }

            }
        }
        int start = ans.first, end = ans.second;
        
        return s.substr(start, end - start + 1);
    }
};