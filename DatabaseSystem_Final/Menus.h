#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <sqlite3.h>
#include "AddMenuActions.h"
#include "UpdateMenuActions.h"
#include "DeleteMenuActions.h"
using namespace std;

// Display Main Menu
void MainMenu(const char* s);
// Display Add Menu
void AddMenu(const char* s);
// Display Update Menu
void UpdateMenu(const char* s);
// Display Delete Menu
void DeleteMenu(const char* s);

// Display Main Menu
void MainMenu(const char* s)
{
	char menuSelect;
	bool quit = false;

	do
	{
		cout << "----------------------------" << endl;
		cout << "Menu" << endl;
		cout << "(A) Add Menu" << endl;
		cout << "(B) Update Menu" << endl;
		cout << "(C) Delete Menu" << endl;
		cout << "(D) Exit" << endl;
		cout << "----------------------------" << endl;

		cout << "What would you like to choose?" << endl;
		cin >> menuSelect;

		switch (menuSelect)
		{
		case 'A':
			AddMenu(s);
			break;
		case 'B':
			UpdateMenu(s);
			break;
		case 'C':
			DeleteMenu(s);
			break;
		case 'D':
			quit = true;
			break;
		default:
			cout << "Invalid" << endl;
			break;
		}

	} while (!quit);


}
// Display Add Menu
void AddMenu(const char* s)
{
	char menuSelect;
	bool quit = false;

	do
	{
		cout << "----------------------------" << endl;
		cout << "Add Menu" << endl;
		cout << "(A) Add Employee" << endl;
		cout << "(B) Add Customer" << endl;
		cout << "(C) Add Order" << endl;
		cout << "(D) Add Product" << endl;
		cout << "(E) Add Product Type" << endl;
		cout << "(F) Add Time Clock" << endl;
		cout << "(G) Back" << endl;
		cout << "----------------------------" << endl;

		cout << "What would you like to choose?" << endl;
		cin >> menuSelect;

		switch (menuSelect)
		{
		case 'A':
			AddEmployee(s);
			break;
		case 'B':
			AddCustomer(s);
			break;
		case 'C':
			AddOrder(s);
		case 'D':
			AddProduct(s);
			break;
		case 'E':
			AddProductType(s);
			break;
		case 'F':
			AddTimeClock(s);
			break;
		case 'G':
			quit = true;
			break;
		default:
			cout << "Invalid" << endl;
			break;
		}
	} while (!quit);

}
// Display Update Menu
void UpdateMenu(const char* s)
{
	char menuSelect;
	bool quit = false;

	do
	{
		cout << "----------------------------" << endl;
		cout << "Update Menu" << endl;
		cout << "(A) Update Employee" << endl;
		cout << "(B) Update Customer" << endl;
		cout << "(C) Update Order" << endl;
		cout << "(D) Update Product" << endl;
		cout << "(E) Update Product Type" << endl;
		cout << "(F) Update Time Clock" << endl;
		cout << "(G) Back" << endl;
		cout << "----------------------------" << endl;

		cout << "What would you like to choose?" << endl;
		cin >> menuSelect;

		switch (menuSelect)
		{
		case 'A':
			UpdateEmployee(s);
			break;
		case 'B':
			UpdateCustomer(s);
			break;
		case 'C':
			UpdateOrder(s);
		case 'D':
			UpdateProduct(s);
			break;
		case 'E':
			UpdateProductType(s);
			break;
		case 'F':
			UpdateTimeClock(s);
			break;
		case 'G':
			quit = true;
			break;
		default:
			cout << "Invalid" << endl;
			break;
		}

	} while (!quit);
}
// Display Delete Menu
void DeleteMenu(const char* s)
{
	char menuSelect;
	bool quit = false;

	do
	{
		cout << "----------------------------" << endl;
		cout << "Delete Menu" << endl;
		cout << "(A) Delete Employee" << endl;
		cout << "(B) Delete Customer" << endl;
		cout << "(C) Delete Order" << endl;
		cout << "(D) Delete Product" << endl;
		cout << "(E) Delete Product Type" << endl;
		cout << "(F) Delete Time Clock" << endl;
		cout << "(G) Back" << endl;
		cout << "----------------------------" << endl;

		cout << "What would you like to choose?" << endl;
		cin >> menuSelect;

		switch (menuSelect)
		{
		case 'A':
			DeleteEmployee(s);
			break;
		case 'B':
			DeleteCustomer(s);
			break;
		case 'C':
			DeleteOrder(s);
		case 'D':
			DeleteProduct(s);
			break;
		case 'E':
			DeleteProductType(s);
			break;
		case 'F':
			DeleteTimeClock(s);
			break;
		case 'G':
			quit = true;
			break;
		default:
			cout << "Invalid" << endl;
			break;
		}

	} while (!quit);
}
