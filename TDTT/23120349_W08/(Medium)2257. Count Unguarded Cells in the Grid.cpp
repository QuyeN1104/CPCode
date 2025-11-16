class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mark(m, vector<int>(n, 0));

        int l[4] = {0, 0, -1, 1};
        int r[4] = {-1, 1, 0, 0};



        for(auto s: guards){
            int x = s[0], y = s[1];
            mark[x][y] = 1;
        }

        for(auto s: walls){
            int x = s[0], y = s[1];
            mark[x][y] = 2;
        }
        for(auto s: guards){
            int x = s[0], y = s[1];
            cout << x << " " << y << endl;
            for(int i = 0; i < 4; i++){
               
                    int x_new = x + l[i], y_new = y + r[i];
                    while (x_new >= 0 && x_new < m && y_new >= 0 && y_new < n){
                        if(mark[x_new][y_new] == 1 || mark[x_new][y_new] == 2){
                            break;
                        }
                    else{
                        mark[x_new][y_new] = 3;
                    }
                    x_new = x_new + l[i]; y_new = y_new + r[i];
                }
            }
        }
        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!mark[i][j]){
                    ++cnt;
                    cout << i << " " << j << endl;
                }
            }
        }

        return cnt;

    }
};