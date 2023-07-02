/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <gtest/gtest.h>


class Solution {
public:
    static int numIslands(std::vector<std::vector<char>>& grid) {
        size_t row{ grid.size() };
        size_t col{ grid[0].size() };
		int count_island{};
		for(size_t i{}, ie{row}; i != ie; ++i){
			for(size_t j{}, je{col}; j != je; ++j){
				if(grid[i][j] == '1' && compress(grid, i, j)){					
					++count_island;
				}
			}
		}
		return count_island;
    }
	
	static bool compress(std::vector<std::vector<char>>& grid, size_t i, int j){
		if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return true;
		
        if (grid[i][j] == '0') return true;        
        grid[i][j] = '0';
        return compress(grid, i+1, j)
			&& compress(grid, i-1, j)
			&& compress(grid, i, j+1)
			&& compress(grid, i, j-1);
	}
};

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

TEST(numIslands, test1){
	
	std::vector<std::vector<char>> input{
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'}		
	};
	
	EXPECT_EQ(Solution::numIslands(input), 1);
	
}

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

TEST(numIslands, test2){
	
	std::vector<std::vector<char>> input{
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'}		
	};
	
	EXPECT_EQ(Solution::numIslands(input), 3);
	
}


/**********************************************************************/
/**********************************************************************/
/**********************************************************************/


int main(int argc, char ** argv){
	
		testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	
	return 0;
}