#include "newclub.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <limits>
#include <fstream>
using namespace std;


void Cult::save(ofstream& out) const {
    out << "Category: cult\n";
    out << "Club Name: " << name << "\n";
    out << "Head: " << head << "\n";
    out << "Professor Incharge: " << pic << "\n";
    out << "Founded Year: " << found_yr << "\n";
    out << "Size: " << c_size << "\n";
    out << "Expenses: " << expenses << "\n";


    out << "Achievements:";
    for (const auto& ach : achievements) {
        out << " " << ach << ";";
    }
    out << "\n";


    out << "Cultural Activity Type: " << culture_type << "\n";


    out << "Coordinators:";
    for (const auto& coord : coordinators) {
        out << " " << coord << ";";
    }
    out << "\n";
}


void General::save(ofstream& out) const {
    out << "Category: gen\n";
    out << "Club Name: " << name << "\n";
    out << "Head: " << head << "\n";
    out << "Professor Incharge: " << pic << "\n";
    out << "Founded Year: " << found_yr << "\n";
    out << "Size: " << c_size << "\n";
    out << "Expenses: " << expenses << "\n";


    out << "Achievements:";
    for (const auto& ach : achievements) {
        out << " " << ach << ";";
    }
    out << "\n";


    out << "Main Focus: " << main_focus << "\n";


    out << "Cores:";
    for (const auto& core : cores) {
        out << " " << core << ";";
    }
    out << "\n";


    out << "Joint Cores:";
    for (const auto& joint_core : joint_cores) {
        out << " " << joint_core << ";";
    }
    out << "\n";


    out << "Members:";
    for (const auto& member : members) {
        out << " " << member << ";";
    }
    out << "\n";


    out << "Projects:";
    for (const auto& project : projects) {
        out << " " << project.first << "," << project.second << ";";
    }
    out << "\n";
}


void Competitive::save(ofstream& out) const {
    out << "Category: comp\n";
    out << "Club Name: " << name << "\n";
    out << "Head: " << head << "\n";
    out << "Professor Incharge: " << pic << "\n";
    out << "Founded Year: " << found_yr << "\n";
    out << "Size: " << c_size << "\n";
    out << "Expenses: " << expenses << "\n";


    out << "Achievements:";
    for (const auto& ach : achievements) {
        out << " " << ach << ";";
    }
    out << "\n";


    out << "Main Focus: " << main_focus << "\n";


    out << "Cores:";
    for (const auto& core : cores) {
        out << " " << core << ";";
    }
    out << "\n";


    out << "Joint Cores:";
    for (const auto& joint_core : joint_cores) {
        out << " " << joint_core << ";";
    }
    out << "\n";


    out << "Interns:";
    for (const auto& intern : interns) {
        out << " " << intern << ";";
    }
    out << "\n";


    out << "Competitions:";
    for (const auto& competition : competitions) {
        out << " " << competition.first << "," << competition.second << ";";
    }
    out << "\n";
}








/*#include "newclub.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <limits>
#include <fstream>
using namespace std;

void Cult::save(ofstream& out) const {
    out << "Category: cult\n";
    out << "Club Name: " << name << "\n";
    out << "Head: " << head << "\n";
    out << "Professor Incharge: " << pic << "\n";
    out << "Founded Year: " << found_yr << "\n";
    out << "Size: " << c_size << "\n";
    out << "Expenses: " << expenses << "\n";

    out << "Achievements:";
    for (const auto& ach : achievements) {
        out << " " << ach << ";";
    }
    out << "\n";

    out << "Cultural Activity Type: " << culture_type << "\n";

    out << "Coordinators:";
    for (const auto& coord : coordinators) {
        out << " " << coord << ";";
    }
    out << "\n";
}

void General::save(ofstream& out) const {
    out << "Category: gen\n";
    out << "Club Name: " << name << "\n";
    out << "Head: " << head << "\n";
    out << "Professor Incharge: " << pic << "\n";
    out << "Founded Year: " << found_yr << "\n";
    out << "Size: " << c_size << "\n";
    out << "Expenses: " << expenses << "\n";

    out << "Achievements:";
    for (const auto& ach : achievements) {
        out << " " << ach << ";";
    }
    out << "\n";

    out << "Main Focus: " << main_focus << "\n";

    out << "Cores:";
    for (const auto& core : cores) {
        out << " " << core << ";";
    }
    out << "\n";

    out << "Joint Cores:";
    for (const auto& joint_core : joint_cores) {
        out << " " << joint_core << ";";
    }
    out << "\n";

    out << "Members:";
    for (const auto& member : members) {
        out << " " << member << ";";
    }
    out << "\n";

    out << "Projects:";
    for (const auto& project : projects) {
        out << " " << project.first << "," << project.second << ";";
    }
    out << "\n";
}

void Competitive::save(ofstream& out) const {
    out << "Category: comp\n";
    out << "Club Name: " << name << "\n";
    out << "Head: " << head << "\n";
    out << "Professor Incharge: " << pic << "\n";
    out << "Founded Year: " << found_yr << "\n";
    out << "Size: " << c_size << "\n";
    out << "Expenses: " << expenses << "\n";

    out << "Achievements:";
    for (const auto& ach : achievements) {
        out << " " << ach << ";";
    }
    out << "\n";

    out << "Main Focus: " << main_focus << "\n";

    out << "Cores:";
    for (const auto& core : cores) {
        out << " " << core << ";";
    }
    out << "\n";

    out << "Joint Cores:";
    for (const auto& joint_core : joint_cores) {
        out << " " << joint_core << ";";
    }
    out << "\n";

    out << "Interns:";
    for (const auto& intern : interns) {
        out << " " << intern << ";";
    }
    out << "\n";

    out << "Competitions:";
    for (const auto& competition : competitions) {
        out << " " << competition.first << "," << competition.second << ";";
    }
    out << "\n";
}*/

