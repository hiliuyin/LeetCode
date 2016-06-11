/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

/*思路:
由左－>右，上－>下，右－>左，下->上的顺序访问二维数组
*/

//Code:
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> results;
        if(matrix.size() < 1)
            return results;
            
        int sx = 0, sy = 0, ex = matrix[0].size(), ey = matrix.size();
        
        while(sx < ex || sy < ey)
        {
            // right
            if(sy < ey)
            {
                for(int i = sy, j = sx; j < ex; ++j)
                    results.push_back(matrix[i][j]);
                ++sy;
            }
            
            // down
            if(sx < ex)
            {
                for(int i = sy, j = ex-1; i < ey; ++i)
                    results.push_back(matrix[i][j]);
                --ex;
            }
            
            // left
            if(sy < ey)
            {
                for(int i = ey - 1, j = ex - 1; j >= sx; --j)
                    results.push_back(matrix[i][j]);
                --ey;
            }
            
            // up
            if(sx < ex)
            {
                for(int i = ey - 1, j = sx; i >= sy; --i)
                     results.push_back(matrix[i][j]);
                ++sx;
            }
        }
        return results;
    }
};
