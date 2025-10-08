#include<iostream>
#include"bits/stdc++.h"
using namespace std;
#define int long long

struct Fenwick {
    int n;
    vector<long long> f;
    Fenwick(int n) : n(n), f(n+1, 0) {}

    void add(int i, long long v) {
        for(; i <= n; i += i & -i){
            f[i] += v;
        }
    }

    long long sum(int i){
        long long s = 0;
        for(; i > 0; i -= i & -i){
            s += f[i];
            return s;
        }
    }

    long long range_sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
    
};

struct SegTree {
    int n;
    vector<long long> st;
    SegTree(int n) : n(n) , st(n+1, 0) {}

    void build(vector<int>& a, int id, int l, int r) {
        if(l == r){
            st[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2*id, l, mid);
        build(a, 2*id + 1, mid+1, r);
        st[id] = st[id*2] + st[2*id + 1];
    }

    void update(int id, int l,  int r, int pos, int val) {
        if(l == r){
            st[id] = val;
            return;
        }
        int mid = (l+r) >> 2;
        if(pos <= mid){
            update(2*id, l, mid, pos, val);
        } else {
            update(2*id + 1, mid +1, r, pos, val);
        }
        st[id] = st[id*2] + st[2*id + 1];
    }

    long long query(int id, int l, int r, int ql , int qr) {
        if(qr < l || ql > r) return 0;
        if(ql <= l && qr >= r) return st[id];
        int mid = l + r >> 2;
        return query(id*2, l, mid, ql, qr) + query(2*id+1, mid+1, r, ql, qr);
    }
};


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}