/* Program name: Final_Programming_Project
Author: Joshua McCullough
Date last updated: 7/28/2021
Purpose: A text menu based application that allows someone to manipulate and access the data in the database */

#include <iostream>
#include <string>
#include <stdio.h>
#include <sqlite3.h>
#include "Menus.h"
#include "Tables.h"
using namespace std;

int main() {

	// gets database
	const char* dir = "C:\\Users\\JoshM\\Desktop\\Final_SQL.db";

	MainMenu(dir);

	return 0;
}