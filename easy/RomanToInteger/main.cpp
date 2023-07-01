/*
oman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/
#include <iostream>
#include <map>
#include <string>
#include <gtest/gtest.h>

class Solution {
public:
    static int romanToInt(std::string s) {
        static std::map<char, int> base{
            {'M', 1000},
            {'D', 500},
            {'C', 100},
            {'L', 50},
            {'X', 10},
            {'V', 5},
            {'I', 1}
        };
        if(s.length() == 0) return 0;
        if(s.length() == 1) return base.at(s[0]);

        int result{};
        for(size_t i{}; i != s.length(); ++i){
            int cur{base[s[i]]};
            int next{base[s[i+1]]};
            if(cur < next){
                result += next - cur;
                ++i;
            } 
            else {
                result += cur;
            }
        }
        return result;
    }
};

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

TEST(romanToInt, test1){
	
	std::string input{"III"};	
	EXPECT_EQ(Solution::romanToInt(input), 3);
}

TEST(romanToInt, test2){
	
	std::string input{"LVIII"};	
	EXPECT_EQ(Solution::romanToInt(input), 58);
}

TEST(romanToInt, test3){
	
	std::string input{"MCMXCIV"};	
	EXPECT_EQ(Solution::romanToInt(input), 1994);
}

int main(int argc, char ** argv){
	
		testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	
	return 0;
}