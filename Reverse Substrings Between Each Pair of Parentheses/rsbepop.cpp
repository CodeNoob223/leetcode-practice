#include <string>
#include <numeric> // for std::gcd
#include <iostream>

class Solution
{
public:
  std::string reverseParentheses(std::string s)
  {
    std::string stack = "";
    std::string temp_reversed = "";

    for (char c : s)
    {
      if (c != ')')
      {
        std::cout << "Push \'" << c << "\':" << std::endl;
        stack.push_back(c);
      }
      else
      {
        std::cout << "found \')\', start reversing until \'(\' " << std::endl;
        temp_reversed = "";
        for (char r = stack.back(); r != '('; r = stack.back())
        {
          temp_reversed += r; // add the char to temp
          stack.pop_back();   // delete the last char
        }
        stack.pop_back(); // remove '(' at the end
        stack += temp_reversed;
      }

      std::cout << stack << std::endl;
    }

    return stack;
  }
};

void test(std::string s)
{
  Solution sol = Solution();

  std::cout << "Output: ";
  std::cout << sol.reverseParentheses(s) << std::endl;
}

int main()
{
  std::string s = "(ed(et(oc))el)"; // Expected: leetcode

  test(s);
}