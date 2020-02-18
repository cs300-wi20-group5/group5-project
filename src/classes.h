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
    int files_write(string fileName);
    int hash_function(int id);
    int add_node(Node * to_add, int hash);
    int add_to_end(Node * to_add, Node * current);
    int display1();
    int display2(Node * current);
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
    int get_id() {return this -> id;}
    string get_name() {return this -> name;}
protected:
    int id;
    string name;
};

class Member: public Person {
public:
    Member(int a, string b) : Person(a, b) {
    }
private:

};

class Provider: public Person {
public:
    Provider(int a, string b) : Person(a, b) {
    }
private:

};



