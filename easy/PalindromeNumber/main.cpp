/*
Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

class Solution {
public:
    static bool isPalindrome(int x) {
        if (x < 0) return false;
        long long reversed{};
        for(long long tmp{x}; tmp; tmp /= 10) {
           reversed = reversed *10+tmp%10;
            
        }
        return x == reversed;
    }
};



TEST(isPalindrome, test1){
	int input{ 121 };
	EXPECT_EQ(Solution::isPalindrome(input), true);	
}
TEST(isPalindrome, test2){
	int input{ -121 };
	EXPECT_EQ(Solution::isPalindrome(input), false);	
}
TEST(isPalindrome, test3){
	int input{ 10 };
	EXPECT_EQ(Solution::isPalindrome(input), false);	
}

int main(int argc, char ** argv){
	
		testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	
	return 0;
}