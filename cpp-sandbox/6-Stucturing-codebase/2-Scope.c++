//Scope refers to the visibility and accessibility of variables, functions, classes, and other identifiers in a C++ program.
// It determines the lifetime and extent of these identifiers

/*1.Global scope: Identifiers declared outside any function or class have a global scope. They can be accessed from any part of the 
program (unless hidden by a local identifier with the same name). The lifetime of a global identifier is the entire duration of the program.*/
#include <iostream>

int globalVar; // This is a global variable

int main() {
    std::cout << "Global variable: " << globalVar << std::endl;
}
/*2.Local scope: Identifiers declared within a function or a block have a local scope. They can be accessed only within the function 
or the block they were declared in. Their lifetime is limited to the duration of the function/block execution.*/
#include <iostream>

void localExample() {
    int localVar; // This is a local variable
    localVar = 5;
    std::cout << "Local variable: " << localVar << std::endl;
}

int main() {
    localExample();
    // std::cout << localVar << std::endl; //error: ‘localVar’ was not declared in this scope
}
/*3.Namespace scope: A namespace is a named scope that groups related identifiers together. Identifiers declared within a namespace 
have the namespace scope. They can be accessed using the namespace name and the scope resolution operator ::.*/
#include <iostream>

namespace MyNamespace {
    int namespaceVar = 42;
}

int main() {
    std::cout << "Namespace variable: " << MyNamespace::namespaceVar << std::endl;
}
/*4.Class scope: Identifiers declared within a class have a class scope. They can be accessed using the class name and the scope
resolution operator :: or, for non-static members, an object of the class and the dot . or arrow -> operator.*/
#include <iostream>

class MyClass {
public:
    static int staticMember;
    int nonStaticMember;

    MyClass(int value) : nonStaticMember(value) {}
};

int MyClass::staticMember = 7;

int main() {
    MyClass obj(10);
    std::cout << "Static member: " << MyClass::staticMember << std::endl;
    std::cout << "Non-static member: " << obj.nonStaticMember << std::endl;
}