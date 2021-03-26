//
// Created by jacob on 2021/3/26.
//
#include <vector>
#include <random>

class Solution {
public:
    Solution(std::vector<int>& nums): v(nums) {}

    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset() {
        return v;
    }

    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle() {
        std::vector<int> ans(v);
        for (auto i = 0; i < ans.size(); ++i){
            std::random_device rd;  //Will be used to obtain a seed for the random number engine
            std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
            std::uniform_int_distribution<> distrib(-100000, 100000);
            auto id = i + distrib(gen) % (ans.size() - i);
            std::swap(ans[id], ans[i]);
        }
        return ans;
    }

private:
    std::vector<int> v;
};