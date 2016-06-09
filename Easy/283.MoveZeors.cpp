/*Question:
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

Tag: Array, two Points
Similar Problem: 27
*/

/*思路:
直接将非零元素放到前面
*/

//Code:
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int sz = nums.size();
        
        for(auto num : nums)
            if(num != 0)
                nums[left++] = num;

        while(left < sz)
            nums[left++] = 0;
    }
};
