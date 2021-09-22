#include <iostream>

using std::cout;
using std::endl;

void signalCallbackHandler(int signum)
{
  if (signum == 2)
  {
    cout << "\nOw, you're leaving... Maybe next time !" << endl;
  }

  exit(signum);
}