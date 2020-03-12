#include "classes.h"
/*
int main() {
    PeopleTable test;

 	test.files_read("../data/old_members.txt", 1);
    	test.files_read("../data/old_providers.txt", 2);
	test.display1();	

	Node * current;
	int code = 222222222;
	int flag = test.find_hash(code, current);
	cout << flag << endl;
    //Below I am testing if adding provider reports works

    int provider_code = 385773619;	//This should be saved from when the provider logged in
    //This information will be gathered when the provider bills ChocAn 
    //and they are prompted to verify the service they have provided
    string date = "2/21/2020";
    string time = "12:10 am";
    string mem_name = "Michael Tran";
    int mem_code = 123456789;
    int serv_code = 123456;
    float fee = 85.99;

    test.add_provider_report(provider_code,date,time,mem_name,mem_code,serv_code,fee);
  
    date = "2/24/2020";
    time = "12:30 am";
    mem_name = "Diana Mejia";
    mem_code = 987654321;
    serv_code = 654321;
    fee = 72.50;

    test.add_provider_report(provider_code,date,time,mem_name,mem_code,serv_code,fee);

    date = "2/22/2020";
    time = "7:02 pm";
    mem_name = "Gilbert Ho";
    mem_code = 927481938;
    serv_code = 541353;
    fee = 201.83;
  
    test.add_provider_report(309123411,date,time,mem_name,mem_code,serv_code,fee);

    //test.display_p_reports(provider_code);
    //test.display_p_reports(309123411);
    
    test.summary_report();
    test.person_delete(309123411);
    test.person_delete(provider_code);
    
    test.summary_report();
    test.display1();

    test.files_read("../data/members.txt", 1);
    test.files_read("../data/providers.txt", 2);
    test.display1();
    test.files_write("../data/test_members.txt", 1);
    test.files_write("../data/test_providers.txt", 2);

    test.files_read("../data/reports_test.txt", 3);
    test.display_reports(385773619);
    test.display_reports(309123411);
	
    test.files_write("../data/reports_test_test.txt", 3);

    return 0;
}
*/

//--------------------- People Table Functions ---------------------------

int PeopleTable::files_read(string fileName, int dataType) {
	if(dataType == 1 || dataType == 2)
		files_read_MP(fileName, dataType);
	if(dataType == 3)
		files_read_PR(fileName);
}

void PeopleTable::files_read_MP(string fileName, int dataType) {
	ifstream file1(fileName);
	int id;
	string str;
	Person * p = nullptr;

	while(getline(file1, str, ',')) {	
		id = stoi(str);
	    	if(getline(file1, str, '\n')) {

			if(dataType == 1)
				p = new Member(id, str);
			if(dataType == 2)
				p = new Provider(id, str);

			int bucket = this -> hash_function(id);
			Node * temp = new Node(p);
			add_node(temp, bucket);
	    	}
	}
}

void PeopleTable::files_read_PR(string fileName) {
	ifstream file1(fileName);
    	int add_member_code, add_service_code, id;
    	string add_time, add_date, add_name, temp, str;
    	float add_fee;
   	
	while(getline(file1, temp, ',') && !file1.eof()) {	
		id = stoi(temp);	

		getline(file1, add_date, ',');

		getline(file1, add_time, ',');

		getline(file1, add_name, ',');

		getline(file1, temp, ',');
		add_member_code = stoi(temp);

		getline(file1, temp, ',');
		add_service_code = stoi(temp);
	    
		//  not including delimiter here since its the last value, 
		//  and with the delimiter it causes an error with stof 
		getline(file1, temp, '\n');
		add_fee = stof(temp);
	     
		add_provider_report(id, add_date, add_time, add_name, add_member_code, add_service_code, add_fee);
   	} 
}

void PeopleTable::files_write(string fileName, int dataType) {
	if(dataType == 1 || dataType == 2)
	       	files_write_MP(fileName, dataType);
	if(dataType == 3)
		files_write_PR(fileName);
}

void PeopleTable::files_write_MP(string fileName, int dataType) {
    ofstream file1(fileName);
    for(int i = 0; i < 23; ++i) {
	if(this->table[i]) {
	    Node * tmp = this->table[i];
	    while(tmp) {
		if(tmp->data->get_type() == dataType) {
			file1 << tmp->data->get_id(); 
			file1 << ",";
			file1 << tmp->data->get_name();
			file1 << endl;	
		}
		tmp = tmp->next;
	    }
	}
    } 

    file1.close(); 
}

