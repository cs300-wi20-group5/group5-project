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

//  	data_base.files_read("../data/members.txt", 1);
 //   	data_base.files_read("../data/providers.txt", 2);


  	data_base.files_read("../data/old_members.txt", 1);
    	data_base.files_read("../data/old_providers.txt", 2);
 

   
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
							cout<<"\nPlease select what you would like to do with the memebers accounts"<<endl;
							cout<<"-Add a new member account (enter 1)"<<endl;
							cout<<"-Delete a current member (enter 2)"<<endl;
							cout<<"-Modify a current members information (enter 3)"<<endl;

							cin>>manager_sub_action;
							cin.ignore();

							if(manager_sub_action == 1)
							{
								//add new member
								int new_member_ID;
								string new_member_name;
								Node * current;

								cout<<"\nPlease enter the new members name"<<endl;
								getline(cin,new_member_name);
								

								do
								{
									cout<<"\nPlease enter a new members nonexistent 9 digit ID"<<endl;
									cin>>new_member_ID;
									cin.ignore();
									if (new_user_id_checker(new_member_ID) == 0 || data_base.find_hash(new_member_ID,current) == 1 )
									{
										valid_answer = 0;
										cout<<"\nEntered ID either exists already or is not 9 digits, please try again"<<endl<<endl;
									}
									else
										valid_answer = 1;
								}while (valid_answer == 0);

								member_user= new Member(new_member_ID,new_member_name);

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
									cout<<"\nPlease enter the ID of the member you wish to remove"<<endl;
									cin>>member_deleting;	
									cin.ignore();
									if (data_base.find_hash(member_deleting,current) == 0)
									{
										valid_answer = 0;
										cout<<"\nEntered ID does not exist, please try again"<<endl<<endl;
									}
									else
										valid_answer = 1;
								}while(valid_answer == 0);

								data_base.person_delete(member_deleting);

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
									cout<<"\nPlease enter the ID of the member you wish to modify"<<endl;
									cin>>member_ID;	
									cin.ignore();
									if (data_base.find_hash(member_ID,current) == 0)
									{
										valid_answer = 0;
										cout<<"\nEntered ID doesn't exist, please try again"<<endl<<endl;
									}
									else
										valid_answer = 1;
								}while(valid_answer == 0);

								do
								{
									cout<<"\nPlease choose one of the categories below from the member to modify: "<<endl;
									cout<<endl<<"-Name (enter 1)"<<endl;
									cout<<"-Street Address (enter 2)"<<endl;
									cout<<"-City (enter 3)"<<endl;
									cout<<"-State (enter 4)"<<endl;
									cin>>mod_choice;
									cin.ignore();


									if (mod_choice ==1)
									{
										cout<<"\nPlease enter the new name you'd like to change for the member"<<endl;
										getline(cin,mod_string);

										if (name_size_checker(mod_string) ==0)
										{
											cout<<"\nInvalid size, please try again"<<endl
											    <<"Note: name must be no more than 25 characters"<<endl;
											mod_choice = 0;
										}

										else
										{
											data_base.person_modify(mod_string,member_ID,mod_choice);
										}
									}



									else if (mod_choice ==2)
									{
										cout<<"Please enter the new street address you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (street_address_checker(mod_string) ==0)
										{
											cout<<"\nInvalid size, please try again"<<endl
											    <<"Note: street address must not exceed 25 characters"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,member_ID,mod_choice);
									}


									else if (mod_choice ==3)
									{
										cout<<"\nPlease enter the new city you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (state_checker(mod_string) ==0)
										{
											cout<<"\nInvalid size, please try again"<<endl
												<<"Note: city name must not exceed 14 characters"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,member_ID,mod_choice);
									}



									else if (mod_choice ==4)
									{
										cout<<"\nPlease enter the new state you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (state_checker(mod_string) ==0)
										{
											cout<<"\nInvalid size, please try again"<<endl
												<<"Note: state name must not exceed 2 characters"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,member_ID,mod_choice); 
									}
									else
										cout<<"\nInvalid modify option, please try again"<<endl
											<<"Note: choose an option from 1 - 4"<<endl;

								} while (mod_choice <1 || mod_choice >4);
							
							
							}
							else
							{
								cout<<"\nInvalid request, please try again"<<endl
									<<"Note: choose an option from 1 - 3"<<endl;
							}
						}while (manager_sub_action < 1 || manager_sub_action > 3);

					}

					else if (manager_action == 2)
					{
						do
						{
							cout<<"\nPlease select what you would like to do with the providers accounts"<<endl;
							cout<<"-Add a new Provider account (enter 1)"<<endl;
							cout<<"-Delete a current Provider (enter 2)"<<endl;
							cout<<"-Modify a current Providers information (enter 3)"<<endl;
							
							cin>>manager_sub_action;
							cin.ignore();

							if(manager_sub_action == 1)
							{

							//add new provider
							int new_provider_ID;
							string new_provider_name;
							Node * current;

							cout<<"\nPlease enter the new Providers name"<<endl;
							getline(cin,new_provider_name);

							do
							{
								cout<<"\nPlease enter the new providers nonexistent 9 digit ID"<<endl;
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


							
							provider_user= new Provider(new_provider_ID,new_provider_name);

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
									cout<<"\nPlease enter the Provider's ID you wish to delete"<<endl;		
									cin>>provider_deleting;
									cin.ignore();
									if (data_base.find_hash(provider_deleting,current) == 0)
									{
										valid_answer = 0;
										cout<<"\nEntered ID doesn't exist, please try again"<<endl<<endl;
									}
									else
										valid_answer = 1;
								}while(valid_answer ==  0);


								data_base.person_delete(provider_deleting);

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
									cout<<"\nPlease enter the ID of the provider you wish to modify"<<endl;		
									cin>>provider_ID;
									cin.ignore();
									if (data_base.find_hash(provider_ID,current) == 0)
									{
										valid_answer = 0;
										cout<<"\nID doesn't exist, please try again"<<endl<<endl;
									}
									else
										valid_answer = 1;

								}while(valid_answer == 0);

								do
								{
									cout<<"\nPlease choose one of the categories from the provider to modify"<<endl;
									cout<<endl<<"-Name (enter 1)"<<endl;
									cout<<"-Street Address (enter 2)"<<endl;
									cout<<"-City (enter 3)"<<endl;
									cout<<"-State (enter 4)"<<endl;
									cin>>mod_choice;
									cin.ignore();


									if (mod_choice ==1)
									{
										cout<<"\nPlease enter the new name you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (name_size_checker(mod_string) ==0)
										{
											cout<<"\ninvalid size, please try again"<<endl
												<<"Note: name must not exceed 25 characters"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,provider_ID,mod_choice); 
									}



									else if (mod_choice ==2)
									{
										cout<<"\nPlease enter the new street address you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (street_address_checker(mod_string) ==0)
										{
											cout<<"\ninvalid size, please try again"<<endl
												<<"Note: street address name must not exceed 25 characters"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,provider_ID,mod_choice); 

									}


									else if (mod_choice ==3)
									{
										cout<<"\nPlease enter the new city you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (state_checker(mod_string) ==0)
										{
											cout<<"\ninvalid size, please try again"<<endl
												<<"Note: city name must not exceed 14 characters"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,provider_ID,mod_choice); 
									}



									else if (mod_choice ==4)
									{
										cout<<"\nPlease enter the new state you'd like to change to"<<endl;
										getline(cin,mod_string);
										if (state_checker(mod_string) ==0)
										{
											cout<<"\ninvalid size, please try again"<<endl
												<<"Note: state name must not exceed 2 characters"<<endl;
											mod_choice = 0;
										}
										else
											data_base.person_modify(mod_string,provider_ID,mod_choice); 
									}
									else
										cout<<"\nInvalid option, please try again"<<endl
											<<"Note: Please choose an option from 1 - 4"<<endl;

								} while (mod_choice <1 || mod_choice >4);


							}
							else
							{
								cout<<"\nInvalid request, please try again"<<endl
									<<"Note: Please choose an option from 1 - 3"<<endl;
							}
						}while (manager_sub_action < 1 || manager_sub_action > 3);


		
					}
					
					else if (manager_action == 3)
					{

						int provider_ID;
						Node * current;

						do
						{
							cout<<"\nPlease enter the providers ID number you wish you see reports from"<<endl;
							cin>>provider_ID;
							cin.ignore();

							if  (data_base.find_hash(provider_ID,current) == 0)
							{
								valid_answer = 0;
								cout<<"\nProvider ID doesn't exist, please try again"<<endl<<endl;
							}
							else
								valid_answer = 1;
						}while(valid_answer == 0);


						data_base.display_personal_report(provider_ID,1);

					}


	
					else if (manager_action == 4)
					{

						int member_ID;
						Node * current;

						do
						{
							cout<<"\nPlease enter the members ID number you wish you see reports from"<<endl;
							cin>>member_ID;
							cin.ignore();

							if (data_base.find_hash(member_ID,current) == 0)
							{
								valid_answer = 0;
								cout<<"\nEntered member ID doesn't exist, please try again"<<endl<<endl;
							}
							else
								valid_answer = 1;
						}while(valid_answer == 0);

						data_base.display_personal_report(member_ID,2);
					}


					else if (manager_action == 5)
					{
						data_base.summary_report();
					}

					else
					{
						cout<<"\nInvalid action, please try again"<<endl
							<<"Note: please choose an option from 1 - 5"<<endl;
					}

				} while ( (manager_action <1)||(manager_action > 5)  );

				cout<<endl<<endl<<"\nWould you like to peform another action?"<<endl;
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
			Node*temp;	

			do
			{
				cout<<endl<<"\nPlease input your provider ID number: "<<endl;
				cout << "Example Code: 309123411" <<endl;
				cin>>provider_ID;
				cin.ignore();

				if (data_base.find_hash(provider_ID,temp) == 0)
				{
					valid_answer = 0;
					cout<<"\nInvalid provider ID, please try again"<<endl<<endl;
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
					cout<<"\nPlease select what you would like to do from the Menu"<<endl<<endl;
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
						string date;
						string time;
						string member_name;
						int member_IDD;
						int service_code;
						float service_fee;
						string service_name;
						int provider_IDD;
						Node * current;	

						//Displays provider directory
						cout<<endl;
						Services();
						cout<<endl;

						do
						{
							cout<<"\nPlease enter the member ID code:"<<endl;
							cin>>member_IDD;
							cin.ignore();
							if(data_base.find_hash(member_IDD,current) == 0)
							{
								valid_answer = 0;
								cout<<"\nInvalid Id, please try again"<<endl<<endl;
							}
							else
								valid_answer = 1;
						}while(valid_answer ==0);

						do
						{	
							cout<<"\nPlease enter the current date in the format of 'MM-DD-YYYY'"<<endl;
							cin>>date;
							cin.ignore();
							if (date_checker(date) == 0)
							{
								valid_answer = 0;
								cout<<"\nInvalid input, please try again"<<endl
									<<"Note: Please enter it exactly in the format of 'MM-DD'YYYY'"<<endl;
							}
							else
								valid_answer = 1;
						}while(valid_answer == 0);

						do
						{
							cout<<"\nPlease enter the current time as 'HH:MM'"<<endl;
							cin>>time;
							cin.ignore();	
							if (time_checker(time) == 0)
							{
								valid_answer = 0;
								cout<<"\nInvalid input, please try again"<<endl
									<<"Note: Please enter the time in the format of 'HH:MM'"<<endl;
							}
							else
								valid_answer = 1;
						}while(valid_answer == 0);
						
						do
						{
							cout<<"\nPlease enter the member's exact name"<<endl;
							getline(cin, member_name);
							valid_answer = 1;

							if (name_size_checker (member_name) == 0 || member_name.compare(current -> data -> get_name()))
							{
								valid_answer = 0;
								cout<<"\nName does not exist in the system, please try again."<<endl
									<<"Note: Please enter the members name exactly as stored from their account"<<endl;
							}
							else
								valid_answer = 1;

						}while(valid_answer == 0);

						do
						{
							cout<<"\nPlease enter the service code"<<endl;
							cin>>service_code;
							cin.ignore();
							if (service_code_checker(service_code) == 0)
							{
								valid_answer = 0;
								cout<<"\nInvalid service code, please try again"<<endl;
								cout<<"Note: Service codes are six digits." <<endl<<endl;
							}
							else 
								valid_answer = 1;
						}while (valid_answer == 0);

						do
						{
							cout<<"\nPlease enter the service fee for the service"<<endl;
							cin>>service_fee;
							cin.ignore();
							if (service_fee_checker (service_fee) == 0)
							{
								valid_answer = 0;
								cout<<"\nInvalid service fee, please try again"<<endl
									<<"Note: Service fees must be up to 999.99"<<endl;
							}
							else
								valid_answer = 1;
						}while (valid_answer == 0);
					
				//		do
				//		{
							cout<<"\nPlease enter the service name"<<endl;
							getline(cin,service_name);
							//if (service_fee_checker (service_fee) == 0)
						//	{
						//		valid_answer = 0;
						//		cout<<"\nInvalid service fee, please try again"<<endl
						//			<<"Note: Service fees must be up to 999.99"<<endl;
						//	}
						//	else
						//		valid_answer = 1;
				//		}while (valid_answer == 0);


						string street = "century";
						string city = "Hillsboro";
						string state = "OR";
						int zip = 97213;
						data_base.add_provider_report(provider_ID,date,time,member_name,member_IDD,service_code,service_fee);
						data_base.add_m_report(member_IDD,date,temp->data->get_name(),service_name,current->data->get_name(),member_IDD,street,city,state,zip);

						//data_base.display_personal_report(member_IDD,2);


					}

					else if (provider_action == 3)
					{
						data_base.display_p_reports(provider_ID);
					}
						
					else
					{
						cout<<"\nInvalid action, please try again"<<endl
							<<"Note: Choose an option between 1 - 3"<<endl;
					}


				} while ( (provider_action <1)||(provider_action > 3)  );
				
				cout<<endl<<endl<<"\nWould you like to peform another action?"<<endl;
				cout<<" Enter '0' for no and '1' for yes"<<endl;
				cin>>provider_repeat;
				cin.ignore();

			}while (provider_repeat == 1);
		}
		else
		{
			cout<<"\nInvalid response, please try again"<<endl
				<<"Note: Choose an option from 0 - 1"<<endl;
		}

	} while (response != 0 && response != 1);
//	data_base.display1();

	return 0;
}
