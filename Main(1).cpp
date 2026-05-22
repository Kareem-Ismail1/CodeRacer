#include <iostream>
#include <string>
#include <cmath>
using namespace std;
/*
Kareem Ismail
Date: April 26, 2026
Program Description: 
The ultimate way to both practice technical interview questions(LeetCode type questions) and 
have fun. The purpose of this is exactly that, provide more experience with LeetCode type 
questions in a 1v1, 2v2, or 4v4 format. The team that completes the question within the 
time limit first wins, if no one solves it, the winner is the one who got more test cases 
passed. This solves the problem of wanting to practice but not having any incentive, 
since it is fun, it will drive you to play, also the rank system also has incentive
since people generally want to be ranked high. Compete against friends, or aim to 
be the best while learning!
*/

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

// ------------------------------
// GLOBAL STATE (temporary MVP storage)
// ------------------------------
vector<string> usernames;

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
string GetUsername() {
    string username;

    cout << "Enter username: ";
    cin >> username;

    // check if username exists
    for (const string &u : usernames) {
        if (u == username) {
            cout << "Welcome back, " << username << "!\n";
            return username;
        }
    }

    // if new user
    cout << "New user created: " << username << "\n";

    usernames.push_back(username);
   
    return username;
}

// ------------------------------
// PRACTICE MODE
// Placeholder coding environment
// ------------------------------
void StartPractice() {
    cout << "\n================ PRACTICE MODE ================\n";

    string prompt = "Problem: Write a function that returns sum of two numbers.";

    cout << prompt << "\n\n";

    cout << "Type your code below (type END to finish):\n";

    string line;
    string userCode = "";

    cin.ignore(); // clear input buffer

    while (true) {
        getline(cin, line);

        if (line == "END") break;

        userCode += line + "\n";
    }

    cout << "\n--- Your Submitted Code ---\n";
    cout << userCode;

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
    string username = GetUsername();

    char choice;

    while (true) {
        cout << "\n=========== CODERACER MENU ===========\n";
        cout << "p - Practice Mode\n";
        cout << "r - Ranked Mode (Coming Soon)\n";
        cout << "t - Test Timer\n";
        cout << "e - Expanding on solutions\n";
        cout << "i - Expanding on idea and vision for coderacer\n";
        cout << "q - Quit\n";
        cout << "======================================\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 'p':
                StartPractice();
                break;

            case 'r':
                RankedNotReadyScreen();
                break;

            case 't':
                testTimer();
                break;

            case 'q':
                cout << "Exiting program. Goodbye " << username << "!\n";
                return 0;

            case 'e':
                cout << "Make a class of problems/solutions, and a vector of those objects" << endl;
                return 0; 

            case 'i':
                cout << "I don't want it to be like Codeforces, but I want it to be educational and competitive in nature" << endl;
                return 0;  

            default:
                cout << "Invalid input. Try again.\n";
        }
    }

    return 0;
}
