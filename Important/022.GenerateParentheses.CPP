/*Question:
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

Tags: Backtrackinig, string
Similar Problems: 20, 32, 301
*/

/*思路：
借助递归
Note：实现过程中用到了lambda递归
*/

//Code:
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n <= 0)
            return {};
        std::vector<std::string> result;
        
        std::function<void(std::vector<std::string>&, std::string, int, int)> helper = 
        [&](std::vector<std::string>& result, std::string paths, int left, int right)
        {
            if(left == n && right == n)
            {
                result.push_back(paths);
                return;
            }
            
            if(left < n)
                helper(result, paths + '(', left + 1, right);
            if(left > right)
                helper(result, paths + ')', left, right + 1);
        };
        
        helper(result, "", 0, 0);
        return result;
    }
};
