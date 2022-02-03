# Naming

Follow google c++ code style naming (https://google.github.io/styleguide/cppguide.html#General_Naming_Rules), with the exception that
class data members should follow the same naming convention as struct data members.

# Includes

Files should only include what is required. That is:

For Header Files:
- The main header file of a library should include all the other headers so programmers using the library need only import the main library header. (may change this later)
- Header files should include everything they require to compile (i.e. referenced stuff), and no more, such that a programmer including the header already has all dependencies.

For situations where header files need to reference each other, you may provide for one a forward reference rather than a #include

For CPP Files:
- The implementation of a header must not explicitly include anything satisfied by the header's includes.
- Where the conditions are not satisfied above, files which utilise something must include it explicitly, rather than relying on a header they include to then also gain access to the thing itself.

Follow the order, with each category separated by newlines:
1. The header being implemented
2. C stdlib stuff
3. C++ stdlib stuff
4. Required libraries
5. This project

As GLFW requires GL, import GL before any imports of GLFW.

# Other Stuff

Avoid global variables

Avoid "using namespace."

Don't code like it's java

Don't code like it's javascript

Asterisk for pointers goes after the type.
