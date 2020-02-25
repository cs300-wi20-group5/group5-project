//
// Created by Aryeh Kempler-Delugach on 2/10/20.
//
#include <fstream>
#include <iostream>
using namespace std;

class Node;
class Person;
class Member;
class Provider;
class Member_Report;
class Provider_Report;

class PeopleTable {
public:
    PeopleTable() {
        table = new Node * [23];
        for(int i = 0; i < 23; ++i) {table[i] = nullptr;}
    }
    int files_read();
    int hash_function(int id);
    int add_node(Node * to_add, int hash);
    int add_to_end(Node * to_add, Node * current);
    int display1();
    int display2(Node * current);
    int find_hash(int code, Node *& current);

    //Functions regarding provider report below
    int add_provider_report(int provider_code, string add_date, string add_time, string add_name, int add_member_code, int add_service_code, float add_fee);
    int display_reports(int provider_code); 

    int summary_report();
    int summary_report_internal(Node * current, int &total_providers, int &total_services, float &total_fees);
    
private:
    Node ** table;
};

class Node {
public:
    Node() {
        data = nullptr;
        next = nullptr;
    }
    Node(Person * input) {
        data = input;
        next = nullptr;
    }
    Person * data;
    Node * next;
};

class Person {
public:
    Person(int new_id, string new_name) {
        id = new_id;
        name = new_name;
    }
    virtual ~Person() {}
    int get_id() {return this -> id;}
    string get_name() {return this -> name;}

    //Functions below are wrapper functions to convert Person* to Provider*
    int add_provider_type(Provider_Report * to_add);
    int display__provider_type();
    int summary_report_check(int &total_providers, int &total_services, float &total_fees);


protected:
    int id;
    string name;
};

class Member: public Person {
public:
    Member(int a, string b) : Person(a, b) {
    }

    //Need function to add member reports
    
private:
    Member_Report * report;

};

class Provider: public Person {
public:
    Provider(int a, string b) : Person(a, b) {
	    report = nullptr;
    }

    //int files_read();
    //int files_write();
    int add_report(Provider_Report * to_add);
    int add_to_end(Provider_Report * to_add, Provider_Report * current);
    int display_reports();
    int summary_report(int &total_providers, int &total_services, float &total_fees);

private:
    Provider_Report * report;

};

//Below report classes will act as nodes to form the reports
class Member_Report {
public:
	Member_Report(string new_date, string new_name, string new_service)
	{
		date_of_service = new_date;
		provider_name = new_name;
		service_name = new_service;

		next = nullptr;
	}

//Functions involving the member report will go below

private:
	Member_Report * next;

	string date_of_service;
	string provider_name;
	string service_name;
};

class Provider_Report {
public:
	Provider_Report(string new_date, string new_time, string new_name, int new_memcode, int new_servcode, float new_fee)
	{
		date_of_service = new_date;
		time = new_time;
		member_name = new_name;
		member_code = new_memcode;
		service_code = new_servcode;
		fee = new_fee;
		
		next = nullptr;
	}
	float get_fee() {return this->fee;}

	Provider_Report *& go_next();
	int display();
	
private:
	Provider_Report * next;

   	string date_of_service;
   	string time;
   	string member_name;
   	int member_code;
   	int service_code;
   	float fee;
};

