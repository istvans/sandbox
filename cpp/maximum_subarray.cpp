#include <algorithm>
#include <chrono>
#include <iostream>
#include <typeinfo>
#include <tuple>
#include <vector>

// Kadane's algorithm; disallowed empty subarray variant
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        auto max_sum = std::numeric_limits<int>::min();
        auto current_sum = 0;
        const auto n = nums.size();
        for (auto i = 0u; i < n; ++i)
        {
            const auto x = nums[i];
            current_sum = std::max(x, current_sum + x);
            max_sum = std::max(current_sum, max_sum);
        }
        return max_sum;
    }
};

int main()
{
    using vec_t = std::vector<int>;
    const auto test_cases = std::make_tuple(
        vec_t{-2,1,-3,4,-1,2,1,-5,4}, vec_t{1}, vec_t{0}, vec_t{-1}, vec_t{-100000});

    std::cout << sizeof(test_cases) << ' ' << std::tuple_size<typeid(test_cases).name()>::value << std::endl;

    // const auto num_test_cases = test_cases.size();
    // for ()
    // {
    //     std::cout << "test case: '" << test_case << '\'' << std::endl;

    //     const auto t1 = std::chrono::high_resolution_clock::now();
    //     const auto res = Solution().maxSubArray(test_case);
    //     const auto t2 = std::chrono::high_resolution_clock::now();
    //     std::cout << res << std::endl;

    //     const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    //     std::cout << "took " << duration << " ns" << std::endl;
    // }

    return 0;
}
