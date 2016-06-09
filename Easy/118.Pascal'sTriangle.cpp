/*Question:
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

Tags: Array
Similar Problems: 119
*/

/*思路:
每到新的一层，都根据上一层的元素求得。
小技巧：由于每一行的元素都是对称的，可以先求得每一行的前半部分，然后将前半部分拷贝到后半部分
*/

//Code:
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows <= 0)
            return {};
        std::vector<std::vector<int>> result(1, {1});
        
        for(int curRow = 2;curRow <= numRows; ++curRow)
        {
            std::vector<int> cur(1, 1);
            
            int index = 1;
            while(index < (curRow + 1) / 2)
            {
                cur.push_back(result[curRow - 2][index - 1] + result[curRow-2][index]);
                ++index;
            }
            
            int distance = (curRow % 2 == 0)? 1 : 2;
            while(index < curRow)
            {
                cur.push_back(cur[index - distance]);
                ++index;
                distance += 2;
            }
            
            result.push_back(cur);
        }
        return result;
    }
};
