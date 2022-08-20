#include <iostream>
#include <fstream>


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
}