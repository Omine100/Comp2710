/*
 * FILE NAME: project4_mrb0094.cpp
 * AUTHOR: Matthew Browning
 * AU ID: mrb0094
 * ABOUT: This program allows for a user to submit and answer questions for points.
 * COMPILE: Compile project4_mrb0094.cpp and run.
 * HELP: Basic information provided by Professor Li and talk through with Ezra Hill from class.
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
using namespace std;

//Strucutre for creating a linked list that holds a trivia question, answer, and point amount
struct trivia_node {
    string question;
    string answer;
    int point;
    trivia_node *next;
};

//Creates a pointer to trivia_node
typedef trivia_node* ptr_node;

class trivia_list {
    public:
        trivia_list(){}
        trivia_list(string question, string answer, int points, trivia_list* link) {
            node.question = question;
            node.answer = answer;
            node.points = points;
            link = link;
        }
}

//Creates two versions
//#define UNIT_TESTING
#define trivia_quiz

int main() {
    
}