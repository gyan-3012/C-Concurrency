// Variadic Template: Thread constructor can take multiple arguments (after C++11)
// Thread cons. can be called with a funtion and all of its argurments

#include <iostream>
#include <thread>
#include <string>

void printID(int id)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "ID = " << id << std::endl;
}

void printIDAndName(int id, std::string name)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << "ID = " << id << ", name = " << name << std::endl;
}

int main()
{
  int id = 0; // Define an integer variable

  // starting threads usinng variadic templates
  std::thread t1(printID, id);
  std::thread t2(printIDAndName, ++id, "Gyan");
  // std::thread t3(printIDAndName, ++id); // this produces a compiler erorr

  // wait for threads before returning
  t1.join();
  t2.join();
  // t3.join();

  return 0;
}

// Output:
// ID = 0
// ID = 1, name = Gyan