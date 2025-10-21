class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int f[101][101] = {};
        int m = o.size();
        int n = o[0].size();

        if(o[0][0] == 1){
                    return 0;
        }

        bool f1 = false, f2 = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(i == 0 || j == 0){
                    if(i){
                        if(o[i][j] || f1) {
                            f[i][j] = 0;
                            f1 = true;
                        } else {f[i][j] = 1;}
                    }
                    else {
                        
                        if(o[i][j] || f2) {
                            f[i][j] = 0;
                            f2 = true;
                        } else {f[i][j] = 1;}
                    }
                } else {
                    f[i][j] = o[i][j] == 0 ? f[i-1][j] + f[i][j-1] : 0;
                }

                

            }
        }
        return f[m-1][n-1];

    }
};