#include "classes.h"

int main() {
    PeopleTable test;
    test.files_read();
    return 0;
}

//--------------------- People Table Functions ---------------------------

int PeopleTable::files_read() {

    ifstream file1("../data/members.txt");
    string str;

    while (getline(file1, str, ',') )
    {
        int id = stoi(str);
        if(getline(file1, str, '\n')) {
            Person * p = new Member(id, str);
            int bucket = this -> hash_function(id);
            Node * temp = new Node(p);
            add_node(temp, bucket);
        }
        else
            break;
    }
    ifstream file2("../data/providers.txt");

    while (getline(file2, str, ',') )
    {
        int id = stoi(str);
        if(getline(file2, str, '\n')) {
            Person * p = new Provider(id, str);
            int bucket = this -> hash_function(id);
            Node * temp = new Node(p);
            add_node(temp, bucket);
        }
        else
            break;
    }
    display1();
    return 0;
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