// Function that loops through hash table to find all reports, when it finds a valid provider, 
// it goes down into the provider and writes all reports to file
void PeopleTable::files_write_PR(string fileName) {
	ofstream file1(fileName);
	Node * tmp;
	
	for(int i = 0; i < 23; ++i) {
		tmp = this->table[i];
		if(this->table[i]) {	
			while(tmp) {	
				if(tmp->data->get_type() == 2)
					tmp->data->wrapperFW(file1);
				tmp = tmp->next;
			}	
		}
	}
	file1.close();
}

int PeopleTable::hash_function(int id) {
    return id % 23;
}

int PeopleTable::add_node(Node *to_add, int hash) {
    if (!table[hash])
        table[hash] = to_add;
    else
        add_to_end(to_add, table[hash]);
    return 0;
}

int PeopleTable::add_to_end(Node *to_add, Node *current) {
    if(!current)
        return 0;
    else if(!current -> next)
        current -> next = to_add;
    else
        add_to_end(to_add, current -> next);
    return 0;
}

int PeopleTable::display1() {
    for(int i = 0; i < 23; ++i) {
	if(table[i]) {
		cout << "index " << i << ": ";
		display2(table[i]);
	}
    }
}

int PeopleTable::display2(Node * current) {
    if(!current)
        return 0;
    int id = current -> data -> get_id();
    string name = current -> data -> get_name();
    cout << " id:" << id << " name:" << name;
    if(!current -> next)
        cout << "\n";
    else
        display2(current -> next);
    return 0;
}

int PeopleTable::find_hash(int code, Node *& current) {

	//Checking to see if the code is valid
	if(code < 200000000)
		return 0;

	int flag = 0;
	int bucket = hash_function(code); 
	current = table[bucket];

	do{
		int id = current -> data -> get_id();
		if(code == id)	{
			flag = 1;
		}
		else
			current = current -> next;

	}while(flag != 1 && current);

	//when id is not found returns 0
	if(flag != 1)
		return 0;	
	else
		return 1;

}

//Used to find node before the node with the key, used for deletion
int PeopleTable::find_hash_previous(int code, Node *& current) {

	int flag = 0;
	int bucket = hash_function(code); 
	current = table[bucket];

	if(!current -> next) {
		int id = current -> data -> get_id();
		
		if(code == id)
			return 1;
		else return 0;
	}

	do{
		int id = current -> next -> data -> get_id();
		if(code == id)	{
			flag = 2;
		}
		else
			current = current -> next;

	}while(flag != 2 && current->next);

	//when id is not found returns 0
	if(flag != 2)
		return 0;	
	else
		return 2;

}


//Adds provider report once all information has been recorded
int PeopleTable::add_provider_report(int provider_code, string add_date, string add_time, string add_name, int add_member_code, int add_service_code, float add_fee)	{

	int flag = 0;
	Node * current;

	flag = find_hash(provider_code, current);
	if(flag == 0)
		return 0;	//returns 0, code is not found within the system

	//Calling provider report constructor to make the report
	Provider_Report * p = new Provider_Report(add_date,add_time,add_name,add_member_code,add_service_code,add_fee);

	//Calling function from Person Class
	current -> data -> add_provider_type(p);

	return 1;

}

//Displays all reports of a specific person based on code. Choice is for either provider or member
int PeopleTable::display_personal_report(int code, int choice) {

	int flag = 0;
	Node * current;

	flag = find_hash(code, current);
	if(flag == 0)
		return 0;

	current -> data -> display_personal_type(choice);
}

//Display provider reports based on provider code
int PeopleTable::display_p_reports(int provider_code) {

	int flag = 0;
	Node * current;

	flag = find_hash(provider_code, current);
	if(flag == 0)
		return 0;	//returns 0, code is not found within the system

	//Call function that uses RTTI to convert Person* into Provider*
	current -> data -> display_provider_type();

	return 1;

}

//Wrapper function for displaying the summary report
int PeopleTable::summary_report() {

	//These variables will be passed by reference to other function calls
	//The other functions will save their values into these variables
	int total_providers = 0;
	int total_services = 0;
	float total_fees = 0;

	cout << "-------------SUMMARY REPORT---------------" << endl;

    for(int i = 0; i < 23; ++i) {
        summary_report_internal(table[i], total_providers, total_services, total_fees);
    }

    	cout <<  "-------------WEEKLY TOTALS----------------" << endl;
	cout << "Total Providers: " << total_providers << endl;
	cout << "Total Consultations: " << total_services << endl;
	cout << "Total Fees: $" << total_fees << endl;
	cout << endl;

}

