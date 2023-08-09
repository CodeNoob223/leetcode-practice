#include <iostream>
#include <unordered_map>
#include <string>

class Solution
{
public:
  int romanToInt(std::string s)
  {
    std::unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int ans = 0;

    for (int i = 0; i < s.length(); i++)
    {
      std::cout << "[" << m[s[i]] << "," << m[s[i+1]] << "]\n";
      if (m[s[i]] < m[s[i + 1]])
      {
        ans -= m[s[i]];
      }
      else
      {
        ans += m[s[i]];
      }
    }

    return ans;
  }
};

int main()
{
  std::string s = "MCMXCIV";
  std::cout << Solution().romanToInt(s);
}
