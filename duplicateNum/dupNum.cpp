#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

class Solution
{
public:
  // O(n)
  bool containsDuplicate(std::vector<int> &nums)
  {
    std::unordered_set<int> seen;
    for (int num : nums)
    { // The "foreach loop"
      if (seen.count(num) > 0)
      {
        return true;
      }
      else
      {
        seen.insert(num);
      }
    }
    return false;
  }
};

int main()
{
  std::vector<int> s = {1,2,3,0};
  std::cout << Solution().containsDuplicate(s); // 0
}