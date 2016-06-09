/*Question:
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

Tag: Array
SP: 118
*/

/**/

//Code:
//Code 1: 
// 当rowIndex值很大的时候会产生runtime error。
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0)
            return {};
        vector<int> result;
        
        for(int i = 0; i <= rowIndex; ++i)
        {
            result.push_back(1);
            int right = result.size() - 2;
            int j = 1;
            
            for(;j <= (rowIndex + 1) / 2; ++j, --right)
                result[j] = result[right] + result[right - 1];
            
            right = 1;
            for(; j < result.size() - 1; ++j, --right)
                result[j] = result[j + right];
        }
        return result;
    }
};
