#include "newclub.h"
#include <iostream>
#include <set>
#include <string>
#include<vector>
#include<map>
using namespace std;


// Constructor for Tech class
Tech::Tech(string name, string pic, string head, int c_size, string found_yr, string expenses,int c_count,int j_count, string focus)
    : Club(name, pic, head, c_size, found_yr, expenses),core_count(c_count),jcore_count(j_count), main_focus(focus) {}




// Overloaded output operator
ostream &operator<<(ostream &out, const Tech &c) {
        out<<dynamic_cast<const Club&>(c);
    out << "Main focus: " << c.main_focus << endl;
    c.print();
    c.print_jcores();
    return out;
}


// Overloaded input operator
istream &operator>>(istream &in, Tech &c) {
    in>>dynamic_cast<Club &>(c);
    cout << "Enter Club Limit for number of Cores: ";
    in >> c.core_count;
    cout << "Enter Club Limit for number of Joint Cores: ";
    in >> c.jcore_count;
    cout << "Main focus: ";
    in.ignore();
    getline(in, c.main_focus);
    c.modify_cores();
    c.modify_jcores();
    return in;
}


// Print cores
void Tech::print() const {
    cout << endl << "List of cores: " << endl;
    for (const auto &n : cores)
        cout << n << " ";
    cout << endl;
}


// Modify cores
void Tech::modify_cores() {
    bool b = true;
    while (b) {
        cout << "1. Add core" << endl;
        cout << "2. Remove core" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
    switch (choice) {
            case 1: {
            if(cores.size() < core_count){
                string name;
                cout << "Enter the name of the core to be added: ";
                getline(cin, name);
                cores.insert(name);
                cout << "Updated...";
                print();
                c_size++;
                }
                else{
                cout<<"Maximum core size reached."<<endl;
                }
                break;
            }
            case 2: {
                string name;
                print();
                cout << "Enter the name to be removed: ";
                getline(cin, name);
                cores.erase(name);
                cout << "Updated ";
                print();
                c_size--;
                break;
            }
            case 3:
                b = false;
                break;
            default:
                cout << "Invalid choice!!!" << endl;
                break;
        }
    }
}


// Print joint cores
void Tech::print_jcores() const {
    cout << endl << "List of joint cores: " << endl;
    for (const auto &n : joint_cores)
        cout << n << " ";
    cout << endl;
}


// Modify joint cores
void Tech::modify_jcores() {
    bool b = true;
    while (b) {
        cout << "1. Add joint core" << endl;
        cout << "2. Remove joint core" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
            if(joint_cores.size() < jcore_count){
                string name;
                cout << "Enter the name of the joint core to be added: ";
                getline(cin, name);
                joint_cores.insert(name);
                cout << "Updated...";
                print_jcores();
                c_size++;
                }
                else{
                cout<<"Maximum joint core size reached."<<endl;
                }
                break;
            }
            case 2: {
                string name;
                print_jcores();
                cout << "Enter the name to be removed: ";
                getline(cin, name);
                joint_cores.erase(name);
                cout << "Updated...";
                print_jcores();
                c_size--;
                break;
            }
            case 3:
                b = false;
                break;
            default:
                cout << "Invalid choice!!!" << endl;
                break;
        }
    }
}


/*#include "newclub.h"
#include <iostream>
#include <set>
#include <string>
#include<vector>
#include<map>

using namespace std;

// Constructor for Tech class
Tech::Tech(string name, string pic, string head, int c_size, int found_yr, int expenses,int c_count,int j_count, string focus)
	: Club(name, pic, head, c_size, found_yr, expenses),core_count(c_count),jcore_count(j_count), main_focus(focus) {}


// Overloaded output operator
ostream &operator<<(ostream &out, const Tech &c) {
    	out<<dynamic_cast<const Club&>(c);
	out << "Main focus: " << c.main_focus << endl;
	c.print();
	c.print_jcores();
	return out;
}

// Overloaded input operator
istream &operator>>(istream &in, Tech &c) {
	in>>dynamic_cast<Club &>(c);
	cout << "Enter Club Limit for number of Cores: ";
	in >> c.core_count;
	cout << "Enter Club Limit for number of Joint Cores: ";
	in >> c.jcore_count;
	cout << "Main focus: ";
	in.ignore();
	getline(in, c.main_focus);
	c.modify_cores();
	c.modify_jcores();
	return in;
}

// Print cores
void Tech::print() const {
	cout << endl << "List of cores: " << endl;
	for (const auto &n : cores)
    	cout << n << " ";
	cout << endl;
}

// Modify cores
void Tech::modify_cores() {
	bool b = true;
	while (b) {
    	cout << "1. Add core" << endl;
    	cout << "2. Remove core" << endl;
    	cout << "3. Exit" << endl;
    	cout << "Enter your choice: ";
    	int choice;
    	cin >> choice;
    	cin.ignore();
	switch (choice) {
        	case 1: {
        	if(cores.size() < core_count){
            	string name;
            	cout << "Enter the name of the core to be added: ";
            	getline(cin, name);
            	cores.insert(name);
            	cout << "Updated...";
            	print();
            	c_size++;
            	}
            	else{
            	cout<<"Maximum core size reached."<<endl;
            	}
            	break;
        	}
        	case 2: {
            	string name;
            	print();
            	cout << "Enter the name to be removed: ";
            	getline(cin, name);
            	cores.erase(name);
            	cout << "Updated ";
            	print();
            	c_size--;
            	break;
        	}
        	case 3:
            	b = false;
            	break;
        	default:
            	cout << "Invalid choice!!!" << endl;
            	break;
    	}
	}
}

// Print joint cores
void Tech::print_jcores() const {
	cout << endl << "List of joint cores: " << endl;
	for (const auto &n : joint_cores)
    	cout << n << " ";
	cout << endl;
}

// Modify joint cores
void Tech::modify_jcores() {
	bool b = true;
	while (b) {
    	cout << "1. Add joint core" << endl;
    	cout << "2. Remove joint core" << endl;
    	cout << "3. Exit" << endl;
    	cout << "Enter your choice: ";
    	int choice;
    	cin >> choice;
    	cin.ignore();
    	switch (choice) {
        	case 1: {
        	if(joint_cores.size() < jcore_count){
            	string name;
            	cout << "Enter the name of the joint core to be added: ";
            	getline(cin, name);
            	joint_cores.insert(name);
            	cout << "Updated...";
            	print_jcores();
            	c_size++;
            	}
            	else{
            	cout<<"Maximum joint core size reached."<<endl;
            	}
            	break;
        	}
        	case 2: {
            	string name;
            	print_jcores();
            	cout << "Enter the name to be removed: ";
            	getline(cin, name);
            	joint_cores.erase(name);
            	cout << "Updated...";
            	print_jcores();
            	c_size--;
            	break;
        	}
        	case 3:
            	b = false;
            	break;
        	default:
            	cout << "Invalid choice!!!" << endl;
            	break;
    	}
	}
}
*/
