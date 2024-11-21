// Detaching a thread from blocking the main flow of execution

#include <iostream>
#include <thread>

void threadFunction()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
  std::cout << "Finished Work in thread\n";
}

int main()
{
  // Create thread
  std::thread t(threadFunction);

  // detach thread and continue with main
  t.detach();

  // do something in the main
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "Completed work in main\n";

  return 0;
}

// Note:
// detatch(): detach
// Be careful while using detach()
// Don't use data in the detached thread that may get out of scope or deleted