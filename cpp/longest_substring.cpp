#include <algorithm>
#include <iostream>
#include <string>

static size_t length_of_longest_substring(std::string s)
{
    // Runtime:608 ms   Memory:272.9 MB
    // size_t subStringStartIndex = 0;
    // size_t maxLength = 0;
    // size_t length = 0;
    // for (size_t i = 0; i < s.length();) {
    //     const auto subString = s.substr(subStringStartIndex, length);

    //     const size_t duplicate_index = subString.find(s[i]);
    //     if (duplicate_index == std::string::npos) {
    //         ++i;
    //         ++length;
    //         maxLength = MAX(maxLength, length);
    //     } else {
    //         subStringStartIndex += duplicate_index + 1;
    //         i = subStringStartIndex;
    //         length = 0;
    //     }
    // }
    // return maxLength;

    // Runtime:280 ms  Memory:6.9 MB
    size_t sub_string_start_index = 0;
    size_t max_length = 0;
    size_t length = 0;
    for (size_t i = 0; i < s.length();) {
        size_t duplicate_index = std::string::npos;
        const size_t sub_string_end_index = sub_string_start_index + length;
        for (size_t j = sub_string_start_index; (j < sub_string_end_index) && (j < s.length()); ++j) {
            if (s[j] == s[i]) {
                duplicate_index = j;
                break;
            }
        }
        if (duplicate_index == std::string::npos) {
            ++i;
            ++length;
            max_length = std::max(max_length, length);
        } else {
            sub_string_start_index = duplicate_index + 1;
            i = sub_string_start_index;
            length = 0;
        }
    }
    return max_length;
}

int main(int argc, char* argv[])
{
    auto length = static_cast<size_t>(0);
    if (argc < 2) {
        length = length_of_longest_substring("");
    }
    else {
        length = length_of_longest_substring(argv[1]);
    }
    std::cout << length << std::endl;

    return 0;
}
