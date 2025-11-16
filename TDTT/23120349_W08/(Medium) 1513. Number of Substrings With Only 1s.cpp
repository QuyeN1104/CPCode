class Solution {
public:
    int numSub(string s) {
        int mod = 1e9 + 7;

        int ans = 0;
        long long cur = 0;
        for(auto c:s){
            if(c == '0'){
                if(cur){
                    ans = ( ans + (cur) * (cur + 1) / 2 ) % mod; 
                    cur = 0;
                }
            } else {
                cur = (cur + 1) % mod;
            }

        }
         ans = ( ans + (cur) * (cur + 1) / 2 ) % mod; 
        return ans;

    }
};