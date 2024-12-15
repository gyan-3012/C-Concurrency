// Starting thread using async (Task)
// In the case of async, if we will not give the launch parameter in async manually
// then at runtime, system will decide to execute thread function synchronously or asynchronously

#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

double divideByNumber(double num, double denom)
{
  // print system id of worker thread
  std::cout << "Worker thread id = " << std::this_thread::get_id() << std::endl;

  std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work
  
  if (denom == 0)
    throw std::runtime_error("Exception from thread: Division by zero!");
  
  return num / denom;
}

int main()
{
  // print system id of worker thread
  std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;

  // use async to start a task
  double num = 42.0, denom = 2.0;

  std::future<double> ftr = std::async(divideByNumber, num, denom);
  // std::future<double> ftr = std::async(std::launch::async, divideByNumber, num, denom);
  // std::future<double> ftr = std::async(std::launch::deferred, divideByNumber, num, denom);
  
  
  // retrieve result within try-catch-block
  try
  {
    double result = ftr.get();
    std::cout << "Result = " << result << std::endl;
  }
  catch (std::runtime_error e)
  {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

// std::launch parameter of async
// 1. std::async(std::launch::async, ...) => thread fxn will run asynchronously
// 2. std::async(std::launch::deferred, ...) => thread fxn will run synchronously
// 3. without launch param: system will decide at runtime based on available cores/threads

// Output: std::launch::async
// Main thread id = 140440530614080
// Worker thread id = 140440530609920
// Result = 21

// Output: std::launch::deferred
// Main thread id = 140442711574336
// Worker thread id = 140442711574336
// Result = 21

// Output: with launch param (better to use -> system will decide at runtime)
// Main thread id = ...
// Worker thread id = ...
// Result = 21

// Notes:
// Tasks uses the concept of thread pools and work stealing queues
// work stealing queues run a watchdog program to monitor available cores 
// and redistribute task accordingly

// Threads (more heavy weight) Vs. Tasks (more light weight)
// Thread: - join(), gen. by OS, alloc. memory / stack / kernel data structrue
// Task: - uses a pool of already created threads
