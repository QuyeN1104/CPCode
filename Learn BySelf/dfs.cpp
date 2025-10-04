#include<iostream>
#include<format>
#include"bits/stdc++.h"
using namespace std;

const int maxn = 2e5+1;
vector<int> dict(maxn, (int)1e9);
vector<int> parent(maxn, -1);
vector<int> tin(maxn, -1);
vector<int> tout(maxn, -1);
vector<int> visited(maxn, false);

int n = 9;

int cnt = 1;
vector<vector<int>> create_adjacent_matrix(){
    vector<vector<int>> adj;
    adj.assign(n, {});
    adj[1] = {2, 4};
    adj[2] = {1, 3, 5};
    adj[3] = {2, 6};
    adj[4] = {1, 5};
    adj[5] = {2, 4, 6, 7};
    adj[6] = {3, 5, 8};
    adj[7] = {5, 8};
    adj[8] = {6,7};
    return adj;
}

void bfs(int v, vector<vector<int>> adj){
    dict[v] = 0;
    parent[v] = -1;
    visited[v] = true;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int top = q.front();
        cout << "top" << top << endl;
        q.pop();
        for(auto u: adj[top]){
            if (!visited[u]){
                dict[u] = dict[top] + 1;
                parent[u] = top;
                visited[u] = true;
                q.push(u);
            }
        }

    }
}

void dfs(int v,int par, vector<vector<int>> adj = create_adjacent_matrix()){
    tin[v] = cnt++;
    visited[v] = true;
    parent[v] = par;
    for(auto s: adj[v]){
        if(!visited[s]){
            dfs(s, v, adj);
        }
    }
    tout[v] = cnt++;
}

// DSU
struct DSU {
    vector<int> parent, sz;
    DSU(int n){
        parent.resize(n+1);
        sz.assign(n+1, 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        a=find(a); b=find(b);
        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);
            parent[b] = parent[a];
            sz[a] += sz[b];
        }
    }

};




int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vector<vector<int>> adj = create_adjacent_matrix();

    cout << "DANH SACH CAC CANH\n";
    for(int i = 1; i < n; i++){
        for(auto j: adj[i]){
            if (i < j){
                cout << i << " " << j << "\n";
            }
        }
    }
    cout << '\n';

    // bfs(1, adj);
    // for(int i = 1; i < n; i++){
    //     cout << i << ' ' << dict[i] << '\n';
    // }

    cout << "-------------" << "DFS" << "-----------------\n";
    dfs(1, 0);
    for(int i = 1; i < n; i++){
        cout << i << " " << tin[i] << " " << tout[i] << endl;
    }

    cout << "-------------------DSU-----------------\n";
    DSU dsu(8);
    for(int i = 1; i < n; i++){
        for(auto j: adj[i]){
            if (i < j){
                dsu.unite(i, j);
            }
        }
    }
    
    for(int i = 1; i < n; i++){
        cout << dsu.parent[i] << " " <<  dsu.sz[i] << endl;
    }

}