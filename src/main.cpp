using namespace std;
#include "classes.h"
#include <string>

int main()
{
	int response;
	int valid_answer = 1;
	Provider * provider_user;
	Member * member_user;
	PeopleTable data_base;


  	data_base.files_read("../data/members.txt", 1);
    	data_base.files_read("../data/providers.txt", 2);
	data_base.files_read("../data/p_reports.txt", 3);
	// data_base.files_read("../data/m_reports.txt", 4); 
	
	int retVal = data_base.display_p_reports(385773619);
	
	cout << retVal << endl;
   
	data_base.display1();	

	int provider_ID;
	int manager_ID;
	
	//perform the IO based on manager vs provider
	do 
	{
		cout<<endl<<"Welcome to the ChocAn system"<<endl<<endl;
		cout<<"Enter '0' for Manager Login" <<endl;
		cout<<"Enter '1' for Provider Login" <<endl;
		cin>>response;
		cin.ignore();

		if (response == 0)
		{
			// managers body 
			int manager_action = 0;
			int manager_sub_action = 0;
			int manager_repeat = 0;
			int flag = 0;
		
			do {		

				cout<<endl<<"Please input the manager passcode: "<<endl;
				cout<< "Example manager passcode: 908070" <<endl;
				cin>>manager_ID;
				cin.ignore();

				if(manager_ID == 908070)
					flag = 1;
				else
					cout << "\nInvalid Manager Code, please try again.\n " <<endl;

			}while(flag != 1);

			do
			{
				do
				{	
					cout<<"\nPlease select what you would like to do from the Menu"<<endl<<endl;
					cout<<"-Modify member account (enter 1)"<<endl;
					cout<<"-Modify provider account (enter 2)"<<endl;
					cout<<"-Display a providers report (enter 3)"<<endl;
					cout<<"-Display a members report (enter 4)"<<endl;
					cout<<"-Display the summary report (enter 5)"<<endl;
					cin>>manager_action;
					cin.ignore();	


					if (manager_action == 1)
					{
						do
						{
							cout<<"Please select what you would like to do with the memebers accounts"<<endl;
							cout<<"-Add a new member account (enter 1)"<<endl;
							cout<<"-Delete a current member (enter 2)"<<endl;
							cout<<"-Modify a current members information (enter 3)"<<endl;

							cin>>manager_sub_action;
							cin.ignore();

							if(manager_sub_action == 1)
							{
								//add new member
								int new_member_ID, new_zip;
								string new_member_name, new_address, new_city, new_state;
								Node * current;

								cout<<"Please enter the new members name"<<endl;
								getline(cin,new_member_name);


								do
								{
									cout<<"Please enter a new members nonexistent 9 digit ID"<<endl;
									cin>>new_member_ID;
									cin.ignore();
									if (new_user_id_checker(new_member_ID) == 0 || data_base.find_hash(new_member_ID,current) == 1 )
									{
										valid_answer = 0;
										cout<<"Entered ID either exists already or is not 9 digits, please try again"<<endl<<endl;
									}
									else
										valid_answer = 1;
								}while (valid_answer == 0);

								cout << "Enter the member's address:\n";
								getline(cin, new_address);

								cout << "Enter the city they live in:\n";
								getline(cin, new_city);

								cout << "Enter the state they live in:\n";
								getline(cin, new_state);

								cout << "Enter their zip code:\n";
								cin >> new_zip;

								member_user= new Member(new_member_ID, new_member_name, new_address, new_city, new_state, new_zip);

								int hashed_ID=data_base.hash_function(member_user->Member::get_id());


								Node * entry = new Node(member_user);

								data_base.add_node(entry,hashed_ID);

								data_base.display1();

							}
							else if(manager_sub_action == 2)
							{

								//delete current member
								int member_deleting;
								Node * current;
								do
								{
									cout<<"Please enter the ID of the member you wish to remove"<<endl;
									cin>>member_deleting;	
									cin.ignore();
									if (data_base.find_hash(member_deleting,current) == 0)
									{
										valid_answer = 0;
										cout<<"Entered ID does not exist, please try again"<<endl<<endl;
									}
									else
										valid_answer = 1;
								}while(valid_answer == 0);

							}

							else if (manager_sub_action == 3)
							{

								//modify current members info
								int member_ID;
								Node * current;
								int mod_choice;
								string mod_string;
								do
								{
									cout<<"Please enter the ID of the member you wish to modify"<<endl;
									cin>>member_ID;	
									cin.ignore();
									if (data_base.find_hash(member_ID,current) == 0)
									{
										valid_answer = 0;
										cout<<"Entered ID doesn't exist, please try again"<<endl<<endl;
									}
									else
										valid_answer = 1;
								}while(valid_answer == 0);

								do
								{
									cout<<"Please choose one of the categories below from the member to modify: "<<endl;
									cout<<endl<<"-Name (enter 1)"<<endl;
									cout<<"-Street Address (enter 2)"<<endl;
									cout<<"-City (enter 3)"<<endl;
									cout<<"-State (enter 4)"<<endl;
									cout << "-Zip (enter 5)" << endl;
									cin>>mod_choice;
									cin.ignore();


									if (mod_choice ==1)
									{
										cout<<"Please enter the new name you'd like to change to"<<endl;
										getline(cin,mod_string);

										if (name_size_checker(mod_string) ==0)
										{
											cout<<"invalid size, please try again"<<endl;
											mod_choice = 0;
										}

										else
										{
											data_base.person_modify(mod_string,member_ID,mod_choice);
										}
									}



									else if (mod_choice ==2)
									{
										cout<<"Please enter the new address you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (street_address_checker(mod_string) ==0)
										{
											cout<<"invalid size, please try again"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,member_ID,mod_choice);
									}


									else if (mod_choice ==3)
									{
										cout<<"Please enter the new city you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (state_checker(mod_string) ==0)
										{
											cout<<"invalid size, please try again"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,member_ID,mod_choice);
									}



									else if (mod_choice ==4)
									{
										cout<<"Please enter the new state you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (state_checker(mod_string) ==0)
										{
											cout<<"invalid size, please try again"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,member_ID,mod_choice); 
									}
									else if (mod_choice == 5)
									{
										cout<<"Please enter the new zip code you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (state_checker(mod_string) ==0)
										{
											cout<<"invalid size, please try again"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,member_ID,mod_choice); 
									}
									else
										cout<<"Invalid modify option, please try again"<<endl<<endl;

								} while (mod_choice <1 || mod_choice >4);


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
							cout<<"Please select what you would like to do with the providers accounts"<<endl;
							cout<<"-Add a new Provider account (enter 1)"<<endl;
							cout<<"-Delete a current Provider (enter 2)"<<endl;
							cout<<"-Modify a current Providers information (enter 3)"<<endl;

							cin>>manager_sub_action;
							cin.ignore();

							if(manager_sub_action == 1)
							{

								//add new provider
								int new_provider_ID, new_zip;
								string new_provider_name, new_address, new_city, new_state;
								Node * current;

								cout<<"Please enter the new Providers name"<<endl;
								getline(cin,new_provider_name);

								do
								{
									cout<<"Please enter the new providers nonexistent 9 digit ID"<<endl;
									cin>>new_provider_ID;
									cin.ignore();
									if (new_user_id_checker(new_provider_ID) == 0 || data_base.find_hash(new_provider_ID,current))
									{
										valid_answer = 0;
										cout<<"ID either exists already or is not 9 digits, please try again"<<endl<<endl;
									}
									else
										valid_answer = 1;
								}while (valid_answer == 0);

								cout << "Enter their address:\n";
								getline(cin, new_address);

								cout << "Enter their city:\n";
								getline(cin, new_city);

								cout << "Enter their state:\n";
								getline(cin, new_state);

								cout << "Enter their zip code:\n";
								cin >> new_zip;


								provider_user= new Provider(new_provider_ID,new_provider_name,new_address,new_city,new_state,new_zip);

								int hashed_ID=data_base.hash_function(provider_user->Provider::get_id());


								Node * entry = new Node(provider_user);

								data_base.add_node(entry,hashed_ID);



							}
							else if(manager_sub_action == 2)
							{
								//delete current provider

								int provider_deleting;	
								Node*current;

								do
								{
									cout<<"Please enter the Provider's ID you wish to delete"<<endl;		
									cin>>provider_deleting;
									cin.ignore();
									if (data_base.find_hash(provider_deleting,current) == 0)
									{
										valid_answer = 0;
										cout<<"Entered ID doesn't exist, please try again"<<endl<<endl;
									}
									else
										valid_answer = 1;
								}while(valid_answer ==  0);




							}

							else if (manager_sub_action == 3)
							{
								//modify current providers info
								int provider_ID;	
								Node*current;
								int mod_choice;
								string mod_string;

								do
								{
									cout<<"Please enter the ID of the provider you wish to modify"<<endl;		
									cin>>provider_ID;
									cin.ignore();
									if (data_base.find_hash(provider_ID,current) == 0)
									{
										valid_answer = 0;
										cout<<"ID doesn't exist, please try again"<<endl<<endl;
									}
									else
										valid_answer = 1;

								}while(valid_answer == 0);

								do
								{
									cout<<"Please choose one of the categories from the provider to modify"<<endl;
									cout<<endl<<"-Name (enter 1)"<<endl;
									cout<<"-Street Address (enter 2)"<<endl;
									cout<<"-City (enter 3)"<<endl;
									cout<<"-State (enter 4)"<<endl;
									cin>>mod_choice;
									cin.ignore();


									if (mod_choice ==1)
									{
										cout<<"Please enter the new name you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (name_size_checker(mod_string) ==0)
										{
											cout<<"invalid size, please try again"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,provider_ID,mod_choice); 
									}



									else if (mod_choice ==2)
									{
										cout<<"Please enter the new address you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (street_address_checker(mod_string) ==0)
										{
											cout<<"invalid size, please try again"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,provider_ID,mod_choice); 

									}


									else if (mod_choice ==3)
									{
										cout<<"Please enter the new city you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (state_checker(mod_string) ==0)
										{
											cout<<"invalid size, please try again"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,provider_ID,mod_choice); 
									}



									else if (mod_choice ==4)
									{
										cout<<"Please enter the new state you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (state_checker(mod_string) ==0)
										{
											cout<<"invalid size, please try again"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,provider_ID,mod_choice); 
									}
									else
										cout<<"Invalid option, please try again"<<endl<<endl;

								} while (mod_choice <1 || mod_choice >4);


							}
							else
							{
								cout<<"Invalid request, please try again"<<endl<<endl;
							}
						}while (manager_sub_action < 1 || manager_sub_action > 3);



					}

					else if (manager_action == 3)
					{

						int provider_ID;
						Node * current;

						do
						{
							cout<<"Please enter the providers ID number you wish you see reports from"<<endl;
							cin>>provider_ID;
							cin.ignore();

							if  (data_base.find_hash(provider_ID,current) == 0)
							{
								valid_answer = 0;
								cout<<"ID doesn't exist, please try again"<<endl<<endl;
							}
							else
								valid_answer = 1;
						}while(valid_answer == 0);


						data_base.display_p_reports(provider_ID);

					}



					else if (manager_action == 4)
					{

						int member_ID;
						Node * current;

						do
						{
							cout<<"Please enter the members ID number you wish you see reports from"<<endl;
							cin>>member_ID;
							cin.ignore();

							if (data_base.find_hash(member_ID,current) == 0)
							{
								valid_answer = 0;
								cout<<"Entered ID doesn't exist, please try again"<<endl<<endl;
							}
							else
								valid_answer = 1;
						}while(valid_answer == 0);

						cout<<"function not made yet "<<endl;

						//data_base.
						//have a function to show member report

					}


					else if (manager_action == 5)
					{
						cout<<"display summary report"<<endl;
						data_base.summary_report();
					}

					else
					{
						cout<<"Invalid action, please try again"<<endl<<endl;
					}

				} while ( (manager_action <1)||(manager_action > 5)  );

				cout<<endl<<endl<<"Would you like to peform another action?"<<endl;
				cout<<" Enter '0' for no and '1' for yes"<<endl;
				cin>>manager_repeat;
				cin.ignore();

			}while (manager_repeat == 1);


		}

		else if (response ==1)
		{
			int provider_code = 0;
			int provider_action = 0;
			int provider_repeat = 0;
			Node*current;	

			do
			{
				cout<<endl<<"Please input your provider ID number: "<<endl;
				cout << "Example Code: 309123411" <<endl;
				cin>>provider_ID;
				cin.ignore();

				if (data_base.find_hash(provider_ID,current) == 0)
				{
					valid_answer = 0;
					cout<<"Invalid ID, please try again"<<endl<<endl;
				}
				else {
					valid_answer = 1;
					cout << "\n Validated \n" << endl;
				}

			}while(valid_answer == 0);

			do
			{
				do
				{	
					cout<<"Please select what you would like to do from the Menu"<<endl<<endl;
					cout<<"-Provider Directory (enter 1)"<<endl;
					cout<<"-Bill Choc An (enter 2)"<<endl;
					cout<<"-Display weekly report (enter 3)"<<endl;
					cin>>provider_action;
					cin.ignore();


					if (provider_action == 1)
					{
						cout<<endl;
						Services();
						cout<<endl;
					}
					else if (provider_action == 2)
					{
						//Bill Choc An
						string date, time, member_name, comments;
						int member_IDD, service_code, provider_IDD;
						float service_fee;
						Node * current;	

						//Displays provider directory
						cout<<endl;
						Services();
						cout<<endl;

						do
						{
							cout<<"Please enter the member ID code:"<<endl;
							cin>>member_IDD;
							cin.ignore();
							if(data_base.find_hash(member_IDD,current) == 0)
							{
								valid_answer = 0;
								cout<<"Invalid Id, please try again"<<endl<<endl;
							}
							else
								valid_answer = 1;
						}while(valid_answer ==0);

						do
						{	
							cout<<"Please enter the current date in the format of 'MM-DD-YYYY'"<<endl;
							cin>>date;
							cin.ignore();
							if (date_checker(date) == 0)
							{
								valid_answer = 0;
								cout<<"Invalid input, please try again"<<endl<<endl;
							}
							else
								valid_answer = 1;
						}while(valid_answer == 0);

						do
						{
							cout<<"Please enter the current time as 'HH:MM'"<<endl;
							cin>>time;
							cin.ignore();	
							if (time_checker(time) == 0)
							{
								valid_answer = 0;
								cout<<"Invalid input, please try again"<<endl<<endl;
							}
							else
								valid_answer = 1;
						}while(valid_answer == 0);
						
						do
						{
							cout<<"Please enter the member's name"<<endl;
							getline(cin, member_name);
							valid_answer = 1;

							if (name_size_checker (member_name) == 0 || member_name.compare(current -> data -> get_name()))
							{
								valid_answer = 0;
								cout<<"Name does not exist in the system, please try again."<<endl<<endl;
							}
							else
								valid_answer = 1;

						}while(valid_answer == 0);
								
						do
						{
							cout<<"Please enter any comments you have (if you dont have any, just write 'none'):"<<endl;
							getline(cin, comments);

							if(!comment_checker)
							{
								valid_answer = 0;
								cout << "Error: Either entered too big of a comment or didn't enter anything, please try again" << endl;
							}
							else
								valid_answer = 1;
						}while(valid_answer ==0);
						
						do
						{
							cout<<"Please enter the service code"<<endl;
							cin>>service_code;
							cin.ignore();
							if (service_code_checker(service_code) == 0)
							{
								valid_answer = 0;
								cout<<"Invalid service code, please try again"<<endl;
								cout<<"Note: Service codes are six digits." <<endl<<endl;
							}
							else 
								valid_answer = 1;
						}while (valid_answer == 0);

						do
						{
							cout<<"Please enter the service fee for the service"<<endl;
							cin>>service_fee;
							cin.ignore();
							if (service_fee_checker (service_fee) == 0)
							{
								valid_answer = 0;
								cout<<"Invalid service fee, please try again"<<endl<<endl;
							}
							else
								valid_answer = 1;
						}while (valid_answer == 0);

						
						data_base.add_provider_report(provider_ID,date,time,member_name,comments,member_IDD,service_code,service_fee);
					}

					else if (provider_action == 3)
					{
						data_base.display_p_reports(provider_ID);
					}
						
					else
					{
						cout<<"\nInvalid action, please try again"<<endl<<endl;
					}


				} while ( (provider_action <1)||(provider_action > 3)  );
				
				cout<<endl<<endl<<"Would you like to peform another action?"<<endl;
				cout<<" Enter '0' for no and '1' for yes"<<endl;
				cin>>provider_repeat;
				cin.ignore();

			}while (provider_repeat == 1);
		}
		else
		{
			cout<<"\nInvalid response, please try again"<<endl;
		}

	} while (response != 0 && response != 1);
	
	data_base.files_write("../data/members_test_1.txt",1);
	data_base.files_write("../data/providers_test_1.txt",2);
	data_base.files_write("../data/provider_reports_test_1.txt",3);

	return 0;
}
