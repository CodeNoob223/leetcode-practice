#include <string>
#include <numeric> // for std::gcd
#include <iostream>
#include <vector>

class Solution
{
public:
  bool isOdd(int num)
  {
    return num % 2 != 0;
  }
  bool threeConsecutiveOdds(std::vector<int> &arr)
  {
    if (arr.size() < 3) {
      return false;
    }
    for (int i = 0; i < arr.size() - 2; i++)
    {
      if (isOdd(arr[i]) && isOdd(arr[i+1]) && isOdd(arr[i+2])) {
        return true;
      }
    }

    return false;
  }
};

void test(std::vector<int> arr)
{
  Solution sol = Solution();

  std::cout << "Output: ";
  std::cout << sol.threeConsecutiveOdds(arr) << std::endl;
}

int main()
{
  std::vector<int> arr = {1, 2, 34, 3, 4, 5, 7, 23, 12}; //[5,7,23] are three consecutive odds.

  test(arr);
}