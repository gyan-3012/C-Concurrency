// Creating a single thread and join it with main function
// So that main function will wait for thread function completion

#include <iostream>
#include <thread>

void threadFunction()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate work
  std::cout << "Finished work in thread\n";
}

int main()
{
  // Create thread
  std::thread t(threadFunction);


  // do something in the main() function
  std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simulate work
  std::cout << "Finished work in main\n";

  // wait for thread to finish
  t.join();

  return 0;
}