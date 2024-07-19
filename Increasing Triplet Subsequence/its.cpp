#include <iostream>
#include <vector>

class Solution
{
public:
  bool increasingTriplet(std::vector<int> &nums)
  {
    int first_small = INT_MAX;
    int second_small = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] <= first_small)
      {
        first_small = nums[i];
      }
      else if (nums[i] <= second_small)
      {
        second_small = nums[i];
      }
      else if (nums[i] > first_small && nums[i] > second_small)
      {
        return true;
      }
    }
    return false;
  }
};

void test(std::vector<int> arr)
{
  Solution sol = Solution();
  std::cout << "Input: ";
  for (int el : arr)
  {
    std::cout << el << " ";
  }
  std::cout << std::endl;
  std::cout << "Output: ";
  std::cout << sol.increasingTriplet(arr) << std::endl;
}

int main()
{
  std::vector<int> arr = {1, 2, 3, 4, 5};     // TRUE any triplet where i < j < k is valid..
  std::vector<int> arr2 = {2, 1, 5, 0, 4, 6}; // TRUE any triplet where i < j < k is valid..
  std::vector<int> arr3 = {1, 2, 1, 3};       // TRUE any triplet where i < j < k is valid..

  test(arr);
  test(arr2);
  test(arr3);
}