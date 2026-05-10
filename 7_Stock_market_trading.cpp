#include<iostream>
#include<string>

using namespace std;


// ==========================================
// STOCK MARKET TRADING EXPERT SYSTEM
//
// FEATURES:
// - Uses rule-based decision making
// - Gives Buy / Sell / Hold advice
// - Uses market trend and risk level
// - Simple expert system using if-else
// ==========================================


void stockMarketTrading()
{
    string trend;
    string risk;

    double amount;


    cout << "\n====================================";
    cout << "\n STOCK MARKET EXPERT SYSTEM ";
    cout << "\n====================================\n";

    // User Input
    cout << "Enter Market Trend (up/down/stable): ";
    getline(cin, trend);

    cout << "Enter Risk Level (low/medium/high): ";
    getline(cin, risk);

    cout << "Enter Investment Amount: ";
    cin >> amount;


    cout << "\n========== INVESTMENT REPORT ==========\n";


    // Rule-based expert advice
    if(trend == "up")
    {
        if(risk == "high")
        {
            cout << "Recommendation : STRONG BUY\n";

            cout << "Expected Return : High\n";
        }

        else if(risk == "medium")
        {
            cout << "Recommendation : BUY\n";

            cout << "Expected Return : Moderate\n";
        }

        else
        {
            cout << "Recommendation : SAFE BUY\n";

            cout << "Expected Return : Stable\n";
        }
    }

    else if(trend == "down")
    {
        if(risk == "low")
        {
            cout << "Recommendation : HOLD\n";

            cout << "Risk : Low\n";
        }

        else
        {
            cout << "Recommendation : SELL\n";

            cout << "Risk : High Loss Possible\n";
        }
    }

    else if(trend == "stable")
    {
        cout << "Recommendation : WAIT AND WATCH\n";

        cout << "Market is currently stable.\n";
    }

    else
    {
        cout << "Invalid Market Trend.\n";
    }


    // Additional advice
    if(amount > 100000)
    {
        cout << "Advice : Diversify Investment Portfolio\n";
    }

    else if(amount > 50000)
    {
        cout << "Advice : Invest Carefully in Multiple Stocks\n";
    }

    else
    {
        cout << "Advice : Start with Low Risk Investments\n";
    }

    cout << "=======================================\n";
}


// Main Function
int main()
{
    stockMarketTrading();

    return 0;
}