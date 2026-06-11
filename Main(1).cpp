
// #include "prompt.h"


/*
Kareem Ismail

Date: May 30, 2026

Code Racer 1.5

Program Description: 
The ultimate way to both practice technical interview questions(LeetCode type questions) and 
have fun. The purpose of this is exactly that, provide more experience with LeetCode type 
questions in a 1v1 format. The player that completes the question within the 
time limit first wins. This solves the problem of wanting to practice but not having any incentive, 
since it is fun, it will drive you to play, also the rank system also has incentive
since people generally want to be ranked high. Compete against friends, or aim to 
be the best while learning!

*/

#include <iostream>
#include <cmath>
#include <random>
#include <limits>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

class RoundResult {
public:
    string code;
    int timeTaken;
    bool timedOut;
};


// ------------------------------
// GLOBAL STATE (temporary MVP storage)
// ------------------------------
vector<string> usernames;

RoundResult codingRound(string prompt){

    RoundResult result;
    result.timedOut = false; 

    cout << prompt << "\n\n";

    string line;
    string userCode = "";

    cout << "Type your code below (END to submit):\n";

    auto start = chrono::steady_clock::now();

    while (true) {

        auto now = chrono::steady_clock::now();

        auto elapsed =
            chrono::duration_cast<chrono::seconds>(now - start);

        if(elapsed.count() >= 120){
            cout << "Time is up!\n";
            result.timedOut = true;
            break;
        }

        getline(cin, line);

        if(line == "END")
            break;

        userCode += line + "\n";
    }

    auto finish = chrono::steady_clock::now();

    result.timeTaken =
        chrono::duration_cast<chrono::seconds>(
            finish - start
        ).count();

    result.code = userCode;

    return result;
}
    random_device rd;
    mt19937 gen(rd());
int getRandom(int size){

    

    uniform_int_distribution<> dist(0, size - 1);

    return dist(gen);
}

class Prompt{ // might need to rework the data types
    // vector<string> testCases;
    public:
    string description; 
    // string solution; 
};


// ------------------------------
// Local Versus Mode
// Placeholder coding environment with 3 loops(P1, P2, Judge)

/*
This function should give a prompt and a timer, 
a fake IDE for player 1 first, then player 2.
Then when both finish, the judge should see all code, and be given judging outlines. 
*/
// ------------------------------

void clearScreen() {
    system("clear");
    cout.flush();
}


