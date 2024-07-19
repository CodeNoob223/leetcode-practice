#include <string>
#include <numeric> // for std::gcd
#include <iostream>

class Solution
{
public:
  std::string reverseWords(std::string s)
  {
    std::string result = "";
    std::string temp = "";

    int i = 0;
    int size = s.size();

    while (i < size)
    {
      if (s[i] == ' ')
      {
        i++;
        continue;
      }

      while (s[i] != ' ' && i < size)
      {
        temp += s[i];
        i++;
      }

      if (temp.size() > 0)
      {
        if (result.size() == 0)
        {
          result = temp;
        }
        else
        {
          result = temp + ' ' + result;
        }
        temp = "";
      }
    }

    return result;
  }
};

void test(std::string s)
{
  Solution sol = Solution();

  std::cout << "Output: ";
  std::cout << sol.reverseWords(s) << std::endl;
}

int main()
{
  std::string s = "a good   example"; // Expected: example good a

  test(s);
}