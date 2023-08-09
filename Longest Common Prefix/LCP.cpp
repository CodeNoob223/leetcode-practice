#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs)
  {
    if (strs.size() == 0) return "";
    std::string ans = strs[0];

    for (int i = 1; i < strs.size(); i++) {
      while(strs[i].find(ans) != 0) {
        ans = ans.substr(0, ans.length() - 1);

        if (ans.empty()) return "";
      }
    }

    return ans;
  }
};

int main()
{
  std::vector<std::string> strs = {"flower", "flow", "flight"};
  std::cout << Solution().longestCommonPrefix(strs);
}
