#include <iostream>
#include <string>

#define MAX(x, y) ((x > y)?(x):(y))

static size_t length_of_longest_substring(std::string s)
{
    size_t subStringStartIndex = 0;
    size_t maxLength = 0;
    size_t length = 0;
    for (size_t i = 0; i < s.length();) {
        const auto subString = s.substr(subStringStartIndex, length);

        const size_t duplicate_index = subString.find(s[i]);
        if (duplicate_index == std::string::npos) {
            ++i;
            ++length;
            maxLength = MAX(maxLength, length);
        } else {
            subStringStartIndex += duplicate_index + 1;
            i = subStringStartIndex;
            length = 0;
        }
    }
    return maxLength;
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
