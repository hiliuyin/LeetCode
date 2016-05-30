/* Question:
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

/* 思路：
贪心算法
输入：[6,1,3,2,4,7]
输出：7
1) 如果当前元素比buy小，buy = prices[i]
2) 如果当前元素比sell大，sell = buy = prices[i]
3) 如果当前元素不是数组中的最后一个元素，且该元素后面的元素比sell值小，则卖出股票，令buy的值为当前元素后面的元素值
Note：在循环结束后，处理最后一次卖出股票的情况
*/

// Code:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        
        int buy = prices[0];
        int sell = -1;
        int result = 0;
        
        for(int i = 1; i < prices.size();)
        {
            if(prices[i] < buy)
                buy = prices[i];
            else if(prices[i] > sell)
                sell = prices[i];
                
            if(++i != prices.size() && prices[i] < sell)
                {
                    result += sell - buy;
                    buy = prices[i];
                    sell = -1;
                }
        }
        
        if(sell > 0) result += sell - buy;
        
        return result;
    }
};

// 贪心没错，但是可以优化
    int maxProfit(vector<int>& prices) {
        std::vector<int>::size_type sz = prices.size();
        if (sz <= 1) return 0;

        int profit = 0;
        for (std::vector<int>::size_type i = 0; i < sz -1; ++i)
        {
            if (prices[i] < prices[i+1])
                profit += prices[i+1] - prices[i];
        }
        return profit;
    }
