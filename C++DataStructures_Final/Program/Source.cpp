/* Program name: Final Program
*  Author: Joshua McCullough
*  Date last updated: 7/30/2021
* Purpose: A game where you sort letters in alphabetical order to win the game
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Stack.h"
#include "GameFunctions.h"
using namespace std;

int main() {
	// variables
	DynamicStack Stack[3];
	GameFunctions GF;
	srand(time(NULL));

	// Main Menu
	GF.Menu(Stack);
	
	return 0;
}