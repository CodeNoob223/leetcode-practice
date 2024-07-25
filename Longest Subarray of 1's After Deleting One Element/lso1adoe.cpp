#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
  int longestSubarray(std::vector<int> &nums)
  {
    int start = 0;
    int end = 0;
    int max = 0;
    int k = 1;

    for (; end < nums.size(); end++)
    {
      if (nums[end] == 0)
      {
        k--;
        while (k < 0 && start < end)
        {
          if (nums[start] == 0)
          {
            k++;
          }
          start++;
        }
      }
      max = std::max(max, end - start);
    }

    return max;
  }
};

void test(std::vector<int> &nums)
{
  Solution sol = Solution();
  std::cout << "Input: ";
  for (int el : nums)
  {
    std::cout << el << " ";
  }
  std::cout << std::endl;
  std::cout << "Output: ";
  std::cout << sol.longestSubarray(nums) << std::endl;
}

int main()
{
  std::vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
  /*
  Output: 5
  Explanation: After deleting the number in position 4,
  [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
  */
  test(nums);
}