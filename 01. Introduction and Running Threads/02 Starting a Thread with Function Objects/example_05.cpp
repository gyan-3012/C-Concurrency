// Lamda function properties

#include <iostream>

int main()
{
  int id = 0; // Define an interger variable

  // capture by reference (immutable)
  auto f0 = [&id]() { std::cout << "a) ID in Lamda = " << id << std::endl; };

  // capture by value (mutable)
  auto f1 = [id]() mutable { std::cout  << "b) ID in Lambda = " << ++id << std::endl; };
  f1(); // call the closure and execure the code within the Lamda
  std::cout << "c) ID in Main = " << id << std::endl;

  // capture by reference (mutable)
  auto f2 = [&id]() mutable { std::cout << "d) ID in Lamda = " << ++id << std::endl; };
  f2();
  std::cout << "e) ID in Main = " << id << std::endl;

  // pass parameter
  auto f3 = [](const int id) { std::cout << "f) ID in Lamda = " << id << std::endl; };
  f3(++id);

  // observe the effect of capturing by reference at an earlier point in time
  f0();

  return 0;
}

// Output:
// b) ID in Lambda = 1
// c) ID in Main = 0
// d) ID in Lamda = 1
// e) ID in Main = 1
// f) ID in Lamda = 2
// a) ID in Lamda = 2