/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits>
#include <gtest/gtest.h>


//Definition for singly-linked list.

class Solution {
public:
	static double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

		size_t left_size{ nums1.size() };
		size_t right_size{ nums2.size() };

		for (size_t left{}, right{ left_size }; left <= right; ) {

			size_t middle_left{ left + ((right - left) / 2) };
			size_t middle_right{ left_size + ((right_size - left_size) + 1) / 2 - middle_left };

			int maxLeftA{ middle_left ? nums1[middle_left - 1] : std::numeric_limits<int>::min() };
			int minRightA{ (middle_left == left_size) ? std::numeric_limits<int>::max() : nums1[middle_left] };
			int maxLeftB{ (middle_right == 0) ? std::numeric_limits<int>::min() : nums2[middle_right - 1] };
			int minRightB{ (middle_right == right_size) ? std::numeric_limits<int>::max() : nums2[middle_right] };

			if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
				if ((left_size + right_size) % 2 == 0)
					return (std::max(maxLeftA, maxLeftB) + std::min(minRightA, minRightB)) / 2.0;
				return std::max(maxLeftA, maxLeftB);
			}
			else if (maxLeftA > minRightB) right = middle_left - 1;
			else left = middle_left + 1;

		}

		return 0.0;
	}

};

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

TEST(MedianOfTwoSortedArrays, test1) {

	std::vector<int> first{ 1, 3 };
	std::vector<int> second{ 2 };
	EXPECT_EQ(Solution::findMedianSortedArrays(first, second), 2.0);
}

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

TEST(MedianOfTwoSortedArrays, test2) {

	std::vector<int> first{ 3, 4 };
	std::vector<int> second{ 1, 2 };
	EXPECT_EQ(Solution::findMedianSortedArrays(first, second), 2.5);
}

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

TEST(MedianOfTwoSortedArrays, test3) {

	std::vector<int> first{ 1, 3 };
	std::vector<int> second{ 2, 4 };
	EXPECT_EQ(Solution::findMedianSortedArrays(first, second), 2.5);
}


/**********************************************************************/
/**********************************************************************/
/**********************************************************************/


int main(int argc, char** argv) {

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

	return 0;
}