//Recursive function for displaying the summary report
int PeopleTable::summary_report_internal(Node * current, int &total_providers, int &total_services, float &total_fees) {
	if(!current)
		return 0;

	//All 9-digit provider codes start with 3, isolating those codes
	int id = current -> data -> get_id();
	id = id%300000000;

	if(id < 200000000) {
		int check = current -> data -> summary_report_check(total_providers, total_services, total_fees);	
	}

	//recursive call to run through every node within LLL
	summary_report_internal(current -> next, total_providers, total_services, total_fees);
    
	return 0;

}

//Adds member reports based on member code
int PeopleTable::add_m_report(int member_code, string new_date, string new_name, string new_service, string new_memname, int new_memcode, string new_street, string new_city, string new_state, int new_zip) {
	int flag = 0;
	Node * current;

	flag = find_hash(member_code, current);
	if(flag == 0)
		return 0;	//returns 0, code is not found within the system

	//Calling member report constructor to make the report
	Member_Report * p = new Member_Report(new_date, new_name, new_service, new_memname, new_memcode, new_street, new_city, new_state, new_zip);

	//Calling function from Person Class
	current -> data -> add_member_type(p);

	return 1;
}

//Display member reports based on member code
int PeopleTable::display_m_reports(int member_code) {
  int flag = 0;
	Node * current;

	flag = find_hash(member_code, current);
	if(flag == 0)
		return 0;	//returns 0, code is not found within the system

	//Call function that uses RTTI to convert Person* into Member*
	current -> data -> display_member_type();

	return 1;
}

//For manager terminal, modifies personal information
int PeopleTable::person_modify (string modify, int ID,int option)
{
	Node * temp;
	if (find_hash(ID, temp) == 0)
		return 0;
	else
		return temp-> data ->info_modify(modify, option);	
	return true;
} 

//For manager terminal, deletes personal information
int PeopleTable::person_delete(int ID) {

	Node * current;
	Node * temp;
	int flag = find_hash_previous(ID, current);

	if(flag == 0)
		return 0;
	else if(flag == 1) {
		temp = current;
		current = NULL;
		delete temp;
	}	
	else {
		temp = current -> next;
		current -> next = temp -> next;
		delete temp;
		temp = NULL;
	}

}

//----------------------------------- Person Functions -------------------------------------
//The functions below use dynamic_cast to convert Person* into Provider*
//This is required in order to get into the scope of the provider to reach Provider data


int Person::add_provider_type(Provider_Report * to_add)
{	
	Provider * ptr = dynamic_cast<Provider*>(this);
	ptr -> add_report(to_add);

}

int Person::add_member_type(Member_Report * to_add)
{	
	Member * ptr = dynamic_cast<Member*>(this);
	ptr -> add_report(to_add);

}
// Wrapper function for writing data from a provider report to a file
void Person::wrapperFW(ofstream & file1) {
	Provider * ptr = dynamic_cast<Provider*>(this);
	if(ptr)
		ptr->fileWrite(file1);
}

int Person::write_p_report(string &add_date, string &add_time, string &add_name, int &add_member_code, int &add_service_code, float &add_fee) {

	Provider * ptr = dynamic_cast<Provider*>(this);
	ptr -> write_report(add_date,add_time,add_name,add_member_code,add_service_code,add_fee);

}

int Person::display_member_type()
{
  cout << "---------------WEEKLY MEMBER REPORT--------------" << endl;
	cout << "Member: " << this->get_name() << endl;
	cout << "Member Code: " << this->get_id() << endl;
	cout << endl;

	Member * ptr = dynamic_cast<Member*>(this);
	ptr -> display_reports();
}

int Person::display_personal_type(int choice) {

	int check;	
	if(choice == 1) {
		Provider * ptr = dynamic_cast<Provider*>(this);
		check = ptr -> display_reports();
	}

	else {
		Member * ptr = dynamic_cast<Member*>(this);
		check = ptr -> display_reports();
	}
	return check;
}

