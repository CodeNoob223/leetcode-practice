#include<iostream>
#include<vector>
#include<unordered_map>

// [2,7,11,15]
// 9
// => [0;1]

class Solution {
    public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> indexes; //cac index
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int soCanTim = target - nums[i];

            if (map.find(soCanTim) != map.end()) { 
                indexes.push_back(map[soCanTim]);
                indexes.push_back(i);
                break;
            } else { //khong tim thay thi find() == end()
                map.insert(std::make_pair(nums[i], i));
            }
        }
        return indexes;
    }
};

int main() {
    std::vector<int> arr = {2,7,11,15};
    int target = 9;
    Solution sol;
    std::vector<int> outPutPair = sol.twoSum(arr, target);
    std::cout << "[" << outPutPair[0] << ";" << outPutPair[1] << "]";
}
