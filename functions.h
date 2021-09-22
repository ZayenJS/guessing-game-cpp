#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void signalCallbackHandler(int signum)
{
  if (signum == 2)
  {
    cout << "\nOw, you're leaving... Maybe next time !" << endl;
  }

  exit(signum);
}

void checkUserResponse(int *numberToGuess, int *userResponse, int *min, int *max)
{
  cout << "Oops, try again, ";

  if (*numberToGuess > *userResponse)
  {
    *min = *min > *userResponse ? *min : *userResponse;
    cout << "it's more !\n";
  }
  else if (*numberToGuess < *userResponse)
  {
    *max = *max < *userResponse ? *max : *userResponse;
    cout << "it's less !\n";
  }
}

bool checkLimits(int *userResponse, int *min, int *max)
{
  bool isValid = true;

  if (*userResponse > *max)
  {
    isValid = false;
    cout << "That's way too high beyond " << *max << endl;
  }
  else if (*userResponse < *min)
  {
    isValid = false;
    cout << "That's way too low, minimum is " << *min << endl;
  }

  return isValid;
}

void askUser(string message, int *userResponse, int *tries)
{
  cout << message;
  cin >> *userResponse;
  *tries = *tries + 1;
}

void gameOver(int *tries)
{
  string message = "Congrats! You found the number in " + std::to_string(*tries);

  if (*tries > 1)
  {
    message += " tries";
  }
  else
  {
    message += " try";
  }

  cout << message << "!" << endl;
}