#include <iostream>

enum class GameState
{
	Scan,
	CoordinateSelection,
	SelectMissile,
	Exit
};

struct Hello
{
	void initialize();
};

struct Player 
{
	int x = 0;
	int y = 0;
	int score = 0;
	int selectMissile = 0;

	bool mapScanning(); 
	void inputYourCoordinatesPlease();
	void missileSelection();
};

struct map
{
	int array_map[10][10] =
	{
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		{1, 0, 0, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 1, 0, 1, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}

	};
};

int main()
{
	GameState gameState{ GameState::CoordinateSelection };
	Hello message;
	Player player;

	switch (gameState)
	{
	case GameState::CoordinateSelection:
		message.initialize();
		player.inputYourCoordinatesPlease();
		gameState = GameState::SelectMissile;
		break;

	case GameState::SelectMissile:
		player.missileSelection();
		gameState = GameState::Scan;
		break;

	case GameState::Scan:
		player.mapScanning();
		if (!player.mapScanning())
		{
			gameState = GameState::CoordinateSelection;
		}
		else
		{
			gameState = GameState::Exit;
		}
		break;
	}

	system("Pause");
	return 0;
}

bool Player::mapScanning()
{
	std::string messageBadLaunch[1];
	std::string messageGoodLaunch[1];
	bool GoodLaunch = true;

	messageBadLaunch[0] = "Your launch will probably not Hit the target, try entering different Coordinated! \n";

	messageGoodLaunch[0] = "Your launch is in range of the target (you might hit it!!!) \n";

	if (x > 10 || y > 10)
	{
		for (int i = 0; i < 1; i++)
		{
			std::cout << messageBadLaunch[i];
			GoodLaunch = false;
		}
	}

	if (x <= 10 || y <= 10)
	{
		for (int i = 0; i < 1; i++)
		{
			std::cout << messageGoodLaunch[i];
			GoodLaunch = true;
		}
	}
}

void Hello::initialize()
{
	std::string messageToPlayer[5];
	messageToPlayer[0] = "Welcome to the Missile Game! \n";
	messageToPlayer[1] = "1 - Scan to see if there are any enemies there \n";
	messageToPlayer[2] = "2 - Choose your Missile \n";
	messageToPlayer[3] = "3 - Put in the Coordinated \n";
	messageToPlayer[4] = "4- Ready to launch your missile?? \n";
	for (int i = 0; i < 5; i++)
	{
		std::cout << messageToPlayer[i];
	}

}

void Player::missileSelection()
{
	std::string messageToPlayer[5];
	messageToPlayer[0] = "Choose a missile from down below \n";
	messageToPlayer[1] = "1- Fire Missile \n";
	messageToPlayer[2] = "2- Water Missile \n";
	messageToPlayer[3] = "3- Earth Missile\n";
	messageToPlayer[4] = "4- Air Missile\n";
	for (int i = 0; i < 4; i++)
	{
		std::cout << messageToPlayer[i];
	}
	std::cin >> selectMissile;
}

void Player::inputYourCoordinatesPlease()
{
	std::cout << "Please input your Coordinated for X and Y down below" << std::endl;

	std::cin >> x >> y;
}
