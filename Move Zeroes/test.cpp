#include <iostream>
#include <vector>

void shift(std::vector<int> &nums, int i)
{
  int range = nums.size();

  for (int x = i; x < range - 1; x++)
  {
    nums[x] = nums[x + 1];
  }
  nums[range - 1] = 0;

  std::cout << "Shifted: ";
  for (int el : nums)
  {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

void moveZeroes(std::vector<int> &nums)
{
  int n = nums.size();
  int lastNonZeroFoundAt = 0;

  // Di chuyển tất cả các số khác 0 về phía trước
  for (int i = 0; i < n; i++)
  {
    if (nums[i] != 0)
    {
      nums[lastNonZeroFoundAt++] = nums[i];
    }
  }

  // Đặt các phần tử còn lại thành 0
  for (int i = lastNonZeroFoundAt; i < n; i++)
  {
    nums[i] = 0;
  }

  std::cout << "Final result: ";
  for (int el : nums)
  {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

int main()
{
  std::vector<int> nums = {0, 0, 1};

  std::cout << "Before moveZeroes: ";
  for (int val : nums)
  {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  moveZeroes(nums);

  std::cout << "After moveZeroes: ";
  for (int val : nums)
  {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  return 0;
}
