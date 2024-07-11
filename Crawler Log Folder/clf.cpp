#include <string>
#include <numeric> // for std::gcd
#include <iostream>
#include <vector>

class Solution
{
public:
  int minOperations(std::vector<std::string> &logs)
  {
    int depth = 0;

    for (int i = 0; i < logs.size(); i++)
    {
      if (logs[i] == "../")
      {
        if (depth > 0) {
          depth--;
        }
      }
      else if (logs[i] != "./")
      {
        depth++;
      }
    }

    return depth;
  }
};

int main()
{
  std::vector<std::string> logs{"d1/", "d2/", "../", "d21/", "./"}; // Expected: 2
  Solution sol = Solution();

  std::cout << "Output: ";
  std::cout << sol.minOperations(logs) << std::endl;
}