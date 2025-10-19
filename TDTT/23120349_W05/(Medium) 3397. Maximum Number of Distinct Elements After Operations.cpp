class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        map<int,int> mp; // mp là trường hợp nhỏ nhất có thể trừ xuống
        vector<int> v;
        for(int i = 0; i < nums.size(); i++){
            int& num = nums[i];
            if(i == 0){
                mp[num] = -k;
                v.push_back(num + mp[num]++);
            } else {
                if(!mp[num]){
                    mp[num] = max(-k, v[i-1] + 1 - num);
                    // cout << num << " " << v[i-1] << " f\n";
                }
                if(mp[num] > k) v.push_back(num + k);
                else {v.push_back(num + mp[num]++);}

            }
            // cout << num << " " << " " << mp[num] - 1 << endl;
        }

        // for(auto num: v) cout << num << " ";
        set<int> s(v.begin(), v.end());
        return s.size();
    }
};