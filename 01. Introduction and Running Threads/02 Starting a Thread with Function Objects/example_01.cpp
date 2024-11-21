// Passing class object having overloaded function call operator to a thread

#include <iostream>
#include <thread>

class Vehicle
{
public:
  void operator()()
  {
    std::cout << "Vehicle object has been created\n";
  }
};

int main()
{
  // create thread
  // std::thread t0(Vehicle()); // C++'s most vexing parse

  std::thread t1((Vehicle()));  // Add an extra pair of parentheses

  std::thread t2 = std::thread(Vehicle());  // Use copy initialization

  std::thread t3{Vehicle()};  // Use uniform initialization with braces

  // do something in main()
  std::cout << "Finished work in main\n";

  // wait for threads to finish
  t1.join();
  t2.join();
  t3.join();

  return 0;
}

// 3 ways to pass callable objects to a thread:
// 1. Passing function pointers
// 2. Passing class objects containing overloaded function call operator ()
// 3. Lamda function (Anonymous inline function)


// Output: order may varry
// Vehicle object has been created
// Finished work in main
// Vehicle object has been created
// Vehicle object has been created