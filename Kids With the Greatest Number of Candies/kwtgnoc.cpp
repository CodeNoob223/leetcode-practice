#include <string>
#include <numeric> // for std::gcd
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  std::vector<bool> kidsWithCandies(std::vector<int> &candies, int extraCandies)
  {
    std::vector<bool> result;
    //int greatest = *std::max_element(candies.begin(), candies.end());
    // Or traditional for loop!
    int greatest = candies[0];
    for (int i = 0; i < candies.size(); i++)
    {
      if (candies[i] >= greatest)
      {
        greatest = candies[i];
      }
    }

    for (int c : candies)
    {
      result.push_back((c + extraCandies) >= greatest);
    }

    return result;
  }
};

int main()
{
  std::vector<int> candies{2, 3, 5, 1, 3}; // Expected: [true,true,true,false,true]
  int extraCandies = 3;
  Solution sol = Solution();

  std::cout << "Output: [";
  for (const bool &val : sol.kidsWithCandies(candies, extraCandies))
  {
    std::cout << ((val > 0) ? "true," : "false,");
  }
  std::cout << "]";
}