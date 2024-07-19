#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
  bool isVowel(char ch)
  {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
      return true;
    }
    return false;
  }

  int maxVowels(std::string s, int k)
  {
    int max = 0;
    int count = 0;
    for (int i = 0; i < s.size() - k + 1; i++)
    {
      if (i == 0)
      {
        for (int x = i; x < i + k; x++)
        {
          if (isVowel(s[x]))
          {
            count++;
          }
        }
      }
      else
      {
        if (isVowel(s[i-1])) {
          count--;
        }
        if (isVowel(s[i+k-1])) {
          count++;
        }
      }
      max = std::max(max, count);
    }

    return max;
  }
};

void test(std::string s, int k)
{
  Solution sol = Solution();
  std::cout << "Input: ";
  std::cout << s << std::endl;
  std::cout << "Output: ";
  std::cout << sol.maxVowels(s, k) << std::endl;
}

int main()
{
  std::string s = "abciiidef";
  int k = 3;

  test(s, k);
}