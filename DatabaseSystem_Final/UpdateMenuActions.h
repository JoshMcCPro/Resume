#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include "sqlite-amalgamation/sqlite3.h"
#include "Tables.h"

using namespace std;

// Update Employee 
void UpdateEmployee(const char* s);
// Update Customer 
void UpdateCustomer(const char* s);
//Updates Order 
void UpdateOrder(const char* s);
// Update Product 
void UpdateProduct(const char* s);
// Update Product Type 
void UpdateProductType(const char* s);
// Update Time Clock 
void UpdateTimeClock(const char* s);
// Displays database
static int callback(void* Notused, int argc, char** argv, char** azColName);


// Update Employee 
void UpdateEmployee(const char* s)
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
			cout << "Update Employee" << endl;
			cout << "----------------------------" << endl;
			cout << "Employee ID: ";
			if (!(cin >> E.emp_ID))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}

			cout << "Employee First Name: ";
			cin >> E.emp_FNAME;
			cout << "Employee Last Name: ";
			cin >> E.emp_LNAME;
			cout << "Employee Title: ";
			cin >> E.emp_TITLE;
			cout << "----------------------------" << endl;
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
			IsValid = true;
		}

	} while (IsValid == true);

	exit = sqlite3_open(s, &DB);

	string sql("UPDATE Employee SET emp_FNAME = '"+ E.emp_FNAME +"', emp_LNAME = '"+ E.emp_LNAME +"', emp_TITLE = '"+ E.emp_TITLE +"' WHERE emp_ID = '"+ to_string(E.emp_ID) +"'");

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
// Update Customer 
void UpdateCustomer(const char* s)
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
			cout << "Update Customer" << endl;
			cout << "----------------------------" << endl;
			cout << "Customer ID: ";
			if (!(cin >> C.cus_ID))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}

			cout << "Customer First Name: ";
			cin >> C.cus_FNAME;
			cout << "Customer Last Name: ";
			cin >> C.cus_LNAME;
			cout << "Customer Location: ";
			cin >> C.cus_LOCATION;
			cout << "----------------------------" << endl;
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
			IsValid = true;
		}

	} while (IsValid == true);

	exit = sqlite3_open(s, &DB);

	string sql("UPDATE Customer SET cus_FNAME = '" + C.cus_FNAME + "', cus_LNAME = '" + C.cus_LNAME + "', cus_LOCATION = '" + C.cus_LOCATION + "' WHERE cus_ID = '" + to_string(C.cus_ID) + "'");

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
//Updates Order 
void UpdateOrder(const char* s)
{
	Order O;
	Customer C;
	Product P;

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
			cout << "Add Order" << endl;
			cout << "----------------------------" << endl;
			cout << "Order ID: ";
			if (!(cin >> O.o_ID))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}

			cout << "Customer ID: ";
			if (!(cin >> C.cus_ID))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}

			cout << "Product ID: ";
			if (!(cin >> P.pro_ID))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}

			cout << "Order Time: ";
			cin >> O.o_TIME;
			cout << "----------------------------" << endl;
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
			IsValid = true;
		}

	} while (IsValid == true);

	exit = sqlite3_open(s, &DB);

	string sql("UPDATE Order SET o_TIME = '" + O.o_TIME + "' WHERE o_ID = '" + to_string(O.o_ID) + "'");

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
// Update Product 
void UpdateProduct(const char* s)
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
			cout << "Update Product" << endl;
			cout << "----------------------------" << endl;
			cout << "Product ID: ";
			if (!(cin >> P.pro_ID))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}

			cout << "Type Name: ";
			cin >> P.type_NAME;
			cout << "Product Name: ";
			cin >> P.pro_NAME;
			cout << "Product Cost: ";
			if (!(cin >> P.pro_COST))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}

			cout << "Product Quantity: ";
			if (!(cin >> P.pro_QUANTITY))
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

	string sql("UPDATE Product SET type_NAME = '" + P.type_NAME + "', pro_NAME = '" + P.pro_NAME + "', pro_COST = '" + to_string(P.pro_COST) + "pro_QUANTITY = '"+ to_string(P.pro_QUANTITY) +"' WHERE pro_ID = '" + to_string(P.pro_ID) + "'");

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
// Update Product Type 
void UpdateProductType(const char* s)
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
			cout << "Update Product Type" << endl;
			cout << "----------------------------" << endl;
			cout << "Type Name: ";
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

	string sql("UPDATE Product Type SET type_NAME = '" + PT.type_NAME + "'");

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
// Update Time Clock 
void UpdateTimeClock(const char* s)
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
			cout << "Update Time Clock" << endl;
			cout << "----------------------------" << endl;
			cout << "Time Clock ID: ";
			if (!(cin >> TC.tm_ID))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}

			cout << "Employee ID: ";
			if (!(cin >> TC.emp_ID))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}

			cout << "Option Name: ";
			cin >> TC.options_NAME;
			cout << "----------------------------" << endl;
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
			IsValid = true;
		}

	} while (IsValid == true);

	exit = sqlite3_open(s, &DB);

	string sql("UPDATE Order SET options_NAME = '" + TC.options_NAME + "' WHERE tm_ID = '" + to_string(TC.tm_ID) + "'");

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
// Displays database
static int callback(void* Notused, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++)
	{
		// column name and value
		cout << azColName[i] << ": " << argv[i] << endl;
	}

	cout << endl;

	return 0;
}