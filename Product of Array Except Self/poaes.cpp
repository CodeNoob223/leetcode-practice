#include <string>
#include <numeric> // for std::gcd
#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
  {
    std::vector<int> result;
    std::map<int, int> left_cache;
    std::map<int, int> right_cache;

    for (int i = 0; i < nums.size(); i++)
    {
      // Calc left
      int left = 1;
      
      if (i == 0) {
        left = 1;
      } else {
        left *= nums[i-1] * left_cache[i-1];
      }

      left_cache[i] = left;

      // Calc right
      int right = 1;

      if (i == 0 || nums[i] == 0) {
        int rightPos = nums.size() - 1;
        while (rightPos > i)
        {
          if (nums[rightPos] == 0)
          {
            right = 0;
            break;
          }
          right *= nums[rightPos];
          rightPos--;
        }
      } else {
        right = right_cache[i-1] / nums[i];
      }

      right_cache[i] = right;

      result.push_back(right * left);
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
  std::vector<int> nums = {1,2,3,4}; // 24,12,8,6
  std::vector<int> nums2 = {-1,1,0,-3,3}; // 0,0,9,0,0
  test(nums);
  test(nums2);

  return 0;
}