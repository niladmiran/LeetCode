//
// Created by jacob on 2021/3/27.
//
#include <vector>
#include <map>

std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::map<int, int> counts;
    std::vector<int> result;
    std::vector<int>::const_iterator it;
    for (it = nums1.begin(); it != nums1.end(); ++it)
        counts[*it]++;
    for (it = nums2.begin(); it != nums2.end(); ++it) {
        if (counts.find(*it) != counts.end() && counts[*it]) {
            counts[*it]--;
            result.push_back(*it);
            if (!counts[*it]) counts.erase(*it);
        }
    }
    return result;
}