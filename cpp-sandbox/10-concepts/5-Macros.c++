/*Macros are preprocessing directives in C++ used by the preprocessor to perform text substitution. They are defined using the #define 
directive, followed by the macro name and the value to be substituted.

Macros can be used to define constants, create function-like macros, or perform conditional compilation.*/


//Constant macros are used to define symbolic constants for use in code. They do not use any memory and are replaced by the preprocessor before the compilation process.

#define PI 3.14159
//This macro defines a symbolic constant PI. You can use it in your code as if it were a regular variable.

double circumference = 2 * PI * radius;


//Function-like macros are similar to regular functions. They take a list of arguments and perform text substitution.



#define SQUARE(x) ((x) * (x))
//This macro defines a function-like macro SQUARE that calculates the square of a number.

int square_of_five = SQUARE(5); // expands to ((5) * (5))

///Conditional Macros can be used for conditional compilation using the #ifdef, #ifndef, #if, #else, #elif, and #endif directives.


#define DEBUG_MODE

#ifdef DEBUG_MODE
  // Code to be compiled only in debug mode
#else
  // Code to be compiled only if DEBUG_MODE is not defined
#endif