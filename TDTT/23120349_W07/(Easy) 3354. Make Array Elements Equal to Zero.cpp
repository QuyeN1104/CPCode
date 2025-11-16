class Solution {
public:
    int countValidSelections(vector<int>& a) {
        int cnt = 0;
        int n = a.size();

        for(int i = 0; i < n; i++){
            if(a[i]) continue;
            for(int st = -1; st < 2; st+=2){
                int step = st;
                vector<int> nums = a;
                int j = i;
                for(j; j >= 0 && j < n; ){
                    if(nums[j]){
                        nums[j]-=1;
                        step = step == 1 ? -1 : 1;
                    }
                    j += step;

                }
                bool f = true;
                for(int u = 0; u < n; u++){
                    if(nums[u]){
                        f = false;
                        break;
                    }
                }
                if(f){
                    cnt++;
                }


            }
        }
        return cnt;
    }
};