int Person::display_provider_type() {

	cout << "---------------WEEKLY REPORT--------------" << endl;
	cout << "Provider: " << this->get_name() << endl;
	cout << "Provider Code: " << this->get_id() << endl;
	cout << endl;

	Provider * ptr = dynamic_cast<Provider*>(this);
	ptr -> display_reports();
}

int Person::summary_report_check(int &total_providers, int &total_services, float &total_fees)
{
	int check;
	Provider * ptr = dynamic_cast<Provider*>(this);
  	check = ptr -> summary_report(total_providers, total_services, total_fees);

	return check; //Will return 0 if there are no reports for Provider
}
int Person::info_modify( string modify, int option)
{
	if (option == 1)
		name = modify;
//	else if (option == 2)
//		address = modify;
//	else if (option ==3)
//		city = modify;
//	else if (option ==4)
//		state = modify;
	else 
		return false;	
	return true;	
}

//------------------------ Provider and Provider Report Functions ---------------------------

Provider_Report *& Provider_Report::go_next(){
	return next;
}

//Adds node to provider report LLL
int Provider::add_report(Provider_Report * to_add){

	if(!report)
		report = to_add;
	else
		add_to_end(to_add, this->report);
}

//Adds node to end of provider report LLL
int Provider::add_to_end(Provider_Report * to_add, Provider_Report * current){
	if(!current)
		return 0;
	else if(!current -> go_next())
		current -> go_next() = to_add;
	else
		add_to_end(to_add, current -> go_next());
	return 0;
}

int Provider::write_report(string &add_date, string &add_time, string &add_name, int &add_member_code, int &add_service_code, float &add_fee) {

	if(this -> report) {
		add_date = this -> report -> get_date();
		add_time = this -> report -> get_time();
		add_name = this -> report -> get_name();
		add_member_code = this -> report -> get_mem_code();
		add_service_code = this -> report -> get_serv_code();
		add_fee = this -> report -> get_fee();

		return 1;
	}
	
	return 0;
}

//Displays all reports for specific provider
int Provider::display_reports() {
	if(!report)
		return 0;
	else
	{	
		Provider_Report * temp = report;

		while(temp)
		{
			temp -> display();
			temp = temp -> go_next();
		}
	}
}

//Displays information for summary reports and adds to totals by reference
int Provider::summary_report(int &total_providers, int &total_services, float &total_fees)
{
	if(!report)
		return 0;
	
	string provider_name = this -> get_name();
	cout << "Provider: " << provider_name << endl;

	Provider_Report * temp = report;
	int weekly_count = 0;	//total number of consultations this provider has had
	float weekly_fee = 0;

	while(temp) {
		++weekly_count;
		weekly_fee += temp -> get_fee();
		temp = temp -> go_next();
	}	

	cout << "Total Number of Consultations: " << weekly_count << endl;
	cout << "Total fee for week: $" << weekly_fee << endl;
	cout << endl;

	total_services += weekly_count;
	total_fees += weekly_fee;
	++total_providers;

	return 1;

}

// Function that takes the stored reports and writes them to file, 
// has a loop to go through all reports since they're stored in a LLL
void Provider::fileWrite(ofstream & file1) {	
	Provider_Report * temp = report;	

	while(temp) {
		if(!temp)
			return;
		if(temp) {
			file1 << this->get_id();
			file1 << ',';
			file1 << temp->get_date();
			file1 << ',';
			file1 << temp->get_time();	
			file1 << ',';
			file1 << temp->get_name();
			file1 << ',';
			file1 << temp->get_mem_code();	
			file1 << ',';
			file1 << temp->get_serv_code();
			file1 << ',';
			file1 << temp->get_fee();
			file1 << endl;
		}
		temp = temp->go_next();	
	}

}

//Display of individual reports for providers
int Provider_Report::display() {

	cout << "Date of Service: " << date_of_service << endl;
	cout << "Time: " << time << endl;
	cout << "Member Name: " << member_name << endl;
	cout << "Member Code: " << member_code << endl;
	cout << "Service Code: " << service_code << endl;
	cout << "Service Fee: $" << fee << endl;
	cout << endl;

} 

//--------------------- Member Functions ---------------------------

Member_Report *& Member_Report::go_next(){
	return next;
}

//Adds node to member report LLL
int Member::add_report(Member_Report * to_add){

	if(!report)
		report = to_add;
	else
		add_to_end(to_add, this->report);
}

