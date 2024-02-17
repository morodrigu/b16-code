#ifndef __stack_enhanced___
#define __stack_enhanced___

#include "stack.hpp"
#include "stack_rpn.hpp"

template <typename T> class StackEnhanced : public Stack<T>
{
  public:
    // Inherit the Stack<T> constructors as they are
    // https://en.cppreference.com/w/cpp/language/using_declaration
    using Stack<T>::Stack;

    void clear()
    {
        // This removes all elements from the stack
        while (!this->empty()) {
            this->pop(); }
    }
};

template <typename T>
StackEnhanced<T> &operator<<(StackEnhanced<T> &stack, const T &value)
{
    // Overload of operator<< so that elements can be pushed onto the stack via a notation like stack << value1 << value2.
        stack.push(value);
        return stack;
}


template <typename T>
StackEnhanced<T> &operator<<(StackEnhanced<T> &stack, Stack<T> (*operation)(StackEnhanced<T>&))
{
    // Overload of operator<< so that operations can be applied to the stack via a notation like stack << plus.
    operation(stack);
    return stack;
}




#endif // __stack_enhanced___