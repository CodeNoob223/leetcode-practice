#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>

class Solution
{
public:
  int maxProfit(std::vector<int> &prices)
  {
    int lowest = prices[0];
    int curr_profit = 0;
    int fin_profit = 0;

    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] < lowest) {
        lowest = prices[i];
      }
      curr_profit = prices[i] - lowest;
      if (curr_profit > fin_profit) fin_profit = curr_profit;
    }
    
    return fin_profit;
  }
};

int main()
{
  std::vector<int> s = {3, 2, 6, 5, 0, 3};
  std::cout << Solution().maxProfit(s); // 0
}