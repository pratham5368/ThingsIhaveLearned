// meaning that you can write a single function or class that can work with different data types
//Template Functions
/*To create a template function, you use the template keyword followed by the type parameters or placeholders enclosed in angle brackets (< >).
Then, you define your function as you normally would, using the type parameters to specify the generic types.

Here’s an example of a simple template function that takes two arguments and returns the larger of the two:*/

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
//To use this function, you can either explicitly specify the type parameter:

int result = max<int>(10, 20);
Or, you can let the compiler deduce the type for you:

int result = max(10, 20);


//Template Classes
/*Similarly, you can create template classes using the template keyword. Here’s an example of a simple template class that represents a pair of values:*/

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 first, T2 second) : first(first), second(second) {}
};

//To use this class, you need to specify the type parameters when creating an object:

Pair<int, std::string> pair(1, "Hello");

//Template Specialization
/*Sometimes, you may need special behavior for a specific data type. In this case, you can use template specialization. For example, you can specialize
the Pair class for a specific type, like char:*/

template <>
class Pair<char, char> {
public:
    char first;
    char second;

    Pair(char first, char second) : first(first), second(second) {
        // Special behavior for characters (e.g., convert to uppercase)
        this->first = std::toupper(this->first);
        this->second = std::toupper(this->second);
    }
};

//Now, when you create a Pair object with char template arguments, the specialized behavior will be used:

Pair<char, char> charPair('a', 'b');