class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, cur = numBottles;
        while(cur >= numExchange){
            ans += cur / numExchange;
            cur = (cur / numExchange)+(cur % numExchange);
        }
        return ans;
    }
};