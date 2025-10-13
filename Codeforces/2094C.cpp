#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int a[801][802];

void sol(){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    if (n==1){
        cout << (a[0][0] == 1 ? 2 : 1) << " " << a[0][0] << '\n';
    } else {
        int sum_ = 0;
        
        for(int i =0; i < n-1; i++){
            sum_ += a[0][i];
        }
        for(int i = 0; i < n; i++){
            sum_+=(a[n-1][i]);
        }

        cout << n * (2*n+1) - sum_ << " ";
        for(int i =0; i < n-1;i++){
            cout <<  a[0][i] << " ";
        }
        for(int i = 0; i < n; i++){
            cout << (a[n-1][i]);
            if (i < n-1){
                cout << " ";
            }
            else {
                cout << "\n";
            }
        }


    }
    
}

int main(){
    std:ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin >> t;
    while(t--){
        sol();
    }

}