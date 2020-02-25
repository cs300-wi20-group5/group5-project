//code goes here
using namespace std;
#include "classes.h"

//  code planning for IO 
int main()
{
	int response;
	do 
	{
		cout<<endl<<"Welcome to the ChocAn system"<<endl<<endl;
		cout<<"Please enter 0 if you are logging on as a manager or 1 if you are logging on as a provider."<<endl;
		cin>>response;


		if (response == 0)
		{
			// managers body 
		}

		else if (response ==1)
		{
			//provider body


		}
		else
		{
			cout<<"invalid response, please try again"<<endl;
		}
	} while (response != 0 && response != 1);

	return 0;
}


/*
	
	Provider * provider_object= new Provider(123456,"billy");

	cout<<provider_object->Provider::get_id()<<endl;

	PeopleTable hash_table;

//	hash_table.files_read();

	
	int new_id = hash_table.hash_function(provider_object->Provider::get_id());

	cout<<new_id<<endl;


	Node * entry = new Node(provider_object);

	cout<<hash_table.add_node(entry,new_id)<<endl;
	hash_table.display1();
	cout<<endl;
	
*/
	



/*
cout would you like to log in as a provider or manager
cin answer


if manager:
	-
if provider:


loop: 
	1.) ask to input ID
		- if invalid 
			beginning of loop again
		- elseif correct
			doctor = new provider(inputted_ID)		

loop:
	cout: options to choose: 
		- provider directory  (1)
		- bill choc An (2)
		- modify member account (3)
		-modify provider account (4)
cin answer ( in numbers)

if (1)
	display provider directory
if (2)
	cout please enter member code
	cin code in a temp variable
	loop
		cout provider directory	
		cout : enter 6 digit service code
		cin 6 digit code
		cout if this is right or not
		if not correct
			go back loop
		if correct
			exit loop
		cout enter comments?
		cin comments
		
		save all inputs

		cout to enter following things
		cin date & time
		cin date service was provided
		cin member name and #
		cin service code
		cin service fee
		
		save all in object?
		
if (3)
	display :
		- add (1)
		- delete (2)
		-modify(3)
	cin answer (in numbers)
	
	if (1)
		- adding member
	if (2)
		- deleting member
	if (3)
		- access member account and modify

if (4)
	display :
		- add (1)
		- delete (2)
		-modify(3)
	cin answer (in numbers)
	
	if (1)
		- adding provider
	if (2)
		- deleting provider
	if (3)
		- access provider account and modify


cout would user like to do more functions
cin answer
if yes
	loop
if no
	exit


*/
