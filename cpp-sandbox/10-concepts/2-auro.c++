//AUTOMATIC TYPE DEDUCTION

/*auto is a keyword, which is used for automatic type deduction. It automatically deduces the type of a variable from the type
of its initializer expression at compile time.It is useful when you are dealing with complex types or when the type of a variable 
is hard to predict. It can help in writing cleaner and less error-prone code.*/

#include <iostream>
#include <vector>

int main() {
    // Traditional way of declaring a variable:
    int myInt = 5;

    // Using auto for type deduction:
    auto myAutoInt = 5; // Automatically deduces the type as 'int'

    // Example with more complex types:
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    // Without auto, iterating the vector would look like this:
    for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // With auto, the iterator declaration becomes simpler:
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << std::endl;
    }
}


//if you don’t provide an initial value, you will get a compile-time error:
auto myVar; // Error: Cannot deduce the type without initializer

//also use auto with function return types to let the compiler automatically deduce the return type based on the returned expression:

auto add(int x, int y) {
    return x + y; // The compiler deduces the return type as 'int'
}