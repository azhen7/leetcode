#include <string>
using namespace std;

class Solution {
    public:
        int getRomanNum(char c)
        {
            switch (c)
            {
                case 'I':
                    return 1;
                case 'V':
                    return 5;
                case 'X':
                    return 10;
                case 'L':  
                    return 50;
                case 'C':
                    return 100;
                case 'D':
                    return 500;
                case 'M':
                    return 1000;
                default:
                    return 0;
            }
        }
        int romanToInt(string s) {
            int sum = 0;
            for (int i = 0; i < s.length(); i++)
            {
                if (getRomanNum(s[i]) < getRomanNum(s[i + 1])
                    && getRomanNum(s[i + 1]) <= getRomanNum(s[i]) * 10)
                {
                    sum += getRomanNum(s[i + 1]) - getRomanNum(s[i]);
                    i++;
                }
                else
                    sum += getRomanNum(s[i]);
                    
            }
            return sum;
        }
};
