#include <iostream>

#include "stack.hpp"
#include "stack_rpn.hpp" // Put your code in this file
//#include "stack_enhanced.hpp"

int main(int argc, char **argv)
{
    // Basic interface
    auto stack = Stack<int>(100);
    stack.push(2);
    stack.push(2);
    stack.push(3);
    plus(stack);
    multiplies(stack);
    std::cout << "2 2 2 + * = " << stack.top() << '\n';

    // Advanced interface (optional)
    stack.clear();
    stack << 2 << 2 << 3;
    
    /*
    std::cout << "Stack content:";
    while (!stack.empty()) {
        std::cout << ' ' << stack.top();
        stack.pop();
    }
    std::cout << '\n';
    */
    
    //std::cout << "check" << std::endl;

    stack << plus;
    stack << multiplies;
    std::cout << "2 2 2 + * = " << stack.top() << '\n';

    stack << 2 << 5 << 18 << plus << multiplies;
    std::cout << "2 5 18 + * = " << stack.top() << '\n';

    

    return 0;
}
