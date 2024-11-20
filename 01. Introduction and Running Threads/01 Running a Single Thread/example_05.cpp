// Using join() as a barrier to control the flow of execution

#include <iostream>
#include <thread>

void threadFunction()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
  std::cout  << "Finished work 1 in thread\n";


  std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
  std::cout  << "Finished work 2 in thread\n";
}

int main()
{
  // create thread
  std::thread t(threadFunction);

  // wait for thread to finish
  t.join();

  // do something in main()
  std::this_thread::sleep_for(std::chrono::milliseconds(50)); //simulate work
  std::cout << "Finished work 1 in main\n";

  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "Finished work 2 in main\n";

  return 0;
}

// Output: The output will be fixed after repositioning join()
// Finished work 1 in thread
// Finished work 2 in thread
// Finished work 1 in main
// Finished work 2 in main