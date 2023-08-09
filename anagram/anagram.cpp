#include <iostream>
#include <unordered_map>
#include <string>

class Solution
{
public:
  bool isAnagram(std::string s, std::string t)
  {
    std::unordered_map<char, int> seen;

    for (char x : s) {
      seen[x]++;
    }

    for (char y : t) {
      seen[y]--;
    }

    for (std::pair<char, int> z : seen) {
      if (z.second != 0) return false;
    }

    return true;
  }
};

int main()
{
  std::string s = "anagram";
  std::string t = "gnaaram";
  std::cout << Solution().isAnagram(s, t); // 1
}