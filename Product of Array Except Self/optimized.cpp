#include <string>
#include <numeric> // for std::gcd
#include <iostream>
#include <vector>
#include <map>

class Solution
{
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums)
  {
    std::vector<int> result;

    // Fill in with all left-side calculated
    for (int i = 0; i < nums.size(); i++)
    {
      if (i == 0)
      {
        result.push_back(1);
      }
      else
      {
        result.push_back(result[i - 1] * nums[i - 1]);
      }
    }

    // Merge all Left *= Right
    int right = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      result[i] *= right;
      right *= nums[i];
    }

    return result;
  }
};

void test(std::vector<int> nums)
{
  std::cout << "Input: ";
  for (int el : nums)
  {
    std::cout << el << " ";
  }
  std::cout << std::endl;

  Solution sol = Solution();

  std::cout << "Final: ";
  for (int el : sol.productExceptSelf(nums))
  {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

int main()
{
  std::vector<int> nums = {1, 2, 3, 4};       // 24,12,8,6
  std::vector<int> nums2 = {-1, 1, 0, -3, 3}; // 0,0,9,0,0
  test(nums);
  test(nums2);

  return 0;
}