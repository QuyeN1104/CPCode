#include<iostream>
#include<vector>
using namespace std;


void sol(){
   int n; cin >> n;
   vector<int> a(n);
   int s_n1 = 0;
   int s_0 = 0;
   for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0){
            s_0++;
        } else if(a[i] == -1){
            s_n1++;
        }
   }
   cout << s_0 + 2*(s_n1 % 2) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}