//
// Created by Aryeh Kempler-Delugach on 3/13/20.
//
/*
#include "classes.h"
#include <assert.h>     // assert

//add these to the class
int run_tests();
int check_table();
int check_table_initialized();
int check_table_len();
int check_hash();
int check_node_add_data();
int check_node_add_collision();
int check_display_empty();
int check_display_something()
int check_find_hash_empty();
int check_find_hash_too_big();
int check_find_hash_something();
int check_find_hash_previous_empty();
int check_find_hash_previous_something();
int check_provider_report_none();
int check_provider_report_display_none();
int check_p_report();
int check_summary_report_internal_none();
int check_addm_none();
int check_p_report();
//GOOD JOB ADDING THESE


//People Table Class tests
int PeopleTable::run_tests() {
    check_table();
    check_table_initialized();
    check_table_len();
    check_hash();
    check_node_add_data();
    check_node_add_collision();
    check_display_empty();
    check_display_something()
    check_find_hash_empty();
    check_find_hash_too_big();
    check_find_hash_something();
    check_find_hash_previous_empty();
    check_find_hash_previous_something();
    check_provider_report_none();
    check_provider_report_display_none();
    check_p_report();
    check_summary_report_internal_none();
    check_addm_none();
    check_p_report();
    check_state();
}

int PeopleTable::check_table() {
    PeopleTable test_table;
    assert(test_table.table);
}

int PeopleTable::check_table_initialized() {
    PeopleTable test_table;
    assert(test_table.table[0] == nullptr);
}

int PeopleTable::check_table_len() {
    PeopleTable test_table;
    assert(test_table.table[22] == nullptr);
}

int PeopleTable::check_hash() {
    PeopleTable test_table;
    assert(test_table.hash_function(123456) == (123456 % 23));
}

int PeopleTable::check_node_add_data() {
    PeopleTable test_table;
    Node * test = new Node();
    int hash = (123456 % 23);
    test_table.add_node(test, hash);
    assert(test_table.table[hash]->data == nullptr);
}

int PeopleTable::check_node_add_collision() {
    PeopleTable test_table;
    Node * test = new Node();
    int hash = (123456 % 23);
    test_table.add_node(test, hash);
    test = new Node();
    test_table.add_node(test, hash);
    assert(test_table.table[hash]->next->data == nullptr);
}

int PeopleTable::check_display_empty() {
    PeopleTable test_table;
    assert(test_table.display(test_table.table[0]) == 0);
}

//CHANGE LINE 174 to 'return 1;'
int PeopleTable::check_display_something() {
    PeopleTable test_table;
    Node * test = new Node();
    int hash = 0;
    test_table.add_node(test, hash);
    assert(test_table.display(test_table.table[0]) == 1);
}

int PeopleTable::check_find_hash_empty() {
    PeopleTable test_table;
    assert(test_table.add_node(124523, nullptr) == 0);
}

int PeopleTable::check_find_hash_too_big() {
    PeopleTable test_table;
    assert(test_table.add_node(200000001, nullptr) == 0);
}

int PeopleTable::check_find_hash_something() {
    PeopleTable test_table;
    Node * test = new Node();
    Person * guy_fieri = new Person(123456, 12, 'guy fieri');
    int hash = (123456 % 23);
    test_table.add_node(test, hash);
    assert(test_table.add_node(123456, test) == 1);
}

int PeopleTable::check_find_hash_previous_empty() {
    PeopleTable test_table;
    assert(test_table.add_node(124523, nullptr) == 0);
}

int PeopleTable::check_find_hash_previous_something() {
    PeopleTable test_table;
    Node * test = new Node();
    Person * gordon_ramsey = new Person(123456, 12, 'gordon ramsey');
    int hash = (123456 % 23);
    test_table.add_node(test, hash);
    assert(test_table.add_node(123456, test) == 1);
}

int PeopleTable::check_provider_report_none() {
    PeopleTable test_table;
    assert(test_table.add_provider_report(200000001, 'AHHH', 'WAAAH', 'WOOO', 13243, 12312, 213.0) == 0);
}

int PeopleTable::check_provider_report_display_none() {
    PeopleTable test_table;
    assert(test_table.display_personal_report(200000001, 1) == 0);
}

int PeopleTable::check_p_report() {
    PeopleTable test_table;
    assert(test_table.display_p_report(200000001, 1) == 0);
}

int PeopleTable::check_summary_report_internal_none() {
    PeopleTable test_table;
    assert(test_table.summary_report_internal(nullptr, 69, 69, 69.69) == 0);
}

int PeopleTable::check_addm_none() {
    PeopleTable test_table;
    assert(test_table.add_m_report(200000001, 'ZOOO', 'WEEEE', 'MAAAAA', 'AAAAAA', 69, 'MAAAAAA', 'AAAAAA', '!!!!!', 1234) == 0);
}

int PeopleTable::check_p_report() {
    PeopleTable test_table;
    assert(test_table.person_modify('crispy chicken', 200000001, 1) == 0);
}

int check_state() {
    assert(state_checker('69') == true);
}
*/
