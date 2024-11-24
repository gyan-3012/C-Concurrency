// Running multiple threads (Fork-Join Parallelism)
// 1. Split the flow of execution into a parallel thread ("fork")
// 2. Perform some work in both the main thread and the parallel thread
// 3. Wait for the parallel thread to finish and unite the split flow of execution again ("join")

#include <iostream>
#include <thread>
#include <vector>

void printHello()
{
  // perform work
  std::cout << "Hello from Worker thread #" << std::this_thread::get_id() << std::endl;
}

int main()
{
  // create threads
  std::vector<std::thread> threads;

  for (size_t i = 0; i < 5; ++i)
  {
    // copying thread objects causes a compile error
    // becasue threads doesn't contain copy constructor
    /*
    std::thread t(printHello);
    threads.push_back(t);
    */

    // moving thread objects will work (move semantics)
    threads.emplace_back(std::thread(printHello));
  }

  // do something in main()
  std::cout << "Hello from Main thread #" << std::this_thread::get_id() << std::endl;
  
  // call join on all thread objects using a range-based loop
  for (auto &t : threads)
    t.join();

  return 0;
}

// Output:
// Hello from Worker thread #139983117248256
// Hello from Worker thread #Hello from Worker thread #139983092070144
// Hello from Worker thread #139983108855552
// 139983083677440
// Hello from Main thread #139983117252416
// Hello from Worker thread #139983100462848

// Becasue the exection order of threads are not fixed so the console output of printHello function is intermingled