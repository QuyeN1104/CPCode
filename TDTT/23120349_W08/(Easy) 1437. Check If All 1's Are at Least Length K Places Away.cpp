class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt = 0;
        bool isHead = true;
        for(auto num : nums){
            if(num == 0){

                cnt++;

            } else {

                if(isHead){
                    isHead = false;
                    cnt = 0;
                    continue;
                }

                if(cnt < k ){
                    return false;
                }
                cnt = 0;
            }
        }
        return true;
    }
};