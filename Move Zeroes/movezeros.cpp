#include <string>
#include <numeric> // for std::gcd
#include <iostream>
#include <vector>

class Solution
{
public:
  void moveZeroes(std::vector<int> &nums)
  {
    int count = 0;
    int zeroPos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != 0)
      {
        nums[zeroPos] = nums[i];
        zeroPos++;
      } else {
        count++;
      }
    }

    for (int i = nums.size() - count; i < nums.size(); i++) {
      nums[i] = 0;
    }
  }
};

void test(std::vector<int> arr)
{
  std::cout << "Input: ";
  for (int el : arr)
  {
    std::cout << el << " ";
  }
  std::cout << std::endl;

  Solution sol = Solution();
  sol.moveZeroes(arr);
  std::cout << "Final: ";
  for (int el : arr)
  {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

int main()
{
  std::vector<int> nums = {0, 0, 1};         // 1,0,0
  std::vector<int> nums2 = {0, 1, 0, 3, 12}; // 1,3,12,0,0
  std::vector<int> nums3 = {0};              // 0
  std::vector<int> nums4 = {0, 0};           // 0
  std::vector<int> nums5 = {1, 0, 1, 0, 1};  // 1,1,0,0
  test(nums);
  test(nums2);
  test(nums3);
  test(nums4);
  test(nums5);

  return 0;
}