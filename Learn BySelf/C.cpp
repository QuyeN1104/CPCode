#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long

void sol(){
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1, {});

    for(int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sol();
    return 0;
}