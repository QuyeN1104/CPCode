#include <iostream>
#include<vector>

using namespace std;

void sol(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2), b(n + 2);
    a[0] = 0; b[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    a[n+1] = m;
    b[n+1] = b[n];

    int cnt = 0;

    for(int i = 1; i <= n; i++){
       if(((a[i] - a[i-1]) % 2 == 0 && b[i] == b[i-1]) || ((a[i] - a[i-1]) % 2 == 1 && b[i] != b[i-1])){
        cnt += a[i] - a[i-1];
       }
       else {
        cnt += a[i] - a[i-1] - 1;
       }
    }
    cnt += m - a[n];
    cout << cnt << '\n';

}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
}