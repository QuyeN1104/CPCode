class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;
        for(auto s: bank){
            int cnt = 0;
            for(auto c: s){

                if(c == '1'){
                    cnt +=1;
                }
            }
            if(cnt){
                ans += cnt * prev;
                prev = cnt;
            }
        }
        return ans;
    }
};