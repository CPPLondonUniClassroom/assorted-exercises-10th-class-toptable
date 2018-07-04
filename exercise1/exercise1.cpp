#include <algorithm>
#include <limits>
#include "exercise1.hpp"

// Requirements:
//   -- if i is even, returns true
//   -- if i is odd, returns false
bool is_even(int i)
{
    return i % 2 == 0;
}

// Requirements:
//   -- returns the number of odd numbers in the given vector
int count_odd(const std::vector<int>& vec)
{
    /*
    return (int)std::count_if(vec.begin(), vec.end(), [] (auto&& elem) {
      return is_even(elem);
    });
    */
    int ret = 0;
    std::for_each(vec.begin(), vec.end(), [&ret] (auto&& elem) {
        if(!is_even(elem))
            ++ret;
    });
    return ret;
}

// Requirements:
//   -- returns the sum of the even numbers in the vector
int even_sum(const std::vector<int>& vec)
{
    auto ret = 0;
    std::for_each(vec.begin(), vec.end(), [&ret] (auto&& elem) {
        if(is_even(elem))
            ret += elem;
    });
    return ret;
}

// Requirements:
//   -- returns a new vector containing only the elements of vec which are
//      divisible by p
std::vector<int> copy_if_divisible_by(const std::vector<int>& vec, int p)
{
    auto out = std::vector<int>{};
    std::for_each(vec.begin(), vec.end(), [&out, &p] (auto&& elem) {
        if(elem % p == 0)
            out.push_back(elem);
    });
    return out;
}

// Requirements:
//   -- returns the largest number in the vector which is divisible by 3, or
//      zero if there are no such numbers
int largest_div_by_three(const std::vector<int>& vec)
{
    int max = std::numeric_limits<int>::min();
    int matches = 0;
    std::for_each(vec.begin(), vec.end(), [&max, &matches] (auto&& elem) {
        if( (elem % 3 == 0) && (elem > max) ) {
            max = elem;
            matches++;
        }
    });
    return (matches > 0) ? max : 0;
}

// Requirements:
//   -- returns true if the elements in vec are sorted, and false otherwise
bool is_sorted(const std::vector<int>& vec)
{
    std::vector<int> work = copy_if_divisible_by(vec, 1); // nasty copy
    std::sort(work.begin(), work.end());
    return std::equal(vec.begin(), vec.end(), work.begin());
}
