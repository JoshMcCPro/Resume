#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <sqlite3.h>
using namespace std;

//
//	*Table Variables*
//

// Order variables
struct Order {
	int o_ID;
	int cus_ID;
	int pro_ID;
	string o_TIME;
};
// Customer variables
struct Customer {
	int cus_ID;
	string cus_FNAME;
	string cus_LNAME;
	string cus_LOCATION;
};
// Employee variables
struct Employee {
	int emp_ID;
	string emp_FNAME;
	string emp_LNAME;
	string emp_TITLE;
};
// Product variables
struct Product {
	int pro_ID;
	string type_NAME;
	string pro_NAME;
	int pro_COST;
	int pro_QUANTITY;
};
// Product Type variables
struct ProductType {
	string type_NAME;
};
// Timer Clock variables
struct TimeClock {
	int tm_ID;
	int emp_ID;
	string options_NAME;
};
// Options variables
struct Options {
	string options_NAME;
};