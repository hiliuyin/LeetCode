/*Question:
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:

A naive implementation of the above process is trivial. Could you come up with other methods?
What are all the possible results?
How do they occur, periodically or randomly?

Tags: Math
Similar Problems: 202
*/

/*思路:
1) 如果数值不为0，并且数值%9==0,返回9
2）返回数值%9的结果
*/

//Code:
//Code 1:
class Solution {
public:
    int addDigits(int num) {
        if(num % 9 == 0 && num != 0) return 9;
        return num% 9;
    }
};

//Code 2:
class Solution {
public:
    int addDigits(int num) {
        return (num == 0)? 0 : (num - 1) % 9 + 1;
    }
};
