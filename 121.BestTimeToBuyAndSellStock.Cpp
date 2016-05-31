/* Question:
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Tag: Array, Dynamic programming
*/

/*思路：
1）当前元素比buy小，令buy=prices[i], sell=-1;
2）当前元素比sell大，令sell=prices[i]；
3）求当前的获利cur=sell-buy，如果profit<cur，令profit=cur
*/

// Code:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::vector<int>::size_type sz = prices.size();
        if(sz <= 1) return 0;

        int profit = 0;
        int buy = prices[0];
        int sell = -1;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] < buy)
            {
                buy = prices[i];
                sell = -1;
            }
            else if(prices[i] > sell)
                sell = prices[i];
                
            int curValue = sell - buy;
            if(curValue > profit) 
                profit = curValue;
         }
        return profit;
    }
};
