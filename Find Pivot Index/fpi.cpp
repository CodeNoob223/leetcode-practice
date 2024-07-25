#include <iostream>
#include <vector>
#include <string>

/*
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal
to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left.
This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.
*/

class Solution
{
public:
  int pivotIndex(std::vector<int> &nums)
  {
    int pivotIndex = -1;
    std::vector<int> sumPrefix(nums.size() + 1, 0); // sum of numbers on the left
    std::vector<int> sumSuffix(nums.size() + 1, 0); // sum of numbers on the right

    // Calc sumSuffix at 0
    for (int x = 1; x < nums.size(); x++)
    {
      sumSuffix[0] += nums[x];
    }

    if (sumSuffix[0] == 0)
    {
      // left == right at index 0
      return 0;
    }

    for (int i = 1; i < nums.size(); i++)
    {
      sumPrefix[i] = sumPrefix[i - 1] + nums[i - 1];
      sumSuffix[i] = sumSuffix[i - 1] - nums[i];

      if (sumPrefix[i] == sumSuffix[i])
        return i;
    }

    return pivotIndex;
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
  std::cout << sol.pivotIndex(nums) << std::endl;
}

int main()
{
  std::vector<int> nums = {1, 7, 3, 6, 5, 6};
  /*
    Output: 3
    Explanation:
    The pivot index is 3.
    Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
    Right sum = nums[4] + nums[5] = 5 + 6 = 11
  */

  std::vector<int> nums2 = {1, 2, 3};
  /*
    Output: -1
    Explanation:
    There is no index that satisfies the conditions in the problem statement.
  */

  test(nums);
  test(nums2);
}