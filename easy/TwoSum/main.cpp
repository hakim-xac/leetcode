/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

class Solution {
public:
    static std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for(auto it{nums.begin()}, ite{nums.end()}; it != ite; ++it){
            for(auto jt{std::next(it)}, jte{ite}; jt != jte; ++jt){
                auto dist_first{ static_cast<int>(std::distance(nums.begin(), it)) };
                auto dist_second{ static_cast<int>(std::distance(nums.begin(), jt)) };
                if(*it + *jt == target) return { dist_first, dist_second };
            }
        }
        return std::vector<int>{ 0, 0 };
    }
};



TEST(twoSum, test1){
	std::vector<int> input{ 2,7,11,15 };
	int target{ 9 };
	auto vec{Solution::twoSum(input, target)};
	EXPECT_EQ(vec[0], 0);
	EXPECT_EQ(vec[1], 1);	
}

TEST(twoSum, test2){
	std::vector<int> input{ 3, 2, 4 };
	int target{ 6 };
	auto vec{Solution::twoSum(input, target)};
	EXPECT_EQ(vec[0], 1);
	EXPECT_EQ(vec[1], 2);	
}

TEST(twoSum, test3){
	std::vector<int> input{ 3, 3 };
	int target{ 6 };
	auto vec{Solution::twoSum(input, target)};
	EXPECT_EQ(vec[0], 0);
	EXPECT_EQ(vec[1], 1);	
}

int main(int argc, char ** argv){
	
		testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	
	return 0;
}