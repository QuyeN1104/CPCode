#include<iostream>
using namespace std;


void sol(){
    int n, m, l, r;
    cin >> n >> m >> l >> r;
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