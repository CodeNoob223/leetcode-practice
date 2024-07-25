#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
  int largestAltitude(std::vector<int> &gain)
  {
    int max = 0;
    std::vector<int> sumprefix(gain.size() + 1, 0);
    for (int i = 1; i <= gain.size(); i++)
    {
      sumprefix[i] = sumprefix[i - 1] + gain[i - 1];

      max = std::max(max, sumprefix[i]);
    }

    for (int el : sumprefix)
    {
      std::cout << el << " ";
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
  std::cout << sol.largestAltitude(nums) << std::endl;
}

int main()
{
  std::vector<int> nums = {-5, 1, 5, 0, -7};
  /*
    Output: 1
    Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
  */

  std::vector<int> nums2 = {44, 32, -9, 52, 23, -50, 50, 33, -84, 47, -14, 84, 36, -62, 37, 81, -36, -85, -39, 67, -63, 64, -47, 95, 91, -40, 65, 67, 92, -28, 97, 100, 81};
  // 781

  test(nums);
  test(nums2);
}