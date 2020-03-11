//
// Created by Aryeh Kempler-Delugach on 2/10/20.
//
#include <fstream>
#include <iostream>
#include <cctype>

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
    /*
    ~PeopleTable() {
	for(int i = 0; i < 23; ++i) {
		Node * tmp;
		while(this->table[i]->next) {
			tmp = this->table[i]->next;
			delete this->table[i];
			this->table[i] = tmp;
		}
		if(!this->table[i]->next) {
			delete this->table[i];
			this->table[i] = nullptr;
		}
	}
    } */


    int files_read(string fileName, int dataType);
    void files_read_MP(string fileName, int dataType);
    void files_read_PR(string fileName);
    void files_write(string fileName, int dataType);
    void files_write_MP(string fileName, int dataType);
    void files_write_PR(string fileName);    

    int hash_function(int id);
    int add_node(Node * to_add, int hash);
    int add_to_end(Node * to_add, Node * current);
    int display1();
    int display2(Node * current);
    int find_hash(int code, Node *& current);
    int display_personal_report(int code, int choice);

    //Functions regarding provider report below
    int add_provider_report(int provider_code, string add_date, string add_time, string add_name, int add_member_code, int add_service_code, float add_fee);
    int display_reports(int provider_code); 
    int write_p_report(Node * current, string &add_date, string &add_time, string &add_name, int &add_member_code, int &add_service_code, float &add_fee);
    int test_p_write(); //Test function for write_p_report

    //Functions regarding member report below
    int add_m_report(int member_code, string new_date, string new_name, string new_service, string new_memname, int new_memcode, string new_street, string new_city, string new_state, int new_zip);
    int display_m_reports(int member_code);
    
    int summary_report();
    int summary_report_internal(Node * current, int &total_providers, int &total_services, float &total_fees);
    

    int summary_report();
    int summary_report_internal(Node * current, int &total_providers, int &total_services, float &total_fees);

    int person_modify(string modify, int ID, int option);

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
    Person(int new_id, int new_type, string new_name) {
        id = new_id;
	type = new_type;
        name = new_name;
    }
    virtual ~Person() {}
    int get_id() {return this -> id;}
    int get_type() {return this->type;}
    string get_name() {return this -> name;}

    //Functions below are wrapper functions to convert Person* to Provider*
    int add_provider_type(Provider_Report * to_add);
    int display_provider_type();
    int display_personal_type(int choice);
    int summary_report_check(int &total_providers, int &total_services, float &total_fees);
    int write_p_report(string &add_date, string &add_time, string &add_name, int &add_member_code, int &add_service_code, float &add_fee);
  
    //Functions below are wrapper functions to convert Person* to Member*
    int add_member_type(Member_Report * to_add);
    int display_member_type();
    
    void wrapperFW(ofstream & file1);
	
      //modifies any person data type that is a string type
    int info_modify(string modify, int option);
    //modifies any person data type that is an int type
    //int info_modify2(int modify, int option);


protected:
    int id;
    int type;
    string name;
};

class Member: public Person {
public:

    Member(int a, string b) : Person(a, 1, b) {

    }


    //Need function to add member reports
    int add_report(Member_Report * to_add);
    int add_to_end(Member_Report * to_add, Member_Report * current);
    int display_reports();
    int write_report(string &add_member_name, string &add_member_code, string &add_street, string &add_city, string &add_state, int &add_zip, string & add_date, string &add_name, string &add_service);
    
private:
    Member_Report * report;

};

class Provider: public Person {
public:

    Provider(int a, string b) : Person(a, 2, b) {

	    report = nullptr;
    }

    //need a function that will return info to be saved
    int add_report(Provider_Report * to_add);
    int add_to_end(Provider_Report * to_add, Provider_Report * current);
    int display_reports();
    int summary_report(int &total_providers, int &total_services, float &total_fees);
    int write_report(string &add_date, string &add_time, string &add_name, int &add_member_code, int &add_service_code, float &add_fee);

    void fileWrite(ofstream & file1);

private:
    Provider_Report * report;

};

//Below report classes will act as nodes to form the reports
class Member_Report {
public:
	Member_Report(string new_date, string new_name, string new_service, string new_memname, int new_memcode, string new_street, string new_city, string new_state, int new_zip)
	{
		date_of_service = new_date;
		provider_name = new_name;
		service_name = new_service;
		member_name = new_memname;
		member_code = new_memcode;
		street = new_street;
		city = new_city;
		state = new_state;
		zip = new_zip;

		next = nullptr;
	}

	//Functions involving the member report will go below
	string get_date() {return this->date_of_service;};
	string get_name() {return this->provider_name;};
	string get_service() {return this->service_name;};
	string get_mem_name() {return this->member_name;};
	int get_code() {return this->member_code;};
	string get_street() {return this->street;};
	string get_city() {return this->city;};
	string get_state() {return this->state;};
	int get_zip() {return this->zip;};


	Member_Report *& go_next();
	void display_member();

private:
	Member_Report * next;

	string date_of_service;
	string provider_name;
	string member_name;
	string service_name;
	int member_code;
	string street;
	string city;
	string state;
	int zip;
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
	
	//Below are used for getter functions
	string get_date() {return this->date_of_service;}
	string get_time() {return this->time;}
	string get_name() {return this->member_name;}
	int get_mem_code() {return this->member_code;}
	int get_serv_code() {return this->service_code;}
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

int Services();

int date_checker(string date);
int time_checker(string time);
int name_size_checker(string name);
int service_code_checker(int service_code);
int service_fee_checker(float service_fee);
int new_user_id_checker( int id);
int street_address_checker( string street_address);
int city_checker( string city);
int state_checker(string state);