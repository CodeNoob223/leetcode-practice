#include <iostream>
#include <vector>

class Solution
{
public:
  int maxArea(std::vector<int> &height)
  {
    int max = 0;
    int left = 0;
    int right = height.size() - 1;

    if (height.size() < 3)
    {
      int areaHeight = std::min(height[left], height[right]);
      int areaWidth = right - left;

      max = std::max(max, areaHeight * areaWidth);
      return max;
    }

    while (left < right)
    {
      int areaHeight = std::min(height[left], height[right]);
      int areaWidth = right - left;

      max = std::max(max, areaHeight * areaWidth);

      if (height[left] < height[right])
      {
        left++;
      }
      else if (height[left] >= height[right])
      {
        right--;
      }
    }

    return max;
  }
};

void test(std::vector<int> &height)
{
  Solution sol = Solution();
  std::cout << "Input: ";
  for (int el : height)
  {
    std::cout << el << " ";
  }
  std::cout << std::endl;
  std::cout << "Output: ";
  std::cout << sol.maxArea(height) << std::endl;
}

int main()
{
  std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  /*
  Output: 49
  Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
  In this case, the max area of water (blue section) the container can contain is 49.
  */
  std::vector<int> heights2 = {2, 3, 4, 5, 18, 17, 6}; // 17
  std::vector<int> heights3 = {1, 2, 4, 3};            // 4
  test(heights);
  test(heights2);
  test(heights3);
}