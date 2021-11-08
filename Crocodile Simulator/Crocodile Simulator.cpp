/*I modified the code so its a game.You need to try an scape the 'safe' zone with enough crocodile food so you can survive at the border and dont get eaten by the crocodiles.
In the 'safe zone you can find food suplies so you have more food and crocodiles that will attack you. This code can be improve using fucntions to not rewrite lots of code and 
a random generate number for the spawning of crocodiles and food supply so its not the same spawning areas and even the creator of the code struggles to win.*/

#include <iostream> 	
#include <string> 	

using namespace std;


class Position
{
public:
	int x;
	int y;

	
	Position()
	{
		x = 5;
		y = 5;
	}
};


class Player
{
public:
	string playerName;
	int crocFood;
	Position pos;	
	bool enoughCrocFood;
	bool understandRules;


	Player()
	{
		playerName = "default player name";
		crocFood = 0;
		enoughCrocFood = false;
		understandRules = false;
	}
};

int main()
{
	Player player1;

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Welcome, player, to Crocodile Simulator. Please enter your name: ";
	cin >> player1.playerName;
	cout << endl;

	while (player1.enoughCrocFood == false)
	{
		cout << "Okay " << player1.playerName << ", how many grams of crocodile food are you carrying? : " ;
		cin >> player1.crocFood;

		//Statement for the correct amount of crocodile food 

		if (player1.crocFood <= 100 && player1.crocFood > 1)
		{
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Good. Let's get cracking. You need to leave the 'safe' zone with enough food to survive in the outside world" << endl;
			cout << endl;
			player1.enoughCrocFood = true;

			while ((player1.pos.x > 0) && (player1.pos.x < 10) && (player1.pos.y > 0) && (player1.pos.y < 10))
			{

				cout << "Your current coordinates are (x = " << player1.pos.x << ", y = " << player1.pos.y << ")." << endl;

				//Making sure the player understand the rules of the game

				while (player1.understandRules == false)
				{
					cout << endl;
					cout << "Do you understand the rules (Yes/No) : ";
					string answerQuestion;
					cin >> answerQuestion;
					cout << endl;

					if (answerQuestion == "Yes")
					{
						cout << "Good luck then " << endl;
						player1.understandRules = true;
					}
					else if (answerQuestion == "No")
					{
						cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
						cout << "You need to leave the 'safe' zone with enough food to survive in the outside world" << endl;
						cout << endl;
						cout << "Your current coordinates are (x = " << player1.pos.x << ", y = " << player1.pos.y << ")." << endl;
						cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					}
					else
					{
						cout << "Invalid answer" << endl;
						cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					}
				}

				//Advice when youre close to the border

				if ((player1.pos.x == 1) || (player1.pos.x == 9) || (player1.pos.y == 1) || (player1.pos.y == 9))
				{
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << endl;
					cout << "Your almost outside the 'safe' zone, make sure you have enough food" << endl;
					cout << endl;
					cout << "You have " << player1.crocFood << " crocodile food with you."<< endl;
					cout << endl;
				}

				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << endl;

				cout << "Which way do you want to go (N/S/E/W)? : ";
				char answer;
				cin >> answer;
			    cout << endl;

			    //Changing Cordinates Depending of The User Input
				switch (answer)
				{
				case 'N':
					player1.pos.y = (player1.pos.y + 1);
					break;

				case 'S':
					player1.pos.y = (player1.pos.y - 1);
					break;

				case 'E':
					player1.pos.x = (player1.pos.x + 1);
					break;

				case 'W':
					player1.pos.x = (player1.pos.x - 1);
					break;

				default:
					cout << "Please enter a valid direction!" << endl;
					cout << endl;
					break;

				}

				//Crocodiles Food Supply Spawning Area

				if ((player1.pos.x == 2 && player1.pos.y == 3))
				{
					cout << "*******************************************************************************************************" << endl;
					cout << "You found a crocodile food supply that contains 30 of crocodile food. Good job" << endl;
					cout << endl;
					player1.crocFood = player1.crocFood + 30;
					cout << "You have " << player1.crocFood << " crocodile food with you." << endl;
					cout << "*******************************************************************************************************" << endl;
					cout << endl;
				}

				if ((player1.pos.x == 7 && player1.pos.y == 9))
				{
					cout << "*******************************************************************************************************" << endl;
					cout << "You found a crocodile food supply that contains 30 of crocodile food. Good job" << endl;
					cout << endl;
					player1.crocFood = player1.crocFood + 30;
					cout << "You have " << player1.crocFood << " crocodile food with you." << endl;
					cout << "*******************************************************************************************************" << endl;
					cout << endl;
				}

				//Crocodiles Spawning Areas
				//I know theres a simpler way of writing this using functions but i dont know how to call them with out giving me an error. 
				
				if ((player1.pos.x == 3 && player1.pos.y == 2))
				{
					Player player1;

					cout << "*******************************************************************************************************" << endl;
					if (player1.crocFood > 20)
					{
						cout << "You have found a crocodile. Luckily you had 20 of crocodile food and you use it as an opportunity to scape." << endl;
						player1.crocFood = player1.crocFood - 20;
						cout << "You have " << player1.crocFood << " crocodile food with you." << endl;
					}
					else
					{
						cout << "You dont have enough crocodile food so the crocodile choose you as his dinner." << endl;
						cout << "*******************************************************************************************************" << endl;
						return 0;
					}
				}
				if ((player1.pos.x == 9 && player1.pos.y == 2))
				{
					cout << "*******************************************************************************************************" << endl;
					if (player1.crocFood > 20)
					{
						cout << "You have found a crocodile. Luckily you had 20 of crocodile food and you use it as an opportunity to scape." << endl;
						player1.crocFood = player1.crocFood - 20;
						cout << "You have " << player1.crocFood << " crocodile food with you." << endl;
					}
					else
					{
						cout << "You dont have enough crocodile food so the crocodile choose you as his dinner." << endl;
						cout << "*******************************************************************************************************" << endl;
						return 0;
					}
				}
				if ((player1.pos.x == 2 && player1.pos.y == 8))
				{
					cout << "*******************************************************************************************************" << endl;
					if (player1.crocFood > 20)
					{
						cout << "You have found a crocodile. Luckily you had 20 of crocodile food and you use it as an opportunity to scape." << endl;
						player1.crocFood = player1.crocFood - 20;
						cout << "You have " << player1.crocFood << " crocodile food with you." << endl;
					}
					else
					{
						cout << "You dont have enough crocodile food so the crocodile choose you as his dinner." << endl;
						cout << "*******************************************************************************************************" << endl;
						return 0;
					}
				}
				if ((player1.pos.x == 5 && player1.pos.y == 10))
				{
					cout << "*******************************************************************************************************" << endl;
					if (player1.crocFood > 20)
					{
						cout << "You have found a crocodile. Luckily you had 20 of crocodile food and you use it as an opportunity to scape." << endl;
						player1.crocFood = player1.crocFood - 20;
						cout << "You have " << player1.crocFood << " crocodile food with you." << endl;
					}
					else
					{
						cout << "You dont have enough crocodile food so the crocodile choose you as his dinner." << endl;
						cout << "*******************************************************************************************************" << endl;
						return 0;
					}
				}
				if ((player1.pos.x == 7 && player1.pos.y == 7))
				{
					cout << "*******************************************************************************************************" << endl;
					if (player1.crocFood > 20)
					{
						cout << "You have found a crocodile. Luckily you had 20 of crocodile food and you use it as an opportunity to scape." << endl;
						player1.crocFood = player1.crocFood - 20;
						cout << "You have " << player1.crocFood << " crocodile food with you." << endl;
					}
					else
					{
						cout << "You dont have enough crocodile food so the crocodile choose you as his dinner." << endl;
						cout << "*******************************************************************************************************" << endl;
						return 0;
					}
				}
			}
		}

		//Answers for having an invalid amount of food

		if (player1.crocFood < 1)
		{
			cout << endl;
			cout << "Your not carrying any food. I suggest you take some with you and insert the amount you are taking" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		}
		if (player1.crocFood > 100)
		{
			
			cout << endl;
			cout << "Your carrying to much weight with you. Throw some crocodile food away and insert how much you carrying" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

		}
	}
	
	//Ending of game

	cout << "*******************************************************************************************************" << endl;
	cout << player1.playerName << ", you managed to scape the 'safe' zone." << endl;
	cout << endl;

	if (player1.crocFood >= 50)
	{
		cout << "Luckily, you have enough crocodile food to distract the crocodiles at the border." << endl;
		cout << endl;
		cout << "YOU SCAPE!!." << endl;
	}
	else
	{
		cout << "Due to a distinct lack of crocodile food the crocodiles at the border choose to eat you instead!" << endl;
		cout << endl;
		cout << "YOU LOSE." << endl;
	}
	cout << "*******************************************************************************************************" << endl;

	return 0;
}

// I tried to use this function for the crocodiles spawning so the code wasnt that messy. But i dont know how to use functions really well

/*int crocodileAppears()
{
	Player player1;

	cout << "*******************************************************************************************************" << endl;
	if (player1.crocFood > 20)
	{
		cout << "You have found a crocodile. Luckily you had 20 of crocodile food and you use it as an opportunity to scape." << endl;
		player1.crocFood = player1.crocFood - 20;
		cout << "You have " << player1.crocFood << " crocodile food with you." << endl;
	}
	else
	{
		cout << "You dont have enough crocodile food so the crocodile choose you as his dinner." << endl;
		cout << "*******************************************************************************************************" << endl;
		return 0;
	}
}*/
