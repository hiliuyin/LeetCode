/* Question:
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/* Method:
借助数字自身异或结果为0的属性
*/

// code:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int result = 0;
        for(auto&& num: nums)
            result ^= num;
        return result;
    }
};