//Adds node to end of member report LLL
int Member::add_to_end(Member_Report * to_add, Member_Report * current){
	if(!current)
		return 0;
	else if(!current -> go_next())
		current -> go_next() = to_add;
	else
		add_to_end(to_add, current -> go_next());
	return 0;
}

int Member::write_report(string &add_member_name, string &add_member_code, string &add_street, string &add_city, string &add_state, int &add_zip, string & add_date, string &add_name, string &add_service) {

	if(this -> report) {
	add_member_name = this -> report -> get_mem_name();
	add_member_code = this -> report -> get_code();
	add_street = this -> report -> get_street();
	add_city = this -> report -> get_city();
	add_state = this -> report -> get_state();
	add_zip = this -> report -> get_zip();
  add_date = this -> report -> get_date();
	add_name = this -> report -> get_name();
	add_service = this -> report -> get_service();

	return 1;
	}
	
	return 0;
}

//Displays all reports for specific member
int Member::display_reports() {
	if(!report)
		return 0;
	else
	{	
		Member_Report * temp = report;

		while(temp)
		{
			temp -> display_member();
			temp = temp -> go_next();
		}
	}
}

int Services() {
        string services[] = {"Yoga\nIntense stretches.\n$99.99\n100001\n\n", "Therapy talk\nTalking with a doctor about your problem.\n$50.50\n100002\n\n","Detoxification of chocolate\nWhere they remove chocolate from your home.\n$499.99\n100003\n\n","Short-term residential treatment\nStay at the facility for a week,getting prepared for long term counseling.\n$900.00\n100004\n\n","Recovery sessions\nBeing supervise when being around chocolate. This is for long term customers.\n$850.66\n100005\n\n","Meditation\nLearn what meditating is and how it can be use to get over your addiction.\n$110.00\n100006\n\n","Find a substitution\nDoctor will help you find something to get your mind off of chocolate.\n$45.50\n100007\n\n"};
        for(int i =0;i<7;++i)
        {
                cout << services[i];
        }
        return 0;
}

// - - - - - - - - - - -  - - - -  - - -  - - -
// functions used as checkers


int new_user_id_checker( int id)
{

	 int temp;
	 int count = 0;
	 temp = id;
	 while(temp != 0) 
	 {
		 ++count;
        	temp /= 10;
    	 }
	
	 if (count != 9)
		 return false;

	 return true;

}

int name_size_checker(string name)
{
	if (name.size() >25)
		return false;
	return true;
}

int service_code_checker(int service_code)
{

	 int temp;
	 int count = 0;
	 temp = service_code;
	 while(temp != 0) 
	 {
		 ++count;
        	temp /= 10;
    	 }
	
	 if (count != 6)
		 return false;

	 return true;

}

int service_fee_checker(float service_fee)
{
	if (service_fee < 0)
		return false;
	if (service_fee > 999.99)
		return false;

	return true;
}



int date_checker(string date)
{
	cout<<endl;

	if (date.size() != 10)
		return false;
	else if ( (date[2] != date [5]) || (date[2] != '-') )
		return false;
	
	else if ( (date[0] != '1') && (date[0] != '0') )
	{
		return false;
	}

	else  
	{
		for (int i = 0; i < date.size(); ++i) 
		{
			if (isdigit(date[i]) == false && i != 2 && i != 5) 
            			return false; 
		}
  
	}
	
	return true;
}


int time_checker(string time)
{
	if(time.size() != 5)
		return false;

	else if (time[2] != ':')
		return false;
	
	else
	{
		for (int i = 0; i < time.size(); ++i) 
		{
			if (isdigit(time[i]) == false && i != 2)
            			return false; 
		}
	}

	return true;
}


int street_address_checker( string street_address)
{
	if ( street_address.size() > 25)
		return false;
	return true;
}

int city_checker( string city)
{
	if (city.size() >14)
		return false;
	return true;
}

int state_checker(string state)
{
	if (state.size() >3)
		return false;
	return true;

}

//Display of individual info for members
void Member_Report::display_member() {
	cout << "Member Name: " << member_name << endl;
	cout << "Member Code: " << member_code << endl;
	cout << "Member Address: " << street << " " << city << ", " << state << "  " << zip << endl << endl;
  cout << "Date of Service: " << date_of_service << endl;
	cout << "Provider Name: " << provider_name << endl;
	cout << "Service Received: " << service_name << endl << endl;
}
