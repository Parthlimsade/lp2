#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


// ======================================================
// AI CHATBOT USING MAP
//
// PURPOSE:
// --------
// Simple rule-based chatbot using map container.
//
// FEATURES:
// ---------
// - Stores questions and responses using key-value pair
// - Key   = user keyword
// - Value = chatbot response
// - Uses substring matching
// - Runs until user types exit/bye
//
// TIME COMPLEXITY:
// ----------------
// O(K * N)
//
// K = number of keywords
// N = length of input string
// ======================================================



string toLowerCase(string text)
{
    transform(text.begin(),
              text.end(),
              text.begin(),
              ::tolower);

    return text;
}



string getResponse(string input, map<string, string>& chatbotData)
{
    input = toLowerCase(input);

    for(auto pair : chatbotData)
    {
        string keyword = pair.first;

        if(input.find(keyword) != string::npos)
        {
            return pair.second;
        }
    }

    return "Sorry, I did not understand.";
}



void chatbot()
{
    map<string, string> chatbotData;

    // key = user input keyword
    // value = chatbot response

    chatbotData["hello"] =
        "Hello! How can I help you?";

    chatbotData["hi"] =
        "Hi! Welcome to our college.";

    chatbotData["admission"] =
        "Admissions are currently open.";

    chatbotData["fees"] =
        "Please visit accounts section for fee details.";

    chatbotData["courses"] =
        "We offer Computer, IT, AI and DS courses.";

    chatbotData["hostel"] =
        "Hostel facility is available for students.";

    chatbotData["placement"] =
        "Top companies visit campus every year.";

    chatbotData["bye"] =
        "Thank you for chatting.";

    chatbotData["exit"] =
        "Chat closed successfully.";


    string userInput;

    cout << "=========== AI CHATBOT ===========\n\n";

    while(true)
    {
        cout << "You : ";

        getline(cin, userInput);

        string response =
            getResponse(userInput, chatbotData);

        cout << "Bot : "
             << response
             << endl;

        string lowerInput =
            toLowerCase(userInput);

        if(lowerInput == "bye" ||
           lowerInput == "exit")
        {
            break;
        }
    }
}



int main()
{
    chatbot();

    return 0;
}