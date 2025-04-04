#ifndef NEWCLUB_H
#define NEWCLUB_H
#include <iostream>
#include <set>
#include <vector>
#include<string>
#include<map>

template<typename T>
class ClubManager;
using namespace std;

class Club {
friend ostream &operator<<(ostream &out, const Club &c);
 friend istream &operator>>(istream &in, Club &c);


template <typename T>
friend class ClubManager;


protected:
  string head;
  string pic;
  int c_size;
  string found_yr;
  string expenses;
  vector<string> achievements;


public:
  string name;
Club(string name = "", string pic = "", string head = "", int c_size = 0,string found_yr = "", string expenses = "");
void add_achievements(string achievement);
void print_achievements(); //Added printing achievements function
virtual void print() const=0;
virtual ~Club();
//file handling
virtual void save(ofstream& out) const = 0;
virtual void load(ifstream& in) = 0;
};
class Tech :virtual public Club {
protected:
    int core_count;
    int jcore_count;
    set<string> cores;
    set<string> joint_cores;
    string main_focus;


public:
    Tech(string name = "", string pic = "", string head = "", int c_size = 0, string found_yr = "", string expenses = "",int core_count = 2,int jcore_count = 2, string main_focus = "");
    friend ostream &operator<<(ostream &out, const Tech &t);
    friend istream &operator>>(istream &in, Tech &t);
    void modify_cores();
    virtual void print() const;
    void modify_jcores();
    void print_jcores() const;
};


class Cult :virtual public Club {
protected:
  set<string> coordinators;
  string culture_type;


public:
  Cult(string name = "", string pic = "", string head = "", int c_size = 0,
   string found_yr = "", string expenses = "",string culture_type="");
  friend ostream &operator<<(ostream &out, const Cult &c);
  friend istream &operator>>(istream &in, Cult &c);
void modify_coords();
virtual void print() const;
//file handling
virtual void save(ofstream& out) const;
virtual void load(ifstream& in);
};


class General :virtual public Tech {
protected:
    set<string> members;
    map<string, string> projects;


public:
    General(string name = "", string pic = "", string head = "", int c_size = 0, string found_yr = "", string expenses = "",int core_count = 2,int jcore_count = 2, string main_focus = "");
    virtual void print() const;
    void modify_members();
    void print_projects() const;
    void modify_projects();
    friend ostream &operator<<(ostream &out, const General &c);
    friend istream &operator>>(istream &in, General &c);
    General & operator+=(const string &proj);
    General & operator-=(const string &proj);
    //file handling
virtual void save(ofstream& out) const;
virtual void load(ifstream& in);
};


class Competitive : virtual public Tech {
protected:
    set<string> interns;
    map<string, string> competitions;


public:
    Competitive(string name = "", string pic = "", string head = "", int c_size = 0, string found_yr = "", string expenses = "",int core_count = 2,int jcore_count = 2,string main_focus = "");
    virtual void print() const;
    void modify_interns();
    void print_competitions() const;
    void modify_competitions();
    friend ostream &operator<<(ostream &out, const Competitive &c);
    friend istream &operator>>(istream &in, Competitive &c);
    Competitive & operator+=(const string &comp);
    Competitive & operator-=(const string &comp);
    //file handling
virtual void save(ofstream& out) const;
virtual void load(ifstream& in);
};


#endif








/*
#include <iostream>
#include <set>
#include <vector>
#include<string>
#include<map>
using namespace std;
class Club {
friend ostream &operator<<(ostream &out, const Club &c);
 friend istream &operator>>(istream &in, Club &c);
friend void top_clubs(int n,map<string,map<string,Club*>>& clubs);//Printing top clubs
friend void create_club(map<string,map<string,Club*>>& clubs);
friend void modify_club(map<string,map<string,Club*>>& clubs);
friend void view_club(map<string,map<string,Club*>>& clubs);
friend void view_all(map<string,map<string,Club*>>& clubs);
friend void loadClubsFromFile(const string& filename, map<string, map<string, Club*>>& clubs);
protected:
  string head;
  string pic;
  int c_size;
  int found_yr;
  int expenses;
  vector<string> achievements;

public:
  string name;
Club(string name = "", string pic = "", string head = "", int c_size = 0,int found_yr = 0, int expenses = 0);
void add_achievements(string achievement);
void print_achievements(); //Added printing achievements function
virtual void print() const=0;
virtual ~Club();
//file handling
virtual void save(ofstream& out) const = 0; 
//virtual void load(ifstream& in) = 0; 
};
class Tech :virtual public Club {
protected:
    int core_count;
    int jcore_count;
	set<string> cores;
	set<string> joint_cores;
	string main_focus;

public:
	Tech(string name = "", string pic = "", string head = "", int c_size = 0, int found_yr = 0,int core_count = 2,int jcore_count = 2, int expenses = 0, string main_focus = "");
	friend ostream &operator<<(ostream &out, const Tech &t);
	friend istream &operator>>(istream &in, Tech &t);
	void modify_cores();
	virtual void print() const;
	void modify_jcores();
	void print_jcores() const;
};

class Cult :virtual public Club {
protected:
  set<string> coordinators;
  string culture_type;

public:
  Cult(string name = "", string pic = "", string head = "", int c_size = 0,
   int found_yr = 0, int expenses = 0,string culture_type="");
  friend ostream &operator<<(ostream &out, const Cult &c);
  friend istream &operator>>(istream &in, Cult &c);
void modify_coords();
virtual void print() const;
//file handling
virtual void save(ofstream& out) const; 
//virtual void load(ifstream& in); 
};

class General :virtual public Tech {
protected:
	set<string> members;
	map<string, string> projects;

public:
	General(string name = "", string pic = "", string head = "", int c_size = 0, int found_yr = 0, int expenses = 0,int core_count = 2,int jcore_count = 2, string main_focus = "");
 	virtual void print() const;
	void modify_members();
	void print_projects() const;
	void modify_projects();
	friend ostream &operator<<(ostream &out, const General &c);
	friend istream &operator>>(istream &in, General &c);
	General & operator+=(const string &proj);
	General & operator-=(const string &proj);
	//file handling
virtual void save(ofstream& out) const; 
//virtual void load(ifstream& in); 
};

class Competitive : virtual public Tech {
protected:
	set<string> interns;
	map<string, string> competitions;

public:
	Competitive(string name = "", string pic = "", string head = "", int c_size = 0, int found_yr = 0, int expenses = 0,int core_count = 2,int jcore_count = 2,string main_focus = "");
	virtual void print() const;
	void modify_interns();
	void print_competitions() const;
	void modify_competitions();
	friend ostream &operator<<(ostream &out, const Competitive &c);
	friend istream &operator>>(istream &in, Competitive &c);
	Competitive & operator+=(const string &comp);
	Competitive & operator-=(const string &comp);
	//file handling
virtual void save(ofstream& out) const; 
//virtual void load(ifstream& in); 
};

*/



