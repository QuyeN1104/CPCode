class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
        f[i][j] là số cách đi từ f[0][0] đến f[i][j]
        */
        int f[101][101];

        for(int i = 0; i < m; i++) f[i][0] = 1;
        for(int i = 0; i < n; i++) f[0][i] = 1;

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }

        return f[m-1][n-1];
    }
};