/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
*/

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/
#include <iostream>
#include <string>
#include <gtest/gtest.h>


class Solution {
public:
    static double myPow(double x, int n) {
		long long num{ n };
		if(num == 0) return 1;
		if(num == 1) return x;
        if(num < 0) {
			num = -num;
			x = 1 / x;
		}
		double result{1};
		for(; num; (num >>= 1) ){
			if(num & 1){
				result *= x;
				--num;
			}
			x *= x;
		}
		return result;
    }
};

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

TEST(myPow, test1){
	
	double input_x{ 2.0 };
	int input_n{ 10 };
	int accuracy{ 10000 };
	double result{ floor(Solution::myPow(input_x, input_n) * accuracy) / accuracy };
	EXPECT_EQ(result, 1024);
	
}

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

TEST(myPow, test2){
	
	double input_x{ 2.10 };
	int input_n{ 3 };
	
	int accuracy{ 10000 };
	double result{ floor(Solution::myPow(input_x, input_n) * accuracy) / accuracy };
	EXPECT_EQ(result, 9.261);
	
}

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

TEST(myPow, test3){
	
	double input_x{ 2.0 };
	int input_n{ -2 };
	
	int accuracy{ 10000 };
	double result{ floor(Solution::myPow(input_x, input_n) * accuracy) / accuracy };
	EXPECT_EQ(result, 0.25);
	
}

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

TEST(myPow, test4){
	
	double input_x{ 1.0 };
	int input_n{ -2147483648 };
	
	int accuracy{ 10000 };
	double result{ floor(Solution::myPow(input_x, input_n) * accuracy) / accuracy };
	EXPECT_EQ(result, 1.0);
	
}

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

TEST(myPow, test5){
	
	double input_x{ 2.0 };
	int input_n{ -2147483648 };
	
	int accuracy{ 10000 };
	double result{ floor(Solution::myPow(input_x, input_n) * accuracy) / accuracy };
	EXPECT_EQ(result, 0.0);
	
}


/**********************************************************************/
/**********************************************************************/
/**********************************************************************/


int main(int argc, char ** argv){
	
		testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	
	return 0;
}