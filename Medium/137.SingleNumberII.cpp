/*
Given an array of integers, every element appears three times except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Tags: Bit Manipulation
*/

//Code:
    int singleNumber(vector<int>& nums) {
        std::map<int, int> m;
        for(auto&& num : nums)
        {
            if(m.find(num) != m.end())
                ++m[num];
            else 
                m[num] = 1;
        }
        
        auto iter = std::find_if(m.begin(), m.end(),
                                [&](const std::pair<int, int>& p)
                                    {return p.second != 3;});

        return iter->first;
    }
