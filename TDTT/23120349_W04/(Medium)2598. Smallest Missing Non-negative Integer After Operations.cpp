class Solution {
public:
    int _mod(int a, int v){
        if(a >= 0){
            return a % v;
        } else {
            return ((a % v) + v) % v;
        }
    }
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> a(100001,0);
        for(int i = 0; i < nums.size() ; i++){
                int mod = _mod(nums[i], value);
                cout << mod << " ";
                if(a[mod] && mod + value*a[mod] < 100001){
                    a[mod + value*a[mod]] = 1;
                }
                a[mod]++;
        }
        cout << endl;

        for(int i = 0; i < 100001; i++) {
            cout << a[i] << " ";
            if(!a[i]){
                return i;
            }
        }
        return 1;
    }
};