/*Question:
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Tags: Array
*/

/*思路：
法一：
空间复杂度为O(m+n);
1）借助两个vector，分别存储第几行第几列的元素是0
2）访问两个vector，将matrix中对应的元素设为0

//Code:
//方法一：
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        int row = matrix.size();
        int column = matrix[0].size();
        
        std::vector<bool> rowVec(row, false);
        std::vector<bool> colVec(column, false);
        
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < column; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    rowVec[i] = true;
                    colVec[j] = true;
                }
            }
            
        for(int i = 0; i < row; ++i)
        if(rowVec[i])
            for(int j = 0; j < column; ++j)
                matrix[i][j] = 0;
                
        for(int i = 0; i < column; ++i)
        if(colVec[i])
            for(int j = 0; j < row; ++j)
                matrix[j][i] = 0;
                
        return;
    }
};
