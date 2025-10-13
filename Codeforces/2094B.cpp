#include<iostream>
#include<cmath>
using namespace std;


void sol(){
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    if (l == 0){
        cout << l << " " << l + m << '\n';
        return;
    }
    if(abs(l) >= m){
        cout << -m << " " << 0 << '\n';
        return;
    }
    cout << l << " " << l + m << '\n';
    
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