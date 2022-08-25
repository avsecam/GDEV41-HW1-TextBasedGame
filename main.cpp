#include <iostream>
#include <fstream>


const int OFFSET = 3;


struct Position {
	int column, row;
};


void printTwoLines(int width, int row, Position playerPosition, Position enemyPosition);
void printHorizontalLine(int width);



int main() {
	std::ifstream settingsFile;

	bool enemyAlive = true;

	int width, height;
	Position playerStartPosition, enemyStartPosition;

	Position playerCurrentPosition, enemyCurrentPosition;

	std::cout << "Text-Based Game\n";
	
	// Load settings.txt
	settingsFile.open("./settings.txt");
	if (!settingsFile) {
		std::cerr << "Unable to open settings.txt.";
		exit(1);
	} else {
		std::cout << "SETTINGS LOADED!\n";
	}
	settingsFile
		>> width >> height
		>> playerStartPosition.column >> playerStartPosition.row
		>> enemyStartPosition.column >> enemyStartPosition.row;
	
	playerCurrentPosition = playerStartPosition;
	enemyCurrentPosition = enemyStartPosition;


	// Print grid
	for (int i = 0; i < height; i++) {
		printTwoLines(width, i, playerCurrentPosition, enemyCurrentPosition);
		}
		printHorizontalLine(width);
	
	// Game Loop
	while(enemyAlive)
	{
		bool positionChanged = false;
		std::string playerInput = "";

		std::cin >> playerInput;

		if (playerInput == "north" || playerInput == "n")
		{
			if(playerCurrentPosition.row > 0)
			{
				playerCurrentPosition.row -= 1;
			}
			else
			{
				playerCurrentPosition.row = height - 1;
			}
			positionChanged = true;
		}
		else if (playerInput == "south" || playerInput == "s")
		{
			if(playerCurrentPosition.row < height - 1)
			{
				playerCurrentPosition.row += 1;
			}
			else
			{
				playerCurrentPosition.row = 0;
			}
			positionChanged = true;
		}
		else if (playerInput == "east" || playerInput == "e")
		{
			if(playerCurrentPosition.column < width - 1)
			{
				playerCurrentPosition.column += 1;
			}
			else
			{
				playerCurrentPosition.column = 0;
			}
			positionChanged = true;
		}
		else if (playerInput == "west" || playerInput == "w")
		{
			if(playerCurrentPosition.column > 0)
			{
				playerCurrentPosition.column -= 1;
			}
			else
			{
				playerCurrentPosition.column = width - 1;
			}
			positionChanged = true;
		}
		else if (playerInput == "attack" || playerInput == "a")
		{
			if (playerCurrentPosition.column == enemyCurrentPosition.column && playerCurrentPosition.row == enemyCurrentPosition.row)
			{
				std::cout << "***   ***   *********   ***   ***   ***  ***  ***   *********   ***   ***" << std::endl;
				std::cout << "***   ***   *********   ***   ***   ***  ***  ***   *********   ****  ***" << std::endl;
				std::cout << " *******    ***   ***   ***   ***   ***  ***  ***      ***      ***** ***" << std::endl;
				std::cout << "   ***      ***   ***   ***   ***   ***  ***  ***      ***      *** *****" << std::endl;
				std::cout << "   ***      *********   *********   *************   *********   ***  ****" << std::endl;
				std::cout << "   ***      *********   *********   *************   *********   ***   ***" << std::endl;
				enemyAlive = false;
			}
			else
			{
				std::cout << "ATTACK MISSED!!!" << std::endl;
			}
		}
		else if (playerInput == "exit")
		{
			std::cout << "Player Left The Game" << std::endl;
			enemyAlive = false;
		}
		else
		{
			std::cout << "INVALID COMMAND" << std::endl;
		}

		if (positionChanged)
		{
			for (int i = 0; i < height; i++) {
			printTwoLines(width, i, playerCurrentPosition, enemyCurrentPosition);
			}
			printHorizontalLine(width);
			std::cout << "" << std::endl;
		}
	}
	
}


void printTwoLines(int width, int row, Position playerPosition, Position enemyPosition) {
	std::string secondLine;
	
	// Draw bars and spaces
	for (int i = 0; i < (width * OFFSET) + 1; i++) {
		if (i % OFFSET == 0) {
			secondLine += '|';
		} else {
			secondLine += ' ';
		}
	}

	if (row == playerPosition.row) {
		secondLine.replace((playerPosition.column * OFFSET) + 1, 1, "P");
	}
	if (row == enemyPosition.row) {
		secondLine.replace((enemyPosition.column * OFFSET) + 2, 1, "E");
	}

	printHorizontalLine(width);
	std::cout << secondLine << '\n';
}


void printHorizontalLine(int width) {
	std::string horizontalLine;
	for (int i = 0; i < (width * OFFSET) + 1; i++) {
		horizontalLine += '-';
	}
	std::cout << horizontalLine << '\n';
}