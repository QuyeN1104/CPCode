#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long


void sol() {
    int n, m , k;
    cin >> m >> n >> k;
    vector<vector<int>> a(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> b(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            b[i][j] = a[i][j];
        }
    }
    

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(b[i][j] == 1){
                for(int u = max(0LL,i - k); u <= min(m-1,i+k); u++){
                    for(int v = max(0LL,j - k); v <= min(n-1,j+k); v++){
                        a[u][v] = 1;
                    }
                }
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sol();
    return 0;

}
