#include <string>
#include <numeric> // for std::gcd
#include <iostream>

class Solution
{
public:
  std::string reverseWords(std::string s)
  {
    std::string result = "";

    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] != ' ')
      {
        char r = s[i];
        std::string word = "";
        for (; r != ' ' && i < s.size(); r = s[i])
        {
          word.push_back(r);
          i++;
        }
        
        if (result.size() == 0) {
          result = word;
        } else {
          result = word + " " + result;
        }
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