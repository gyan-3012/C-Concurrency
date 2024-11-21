// Create multiple threads and detaching them 

#include <iostream>
#include <thread>

void evenFunctionThread()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
  std::cout << "Even Thread\n";
}

void oddFunctionThread()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
  std::cout << "Odd Thread\n";
}

int main()
{
  // Creating Odd and Even threads and detaching them
  for (int i = 0; i < 6; i++)
  {
    // when i is even
    if (i % 2 == 0)
    {
      std::thread t(evenFunctionThread);
      t.detach();
    }
    // when i is odd
    else
    {
      std::thread t(oddFunctionThread);
      t.detach();
    }
  }

  // ensure that main does not return before the threads are finished
  std::this_thread::sleep_for(std::chrono::milliseconds(2));

  std::cout << "End of main is reached\n";

  return 0;
}

// Output: Even and Odd thread order may be different in each execution
// Odd Thread
// Even Thread
// Odd Thread
// Even Thread
// Even Thread
// Odd Thread
// End of main is reached