#include <string>
#include <numeric> // for std::gcd
#include <iostream>
#include <vector>

class Solution
{
public:
  bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
  {
    for (int i = 0; i < flowerbed.size(); i++)
    {
      if (flowerbed[i] == 0)
      {
        if (i == 0 || flowerbed[i-1] == 0) {
          if (i == flowerbed.size() - 1 || flowerbed[i+1] == 0) {
            flowerbed[i] = 1;
            n--;
            if (n == 0) {
              return true;
            }
          }
        }
      }
    }

    return n <= 0;
  }
};

void test(std::vector<int> &flowerbed, int n)
{
  Solution sol = Solution();

  std::cout << "Output: ";
  std::cout << sol.canPlaceFlowers(flowerbed, n) << std::endl;
}

int main()
{
  std::vector<int> flowerbed{1,0,0,0,0,1}; // Expected: false
  int n = 2;

  test(flowerbed, n);
}