/*Question:
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

Subscribe to see which companies asked this question

Tags: Binary Search Tree
Similar Problems: (E) Contains Duplicate (E) Contains Duplicate II
*/

/*思路:
*/

//Code:
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int sz = nums.size();
        std::vector<std::pair<long, int>> mapping; //The first type should be long

        for (int i = 0; i < sz; ++i)
            mapping.push_back(std::make_pair(nums[i], i));
        
        std::sort(mapping.begin(), mapping.end());
        
        for (int i = 0; i < sz; ++i)
        {
            for (int j = i + 1; j < sz && mapping[j].first - mapping[i].first <= t; ++j)
            {
                if (std::abs(mapping[i].second - mapping[j].second) <= k)
                    return true;
            }
        }

        return false;
    }
};
