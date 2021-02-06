#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        std::unordered_map<int, int> elem_count;
        for (auto i: nums) {
            ++elem_count[i];
        }
        for (auto it = elem_count.begin(); it != elem_count.end(); ++it) {
            std::cout << it->first << " -> " << it->second << std::endl;
        }

        vector<int> unique_nums;
        for (auto& e: elem_count) {
            if (e.second == 1) {
                unique_nums.push_back(e.first);
            }
        }
        // (void)std::transform(elem_count.begin(), elem_count.end(), unique_nums.begin(),
        //     [](std::pair<int, int> elem){ return elem.second == 1 ? elem.first : 0; });
        for (auto it = unique_nums.begin(); it != unique_nums.end(); ++it) {
            std::cout << *it << std::endl;
        }
        return std::accumulate(unique_nums.begin(), unique_nums.end(), 0);
    }
};

int main()
{
    vector<int> i{1,2,3,2};
    const auto t1 = std::chrono::high_resolution_clock::now();
    const auto res = Solution().sumOfUnique(i);
    const auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << res << std::endl;

    const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    std::cout << "took " << duration << " ns" << std::endl;

    return 0;
}
