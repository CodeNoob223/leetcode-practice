#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

class Solution
{
public:
  int reverse(int x)
  {
    int rev_num = 0;

    while (x != 0)
    {
      int curr_digit = x % 10; //(123 -> 3)

      if (rev_num > INT_MAX/10 || rev_num == INT_MAX/10 && curr_digit > 7) return 0;

      if (rev_num < INT_MIN/10 || rev_num == INT_MIN/10 && curr_digit < -8) return 0;

      rev_num = rev_num * 10 + curr_digit;
      x /= 10; // 123 -> 12
    }

    return rev_num;
  }
};

int main()
{
  std::cout << Solution().reverse(-123); // 321
}