// Example code to get the number of CPU cores of a system

#include <iostream>
#include <thread>

int main()
{
  unsigned int nCores = std::thread::hardware_concurrency();
  std::cout << "This machine supports concurreny with " << nCores << " cores available" << std::endl;

  return 0;
}