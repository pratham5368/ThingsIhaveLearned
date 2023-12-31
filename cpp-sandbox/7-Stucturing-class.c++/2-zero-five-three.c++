
/*The Rule of Zero states that if a class or structure does not explicitly manage resources, it should not define anyof the special
member functions, i.e., destructor, copy constructor, copy assignment operator, move constructor, and move assignment operator.
The compiler will automatically generate these functions, and the behavior will be correct for managing resources like memory and file handles.*/



struct MyResource {
    std::string name;
    int value;
};
//In this example, MyResource is a simple structure that does not manage any resources, so it does not define any special member functions.
//The compiler will generate them automatically, and the behavior will be correct.


/*The Rule of Three states that a class or structure that manages resources should define the following three special member functions:

1.Destructor
2.Copy constructor
3.Copy assignment operator
These functions are necessary for proper resource management, such as releasing memory or correctly handling deep copies.*/


class MyResource {
public:
    // Constructor and destructor
    MyResource() : data(new int[100]) {} 
    ~MyResource() { delete[] data; } 

    // Copy constructor
    MyResource(const MyResource& other) : data(new int[100]) {
        std::copy(other.data, other.data + 100, data);
    }

    // Copy assignment operator
    MyResource& operator=(const MyResource& other) {
        if (&other == this) { return *this; }
        std::copy(other.data, other.data + 100, data);
        return *this;
    }

private:
    int* data;
};
//MyResource is a class that manages a resource (an array of integers), so it defines the destructor copy constructor, andcopy assignment operator.



/*The Rule of Five extends the Rule of Three to include two additional special member functions:

1.Move constructor
2.Move assignment operator
Modern C++ introduces move semantics, which allows for more efficient handling of resources by transferring ownership without
necessarily copying all the data.*/


class MyResource {
public:
    // Constructors and destructor
    MyResource() : data(new int[100]) {}
    ~MyResource() { delete[] data; }

    // Copy constructor
    MyResource(const MyResource& other) : data(new int[100]) {
        std::copy(other.data, other.data + 100, data);
    }

    // Copy assignment operator
    MyResource& operator=(const MyResource& other) {
        if (&other == this) { return *this; }
        std::copy(other.data, other.data + 100, data);
        return *this;
    }

    // Move constructor
    MyResource(MyResource&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Move assignment operator
    MyResource& operator=(MyResource&& other) noexcept {
        if (&other == this) { return *this; }
        delete[] data;
        data = other.data;
        other.data = nullptr;
        return *this;
    }

private:
    int* data;
};