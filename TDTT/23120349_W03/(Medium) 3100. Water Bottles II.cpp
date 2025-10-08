class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        long long ans = 0;
        int numEmpties = 0;
        while(numBottles > 0) {
            // cout << numBottles << endl;
            ans += numBottles;
            numEmpties += numBottles;
            numBottles = 0;
            while (numExchange <= numEmpties){
                numEmpties -= numExchange++;
                numBottles++;
            }
            
        }

        return ans ;
    }
};