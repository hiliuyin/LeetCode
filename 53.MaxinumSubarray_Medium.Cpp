/* Question:
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

/* 思路：
从前往后将所有元素相加，如果加完后curSum值为负，则令sum=0；
如果curSum>result，令result=curSum。

Note：如果最后result的值为0，则需要处理数组中可能所有元素为负数的情况，扫描数组，并令result最终为数组中的最大值
*/

// Code:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int result = 0;
        int curSum = 0;
        for(auto&& num: nums)
        {
            curSum += num;
            if(curSum < 0) curSum = 0;
            else if(curSum > result) 
                result = curSum;
        }
        
        // Handle the situation that all the elements in the array are negative
        if(result == 0)
        {
            result = nums[0];
            for(int i = 1; i < nums.size(); ++i)
            if(nums[i] > result) result = nums[i];
        }
        
        return result;
    }
};
