#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <vector>
using namespace std;

void drawMan(int index);

int main()
{
  string input;
  int index = 0;
  char ch;
  bool done = true;
  vector<int> indexes;
  vector<char> wrongGuesses;

  cout << "Enter word to guess: ";
  cin >> input;

  char guess[input.length()];

  for(int i = 0; i < input.length(); i++)
  {
    guess[i] = '_';
  }

  while(true)
  {
    cout << "\033[2J\033[1;1H";

    drawMan(index);

    cout << endl;
    for(int i = 0; i < strlen(guess); i++)
    {
      cout << guess[i] << " ";
    }
    cout << endl;

    if(wrongGuesses.size() > 0)
    {
      cout << endl;
      for(int i = 0; i < wrongGuesses.size(); i++)
      {
        cout << wrongGuesses[i] << " ";
      }
      cout << endl;
    }

    if(index == 6)
    {
      cout << endl << "You lose! All guesses used up!";
      cin.ignore();
      cin.get();
      break;
    }
    for(int x = 0; x < input.length(); x++)
    {
      if(guess[x] == '_')
      {
        done = false;
        break;
      }
      else
        done = true;
    }
    if(done)
    {
      cout << endl << "You win! You guessed the word.";
      cin.ignore();
      cin.get();
      break;
    }

    cin.ignore();
    cout << endl << "Enter a character: ";
    cin.get(ch);

    for(int i = 0; i < input.length(); i++)
    {
      if(toupper(ch) == toupper(input.at(i)))
      {
        indexes.push_back(i);
      }
    }
    if(indexes.size() > 0)
    {
      for(int x: indexes)
      {
        guess[x] = input.at(x);
      }
      indexes.clear();
    }
    else
    {
      index++;
      wrongGuesses.push_back(toupper(ch));
    }
  }

  return 0;
}

void drawMan(int index)
{
  switch(index)
  {
    case 0:
      cout << "-----" << endl;
      cout << "|   |" << endl;
      cout << "|    " << endl;
      cout << "|    " << endl;
      cout << "|    " << endl;
      cout << "|    " << endl;
      cout << "|    " << endl;
      break;
    case 1:
      cout << "-----" << endl;
      cout << "|   |" << endl;
      cout << "|   0" << endl;
      cout << "|    " << endl;
      cout << "|    " << endl;
      cout << "|    " << endl;
      cout << "|    " << endl;
      break;
    case 2:
      cout << "-----" << endl;
      cout << "|   |" << endl;
      cout << "|   0" << endl;
      cout << "|   +" << endl;
      cout << "|   |" << endl;
      cout << "|    " << endl;
      cout << "|    " << endl;
      break;
    case 3:
      cout << "-----" << endl;
      cout << "|   |" << endl;
      cout << "|   0" << endl;
      cout << "| --+" << endl;
      cout << "|   |" << endl;
      cout << "|    " << endl;
      cout << "|    " << endl;
      break;
    case 4:
      cout << "-----" << endl;
      cout << "|   |" << endl;
      cout << "|   0" << endl;
      cout << "| --+--" << endl;
      cout << "|   |" << endl;
      cout << "|    " << endl;
      cout << "|    " << endl;
      break;
    case 5:
      cout << "-----" << endl;
      cout << "|   |" << endl;
      cout << "|   0" << endl;
      cout << "| --+--" << endl;
      cout << "|   |" << endl;
      cout << "|  /" << endl;
      cout << "|    " << endl;
      break;
    case 6:
      cout << "-----" << endl;
      cout << "|   |" << endl;
      cout << "|   0" << endl;
      cout << "| --+--" << endl;
      cout << "|   |" << endl;
      cout << "|  / \\" << endl;
      cout << "|    " << endl;
      break;
  }
}
