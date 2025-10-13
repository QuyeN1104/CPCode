#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<int, int> mp, cnt;

void sol() {
    // Input
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    
    // Check equal frequency or not

    mp.clear();
    for (auto i: a){
        mp[i]++;
    }

    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->second % k){
            cout << 0 << '\n';
            return;
        }
    }

    int ans = 0;

    int l = 0;
    cnt.clear();
    for(int r = 0; r < n; r++){
        if(++cnt[a[r]] > mp[a[r]] / k){
            while(cnt[a[r]] > mp[a[r]] / k){
                cnt[a[l]]--;
                l++;
            }
        }
        ans += (r - l + 1);

    }
    cout << ans << '\n';




}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
}