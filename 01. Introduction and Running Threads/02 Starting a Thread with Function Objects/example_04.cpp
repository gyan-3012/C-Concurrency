// Lamda function Parameters

#include <iostream>

int main()
{
  int id = 0;

  // create lamda
  auto f = [](const int id) { std::cout << "ID = " << id << std::endl; };  // ID is passed as a parameter

  // execute function object and pass the parameter
  f(id);

  return 0;
}

// Output:
// ID = 0