#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class Solution
{
public:
  bool containsNearbyDuplicate(std::vector<int> &nums, int k)
  {
    std::unordered_map<int, int> hashMap;

    for (int i = 0; i < nums.size(); i++)
    { // The "foreach loop"
      if (hashMap.find(nums[i]) != hashMap.end())
      {
        if (i - hashMap[nums[i]] <= k) 
        {
          return true;
        }
      }
      hashMap[nums[i]] = i;
    }
    return false;
  }
};

int main()
{
  std::vector<int> s = {1, 0, 1, 1};
  std::cout << Solution().containsNearbyDuplicate(s, 1); // 1
}