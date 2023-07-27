#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <sqlite3.h>
#include "Tables.h"
using namespace std;

// Delete Employee 
void DeleteEmployee(const char* s);
// Delete Customer 
void DeleteCustomer(const char* s);
// Delete Order 
void DeleteOrder(const char* s);
// Delete Product 
void DeleteProduct(const char* s);
// Delete Product Type 
void DeleteProductType(const char* s);
// Delete Time Clock 
void DeleteTimeClock(const char* s);
// Displays database
static int callback(void* Notused, int argc, char** argv, char** azColName);

// Delete Employee 
void DeleteEmployee(const char* s)
{
	Employee E;
	sqlite3* DB;
	string List;

	char* messaggeError;
	int exit;
	bool IsValid = true;

	cout << "Employee List" << endl;
	cout << "----------------------------" << endl;

	exit = sqlite3_open(s, &DB);

	List = "SELECT *";
	List += " FROM Employee";

	sqlite3_exec(DB, List.c_str(), callback, NULL, NULL);

	do
	{
		IsValid = false;

		try
		{
			cout << "Delete Employee" << endl;
			cout << "----------------------------" << endl;
			cout << "Employee ID: ";
			if (!(cin >> E.emp_ID))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}
			cout << "----------------------------" << endl;
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
			IsValid = true;
		}

	} while (IsValid == true);

	exit = sqlite3_open(s, &DB);

	string sql("DELETE FROM Employee WHERE emp_ID = '" + to_string(E.emp_ID) + "'");

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		cerr << "Error Insert" << endl;
		sqlite3_free(messaggeError);
	}
	else
	{
		cout << "Records created Successfully!" << endl;
	}

}
// Delete Customer 
void DeleteCustomer(const char* s)
{
	Customer C;
	sqlite3* DB;
	string List;

	char* messaggeError;
	int exit;
	bool IsValid = true;

	cout << "Customer List" << endl;
	cout << "----------------------------" << endl;

	exit = sqlite3_open(s, &DB);

	List = "SELECT *";
	List += " FROM Customer";

	sqlite3_exec(DB, List.c_str(), callback, NULL, NULL);

	do
	{
		IsValid = false;

		try
		{
			cout << "Delete Customer" << endl;
			cout << "----------------------------" << endl;
			cout << "Customer ID: ";
			if (!(cin >> C.cus_ID))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}
			cout << "----------------------------" << endl;
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
			IsValid = true;
		}

	} while (IsValid == true);

	exit = sqlite3_open(s, &DB);

	string sql("DELETE FROM Customer WHERE cus_ID = '" + to_string(C.cus_ID) + "'");

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		cerr << "Error Insert" << endl;
		sqlite3_free(messaggeError);
	}
	else
	{
		cout << "Records created Successfully!" << endl;
	}
}
// Delete Order 
void DeleteOrder(const char* s)
{
	Order O;
	sqlite3* DB;
	string List;

	char* messaggeError;
	int exit;
	bool IsValid = true;

	cout << "Order List" << endl;
	cout << "----------------------------" << endl;

	exit = sqlite3_open(s, &DB);

	List = "SELECT *";
	List += " FROM Order";

	sqlite3_exec(DB, List.c_str(), callback, NULL, NULL);

	do
	{
		IsValid = false;

		try
		{
			cout << "Delete Order" << endl;
			cout << "----------------------------" << endl;
			cout << "Order ID: ";
			if (!(cin >> O.o_ID))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}
			cout << "----------------------------" << endl;
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
			IsValid = true;
		}

	} while (IsValid == true);

	exit = sqlite3_open(s, &DB);

	string sql("DELETE FROM Order WHERE o_ID = '" + to_string(O.o_ID) + "'");

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		cerr << "Error Insert" << endl;
		sqlite3_free(messaggeError);
	}
	else
	{
		cout << "Records created Successfully!" << endl;
	}
}
// Delete Product 
void DeleteProduct(const char* s)
{
	Product P;
	sqlite3* DB;
	string List;

	char* messaggeError;
	int exit;
	bool IsValid = true;

	cout << "Product List" << endl;
	cout << "----------------------------" << endl;

	exit = sqlite3_open(s, &DB);

	List = "SELECT *";
	List += " FROM Product";

	sqlite3_exec(DB, List.c_str(), callback, NULL, NULL);

	do
	{
		IsValid = false;

		try
		{
			cout << "Delete Product" << endl;
			cout << "----------------------------" << endl;
			cout << "Product ID: ";
			if (!(cin >> P.pro_ID))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}
			cout << "----------------------------" << endl;
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
			IsValid = true;
		}

	} while (IsValid == true);

	exit = sqlite3_open(s, &DB);

	string sql("DELETE FROM Product WHERE pro_ID = '" + to_string(P.pro_ID) + "'");

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		cerr << "Error Insert" << endl;
		sqlite3_free(messaggeError);
	}
	else
	{
		cout << "Records created Successfully!" << endl;
	}
}
// Delete Product Type 
void DeleteProductType(const char* s)
{
	ProductType PT;
	sqlite3* DB;
	string List;

	char* messaggeError;
	int exit;
	bool IsValid = true;

	cout << "Product Type List" << endl;
	cout << "----------------------------" << endl;

	exit = sqlite3_open(s, &DB);

	List = "SELECT *";
	List += " FROM Product Type";

	sqlite3_exec(DB, List.c_str(), callback, NULL, NULL);

	do
	{
		IsValid = false;

		try
		{
			cout << "Delete Product Type" << endl;
			cout << "----------------------------" << endl;
			cout << "Product Type Name: ";
			cin >> PT.type_NAME;
			cout << "----------------------------" << endl;
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
			IsValid = true;
		}

	} while (IsValid == true);

	exit = sqlite3_open(s, &DB);

	string sql("DELETE FROM Product Type WHERE type_NAME = '" + PT.type_NAME + "'");

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		cerr << "Error Insert" << endl;
		sqlite3_free(messaggeError);
	}
	else
	{
		cout << "Records created Successfully!" << endl;
	}
}
// Delete Time Clock 
void DeleteTimeClock(const char* s)
{
	TimeClock TC;
	sqlite3* DB;
	string List;

	char* messaggeError;
	int exit;
	bool IsValid = true;

	cout << "Time Clock List" << endl;
	cout << "----------------------------" << endl;

	exit = sqlite3_open(s, &DB);

	List = "SELECT *";
	List += " FROM Time Clock";

	sqlite3_exec(DB, List.c_str(), callback, NULL, NULL);

	do
	{
		IsValid = false;

		try
		{
			cout << "Delete Time Clock" << endl;
			cout << "----------------------------" << endl;
			cout << "Time Clock ID: ";
			if (!(cin >> TC.tm_ID))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}
			cout << "----------------------------" << endl;
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
			IsValid = true;
		}

	} while (IsValid == true);

	exit = sqlite3_open(s, &DB);

	string sql("DELETE FROM Time Clock WHERE tm_ID = '" + to_string(TC.tm_ID) + "'");

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		cerr << "Error Insert" << endl;
		sqlite3_free(messaggeError);
	}
	else
	{
		cout << "Records created Successfully!" << endl;
	}
}
