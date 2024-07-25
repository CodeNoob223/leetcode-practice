#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
  int longestOnes(std::vector<int> &nums, int k)
  {
    int start = 0;
    int end = 0;
    int max = 0;
    while (end < nums.size())
    {
      if (nums[end] == 0)
      {
        k--;
        while (k < 0)
        {
          if (nums[start] == 0)
          {
            // return the 1 back to k
            k++;
          }
          start++;
        }
      }
      max = std::max(max, end - start + 1);
      end++;
    }

    return max;
  }
};

void test(std::vector<int> &nums, int k)
{
  Solution sol = Solution();
  std::cout << "Input: ";
  for (int el : nums)
  {
    std::cout << el << " ";
  }
  std::cout << std::endl;
  std::cout << "Output: ";
  std::cout << sol.longestOnes(nums, k) << std::endl;
}

int main()
{
  std::vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;
  /*
  Output: 6
  Explanation: [1,1,1,0,0,1,1,1,1,1,1]
  Numbers were flipped from 0 to 1. The longest subarray is underlined.
  */

  std::vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}; // 10
  int k2 = 3;

  std::vector<int> nums3 = {0}; // 1
  int k3 = 1;

  // test(nums, k);
  // test(nums2, k2);
  test(nums3, k3);
}