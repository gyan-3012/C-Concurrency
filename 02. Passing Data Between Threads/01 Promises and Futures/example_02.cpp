// Wait for data to set on the promise end end or a particular timeout duration
#include <iostream>
#include <thread>
#include <future>
#include <cmath>

void computeSqrt(std::promise<double> &&prms, double input)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // simulate work
  double output = sqrt(input);
  prms.set_value(output);
}

int main()
{
  // define input data
  double inputData = 42.0;

  // create promise and future
  std::promise<double> prms;
  std::future<double> ftr = prms.get_future();

  // start thread and pass promise as argument
  std::thread t(computeSqrt, std::move(prms), inputData);
  
  // wait for result to become available
  auto status = ftr.wait_for(std::chrono::milliseconds(1000));

  //check the future_status is ready, timeout or deferred
  if (status == std::future_status::ready) // result is ready
  {
    std::cout << "Result = " << ftr.get() << std::endl;
  }
  // timeout has expired or function has not yet been started
  else if (status == std::future_status::timeout || status == std::future_status::deferred)
  {
    std::cout << "Result unavailable" << std::endl;
  }
  
  // thread barrier
  t.join();
  
  return 0;
}

// Imp Notes: wait(), or wait_for(timeout) method on the future end
// ftr.wait() => it will block the execution until data is available to get at future end
// ftr.wait_for(timeout) => it will wait for timeout period or data is ready before timeout period

// Output
// double output = Result unavailable