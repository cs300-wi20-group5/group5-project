//code goes here
using namespace std;
#include "classes.h"

//  code planning for IO 
int main()
{
	int response;
	Provider * provider_user;
	PeopleTable data_base;
	data_base.files_read();

	int provider_ID;
	int manager_ID;
	
	//load database's profiles up with all preexisting users
	PeopleTable database;
	//database.files_read();

	//perform the IO based on manager vs provider
	do 
	{
		cout<<endl<<"Welcome to the ChocAn system"<<endl<<endl;
		cout<<"Please enter 0 if you are logging on as a manager or 1 if you are logging on as a provider."<<endl;
		cin>>response;


		if (response == 0)
		{
			// managers body 
			int manager_action = 0;
			int manager_sub_action = 0;
			int manager_repeat = 0;
				
			cout<<endl<<"Please input your manager ID number: "<<endl;
			cin>>manager_ID;

			/*
			 verify manager ID
			 */

			do
			{
				do
				{	
					cout<<"Please select what you would like to do from the Menu"<<endl<<endl;
					cout<<"-Modify member account (enter 1)"<<endl;
					cout<<"-Modify provider account (enter 2)"<<endl;
					cin>>manager_action;
					
					if (manager_action == 1)
					{
						do
						{
							cout<<"Please select what you would like to do with the memebers accounts"<<endl;
							cout<<"-Add a new member account (enter 1)"<<endl;
							cout<<"-Delete a current member (enter 2)"<<endl;
							cout<<"-Modify a current members information (enter 3)"<<endl;

							cin>>manager_sub_action;

							if(manager_sub_action == 1)
							{
							//add new member
							}
							else if(manager_sub_action == 2)
							{
							//delete current member
							}
							else if (manager_sub_action == 3)
							{
							//modify current members info
							}
							else
							{
								cout<<"Invalid request, please try again"<<endl<<endl;
							}
						}while (manager_sub_action < 1 || manager_sub_action > 3);

					}
					else if (manager_action == 2)
					{
						do
						{
							cout<<"Please select what you would like to do with the memebers accounts"<<endl;
							cout<<"-Add a new Provider account (enter 1)"<<endl;
							cout<<"-Delete a current Provider (enter 2)"<<endl;
							cout<<"-Modify a current Providers information (enter 3)"<<endl;
							
							cin>>manager_sub_action;

							if(manager_sub_action == 1)
							{
							//add new provider
							}
							else if(manager_sub_action == 2)
							{
							//delete current provider
							}
							else if (manager_sub_action == 3)
							{
							//modify current providers info
							}
							else
							{
								cout<<"Invalid request, please try again"<<endl<<endl;
							}
						}while (manager_sub_action < 1 || manager_sub_action > 3);


		
					}
					else
					{
						cout<<"Invalid action, please try again"<<endl<<endl;
					}

				} while ( (manager_action <1)||(manager_action > 4)  );

				cout<<endl<<endl<<"Would you like to peform another action?"<<endl;
				cout<<" Enter '0' for no and '1' for yes"<<endl;
				cin>>manager_repeat;

			}while (manager_repeat == 1);


		}

		else if (response ==1)
		{
			//provider body

			int provider_action = 0;
			int provider_repeat = 0;
			
			cout<<endl<<"Please input your provider ID number: "<<endl;
			cin>>provider_ID;
			/*
			check if input ID matches
			 */	

			do
			{
				do
				{	
					cout<<"Please select what you would like to do from the Menu"<<endl<<endl;
					cout<<"-Provider Directory (enter 1)"<<endl;
					cout<<"-Bill Choc An (enter 2)"<<endl;
					cin>>provider_action;


					if (provider_action == 1)
					{
						//display provider directory
					}
					else if (provider_action == 2)
					{
						//Bill Choc An
						string date;
						string time;
						string member_name;
						int member_ID;
						int service_code;
						float service_fee;


						cout<<"Please enter the members ID number:"<<endl;
						/*
						 verifies it is correct 
						 display if suspended or whatever else 
						
						 display directory
						 checks input and such and outputs and such
						 */
						cout<<"Please enter the current date in the format of 'MM-DD-YYYY'"<<endl;
						cin>>date;

						cout<<"Please enter the current time as 'HH:MM'"<<endl;
						cin>>time;

						cout<<"Please enter the member's name"<<endl;
						cin>>member_name;

						cout<<"Please enter the member's ID number: "<<endl;
						cin>>member_ID;

						cout<<"Please once again enter the service code"<<endl;
						cin>>service_code;

						cout<<"Please enter the service fee for the service"<<endl;
						cin>>service_fee;
						 
						
					}
					else
					{
						cout<<"Invalid action, please try again"<<endl<<endl;
					}


				} while ( (provider_action <1)||(provider_action > 4)  );
				
				cout<<endl<<endl<<"Would you like to peform another action?"<<endl;
				cout<<" Enter '0' for no and '1' for yes"<<endl;
				cin>>provider_repeat;

			}while (provider_repeat == 1);



		}

		else
		{
			cout<<"Invalid response, please try again"<<endl;
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
