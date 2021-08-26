#include <iostream>
#include <string>
#include <utility>

#define TEST_CASE() 1

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
static void test()
{

}
#endif


int main()
{
    std::cout << "Running " << TEST_CASE() << std::endl;
    test();
    return 0;
}
