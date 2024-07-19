#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Solution
{
public:
  int maxOperations(std::vector<int> &nums, int k)
  {
    std::map<int, int> map;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      int x = k - nums[i];
      if (map.find(x) != map.end())
      {
        count++;

        if (map[x] == 1)
        {
          map.erase(map.find(x));
        }
        else
        {
          map[x]--;
        }
      }
      else
      {
        map[nums[i]]++;
      }
    }

    return count;
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
  std::cout << sol.maxOperations(nums, k) << std::endl;
}

int main()
{
  std::vector<int> nums = {1, 2, 3, 4};
  int k = 5;
  /*
  Output: 2
  Explanation: Starting with nums = [1,2,3,4]:
  - Remove numbers 1 and 4, then nums = [2,3]
  - Remove numbers 2 and 3, then nums = []
  There are no more pairs that sum up to 5, hence a total of 2 operations.
  */

  std::vector<int> nums2 = {3, 1, 3, 4, 3}; // 1
  int k2 = 6;

  std::vector<int> nums3 = {4, 4, 1, 3, 1, 3, 2, 2, 5, 5, 1, 5, 2, 1, 2, 3, 5, 4}; // 2
  int k3 = 2;

  std::vector<int> nums4 = {2, 2, 2, 3, 1, 1, 4, 1}; // 2
  int k4 = 4;

  // test(nums, k);
  // test(nums2, k2);
  // test(nums3, k3);
  test(nums4, k4);
}