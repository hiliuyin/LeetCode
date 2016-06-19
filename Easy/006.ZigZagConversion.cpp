/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

//Code:
//Code 1:
    string convert(string s, int numRows) {
        if(s.empty() || numRows < 2) return s;
        std::vector<std::string> vec(numRows);
        
        int row = 0;
        bool bUp = false;
        for(auto&& ch : s)
        {
            vec[row] += ch;
            
            if(!bUp)
            {
                ++row;
                if(row == numRows)
                {
                    row = numRows - 2;
                    bUp = true;
                }
            }
            else
            {
                --row;
                if(row < 0)
                {
                    row = 1;
                    bUp = false;
                }
            }
        }
        
        std::string result;
        for(int i = 0; i < numRows; ++i)
            result += vec[i];
        return result;
    }
//Code 2:
std::string convert(std::string s, int nRows)
{
    if (s.size() <= 1 || nRows <= 1) return s;

    std::string result;

    for (int i = 0, iEnd = s.size(); i < iEnd; i += nRows*2-2)
        result.append(1, s[i]);

    for (int r = 1; r < nRows-1; ++r)
    {
        const int steps = 2 * nRows - 2 * r - 2;
        for (int i = r, iEnd = s.size(), k = 0; i < iEnd;)
        {
            result.append(1, s[i]);
            if (k++ % 2 == 0)
                i += steps;
            else
                i += r*2;
        }
    }

    for (int i = nRows - 1, iEnd = s.size(); i < iEnd; i += nRows * 2 - 2)
        result.append(1, s[i]);

    return result;
}
