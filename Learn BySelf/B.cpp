#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 1;
int a[maxn];
int b[maxn];

void sol(){
    // for(int i = 0; i <= n + 1; i++) a[i
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int k, l, r;
        cin >> k >> l >> r;
        if(k == 0){
            b[l] += 1;
            b[r+1] -= 1;
        } else if(k == 1){
            b[l] -= 1;
            b[r+1] += 1;
        } else if (k == 2){
            a[l] += 1;
            b[l] += 1-l;
            b[r+1] -= 1 - l;
            a[r+1] -=1;
        } else {
            a[l] -= 1;
            b[l] -= 1-l;
            b[r+1] += 1 - l;
            a[r+1] +=1;
        }

    }
    int A = 0, B = 0;
    for(int i = 1; i <= n; i++){
        A += a[i];
        B += b[i];
        cout << A*i + B << " ";
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sol();
    return 0;
}