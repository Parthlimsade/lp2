#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


// Function to convert text into lowercase
string toLower(string text)
{
    transform(text.begin(),
              text.end(),
              text.begin(),
              ::tolower);

    return text;
}


int main()
{
    // Knowledge Base
    map<string, string> chatbot = {

        {"hello",
         "Hello! How can I help you?"},

        {"hi",
         "Hello! How can I help you?"},

        {"admission",
         "Admissions are open now."},

        {"fees",
         "Please contact office for fee details."},

        {"courses",
         "We offer C++, Java, Python and AI courses."},

        {"hostel",
         "Hostel facility is available."},

        {"placement",
         "Many companies visit for placements."},

        {"library",
         "Library facility is available."},

        {"sports",
         "Sports facilities are available."},

        {"help",
         "You can ask about admission, fees, hostel and courses."},

        {"thanks",
         "You are welcome!"},

        {"bye",
         "Thank you for chatting."}
    };


    string userInput;

    cout << "=========================="
         << endl;

    cout << "      AI CHATBOT"
         << endl;

    cout << "=========================="
         << endl;

    cout << "Type 'bye' to exit."
         << endl;


    while(true)
    {
        cout << "\nYou : ";

        getline(cin, userInput);

        userInput = toLower(userInput);

        bool found = false;


        // Search keywords
        for(auto pair : chatbot)
        {
            if(userInput.find(pair.first)
               != string::npos)
            {
                cout << "Bot : "
                     << pair.second
                     << endl;

                found = true;


                // Exit condition
                if(pair.first == "bye")
                {
                    return 0;
                }

                break;
            }
        }


        // Default response
        if(!found)
        {
            cout << "Bot : Sorry, I did not understand."
                 << endl;
        }
    }

    return 0;
}