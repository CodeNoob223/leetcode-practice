#include <iostream>
#include <vector>
#include <string>
#include <string.h>

class Solution
{
public:
  /*
   * @param strs: a list of strings
   * @return: encodes a list of strings to a single string.
   */
  std::string encode(std::vector<std::string> &strs)
  {
    // write your code here
    std::string result;
    for (std::string str: strs)
    {
      result += str + "*,";
    }
    return result;
  }

  /*
   * @param str: A string
   * @return: decodes a single string to a list of strings
   */
  std::vector<std::string> decode(std::string &str)
  {
    // write your code here
    std::vector<std::string> result;

    // declaring character array (+1 for null terminator)
    char* char_array = new char[str.length() + 1];
  
    // copying the contents of the
    // string to char array
    strcpy(char_array, str.c_str());

    char *p;
    p = strtok(char_array, "*,");

    while (p != NULL)
    {
      result.push_back(p);
      p = strtok(NULL, "*,");
    }
    return result;
  }
};

int main()
{
  std::vector<std::string> strs = {"lint","code","love","you"};
  std::string newStrs = Solution().encode(strs);

  for (std::string str : Solution().decode(newStrs)) {
    std::cout << str << std::endl;
  }
}

