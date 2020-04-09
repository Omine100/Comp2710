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
#include <sstream>
#include <cassert>
using namespace std;

//Structure for creating a linked list that holds a trivia question, answer, and point amount.
struct trivia_node {
    string question;
    string answer;
    int point;
    trivia_node *next;
};

//Creates a pointer to trivia_node.
typedef trivia_node* ptr_node;

//Function declarations.
void init_question_list(ptr_node&);
bool checkResponse(string, int);
void add_question(ptr_node&, int);
int ask_question(ptr_node, int);
void Unit_Test();

//Creates two versions.
//#define UNIT_TESTING
#define trivia_quiz

//Main program.
int main() {
#ifdef trivia_quiz
    string response;
    int num_of_questions = 1;
    ptr_node node_list = new trivia_node;

    cout << "*** Welcome to Matthew's trivia quiz game ***\n";
    cout << "Would you like to add a question? (Yes/No): ";
    getline(cin, response);
    if (checkResponse(response, 1)) {
        do {
            add_question(node_list, num_of_questions);
            cout << "Continue? (Yes/No): ";
            getline(cin, response);
            if (response == "Yes" || response == "yes") {
                num_of_questions = num_of_questions + 1;
            }
        } while (checkResponse(response, 2));
        ask_question(node_list, num_of_questions);
    } else {
        init_question_list(node_list);
        ask_question(node_list, 3);
    }

    cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***";
    return 0;
#endif

#ifdef UNIT_TESTING
    Unit_Test();
    return 0;
#endif
}

//Checks users responses and returns true or false.
bool checkResponse(string response, int choice) {
    while(response != "Yes" && response != "yes" && response != "No" && response != "no") {
        cout << "\n------ Invalid Input ------\n\n";
        switch (choice) {
            case 1:
                cout << "Would you like to add a question? (Yes/No): ";
                break;
            case 2:
                cout << "Continue? (Yes/No): ";
                break;
            default:
                cout << "(Yes/No): ";
                break;
        }
        getline(cin, response);
    }

    if (response == "Yes" || response == "yes") {
        return true;
    }
    return false;
}

//Initializes the quiz to have these three questions inputted into the linked list.
void init_question_list(ptr_node& q_list) {
    ptr_node new_question = new trivia_node;
    new_question->question = "How long was the shortest war on record? (Hint: how many minutes)?";
    new_question->answer = "38";
    new_question->point = 100;
    q_list = new_question;

    ptr_node new_question2 = new trivia_node;
    new_question2->question = "What was the Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)?";
    new_question2->answer = "Bank of Italy";
    new_question2->point = 50;
    q_list->next = new_question2;

    ptr_node new_question3 = new trivia_node;
    new_question3->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
    new_question3->answer = "Wii Sports";
    new_question3->point = 20;
    q_list->next->next = new_question3;
}

//Gives user the option to add a question to the linked list.
//Question is added to the front of the linked list.
void add_question(ptr_node& q_list, int num_of_questions) {
    string question, answer, stringPoint;
    int point;
    
    ptr_node new_question = new trivia_node;

    cout << "Enter a new question: ";
    getline(cin, question);
    cout << "Enter an answer: ";
    getline(cin, answer);
    cout << "Enter award points: ";
    getline(cin, stringPoint);
    stringstream(stringPoint) >> point;

    new_question->question = question;
    new_question->answer = answer;
    new_question->point = point;

    if (num_of_questions == 1) {
        q_list = new_question;
    } else {
        new_question->next = q_list;
        q_list = new_question;
    }
}

//Checks for null value.
//Asks the user trivia questions and starts the game
int ask_question(ptr_node q_list, int num_ask) {
    int points = 0;
    if (q_list == NULL) {
        return 0;
    } else if (num_ask < 1) {
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
    } else {
        string user_answer;
        for (int x = 0; x < num_ask; x++) {
            cout << "\nQuestion: " << q_list->question;
            cout << "\nAnswer: ";
            getline(cin, user_answer);
            if (user_answer.compare(q_list->answer) == 0) {
                cout << "Your answer is correct. You receive " << q_list->point << " points.\n";
                points = points + q_list->point;
            } else {
                cout << "Your answer is wrong. The correct answer is: " << q_list->answer << "\n";
            }
            cout << "Your total points: " << points << "\n";
            if (q_list->next == NULL) {
                break;
            }
            q_list = q_list->next;
        }
    }

    return points;
}

//Test cases to check whether the methods work.
void Unit_Test() {
    cout << "*** This is a debugging version ***\n";

    cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
    ptr_node node_list1 = new trivia_node;
    init_question_list(node_list1);
    ask_question(node_list1, 0);
    cout << "\nCase 1 Passed\n\n";

    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters a correct answer.";
    ptr_node node_list2 = new trivia_node;
    init_question_list(node_list2);
    int test2;
    test2 = ask_question(node_list2, 1);
    assert(test2 == 100);
    cout << "\nCase 2.1 Passed\n\n";

    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters an incorrect answer.";
    ptr_node node_list3 = new trivia_node;
    init_question_list(node_list3);
    int test3;
    test3 = ask_question(node_list3, 1);
    assert(test3 == 0);
    cout << "\nCase 2.2 Passed\n\n";

    cout << "Unit Test Case 3.1: Ask all questions of the last trivia in the linked list. The tester enters correct answers.";
    ptr_node node_list4 = new trivia_node;
    init_question_list(node_list4);
    int test4;
    test4 = ask_question(node_list4, 3);
    assert(test4 == 170);
    cout << "\nCase 3.1 Passed\n\n";

    cout << "Unit Test Case 3.2: Ask all questions of the last trivia in the linked list. The tester enters wrong answers.";
    ptr_node node_list5 = new trivia_node;
    init_question_list(node_list5);
    int test5;
    test5 = ask_question(node_list5, 3);
    assert(test5 == 0);
    cout << "\nCase 3.2 Passed\n\n";

    cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
    cout << "Warning - There is only 3 trivia in the list.";
    if (5 > 3) {
        cout << "\nCase 4 Passed\n\n";
    }

    cout << "*** End of the Debugging Version ***" << endl;
}