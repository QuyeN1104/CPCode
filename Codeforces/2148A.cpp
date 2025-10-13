#include<iostream>
using namespace std;

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        int x, n;
        cin >> x >> n;
        cout << (n % 2 ? x : 0) << '\n';
    }
}