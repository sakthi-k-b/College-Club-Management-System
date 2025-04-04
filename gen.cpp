#include "newclub.h"
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>
#include <fstream>
using namespace std;


// Constructor for General class
General::General(string name, string pic, string head, int c_size, string found_yr, string expenses,int c_count,int j_count, string main_focus)
    : Tech(name, pic, head, c_size, found_yr, expenses,c_count,j_count, main_focus) {
    cout << "General Technical Club constructed." << endl;
}


void General::print() const{
    if (!members.empty()){
        cout << endl << "List of members: " << endl;
        for (const string &i : members)
            cout << i << endl;
    }
}


void General::modify_members() {
    cout<<"Choose member operations :"<<endl;
    bool b = true;
    while (b) {
        cout << "1. Add member" << endl;
        cout << "2. Remove member" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                string name;
                cout << "Enter the name of the member to be added: ";
                getline(cin, name);
                members.insert(name);
                cout << "Updated." << endl;
                print();
                c_size = members.size();
                break;
            }
            case 2: {
                string name;
                cout << "Enter the name of the member to be removed: ";
                getline(cin, name);
                members.erase(name);
                cout << "Updated." << endl;
                print();
                c_size = members.size();
                break;
            }
            case 3:
                b = false;
                break;
            default:
                cout << "Invalid choice!" << endl;
                b = false;
                break;
        }
    }
}


void General::print_projects() const {
    cout << endl << "List of projects: " << endl;
    for (const auto &project : projects)
        cout << "Project: " << project.first << ", Creator: " << project.second << endl;
}


void General::modify_projects() {
    cout<<"Choose project operations :"<<endl;
    bool b = true;
    while (b) {
        cout << "1. Add project" << endl;
        cout << "2. Delete project" << endl;
        cout << "3. Display projects"<< endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        string project;
        switch (choice) {
            case 1: {
                cout << "Enter the project to be added: ";
                cin.ignore();
                getline(cin, project);
                *this += project;
                break;
            }
            case 2:
                cout << "Enter the project to be deleted: ";
                cin.ignore();
                getline(cin, project);
                *this -= project;
                break;
            case 3:
                print_projects();
                break;
            case 4:
                b = false;
                break;
            default:
                cout << "Invalid choice!" << endl;
        b=false;
                break;
        }
    }
}


ostream &operator<<(ostream &out, const General &c) {
   
    out<<dynamic_cast<const Tech&>(c);
    c.print();
    c.print_projects();
    return out;
}


istream &operator>>(istream &in, General &c) {
    in>>dynamic_cast<Tech&>(c);
    c.modify_members();
    c.modify_projects();
   
        in.ignore();
    return in;
}


General & General :: operator+=(const string &proj){
string creator;
cout << "Enter the creator of the project: ";
cin.ignore();
getline(cin, creator);
projects[proj] = creator;
cout<<"Succesfully added project."<<endl;
return *this;
}
General & General :: operator-=(const string &proj){
projects.erase(proj);
cout<<"Succesfully deleted project."<<endl;
return *this;
}














/*#include "newclub.h"
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// Constructor for General class
General::General(string name, string pic, string head, int c_size, int found_yr, int expenses,int c_count,int j_count, string main_focus)
	: Tech(name, pic, head, c_size, found_yr, expenses,c_count,j_count, main_focus) {
	cout << "General Technical Club constructed." << endl;
}


void General::print() const{
	if (!members.empty()){
    	cout << endl << "List of members: " << endl;
    	for (const string &i : members)
        	cout << i << endl;
	}
}

void General::modify_members() {
	cout<<"Choose member operations :"<<endl;
	bool b = true;
	while (b) {
    	cout << "1. Add member" << endl;
    	cout << "2. Remove member" << endl;
    	cout << "3. Exit" << endl;
    	cout << "Enter your choice: ";
    	int choice;
    	cin >> choice;
    	cin.ignore();
    	switch (choice) {
        	case 1: {
            	string name;
            	cout << "Enter the name of the member to be added: ";
            	getline(cin, name);
            	members.insert(name);
            	cout << "Updated." << endl;
            	print();
            	c_size = members.size();
            	break;
        	}
        	case 2: {
            	string name;
            	cout << "Enter the name of the member to be removed: ";
            	getline(cin, name);
            	members.erase(name);
            	cout << "Updated." << endl;
            	print();
            	c_size = members.size();
            	break;
        	}
        	case 3:
            	b = false;
            	break;
        	default:
            	cout << "Invalid choice!" << endl;
            	b = false;
            	break;
    	}
	}
}

void General::print_projects() const {
	cout << endl << "List of projects: " << endl;
	for (const auto &project : projects)
    	cout << "Project: " << project.first << ", Creator: " << project.second << endl;
}

void General::modify_projects() {
	cout<<"Choose project operations :"<<endl;
	bool b = true;
	while (b) {
    	cout << "1. Add project" << endl;
    	cout << "2. Delete project" << endl;
    	cout << "3. Display projects"<< endl;
    	cout << "4. Exit" << endl;
    	cout << "Enter your choice: ";
    	int choice;
    	cin >> choice;
    	string project;
    	switch (choice) {
        	case 1: {
            	cout << "Enter the project to be added: ";
            	cin.ignore();
            	getline(cin, project);
            	*this += project;
            	break;
        	}
        	case 2:
            	cout << "Enter the project to be deleted: ";
            	cin.ignore();
            	getline(cin, project);
            	*this -= project;
            	break;
        	case 3:
            	print_projects();
            	break;
        	case 4:
            	b = false;
            	break;
        	default:
            	cout << "Invalid choice!" << endl;
    	b=false;
            	break;
    	}
	}
}

ostream &operator<<(ostream &out, const General &c) {
    
	out<<dynamic_cast<const Tech&>(c);
	c.print();
	c.print_projects();
	return out;
}

istream &operator>>(istream &in, General &c) {
	in>>dynamic_cast<Tech&>(c);
	c.modify_members();
	c.modify_projects();
    
    	in.ignore();
	return in;
}

General & General :: operator+=(const string &proj){
string creator;
cout << "Enter the creator of the project: ";
cin.ignore();
getline(cin, creator);
projects[proj] = creator;
cout<<"Succesfully added project."<<endl;
return *this;
}
General & General :: operator-=(const string &proj){
projects.erase(proj);
cout<<"Succesfully deleted project."<<endl;
return *this;
}
*/