void LocalOneVOne(string username1, string username2, string prompt){
    string winner;
    cout << "Give " << username1 << " the device. " << endl << "Prompt will be shown in 15 seconds." << endl;
    for (int i = 1; i <= 15; i++) {
        // cout << "Time elapsed: " << i << " seconds" << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
        cout << "Two minutes starts now!" << endl; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        RoundResult player1 = codingRound(prompt);

        string userCode1 = player1.code;

        clearScreen(); 
        cout << "Give " << username2 << " the device. " << endl << "Prompt will be shown in 15 seconds." << endl;
      
         for (int i = 1; i <= 15; i++) {
        // cout << "Time elapsed: " << i << " seconds" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        }
        cout << "Two minutes starts now!" << endl;

        RoundResult player2 = codingRound(prompt);

        string userCode2 = player2.code;

        clearScreen(); 
        cout << "Please give the device to the Judge" << endl << endl;

        cout << "Judge: You will recieve the code in 10 seconds, please find the winner according to these guidelines" << endl; 

        cout << "Please judge by whoever completed the assignment so an incomplete one is a loss, then judge by whoever completed it the fastest" << endl;

        cout << username1 << "'s Code: " << endl << endl;

        cout << userCode1 << endl << endl; 

        cout << username1 << " wrote this in " << player1.timeTaken << " seconds." << endl << endl;

        cout << username2 << "'s Code: " << endl << endl;

        cout << userCode2 << endl << endl; 

        cout << username2 << " wrote this in " << player2.timeTaken << " seconds." << endl << endl;

        cout << "Please choose the winner" << endl; 

        getline(cin, winner);

        cout << "The winner is " << winner << "!" << endl; 
}

// ------------------------------
// TIMER TEST FUNCTION
// Prints every second for 60 seconds
// ------------------------------
void testTimer() {
    cout << "Starting timer...\n";

    for (int i = 1; i <= 60; i++) {
        cout << "Time elapsed: " << i << " seconds" << endl;

        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "Timer ended at 60 seconds.\n";
}

// ------------------------------
// USERNAME INPUT FUNCTION
// Simple version using vector storage
// ------------------------------
vector<string> GetUsernames() {

    vector<string> players(2);

    cout << "Player 1 enter your username: ";
   
    getline(cin, players[0]);
    while(players[0].empty()){
        cout << "Username cannot be empty: ";
        getline(cin, players[0]);
    }

    cout << "Player 2 enter your enter username: ";
    getline(cin,players[1]);
    while(players[1].empty()){
        cout << "Username cannot be empty: ";
        getline(cin, players[0]);
    }


    return players;
}

// ------------------------------
// PRACTICE MODE
// Placeholder coding environment
// ------------------------------
void StartPractice(string prompt) {
    cout << "\n================ PRACTICE MODE ================\n";

    RoundResult prac = codingRound(prompt);

    cout << prac.code << endl;

    cout << "Done in " << prac.timeTaken << " seconds!" << endl; 

    cout << "\n(Submission stored — evaluation system coming later)\n";
}

// ------------------------------
// RANKED MODE NOT READY
// ------------------------------
void RankedNotReadyScreen() {
    cout << "\n=====================================\n";
    cout << "Ranked Mode is not ready yet.\n";
    cout << "Coming soon...\n";
    cout << "=====================================\n\n";
}

// ------------------------------
// MAIN MENU (TITLE SCREEN)
// ------------------------------
int main() {
    vector<string> usernames(2);
    
    usernames = GetUsernames();

    char choice;

    vector<Prompt> prompts;
  
    Prompt p1;
    p1.description = "Write a function that returns sum of two numbers";

    Prompt p2;
    p2.description = "Write a function that finds max of two numbers";

    Prompt p3;
    p3.description = "Write a function that checks if number is even";

    Prompt p4;
    p4.description = "Write a function that returns the largest of 3 numbers";

    Prompt p5;
    p5.description = "Write a function that finds the minimum in a vector";

    Prompt p6;
    p6.description = "Write a function checks if a numnber is odd";

    Prompt p7;
    p7.description = "Write a function that counts vowels in a string";

    Prompt p8;
    p8.description = "Write a function that finds sum of elements in vector";

    Prompt p9;
    p9.description = "Write a function that gets a username from input";

    Prompt p10;
    p10.description = "Write a function checks if number is positive/negative";

    prompts.push_back(p1);
    prompts.push_back(p2);
    prompts.push_back(p3);
    prompts.push_back(p4);
    prompts.push_back(p5);
    prompts.push_back(p6);
    prompts.push_back(p7);
    prompts.push_back(p8);
    prompts.push_back(p9);
    prompts.push_back(p10);


    while (true) {
        cout << "\n=========== CODERACER MENU ===========\n";
        cout << "p - Practice Mode\n";
        cout << "r - Ranked Mode (Coming Soon)\n";
        cout << "t - Test Timer\n";
        cout << "l - Local 1v1 Mode\n";
        cout << "q - Quit\n";
        cout << "======================================\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 'p':
                if(prompts.empty()){
                    cout << "No prompts available.\n";
                    return 0; 
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                StartPractice(prompts.at(getRandom(prompts.size())).description);
                break;

            case 'r':
                RankedNotReadyScreen();
                break;

            case 't':
                testTimer();
                break;

            case 'q':
                cout << "Exiting program. Goodbye " << usernames[0] << " and " << usernames[1] << "!" << endl; 
                return 0;
            case 'l':
                if(prompts.empty()){
                    cout << "No prompts available.\n";
                    return 0; 
                }
                LocalOneVOne(usernames[0], usernames[1],prompts.at(getRandom(prompts.size())).description);
                break;
            default:
                cout << "Invalid input. Try again.\n";
        }
    }

    return 0;
}