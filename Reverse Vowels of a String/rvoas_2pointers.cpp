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
    std::vector<std::pair<int, char>> found;

    for (int i = 0; i < s.size(); i++)
    {
      if (isVowel(s[i]))
      {
        found.push_back(std::make_pair(i, s[i]));
      }
    }

    int size = found.size();
    for (int i = 0; i < found.size(); i++)
    {
      int index = found[size - 1 - i].first;
      s[index] = found[i].second;
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