#include "newclub.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <limits>
#include <fstream>
using namespace std;


void Cult::load(ifstream& in) {
    string line;
    try {
        getline(in, line); name = line.substr(line.find(":") + 2); // Extract Club Name
        getline(in, line); head = line.substr(line.find(":") + 2); // Extract Head
        getline(in, line); pic = line.substr(line.find(":") + 2); // Extract Professor Incharge
        getline(in, line); found_yr = stoi(line.substr(line.find(":") + 2)); // Extract Founded Year
        getline(in, line); c_size = stoi(line.substr(line.find(":") + 2)); // Extract Size
        getline(in, line); expenses = stoi(line.substr(line.find(":") + 2)); // Extract Expenses


        getline(in, line); // Skip "Achievements:"
        achievements.clear();
        while (getline(in, line) && line.find("- ") != string::npos) {
            achievements.push_back(line.substr(line.find("- ") + 2));
        }


        getline(in, line); culture_type = line.substr(line.find(":") + 2); // Extract Cultural Activity Type


        getline(in, line); // Skip "Coordinators:"
        coordinators.clear();
        while (getline(in, line) && line.find("- ") != string::npos) {
            coordinators.insert(line.substr(line.find("- ") + 2));
        }
    } catch (exception& e) {
        cerr << "Error loading Cult club data: " << e.what() << endl;
    }
}


void General::load(ifstream& in) {
    string line;
    try {
        getline(in, line); name = line.substr(line.find(":") + 2); // Extract Club Name
        getline(in, line); head = line.substr(line.find(":") + 2); // Extract Head
        getline(in, line); pic = line.substr(line.find(":") + 2); // Extract Professor Incharge
        getline(in, line); found_yr = stoi(line.substr(line.find(":") + 2)); // Extract Founded Year
        getline(in, line); c_size = stoi(line.substr(line.find(":") + 2)); // Extract Size
        getline(in, line); expenses = stoi(line.substr(line.find(":") + 2)); // Extract Expenses
        getline(in, line); // Skip "Achievements:"
        achievements.clear();
        while (getline(in, line) && line.find("- ") != string::npos) {
            achievements.push_back(line.substr(line.find("- ") + 2));
        }
        getline(in, line); main_focus = line.substr(line.find(":") + 2); // Extract Main Focus


        getline(in, line); // Skip "Cores:"
        cores.clear();
        while (getline(in, line) && line.find("- ") != string::npos) {
            cores.insert(line.substr(line.find("- ") + 2));
        }


        getline(in, line); // Skip "Joint Cores:"
        joint_cores.clear();
        while (getline(in, line) && line.find("- ") != string::npos) {
            joint_cores.insert(line.substr(line.find("- ") + 2));
        }


        getline(in, line); // Skip "Members:"
        members.clear();
        while (getline(in, line) && line.find("- ") != string::npos) {
            members.insert(line.substr(line.find("- ") + 2));
        }


        getline(in, line); // Skip "Projects:"
        projects.clear();
        while (getline(in, line) && line.find("Project: ") != string::npos) {
            auto pos = line.find(", Creator: ");
            if (pos != string::npos) {
                string project_name = line.substr(10, pos - 10);
                string creator = line.substr(pos + 11);
                projects[project_name] = creator;
            }
        }
    } catch (exception& e) {
        cerr << "Error loading General club data: " << e.what() << endl;
    }
}


void Competitive::load(ifstream& in) {
    string line;
    try {
        getline(in, line); name = line.substr(line.find(":") + 2); // Extract Club Name
        getline(in, line); head = line.substr(line.find(":") + 2); // Extract Head
        getline(in, line); pic = line.substr(line.find(":") + 2); // Extract Professor Incharge
        getline(in, line); found_yr = stoi(line.substr(line.find(":") + 2)); // Extract Founded Year
        getline(in, line); c_size = stoi(line.substr(line.find(":") + 2)); // Extract Size
        getline(in, line); expenses = stoi(line.substr(line.find(":") + 2)); // Extract Expenses
		getline(in, line); // Skip "Achievements:"
        achievements.clear();
        while (getline(in, line) && line.find("- ") != string::npos) {
            achievements.push_back(line.substr(line.find("- ") + 2));
        }
        getline(in, line); main_focus = line.substr(line.find(":") + 2); // Extract Main Focus


        getline(in, line); // Skip "Cores:"
        cores.clear();
        while (getline(in, line) && line.find("- ") != string::npos) {
            cores.insert(line.substr(line.find("- ") + 2));
        }
        getline(in, line); // Skip "Joint Cores:"
        joint_cores.clear();
        while (getline(in, line) && line.find("- ") != string::npos) {
            joint_cores.insert(line.substr(line.find("- ") + 2));
        }
        getline(in, line); // Skip "Interns:"
        interns.clear();
        while (getline(in, line) && line.find("- ") != string::npos) {
            interns.insert(line.substr(line.find("- ") + 2));
        }


        getline(in, line); // Skip "Competitions:"
        competitions.clear();
        while (getline(in, line) && line.find("- ") != string::npos) {
            auto pos = line.find(", ");
            if (pos != string::npos) {
                string competition_name = line.substr(10, pos - 10);
                string place = line.substr(pos + 2);
                competitions[competition_name] = place.substr(0, place.find(" Place"));
            }
        }
    } catch (exception& e) {
        cerr << "Error loading Competitive club data: " << e.what() << endl;
    }
}








