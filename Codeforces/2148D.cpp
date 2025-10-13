#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void solution(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end(),[](int x, int y){
        if(x % 2 == 0 && y % 2) return false;
        if(x % 2 && y % 2 == 0) return true;
        if(x % 2 == 0&& y % 2 == 0) return x < y;
        return x < y;
    });

    if(a[0] % 2 == 0){
        cout <<  0 << '\n'; // no toggle
        return;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2){
            cnt += 1;
        }
        else{
            break;
        }
    }
    long long sum = 0;
    for (int  i = cnt/2; i < n; i++){
        sum += a[i];
    }
    cout << sum << '\n';

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--){
        solution();
    }
}