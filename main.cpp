#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include "functions.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  signal(SIGINT, signalCallbackHandler);

  srand(time(NULL));

  int min = 0;
  int max = 100;
  int numberToGuess = rand() % max + 1;
  int userResponse;
  bool validUserResponse = true;
  int tries = 0;
  string message = "Enter a number between " + std::to_string(min) + " and " + std::to_string(max) + ": ";

  cout << "Let's play a game !\n";
  askUser(message, &userResponse, &tries);

  while (numberToGuess != userResponse)
  {
    validUserResponse = checkLimits(&userResponse, &min, &max);

    if (validUserResponse)
    {
      checkUserResponse(&numberToGuess, &userResponse, &min, &max);
    }

    message = "Enter another number between " + std::to_string(min) + " and " + std::to_string(max) + ": ";

    askUser(message, &userResponse, &tries);
  }

  gameOver(&tries);

  return 0;
}