class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        long f[(int)1e5+1];
        int mod = 1e9 + 7;
        f[0] = 0;
        int n = nextVisit.size();
        for(int i = 1; i < n; i++){
            f[i] = (long)(2 + 2 * f[i-1] - f[nextVisit[i-1]] + mod) % mod;
        }
        return f[n-1];
    }
};