#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

#define TEST_CASE() 4

#if TEST_CASE() == 1
template <class T>
void bar(T&& x)
{
    std::cout << x << '\n';
}

template <class T>
void foo(T&& x)
{
    bar(std::forward<T>(x));
}

static void test()
{
    foo(std::string{"alma"});
    const auto dont_change = std::string{"korte"};
    foo(dont_change);
}
#endif  // TEST_CASE() == 1

#if TEST_CASE() == 2
struct Date
{
    int day;
    int month;
    int year;

    template <class T>
    Date(T&& date_string)
    {
        auto stream = std::istringstream{date_string};
        std::string part;
        for (auto i = 0; std::getline(stream, part, '-'); ++i) {
            switch (i) {
                case 0:
                    this->day = std::stoi(part);
                    break;
                case 1:
                    this->month = std::stoi(part);
                    break;
                case 2:
                    this->year = std::stoi(part);
                    break;
                default:
                    throw std::runtime_error("unexpected part on index " + std::to_string(i) + ": " + part);
            }
        }
    }
};

static constexpr bool operator<(const Date& lhs, const Date& rhs)
{
    return std::tie(lhs.year, lhs.month, lhs.day)
         < std::tie(rhs.year, rhs.month, rhs.day);
}

template <class Out>
static Out& operator<<(Out& out, const Date& date)
{
    return out << std::setw(2) << std::setfill('0') << date.day << '-'
               << std::setw(2) << std::setfill('0') << date.month << '-'
               << date.year;
}

/**
 You are provided with an array of custom Date objects. A date has members Day, Month
and Year of type integer, and is represented in input and output as "DD-MM-YYYY".
Implement below function such that it returns the third-latest date, given such an array of Date
objects. You may assume the input array will always have at least 3 distinct elements, and that
the dates in the input are valid.
Extra marks are given for an efficient implementation.
Example:
Input: [14-04-2001, 29-12-2061, 21-10-2019, 07-01-1973, 19-07-2014, 11-03-1992, 21-10-2019]
Output: 19-07-2014
 */
template <class DateVector>
Date get_third_latest_date(DateVector&& dates)
{
    if (dates.size() < 3) {
        throw std::runtime_error("at least 3 elements are needed; provided: " + std::to_string(dates.size()));
    }

    const auto sorted_dates = std::set<Date>(dates.cbegin(), dates.cend());
    auto it = sorted_dates.cend();
    return *std::prev(it, 3);
}

static void test()
{
    std::cout << get_third_latest_date(std::vector<Date>{"14-04-2001", "29-12-2061", "21-10-2019", "07-01-1973",
        "19-07-2014", "11-03-1992", "21-10-2019"}) << '\n';
}
#endif  // TEST_CASE() == 2

#if TEST_CASE() == 3

/*
 * Complete the 'longestEvenWord' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING sentence as parameter.
 */
using namespace std;
static string longestEvenWord(string sentence) {
    auto stream = std::istringstream(sentence);

    string word;
    auto even_word_counts = multimap<int, std::string>{};
    for (; getline(stream, word, ' ');) {
        if (word.size() % 2 == 0) {
            even_word_counts.emplace(word.size(), word);
        }
    }
    for (auto i: even_word_counts) {
        std::cout << i.first << " -> " << i.second << '\n';
    }
    if (even_word_counts.empty()) {
        return "00";
    } else {
        auto it = prev(even_word_counts.end());
        return even_word_counts.find(it->first)->second;
    }
}

static void test()
{
    std::cout << longestEvenWord("Time to write great code") << '\n';
}
#endif  // TEST_CASE() == 3


#if TEST_CASE() == 4
static void test()
{
    auto number = 649578;
    while(number != 0)
    {
       int current = number % 10; // get rightmost digit
       number /= 10;
       // process 'current', or store in a container for later processing
       std::cout << current << '\n';
    }
}
#endif  // TEST_CASE() == 4

int main()
{
    std::cout << "Running " << TEST_CASE() << std::endl;
    test();
    return 0;
}
