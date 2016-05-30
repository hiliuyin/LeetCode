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
        
        int result = nums[0];
        for(int i = 1; i < nums.size(); ++i)
            result ^= nums[i];
        return result;
    }
};

int result = 0;
for (vector<int>::size_type i = 0; i < nums.size(); ++i) // 或者用const_iterator
    result ^= nums[i];
return result;

// 如果用modern c++
int result = 0;
for (auto&& num : nums)
    result ^= num;
return result;


