#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define TEST_CASE() 2

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
#endif

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
#endif


int main()
{
    std::cout << "Running " << TEST_CASE() << std::endl;
    test();
    return 0;
}
