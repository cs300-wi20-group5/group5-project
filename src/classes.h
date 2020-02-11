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
        for(int i = 0; i < 23; ++i) {table[i] = nullptr}
    }
    int hash_function(int id);
    int create_table();
private:
    Node ** table;
};

class Node {
    Node(Person * input) {
        this -> data = input;
        next = nullptr;
    }
public:
    Person * data;
    Node * next;
};

class Person {
public:
    Person(int new_id, char * new_name) {
        id = new_id;
        name = new_name;
    }
    int get_id() {return this -> id;}
protected:
    int id;
    char * name;
};

class Member: public Person {
public:
    Member(int a, char * b) : Person(a, b) {
    }
private:

};

class Provider: public Person {
public:
    Provider(int a, char * b) : Person(a, b) {
    }
private:

};



