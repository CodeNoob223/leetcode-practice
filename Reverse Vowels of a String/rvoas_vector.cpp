#include <string>
#include <numeric> // for std::gcd
#include <iostream>
#include <vector>

class Solution
{
public:
  bool isVowel(char c)
  {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
      return 1;
    else
      return 0;
  }
  std::string reverseVowels(std::string s)
  {
    int start = 0;
    int end = s.size() - 1;

    while (start < end)
    {
      if (isVowel(s[start]) && isVowel(s[end])) {
        std::swap(s[start], s[end]);
        start++;
        end--;
      }
      if (!isVowel(s[start])) {
        start++;
      }
      if (!isVowel(s[end])) {
        end--;
      }
    }

    return s;
  }
};

void test(std::string s)
{
  Solution sol = Solution();

  std::cout << "Output: ";
  std::cout << sol.reverseVowels(s) << std::endl;
}

int main()
{
  std::string s = "race car"; // Expected: race car (a,e,a) => (a,e,a)

  test(s);
}