#include <iostream>
#include <fstream>


const int OFFSET = 3;


void printTwoLines(int width);
void printHorizontalLine(int width);


int main() {
	std::ifstream settingsFile;

	int width, height;
	int playerStartColumn, playerStartRow;
	int enemyStartColumn, enemyStartRow;

	int playerCurrentColumn, playerCurrentRow;

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
		>> playerStartColumn >> playerStartRow
		>> enemyStartColumn >> enemyStartRow;
	
	// Print grid
	for (int i = 0; i < height; i++) {
		printTwoLines(width);
	}
	printHorizontalLine(width);
	
}


void printTwoLines(int width) {
	std::string secondLine;
	for (int i = 0; i < (width * OFFSET) + 1; i++) {
		if (i % 3 == 0) {
			secondLine += '|';
		} else {
			secondLine += ' ';
		}
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