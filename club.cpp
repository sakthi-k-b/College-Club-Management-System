#include "newclub.h"
#include <iostream>
#include <set>
#include <string>
#include<vector>
#include<map>


using namespace std;
bool isInteger(const string &str) {
    try {
        size_t pos;
        stoi(str, &pos);
        // Check if the entire string was converted
        return pos == str.length();
    } catch (const invalid_argument &) {
        return false; // Not an integer
    } catch (const out_of_range &) {
        return false; // Out of range for integer
    }
}
// Constructor for Club
Club::Club(string n, string p, string h, int si, string yr, string exp)
    : name(n), pic(p), head(h), c_size(si), found_yr(yr), expenses(exp) {}
Club::~Club(){}


// Method to add achievements to the Club
void Club::add_achievements(string achievement) {
    achievements.push_back(achievement);
}


// Overload the << operator to output Club details
ostream &operator<<(ostream &out, const Club &c) {
   
    out << "Club Name : " << c.name << endl;
    out << "Club Head : " << c.head << endl;
    out << "Professor Incharge : " << c.pic << endl;
    out << "Founded Year : " << c.found_yr << endl;
    out << "Club Size : " << c.c_size << endl;
    out << "Club Expenses : " << c.expenses << endl;
    out << "Achievements: " << endl;
    for (const auto &ach : c.achievements) {
        out << " - " << ach << endl;
    }
    return out;
}


// Overload the >> operator to input Club details
istream &operator>>(istream &in, Club &c) {
    string yr;
    string exp;
    string si;
    cout << "Enter Club Name: ";
    in.ignore();
    getline(in,c.name);
    cout << "Enter Club Head: ";
    getline(in,c.head);
    cout << "Enter Professor Incharge of Club: ";
    getline(in,c.pic);
    cout << "Enter Club Founded Year: ";
    in >> yr;
    if(isInteger(yr))
    {
        c.found_yr=yr;
    }
    else
    {
        cout<<"Invalid Input\nFounding year initialized to 2020\n";
        c.found_yr="2020";
    }
    cout << "Enter Club Size: ";
    in >> si;//c.c_size
    if(isInteger(si))
    {
         c.c_size = stoi(si);
    }
    else
    {
        cout<<"Invalid Input\nClub size initialized to 3\n";
        c.c_size=3;
    }
    cout << "Enter Club Expenses: ";
    in >> exp;
    if(isInteger(exp))
    {
        c.expenses=exp;
    }
    else
    {
        cout<<"Invalid Input\nClub expenses initialized to 500\n";
        c.expenses="500";
    }


    string a;
    cout << "Enter 1 to add achievements, 0 to stop: ";
    in >> a;
    in.ignore();
    while (a == "1") {
        string achievement;
        cout << "Enter achievement: ";
        getline(in, achievement);
        c.add_achievements(achievement);


        cout << "Enter 1 to add more achievements, 0 to stop: ";
        in >> a;
        in.ignore();
    }
    if((a == "1")||(a == "0" ))
    {
       
    }
    else{
        cout<<"Invalid input\n";
    }
    /*
    int a;
    cout << "Enter 1 to add achievements, 0 to stop adding achievements." << endl;
    in >> a;
    in.ignore();  // Clear the newline for the following getline
    while (a != 0) {
        switch (a) {
            case 1: {
                string achievement;
                cout << "Enter achievement: ";
                getline(in, achievement);
                c.add_achievements(achievement);
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid Operation.." << endl;
                break;
        }
        cout << "Enter 1 to add achievements, 0 to stop adding achievements." << endl;
        in >> a;
        in.ignore();
    }
*/
    return in;
}


















/*
#include "newclub.h"
#include <iostream>
#include <set>
#include <string>
#include<vector>
#include<map>

using namespace std;

// Constructor for Club
Club::Club(string n, string p, string h, int si, int yr, int exp)
	: name(n), pic(p), head(h), c_size(si), found_yr(yr), expenses(exp) {}
Club::~Club(){}

// Method to add achievements to the Club
void Club::add_achievements(string achievement) {
	achievements.push_back(achievement);
}

// Overload the << operator to output Club details
ostream &operator<<(ostream &out, const Club &c) {
	out << "Club Name : " << c.name << endl;
	out << "Club Head : " << c.head << endl;
	out << "Professor Incharge : " << c.pic << endl;
	out << "Founded Year : " << c.found_yr << endl;
	out << "Club Size : " << c.c_size << endl;
	out << "Club Expenses : " << c.expenses << endl;
	out << "Achievements: " << endl;
	for (const auto &ach : c.achievements) {
    	out << " - " << ach << endl;
	}
	return out;
}

// Overload the >> operator to input Club details
istream &operator>>(istream &in, Club &c) {
	cout << "Enter Club Name: ";
	in >> c.name;
	cout << "Enter Club Head: ";
	in >> c.head;
	cout << "Enter Professor Incharge of Club: ";
	in >> c.pic;
	cout << "Enter Club Founded Year: ";
	in >> c.found_yr;
	cout << "Enter Club Size: ";
	in >> c.c_size;
	cout << "Enter Club Expenses: ";
	in >> c.expenses;

	int a;
	cout << "Enter 1 to add achievements, 0 to stop: ";
	in >> a;
	in.ignore();
	while (a == 1) {
    	string achievement;
    	cout << "Enter achievement: ";
    	getline(in, achievement);
    	c.add_achievements(achievement);

    	cout << "Enter 1 to add more achievements, 0 to stop: ";
    	in >> a;
    	in.ignore();
	}
	/*
	int a;
	cout << "Enter 1 to add achievements, 0 to stop adding achievements." << endl;
	in >> a;
	in.ignore();  // Clear the newline for the following getline
	while (a != 0) {
    	switch (a) {
        	case 1: {
            	string achievement;
            	cout << "Enter achievement: ";
            	getline(in, achievement);
            	c.add_achievements(achievement);
            	break;
        	}
        	case 0:
            	break;
        	default:
            	cout << "Invalid Operation.." << endl;
            	break;
    	}
    	cout << "Enter 1 to add achievements, 0 to stop adding achievements." << endl;
    	in >> a;
    	in.ignore();
	}
	return in;
}

*/



