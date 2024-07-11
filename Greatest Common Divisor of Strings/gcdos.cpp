#include <string>
#include <iostream>

class Solution
{
public:
  std::string gcdOfStrings(std::string str1, std::string str2)
  {
    int size1 = str1.size();
    int size2 = str2.size();
    std::string result = "";

    int min = size1;

    if (size2 < size1)
    {
      min = size2;
    }

    int found = 0;
    int streakStopped = 0;

    int i = 0;
    int j = 0;

    while (i < size1)
    {
      if (streakStopped)
        break;

      while (j < size2)
      {
        if (streakStopped)
          break;

        if (str1[i] == str2[j])
        {
          found = 1;
        }

        if (found == 1)
        {
          result += str2[j];

          for (int x = j + 1; x < min; x++)
          {
            if (str1[x] != str2[x])
            {
              streakStopped = 1;
              break;
            }
            else
            {
              result += str2[x];
            }
          }
        }

        j++;
      }
      i++;
    }

    if (result.size() == 0)
      return "";

    while (result.size() > 0)
    {
      if ((size1 % result.size() == 0) && (size2 % result.size() == 0))
        break;
      result.pop_back();
    }

    if (size1 >= size2)
    {
      for (int i = 0; i < size1; i += result.size())
      {
        if (str1.substr(i, result.size()) != result)
        {
          return "";
        }
      }
    }
    else
    {
      std::cout << size2 << std::endl;
      for (int i = 0; i < size2; i += result.size())
      {
        if (str2.substr(i, result.size()) != result)
        {
          return "";
        }
      }
    }

    return result;
  }
};

int main()
{
  std::string str1 = "TAUXXTAUXXTAUXXTAUXXTAUXX";
  std::string str2 = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX";
  std::string expected = "TAUXX";

  Solution sol = Solution();

  std::cout << "Expected: \"" + expected + "\"" << std::endl;
  std::cout << "Output: \"" + sol.gcdOfStrings(str1, str2) + "\"" << std::endl;
}