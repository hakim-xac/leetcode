/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/
#include <iostream>
#include <string>
#include <gtest/gtest.h>


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* out{nullptr};
		while(l1 || l2){
			int v1{ l1 ? l1->val : 0 };
			int v2{ l2 ? l2->val : 0 };
			if(!out) [[unlikely]] out = new ListNode(v1 + v2);
			else {
				int val{ v1 + v2 };
				if(out->val >= 10){
					out->val -= 10;
					++val;
				}
				ListNode* tmp{ new ListNode(val, out) };
				out = tmp;
			}
			
			if(l1) l1 = l1->next;
			if(l2) l2 = l2->next;
		}
		while (out && out->val >= 10) {
			out->val -= 10;
			ListNode* tmp{ new ListNode(1, out) };
			out = tmp;
		}

		reverseListNode(out);
		return out;
    }

	static void reverseListNode(ListNode*& ls) {

		ListNode* prev{};
		ListNode* curr{ ls };
		ListNode* next{ ls->next };
		while (next) {
			curr->next = std::exchange(prev, curr);
			curr = next;
			next = curr->next;
		}
		curr->next = prev;
		ls = curr;
	}

	static void deleteListNode(ListNode* ls) {
		while (ls) {
			ListNode* tmp{ std::exchange(ls, ls->next) };
			delete tmp;
		}
	}
};

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

TEST(addTwoNumbers, test1){
	
	ListNode* first_list = new ListNode(3);
	first_list = new ListNode(4, first_list);
	first_list = new ListNode(2, first_list);
	
	ListNode* second_list = new ListNode(4);
	second_list = new ListNode(6, second_list);
	second_list = new ListNode(5, second_list);
	
	ListNode* pattern_list = new ListNode(8);
	pattern_list = new ListNode(0, pattern_list);
	pattern_list = new ListNode(7, pattern_list);
	
	ListNode* output_list{ Solution::addTwoNumbers(first_list, second_list) };
	ASSERT_TRUE(output_list);
	while(output_list && pattern_list){
		EXPECT_EQ(output_list->val, pattern_list->val);
		output_list = output_list->next;
		pattern_list = pattern_list->next;
	}
	Solution::deleteListNode(first_list);
	Solution::deleteListNode(second_list);
	Solution::deleteListNode(pattern_list);
	Solution::deleteListNode(output_list);
}



/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

TEST(addTwoNumbers, test2) {

	ListNode* first_list = new ListNode(0);

	ListNode* second_list = new ListNode(0);

	ListNode* pattern_list = new ListNode(0);

	ListNode* output_list{ Solution::addTwoNumbers(first_list, second_list) };
	ASSERT_TRUE(output_list);
	while (output_list && pattern_list) {
		EXPECT_EQ(output_list->val, pattern_list->val);
		output_list = output_list->next;
		pattern_list = pattern_list->next;
	}
	Solution::deleteListNode(first_list);
	Solution::deleteListNode(second_list);
	Solution::deleteListNode(pattern_list);
	Solution::deleteListNode(output_list);
}


/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

TEST(addTwoNumbers, test3) {

	ListNode* first_list = new ListNode(9);
	first_list = new ListNode(9, first_list);
	first_list = new ListNode(9, first_list);
	first_list = new ListNode(9, first_list);
	first_list = new ListNode(9, first_list);
	first_list = new ListNode(9, first_list);
	first_list = new ListNode(9, first_list);

	ListNode* second_list = new ListNode(9);
	second_list = new ListNode(9, second_list);
	second_list = new ListNode(9, second_list);
	second_list = new ListNode(9, second_list);

	ListNode* pattern_list = new ListNode(1);
	pattern_list = new ListNode(0, pattern_list);
	pattern_list = new ListNode(0, pattern_list);
	pattern_list = new ListNode(0, pattern_list);
	pattern_list = new ListNode(9, pattern_list);
	pattern_list = new ListNode(9, pattern_list);
	pattern_list = new ListNode(9, pattern_list);
	pattern_list = new ListNode(8, pattern_list);

	ListNode* output_list{ Solution::addTwoNumbers(first_list, second_list) };
	ASSERT_TRUE(output_list);
	while (output_list && pattern_list) {
		EXPECT_EQ(output_list->val, pattern_list->val);
		output_list = output_list->next;
		pattern_list = pattern_list->next;
	}
	Solution::deleteListNode(first_list);
	Solution::deleteListNode(second_list);
	Solution::deleteListNode(pattern_list);
	Solution::deleteListNode(output_list);
}


/**********************************************************************/
/**********************************************************************/
/**********************************************************************/


int main(int argc, char ** argv){
	
		testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	
	return 0;
}