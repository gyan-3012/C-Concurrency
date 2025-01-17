#include <iostream>
#include <thread>
#include <vector>

int main()
{
  // create threads
  std::vector<std::thread> threads;

  for (size_t i = 0; i < 10; ++i)
  {
    // create new thread from a Lamda
    threads.emplace_back([i]() {
      // wait for certain amount of time
      std::this_thread::sleep_for(std::chrono::milliseconds(10 * i));

      // perform work
      std::cout << "Hello from Wroker thread #" << i << std::endl;
    });
  }

  // do something in main()
  std::cout << "Hello from Main thread" << std::endl;
  
  // call join on all thread objects using a range-based loop
  for (auto &t : threads)
    t.join();

  return 0;
}

// Output:
// Hello from Wroker thread #0
// Hello from Main thread
// Hello from Wroker thread #1
// Hello from Wroker thread #2
// Hello from Wroker thread #3
// Hello from Wroker thread #4
// Hello from Wroker thread #5
// Hello from Wroker thread #6
// Hello from Wroker thread #7
// Hello from Wroker thread #8
// Hello from Wroker thread #9