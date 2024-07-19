#include <iostream>
#include <vector>

class Solution
{
public:
  char *toChar(int number)
  {
    // Chuyển đổi số thành chuỗi sử dụng sprintf
    // Dự tính kích thước mảng (10 + 1 cho ký tự kết thúc '\0')
    char *charArray = new char[11];
    std::sprintf(charArray, "%d", number);
    return charArray;
  }

  int compress(std::vector<char> &chars)
  {
    if (chars.size() == 1) return 1;

    std::vector<char> result;

    char found_char = chars[0];
    int count = 1;

    for (int i = 1; i < chars.size(); i++)
    {
      if (chars[i] == found_char)
      {
        count++;

        if (i == chars.size() - 1)
        {
          result.push_back(found_char);

          if (count > 1)
          {
            char *count_str = toChar(count);
            for (int x = 0; count_str[x] != '\0'; x++)
            {
              result.push_back(count_str[x]);
            }
          }
        }
      }
      else if ((chars[i] != found_char))
      {
        result.push_back(found_char);

        if (count > 1)
        {
          char *count_str = toChar(count);
          for (int x = 0; count_str[x] != '\0'; x++)
          {
            result.push_back(count_str[x]);
          }
        }

        found_char = chars[i];
        count = 1;

        if (i == chars.size() - 1)
        {
          result.push_back(found_char);
        }
      }
    }

    std::cout << "New: ";
    for (char el : result)
    {
      std::cout << el << " ";
    }
    std::cout << std::endl;

    chars = result;
    return result.size();
  }
};

void test(std::vector<char> chars)
{
  Solution sol = Solution();
  std::cout << "Input: ";
  for (char el : chars)
  {
    std::cout << el << " ";
  }
  std::cout << std::endl;
  std::cout << "Output: ";
  std::cout << sol.compress(chars) << std::endl;
}

int main()
{
  std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c', 'd'};
  // Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

  test(chars);
}