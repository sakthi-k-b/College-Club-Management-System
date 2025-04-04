#include"newclub.h"
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<limits>
Cult::Cult(string name,string pic,string head,int c_size,string found_yr, string expenses,string culture_type):Club(name,pic,head,c_size,found_yr,expenses),culture_type(culture_type)
{
   cout<<"Cultural club "<<name<<" is created successfully"<<endl;
}


ostream &operator<<(ostream &out, const Cult &clt)
{
    out<<dynamic_cast<const Club&>(clt);
    out<<"Type of cultural activity: "<<clt.culture_type<<endl;
    out<<"Coordinators:\n";
    for(auto it=clt.coordinators.begin();it!=clt.coordinators.end();it++)
    {
    out<<*it<<endl;
    }
    return out;
}


istream &operator>>(istream &in, Cult &clt)
{
     
     
    in>>dynamic_cast<Club&>(clt);
    //in.ignore();
    cout<<"Enter the type of cultural activity: "<<endl;
    getline(in,clt.culture_type);
    return in;
}


void Cult::modify_coords()
{


    bool b=true;
    while(b)
    {
        cout<<"1. add coordinators"<<endl;
        cout<<"2. remove coordinators"<<endl;
        cout<<"3. exit"<<endl;
        cout<<"enter your choice: ";
        int choice;
        cin>>choice;
        cin.ignore();
        switch(choice)
        {
        case 1:
            {
                string name;
                cout<<"enter the name of the coordinator to be added: ";
                getline(cin,name);
                coordinators.insert(name);
                cout<<"Updated...";
                this->print();
                this->c_size++;
                break;
            }
        case 2:
            {
                string name;
                this->print();
                cout<<"enter the name to be removed: ";
                getline(cin,name);
                coordinators.erase(name);
                cout<<"updated ";
                this->print();
                this->c_size--;
                break;
            }
        case 3:
            {
                b=false;
                break;
            }
        default:
            {
                cout<<"Invalid choice!!!"<<endl;
                b=false;
                break;
            }
        }
    }


}
void Cult::print() const
{
    cout<<endl;
    cout<<"list of coordinators: "<<endl;
    for(auto &n: coordinators)
        cout<<n<<" ";
    cout<<endl;
}





/*#include"newclub.h"
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<limits>
#include <fstream>
Cult::Cult(string name,string pic,string head,int c_size,int found_yr, int expenses,string culture_type):Club(name,pic,head,c_size,found_yr,expenses),culture_type(culture_type)
{
   cout<<"Cultural club "<<name<<" is created successfully"<<endl;
}

ostream &operator<<(ostream &out, const Cult &clt)
{
	out<<dynamic_cast<const Club&>(clt);
	out<<"Type of cultural activity: "<<clt.culture_type<<endl;
	out<<"Coordinators:\n";
	for(auto it=clt.coordinators.begin();it!=clt.coordinators.end();it++)
	{
	out<<*it<<endl;
	}
	return out;
}

istream &operator>>(istream &in, Cult &clt)
{  	 
	in>>dynamic_cast<Club&>(clt);
	cout<<"Enter the type of cultural activity: "<<endl;
	getline(in,clt.culture_type);
	return in;
}

void Cult::modify_coords()
{

	bool b=true;
	while(b)
	{
    	cout<<"1. add coordinators"<<endl;
    	cout<<"2. remove coordinators"<<endl;
    	cout<<"3. exit"<<endl;
    	cout<<"enter your choice: ";
    	int choice;
    	cin>>choice;
    	cin.ignore();
    	switch(choice)
    	{
    	case 1:
        	{
            	string name;
            	cout<<"enter the name of the coordinator to be added: ";
            	getline(cin,name);
            	coordinators.insert(name);
            	cout<<"Updated...";
            	this->print();
            	this->c_size++;
            	break;
        	}
    	case 2:
        	{
            	string name;
            	this->print();
            	cout<<"enter the name to be removed: ";
            	getline(cin,name);
            	coordinators.erase(name);
            	cout<<"updated ";
            	this->print();
            	this->c_size--;
            	break;
        	}
    	case 3:
        	{
            	b=false;
            	break;
        	}
    	default:
        	{
            	cout<<"Invalid choice!!!"<<endl;
            	b=false;
            	break;
        	}
    	}
	}

}
void Cult::print() const
{
	cout<<endl;
	cout<<"list of coordinators: "<<endl;
	for(auto &n: coordinators)
    	cout<<n<<" ";
	cout<<endl;
}
*/




