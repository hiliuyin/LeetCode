/*Question:
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

/*思路:
递归实现
*/

//Code:
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
            
        std::vector<string> mapping{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        
        letterCombinationsHelper(mapping, digits, 0, "", result);
        
        return result;
    }
private:
    void letterCombinationsHelper(std::vector<string>& mapping, string digits, int index, string resStr, vector<string>& result)
    {
        if(index == digits.size())
            result.push_back(resStr);
        else
        {
            string curStr = mapping[digits[index] - '2'];
            for(int i = 0, sz = curStr.size(); i < sz; ++i)
                letterCombinationsHelper(mapping,digits,index + 1, resStr + curStr[i], result);
        }
    }
};
