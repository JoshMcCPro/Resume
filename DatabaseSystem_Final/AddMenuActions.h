#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include "sqlite-amalgamation/sqlite3.h"
#include "Tables.h"
using namespace std;

// Adds Employee to database
void AddEmployee(const char* s);
// Adds Customer to database
void AddCustomer(const char* s);
// Adds Order to database
void AddOrder(const char* s);
// Adds Product to database
void AddProduct(const char* s);
// Adds Product Type to database
void AddProductType(const char* s);
// Adds Time Clock to database
void AddTimeClock(const char* s);

// Adds Employee to database
void AddEmployee(const char* s)
{
	Employee E;
	sqlite3* DB;
	string sql;

	char* messaggeError;
	int exit;
	bool IsValid = true;

	do
	{
		IsValid = false;

		try
		{
			cout << "Add Employee" << endl;
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

	sql = "INSERT INTO Employee (emp_ID, emp_FNAME, emp_LNAME, emp_TITLE) ";
	sql += "VALUES('" + to_string(E.emp_ID) + "', '" + E.emp_FNAME + "', '" + E.emp_LNAME + "', '" + E.emp_TITLE + "')";

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
// Adds Customer to database
void AddCustomer(const char* s)
{
	Customer C;
	sqlite3* DB;
	string sql;

	char* messaggeError;
	int exit;
	bool IsValid = true;

	do
	{
		IsValid = false;

		try
		{
			cout << "Add Customer" << endl;
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

	sql = "INSERT INTO Customer (cus_ID, cus_FNAME, cus_LNAME, cus_LOCATION) ";
	sql += "VALUES('" + to_string(C.cus_ID) + "', '" + C.cus_FNAME + "', '" + C.cus_LNAME + "', '" + C.cus_LOCATION + "')";

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
// Adds Order to database
void AddOrder(const char* s)
{
	Order O;
	Customer C;
	Product P;

	sqlite3* DB;
	string sql;

	char* messaggeError;
	int exit;
	bool IsValid = true;

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

	sql = "INSERT INTO Order (o_ID, cus_ID, pro_ID, o_TIME) ";
	sql += "VALUES('" + to_string(O.o_ID) + "', '" + to_string(C.cus_ID) + "', '" + to_string(P.pro_ID) + "', '" + O.o_TIME + "')";

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
// Adds Product to database
void AddProduct(const char* s)
{
	Product P;
	ProductType PT;
	sqlite3* DB;
	string sql;

	char* messaggeError;
	int exit;
	bool IsValid = true;

	do
	{
		IsValid = false;

		try
		{
			cout << "Add Product" << endl;
			cout << "----------------------------" << endl;
			cout << "Product ID: ";
			if (!(cin >> P.pro_ID))
			{
				cin.clear();
				cin.ignore();
				throw invalid_argument("You can not enter a letter as a number!");
			}

			cout << "Type Name: ";
			cin >> PT.type_NAME;
			cout << "Product Name: ";
			cin >> P.pro_NAME;
			cout << "Producr Cost: ";
			cin >> P.pro_COST;
			cout << "Producr Cost: ";
			cin >> P.pro_QUANTITY;
			cout << "----------------------------" << endl;
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
			IsValid = true;
		}

	} while (IsValid == true);

	exit = sqlite3_open(s, &DB);

	sql = "INSERT INTO Product (pro_ID, type_NAME, pro_NAME, pro_COST, pro_QUANTITY) ";
	sql += "VALUES('" + to_string(P.pro_ID) + "', '" + PT.type_NAME + "', '" + P.pro_NAME + "', '" + to_string(P.pro_COST) + "', '" + to_string(P.pro_QUANTITY) + "')";

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
// Adds Product Type to database
void AddProductType(const char* s)
{
	ProductType PT;
	sqlite3* DB;
	string sql;

	char* messaggeError;
	int exit;
	bool IsValid = true;

	do
	{
		IsValid = false;

		try
		{
			cout << "Add Product Type" << endl;
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

	sql = "INSERT INTO Product Type (type_NAME) ";
	sql += "VALUES('" + PT.type_NAME + "')";

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
// Adds Time Clock to database
void AddTimeClock(const char* s)
{
	TimeClock TC;
	sqlite3* DB;
	string sql;

	char* messaggeError;
	int exit;
	bool IsValid = true;

	do
	{
		IsValid = false;

		try
		{
			cout << "Add Product Type" << endl;
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
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
			IsValid = true;
		}

	} while (IsValid == true);

	exit = sqlite3_open(s, &DB);

	sql = "INSERT INTO Time Clock (tm_ID, emp_ID, options_NAME) ";
	sql += "VALUES('" + to_string(TC.tm_ID) + "', '"+ to_string(TC.emp_ID) +"', '"+ TC.options_NAME +"')";

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