//My first game, a number guessing game with a betting element, 01/29/21
#include <ctime>
#include <iostream> // Console input/output.
#include <string>   // Using strings.
using namespace std;

int main() // Entry point for every C++ program.
{
	// Declare variables.
	bool currentPlayer, quitGame = false, bettingPhase = false, rematch = false;
	int randomNum, guess;
	string player1, player2 ;
	unsigned int bet1;
	int pot = 0;
	int player1Pool = 100, player2Pool = 100, minimumBet = 5;
	unsigned int raise;
	char mrf = 'd';
	char mf;
	// Naming phase.
	cout << "Player 1, enter your name: ";
	cin >> player1;
	cout << "Okay, your name is " << player1 << endl << "=================" << endl;

	cout << "Player 2, enter your name: ";
	cin >> player2;
	cout << "Okay, your name is " << player2 << endl << "=================" << endl;
	
	// Randomize who goes first. You can also use a Boolean.
	srand((unsigned)time(NULL)); // Seeds the random number sequence
	currentPlayer = rand() % 2; // Sets currently player to 0 or 1. 

	// Start the game. Main game loop.
	cout << "Both players have a starting pool at $100, may the odds ever be in your favour. \n";
	while (bettingPhase == false) // !quitGame or quitGame != true
	{ 
		cout << "Minimum bets are placed at :$" << minimumBet << endl;
		player1Pool -= minimumBet;
		player2Pool -= minimumBet;
		pot += minimumBet * 2;
		cout << player1 << " your current pool is : $" << player1Pool << endl;
		cout << player2 << " your current pool is : $" << player2Pool << endl;
		cout << "The pot is at : $" << pot << endl << "=================" << endl;
		
		if (currentPlayer == 0) // if player 1 is going first
		{
			quitGame = false;
			// player 1 starts the bet
			cout << player1 << " you will go first, " << player2 << " you will go second." << endl;
			cout << player1 << " place your bet : $";
			cin >> bet1;
			player1Pool = player1Pool - bet1;
			cout << "You have $" << player1Pool << " remaining \n" << "=================" << endl;
			// Player 2 matches or raises
			cout << player2 << " would you like to (M)atch, (R)aise or (F)old the bet?";
			cin >> mrf;
			mrf= toupper(mrf);
			if (mrf== 'M') // If player2 matches the bet
			{
				player2Pool -=bet1;
				cout << "You have matched the bet of : $" << bet1  << endl;
				pot = bet1 + bet1 + (minimumBet * 2);
				cout << "You have $" << player2Pool << " remaining \n" << "=================" << endl;
			}
			if (mrf == 'R') // If player 2 raises the bet
			{
				cout << "You have delcared to raise the bet. How much would you like to raise it by? : $";
				cin >> raise;
				player2Pool -=(raise + bet1);
				cout  << "You have now bet : $" << raise + bet1 << " your remaining pool is : $" << player2Pool << endl;
				// ask player 1 if they want to m/f
				cout << "=================" << endl << player1 << " would you like to match or fold? M/F ";
				cin >> mf;
				mf = toupper(mf);
				
				if (mf == 'F') //if player 1 folds
				{
					cout << "You have folded your bet and lost this bet. You have  $" << player1Pool << " remaining. " << endl << "=================" << endl;
					player2Pool += bet1 + bet1 + raise;
					pot = 0;
					cout << player2 << " your pool is now $" << player2Pool  << endl;
					if (player1Pool <=0)
					{
						cout << player1 << " , it's been a pleasure doing buisness with you. Better luck next time!" << endl;
						cout << player2 << " , WINNER WINNER CHICKEN DINNER! " << endl;
						bettingPhase = true;
					}
					quitGame = true;
				}
				else // if player 1 matches
				{
					player1Pool -= raise;
					cout  << "You have matched the bet of : $" << bet1 + raise << ". Your pot is now equal to $" << player1Pool << endl;
					pot = bet1 + bet1 + raise + raise + (minimumBet * 2);
				}
			}
			if (mrf== 'F') //if player 2 folds
			{
				cout << "You have folded your bet and lost this bet. You have  $" << player2Pool << " remaining. " << endl << "=================" << endl;
				player1Pool += (minimumBet * 2) + bet1;
				pot = 0;
				cout << player1 << " your pool is now $" << player1Pool << endl;
				if (player2Pool <= 0)
				{
					cout << player1 << " , it's been a pleasure doing buisness with you. Better luck next time!" << endl;
					cout << player2 << " , WINNER WINNER CHICKEN DINNER! " << endl;
					bettingPhase = true;
					currentPlayer = !currentPlayer;
				}
				quitGame = true;
			}
		}
		else // if player 2 is going first
		{
		
			// player 2 starts the bet
			cout << player2 << " you will go first, " << player1 << " you will go second." << endl;
			cout << player2 << " place your bet : $";
			cin >> bet1;
			player2Pool = player2Pool - bet1;
			cout << "You have $" << player2Pool << " remaining \n" << "=================" << endl;
			// Player 1 matches or raises or fold
			cout << player1 << " would you like to (M)atch, (R)aise or (F)old the bet?";
			cin >> mrf;
			mrf = toupper(mrf);
			if (mrf == 'M') // If player1 matches the bet
			{
				player1Pool -= bet1;
				cout << "You have matched the bet of : $" << bet1 << endl;
				pot = bet1 + bet1 + (minimumBet * 2);
				cout << "You have $" << player1Pool << " remaining \n" << "=================" << endl;
			}
			if (mrf == 'R') // If player 1 raises the bet
			{
				cout << "You have delcared to raise the bet. How much would you like to raise it by? : $";
				cin >> raise;
				player1Pool -= (raise + bet1);
				cout << "You have now bet : $" << raise + bet1 << " your remaining pool is : $" << player1Pool << endl;
				// ask player 2 if they want to m/f
				cout << "=================" << endl << player2 << " would you like to match or fold? M/F ";
				cin >> mf;
				mf = toupper(mf);

				if (mf == 'F') //if player 2 folds
				{
					cout << "You have folded your bet and lost this bet. You have  $" << player2Pool << " remaining. " << endl << "=================" << endl;
					player1Pool += bet1 + bet1 + raise;
					pot = 0;
					cout << player1 << " your pool is now $" << player2Pool << endl;
					if (player2Pool <= 0)
					{
						cout << player2 << " , it's been a pleasure doing buisness with you. Better luck next time!" << endl;
						cout << player1 << " , WINNER WINNER CHICKEN DINNER! " << endl;
						bettingPhase = true;
						
					}
					quitGame = true;
				}
				else // if player 2 matches
				{
					player2Pool -= raise;
					cout << "You have matched the bet of : $" << bet1 + raise << ". Your pot is now equal to $" << player2Pool << endl;
					pot = bet1 + bet1 + raise + raise + (minimumBet * 2);
				}
			}
			if (mrf == 'F') //if player 1 folds
			{
				cout << "You have folded your bet and lost this bet. You have  $" << player1Pool << " remaining. " << endl << "=================" << endl;
				player2Pool += (minimumBet * 2) + bet1;
				pot = 0;
				cout << player2 << " your pool is now $" << player2Pool << endl;
				currentPlayer = !currentPlayer;
				if (player1Pool <= 0)
				{
					cout << player1 << " , it's been a pleasure doing buisness with you. Better luck next time!" << endl;
					cout << player2 << " , WINNER WINNER CHICKEN DINNER! " << endl;
					bettingPhase = true;
				}
				quitGame = true;
			}
		}
	    
		cout << "The pot is : $" << pot << endl << "=================" << endl;
		// Create random number from 1 to 100 inclusive.
		srand((unsigned)time(NULL)); // Seeds the random number sequence.
		randomNum = 1 + rand() % 100; // Returns 1-100 inclusive
		 // Start the game. Main game loop.
		while (quitGame == false) // !quitGame or quitGame != true
		{
			// The ?: below is the conditional operator. It's a mini if/else.
			// The ?: below is the conditional operator. It's a mini if/else.
			cout << (currentPlayer == 0 ? player1 : player2) << ", enter a guess between 1-100: ";
			cin >> guess; // cin is dangerous. We're not accounting for fail.
			// Check the guess against three possibilities.
			if (guess < randomNum)
			{

				cout << "Your guess is too low." << endl << "=================" << endl;
			}
			else if (guess > randomNum)
			{
				cout << "Your guess is too high." << endl << "=================" << endl;
			}
			else // guess == randomNum
			{
				cout << "You win this round! The pot is yours!"<< endl;
				if (currentPlayer == 0)
				{
					player1Pool += pot;
					cout << player1 << " you have won : $" << pot << ". Your pool is : $" << player1Pool << endl << "=================" << endl;
				}
				else
				{
					player2Pool += pot;
					cout << player2 << " you have won : $" << pot << ". Your pool is : $" << player2Pool << endl << "=================" << endl;
				}
				if (player1Pool <= 0)
				{
					cout << player1 << ", it's been a pleasure doing buisness with you. Better luck next time!" << endl << "=================" << endl;
					cout << player2 << ", WINNER WINNER CHICKEN DINNER! " << endl << "=================" << endl;
					bettingPhase = true;
				}
				if (player2Pool <= 0)
				{
					cout << player2 << ", it's been a pleasure doing buisness with you. Better luck next time!" << endl << "=================" << endl;
					cout << player1 << ", WINNER WINNER CHICKEN DINNER! " << endl << "=================" << endl;
					bettingPhase = true;
				}
				pot = 0;
				currentPlayer = !currentPlayer;
				

				quitGame = true;

			}
			if (quitGame == false) // Game is still on, switch player.
				currentPlayer = !currentPlayer;

		}
		
	}
	system("pause"); // Pause the console before closing. Not portable.
	return 0;
}