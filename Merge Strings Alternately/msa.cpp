#include <string>
#include <iostream>

class Solution
{
public:
  std::string mergeAlternately(std::string word1, std::string word2)
  {
    int length1 = word1.size();
    int length2 = word2.size();

    std::string result = "";

    // Loop the bigger length, not the total length!
    for (int i = 0; (i < length1 || i < length2); i++)
    {
      if (i < length1)
      {
        result += word1[i];
      }
      if (i < length2)
      {
        result += word2[i];
      }
    }

    return result;
  }
};

int main()
{
  std::string word1 = "ab";
  std::string word2 = "pqrs";
  std::string desired = "apbqrs";

  Solution sol = Solution();
  std::string result = sol.mergeAlternately(word1, word2);
  std::cout << result + " ";
  std::cout << desired << std::endl;
  std::cout << (result == desired);
}