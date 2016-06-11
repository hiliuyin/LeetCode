/*Question:
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

SP: 54
*/

/*思路:
*/

//Code: 

//Code 2:
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > mat(n, vector<int>(n));
        int r = 0, c = -1, x = 1;
        const int g[5] = { 0, 1, 0, -1, 0 };
        for (int b = 0, i = 0; n > 0; n -= (b ^= 1), i = (++i % 4)) {
            for (int s = 0; s < n; s++) {
                mat[r += g[i]][c += g[i+1]] = x++;
            }
        }
        return mat;
    }
};
