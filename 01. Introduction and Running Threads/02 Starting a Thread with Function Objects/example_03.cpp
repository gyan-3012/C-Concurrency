// Lamda function: functor
// [] => capture list
// () => parameter list
// {} => main part

#include <iostream>

int main()
{
  // create lambdas
  int id = 0; // Define and inter variable

  // auto f0 = []() { std::cout << "ID = " << id << std::endl; };  // Error: 'id' cannot be accessed

  id++;
  auto f1 = [id]() { std::cout << "ID = " << id << std::endl; };  // OK, 'id' is captured by value

  id++;
  auto f2 = [&id]() {std::cout << "ID = " << id << std::endl; };  // OK, 'id' captured by reference

  // auto f3 = [id]() {std::cout << "ID = " << ++id << std::endl; };  // Error, 'id' may not be modified

  auto f4 = [id]() mutable { std::cout << "ID = " << ++id << std::endl; };  // OK, 'id' may be modified

  // execute lambdas
  f1();
  f2();
  f4();

  return 0;
}

// Output:
// ID = 1
// ID = 2
// ID = 3

// Note:
// functor: lamda function
// closure: f1, f2, f4: it has type and can be called through function call operator ()