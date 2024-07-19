bool increasingTriplet(std::vector<int> &nums)
  {
    int first_small = INT_MAX;
    int second_small = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] <= first_small)
      {
        first_small = nums[i];
      }
      else if (nums[i] <= second_small)
      {
        second_small = nums[i];
      }
      else if (nums[i] > first_small && nums[i] > second_small)
      {
        return true;
      }
    }
    return false;
  }