#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include <cassert>
#include <functional>

// Plus function
template <typename T>
Stack<T> plus(Stack<T> &stackIn){
    T a = stackIn.top();
    stackIn.pop();
    T b = stackIn.top();
    stackIn.pop();

    stackIn.push(a + b);
    return stackIn;

};

// Minus function
template <typename T>
Stack<T> minus(Stack<T> &stackIn){
    T a = stackIn.top();
    stackIn.pop();
    T b = stackIn.top();
    stackIn.pop();

    stackIn.push(b - a);
    return stackIn;
};


// Multiplies function
template <typename T>
Stack<T> multiplies(Stack<T> &stackIn){
    T a = stackIn.top();
    stackIn.pop();
    T b = stackIn.top();
    stackIn.pop();

    stackIn.push(a * b);
    return stackIn;
};


// Divides function
template <typename T>
Stack<T> divides(Stack<T> &stackIn){
    T a = stackIn.top();
    stackIn.pop();
    T b = stackIn.top();
    stackIn.pop();

    stackIn.push(b/a);
    return stackIn;
};


// Negate function
// Returning negated top element
template <typename T>
Stack<T> negate(Stack<T> &stackIn){
    T a = stackIn.top();
    stackIn.pop();

    stackIn.push(-1*a);
    return stackIn;
};

template <typename T>
Stack<T> &operator<<(Stack<T> &stack, const T &value)
{
    // Overload of operator<< so that elements can be pushed onto the stack via a notation like stack << value1 << value2.
        stack.push(value);
        return stack;
}

template <typename T>
Stack<T> &operator<<(Stack<T> &stack, Stack<T> (*operation)(Stack<T>&))
{
    // Overload of operator<< so that operations can be applied to the stack via a notation like stack << plus.
    operation(stack);
    return stack;
}


#endif // __stack_rpn__
