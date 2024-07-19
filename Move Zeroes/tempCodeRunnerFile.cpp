void shift(std::vector<int> &nums, int i)
  {
    int range = nums.size() - i;

    for (int x = i; x < range; x++)
    {
      if (x == range - 1)
      {
        nums[x] = 0;
      }
      else
      {
        if (nums[x + 1] == 0)
        {
          shift(nums, x + 1);
        }
        if (x + 1 < range)
        {
          nums[x] = nums[x + 1];
        }
        else
        {
          nums[x] = 0;
        }
      }
      std::cout << "index-" << x << ": " << nums[x] << "<-" << nums[x + 1] << std::endl;
      std::cout << "Shifted: ";
      for (int el : nums)
      {
        std::cout << el << " ";
      }
      std::cout << std::endl;
    }
  }