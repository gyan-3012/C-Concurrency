// Passing data to a thread function: Using class object as callback object

#include <iostream>
#include <thread>

class Vehicle
{
public:
  Vehicle(int id) : _id(id) {}

  void operator()()
  {
    std::cout << "Vehicle #" << _id << " object has been created\n";
  }

private:
  int _id;
};

int main()
{
  // create thread
  std::thread t = std::thread(Vehicle(1));  // Use copy initialization

  // do something in main()
  std::cout << "Finished work in main\n";

  // wait for threads to finish
  t.join();

  return 0;
}

// Note:
// the function object is copied into internal storage accessible to the new thread
// and the new thread invokes the operator () 

// Output:
// Finished work in main
// Vehicle #1 object has been created