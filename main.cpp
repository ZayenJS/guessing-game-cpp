#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include "exit.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
  signal(SIGINT, signalCallbackHandler);
  srand(time(NULL));
  int min = 0;
  int max = 100;
  int numberToGuess = rand() % max + 1;
  int userResponse;

  cout << "Let's play a game !\n";
  cout << "Enter a number between " << min << " and " << max << ": ";
  cin >> userResponse;
  int tries = 1;

  while (numberToGuess != userResponse)
  {
    cout << "\nOops, try again, ";

    if (numberToGuess > userResponse)
    {
      min = min > userResponse ? min : userResponse;
      cout << "it's more !\n";
    }
    else if (numberToGuess < userResponse)
    {
      max = max < userResponse ? max : userResponse;
      cout << "it's less !\n";
    }

    cout << "Enter another number between " << min << " and " << max << ": ";
    cin >> userResponse;
    tries++;
  }

  cout << "Congrats! You found the number in " << tries << " tries!" << endl;

  return 0;
}