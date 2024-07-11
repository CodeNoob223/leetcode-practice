#include <string>
#include <numeric> // for std::gcd
#include <iostream>

class Solution
{
public:
  std::string gcdOfStrings(std::string str1, std::string str2)
  {
    if (str1 + str2 != str2 + str1) {
      return "";
    }

    return str1.substr(0, std::gcd(str1.size(), str2.size()));
  }
};

int main()
{
  std::string str1 = "TAUXXTAUXXTAUXXTAUXXTAUXX";
  std::string str2 = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXX";
  std::string expected = "";

  Solution sol = Solution();

  std::cout << "Expected: \"" + expected + "\"" << std::endl;
  std::cout << "Output: \"" + sol.gcdOfStrings(str1, str2) + "\"" << std::endl;
}