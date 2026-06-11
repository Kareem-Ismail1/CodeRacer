#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

/*
Class Player
    username
    submittedCode
    score
    hasSubmitted
*/

class Prompt{ // might need to rework the data types
    // vector<string> testCases;
    string name; 
    // string solution; 
};


/*


Class GameSession
    players
    currentPrompt
    timerSeconds
    gameMode
    winner

    StartTimer()

    DisplayPrompt()

    SubmitCode(player)

    GradeSubmission(player)

    DetermineWinner()

    EndGame()

*/