#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <unordered_map>

static size_t length_of_longest_substring(std::string s)
{
    // on LeetCode => Runtime:608 ms   Memory:272.9 MB
    // on my PC (-O0) => Runtime:1.7 ms
    // size_t sub_string_start_index = 0;
    // size_t max_length = 0;
    // size_t length = 0;
    // for (size_t i = 0; i < s.length();) {
    //     const auto subString = s.substr(sub_string_start_index, length);

    //     const size_t duplicate_index = subString.find(s[i]);
    //     if (duplicate_index == std::string::npos) {
    //         ++i;
    //         ++length;
    //         max_length = std::max(max_length, length);
    //     } else {
    //         sub_string_start_index += duplicate_index + 1;
    //         i = sub_string_start_index;
    //         length = 0;
    //     }
    // }
    // return max_length;

    // on LeetCode => Runtime:280 ms  Memory:6.9 MB
    // on my PC (-O0) => Runtime:1 ms
    // size_t sub_string_start_index = 0;
    // size_t max_length = 0;
    // size_t length = 0;
    // for (size_t i = 0; i < s.length();) {
    //     size_t duplicate_index = std::string::npos;
    //     const size_t sub_string_end_index = sub_string_start_index + length;
    //     for (size_t j = sub_string_start_index; (j < sub_string_end_index) && (j < s.length()); ++j) {
    //         if (s[j] == s[i]) {
    //             duplicate_index = j;
    //             break;
    //         }
    //     }
    //     if (duplicate_index == std::string::npos) {
    //         ++i;
    //         ++length;
    //         max_length = std::max(max_length, length);
    //     } else {
    //         sub_string_start_index = duplicate_index + 1;
    //         i = sub_string_start_index;
    //         length = 0;
    //     }
    // }
    // return max_length;

    // on LeetCode => Runtime:24 ms  Memory:12.6 MB
    // on my PC (-O0) => Runtime:17.7 ms
    size_t max_substring_length = 0;
    size_t length = s.length();
    std::unordered_map<char, size_t> char_index_map;
    for (size_t i = 0, j = 0; ((i < length) && (j < length)); ++j) {
        auto current_char = s[j];
        bool inserted = false;
        auto it = char_index_map.end();
        std::tie(it, inserted) = char_index_map.emplace(current_char, j);
        auto& char_index = it->second;
        if (!inserted) {
            i = std::max(char_index, i);
        }
        max_substring_length = std::max(max_substring_length, (j - i + 1));
        char_index = j + 1;  // TODO: why + 1?
    }
    return max_substring_length;
}

int main(int argc, char* argv[])
{
    auto input = std::string{};  // default input: empty string
    if (argc >= 2) {
        input = argv[1];
    }

    const auto t1 = std::chrono::high_resolution_clock::now();
    const auto length = length_of_longest_substring(input);
    const auto t2 = std::chrono::high_resolution_clock::now();

    std::cout << length << std::endl;

    const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    std::cout << "duration: " << duration << "ns" << std::endl;

    return 0;
}
