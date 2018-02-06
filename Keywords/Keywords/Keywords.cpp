#include "stdafx.h"
#include "iostream"
#include "string"
#include "cstdlib"
#include "ctime"

using namespace std;

int main()
{
	enum fields {WORD, HINT, NUM_FIELDS}; // the lists we can put questions and answers into
	enum difficulty {EASY, MEDIUM, HARD, NUM_DIFF_LEVEL}; // difficulty selector (not used)
	const int NUM_WORDS = 5; // the number of guessable words
	const string WORDS[NUM_WORDS][NUM_FIELDS] = //list of words with their hints
	{
	{ "wall", "Do you feel you're banging your head against something?" },
	{"glasses", "These might help you see the answer."},
	{"labored", "Goind slowly, isn't it?"},
	{"persistent", "Keep at it."},
	{"jumble", "It's what this game is all about!"},
	};

	cout << "There are " << NUM_DIFF_LEVEL << " difficulty levels.\n\n";
	srand(static_cast<unsigned int>(time(0))); //seeding a random number generator
	int choice = (rand() % NUM_WORDS); // using the random number generator to select a word
	string theWord = WORDS[choice][WORD]; //word to guess
	string theHint = WORDS[choice][HINT]; //hint for word
	string jumble = theWord; //mixing up the word
	int length = jumble.size(); 

	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	cout << "Welcome to Keywords!\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter -hint- for a hint.\n";
	cout << "Enter -quit to exit the program!\n";
	cout << "The jumble is: " << jumble; string guess;
	cout << "\nYour Guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "Sorry, that's not it.\n";
		}
		cout << "Your Guess: \n";
		cin >> guess;
	}

	if (guess == theWord)
	{
		cout << "You are correct Sir!\n";
	}

	cout << "Thanks for playing!\n";
	system("pause");

    return 0;
}

