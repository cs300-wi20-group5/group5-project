#include "classes.h"

int main() {
    PeopleTable test;
    test.files_read("../data/members.txt", 1);
    test.files_read("../data/providers.txt", 2);
    test.display1();
    test.files_write("../data/test_members.txt");
    return 0;
}

//--------------------- People Table Functions ---------------------------

int PeopleTable::files_read(string fileName, int dataType) {

    ifstream file1(fileName);
    string str;

    while (getline(file1, str, ',') )
    {
	Person * p = nullptr;
        int id = stoi(str);
        if(getline(file1, str, '\n')) {

	    if(dataType == 1)
		p = new Member(id, str);
	    if(dataType == 2)
		p = new Provider(id, str);

            int bucket = this -> hash_function(id);
            Node * temp = new Node(p);
            add_node(temp, bucket);
        }
        else
            break;
    }

    return 0;
}

int PeopleTable::files_write(string fileName) {
    
    ofstream file1(fileName);
    for(int i = 0; i < 23; ++i) {
	if(this->table[i]) {
	    Node * tmp = this->table[i];
	    while(tmp) {
		file1 << tmp->data->get_id();
		file1 << ",";
		file1 << tmp->data->get_name();
		file1 << endl;	

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
        cout << "index " << i << ": ";
        display2(table[i]);
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


