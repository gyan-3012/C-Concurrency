// Influence of the number of threads on the performance of a program
#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <vector>
#include <chrono>

void workerFunction(int n)
{
  // print system id of worker thread
  std::cout << "Worker thread id = " << std::this_thread::get_id() << std::endl;

  // perform work
  for (int i = 0; i < n; ++i)
  {
    sqrt(12345.6789);
  }
}

int main()
{
  // print system id of worker thread
  std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;

  // start time measurement
  std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

  // launch various tasks
  std::vector<std::future<void>> futures;
  // int nLoops = 1e7, nThreads = 5;
  int nLoops = 10, nThreads = 5;
  for (int i = 0; i < nThreads; ++i)
  {
    // futures.emplace_back(std::async(std::launch::async, workerFunction, nLoops));
    futures.emplace_back(std::async(std::launch::deferred, workerFunction, nLoops));
  }

  // wait for tasks to complete
  for (const std::future<void> &ftr : futures)
    ftr.wait();

  // stop time measurement and print execution time
  std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
  std::cout << "Execution finished after " << duration <<" microseconds" << std::endl;
  
  return 0;
}

// 1. int nLoops = 1e7 , nThreads = 5 , std::launch::async
// Output: ~247 milliseconds
// Main thread id = 140630705043264
// Worker thread id = 140630705039104
// Worker thread id = 140630688253696
// Worker thread id = 140630696646400
// Worker thread id = 140630679860992
// Worker thread id = 140630671468288
// Execution finished after 24767 microseconds

// 2. int nLoops = 1e7 , nThreads = 5 , std::launch::deferred
// Output: ~933 milliseconds
// Main thread id = 140247136159552
// Worker thread id = 140247136159552
// Worker thread id = 140247136159552
// Worker thread id = 140247136159552
// Worker thread id = 140247136159552
// Worker thread id = 140247136159552
// Execution finished after 93372 microseconds

// 3. int nLoops = 10 , nThreads = 5 , std::launch::async
// Output: ~0.4 milliseconds
// Main thread id = 139809684186944
// Worker thread id = 139809684182784
// Worker thread id = 139809659004672
// Worker thread id = 139809675790080
// Worker thread id = 139809667397376
// Worker thread id = 139809650611968
// Execution finished after 387 microseconds

// 4. int nLoops = 10 , nThreads = 5 , std::launch::deferred
// Output: 0.05 milliseconds
// Main thread id = 140584353662784
// Worker thread id = 140584353662784
// Worker thread id = 140584353662784
// Worker thread id = 140584353662784
// Worker thread id = 140584353662784
// Worker thread id = 140584353662784
// Execution finished after 48 microseconds
