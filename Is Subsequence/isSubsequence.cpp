#include <string>
#include <numeric> // for std::gcd
#include <iostream>
#include <vector>

class Solution
{
public:
  bool isSubsequence(std::string s, std::string t)
  {
    int start = 0;
    int pos = 0;

    for (int i = 0; i < t.size(); i++)
    {
      if (t.find(t[i]) != std::string::npos)
      {
        // found
        if (t[i] == s[pos])
        {
          std::cout << t[i] << std::endl;
          if (pos == s.size() - 1)
            return true;
          pos++;
        }
      }
    }

    return false;
  }
};

void test(std::string s, std::string t)
{
  std::cout << "Input: " << s << " " << t << std::endl;

  Solution sol = Solution();

  std::cout << "Final: ";

  std::cout << sol.isSubsequence(s, t) << " ";

  std::cout << std::endl;
}

int main()
{
  std::string s = "abc";
  std::string t = "ahbgdc";

  test(s, t);
  return 0;
}