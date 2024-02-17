#ifndef __radix_sort__
#define __radix_sort__

#include <algorithm>
#include <limits>
#include<iostream>

template <typename I>
static constexpr int num_digits_v =
    std::numeric_limits<typename I::value_type>::digits;

template <typename I>
void radix_sort(const I &begin, const I &end, int digit = num_digits_v<I>)
{
        // 'digit' is the number of digits to consider
    // Stop looping when this gets to zero
    if (digit <= 0){
        return;
    }

    // Define the two vectors to hold elements with 0 and 1 at this digit
    std::vector<typename I::value_type> zeros;
    std::vector<typename I::value_type> ones;

    // move through the list
    for (auto it = begin; it != end; ++it) {
        // Getting the value
        auto value = *it;

        // Check digit value
        bool digit_value = ((value & (1 << (digit - 1))) != 0);

        // If the digit is 1, put it in the ones list
        if (digit_value){
            ones.push_back(*it);
        }
        else{
            zeros.push_back(*it);
        }
    }

    // Combining into one list
    // Copying the zeros list in
    std::copy(zeros.begin(), zeros.end(), begin);
    // Copying the ones list into the zeros list
    std::copy(ones.begin(), ones.end(), std::next(begin, zeros.size()));   

    // Call the radix sort on the two sublists
    // Sorting the zeros list in place
    radix_sort(begin, std::next(begin, zeros.size()), digit - 1);
    
    // Sorting the ones list in place
    radix_sort(std::next(begin, zeros.size() + 1), end, digit - 1);
    

}

#endif // __radix_sort__