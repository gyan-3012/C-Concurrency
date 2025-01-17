// Promise (sending end) - Future (Receiving end) communication channel
// used to send data & exception from worker threads to parent threads

#include <iostream>
#include <thread>
#include <future>

void modifyMessage(std::promise<std::string> && prms, std::string message)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(4000)); // simulate work
  std::string modifiedMessage = message + " has been modified";
  prms.set_value(modifiedMessage);
}

int main()
{
  // define message
  std::string messageToThread = "My Message";

  // create promise and future
  std::promise<std::string> prms;
  std::future<std::string> ftr = prms.get_future();

  // start thread and pass promise as argument
  // promise object cann't be copied so we are moving it as rvalue reference
  std::thread t(modifyMessage, std::move(prms), messageToThread);

  // print original message to console
  std::cout << "Original message from main(): " << messageToThread << std::endl;

  // retrieve modified message via future and print to console
  std::string messageFromThread = ftr.get();
  std::cout << "Modified message from thread(): " << messageFromThread << std::endl;

  // thread barrier
  t.join();

  return 0;
}

// Imp. Points about get() method on future comm. end
// - get will wait until data is set on the promise end using set_value() method
// - if get() is called later after set_value() has been called then it will get the value without any delay

// Output:
// Original message from main(): My Message
// Modified message from thread(): My Message has been modified