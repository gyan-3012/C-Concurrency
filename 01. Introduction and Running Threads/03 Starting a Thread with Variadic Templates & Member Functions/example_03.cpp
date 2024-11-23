// passing reference variable to a thread as function arguments

#include <iostream>
#include <thread>
#include <string>

void printName(std::string& name, int waitTime)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
  name += " (from Thread)";
  std::cout << name << std::endl;
}

int main()
{
  std::string name("Gyan");
  
  // starting thread
  std::thread t(printName, std::ref(name), 50);

  // wait for thread before returning
  t.join();

  // print name from main
  name += " (from Main)";
  std::cout << name << std::endl;

  return 0;
}

// Output:
// Gyan (from Thread)
// Gyan (from Thread) (from Main)