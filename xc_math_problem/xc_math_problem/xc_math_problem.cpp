// 23SP - COSC1436
// XC_mathProblem
// PROF KEITH
// WON HEO

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

//global var
const int OPTION_CNT = 7;
const int OPTION_ROW_CNT = 3;
const string OPTIONS[OPTION_CNT] = { "sin()", "cos()", "tan()", "arcsin()", "arccos()", "arctan()", "exit"};
bool g_bDegreeFlag = false;
double g_dataInput = 0;

//func prototype
void promptOption(void);
void promptUnitOfData(void);
void promptData(void);
double doTrig(string& optionInputInString, int optionInput, double userInput);

int main()
{
    int optionInput = 0;
    string optionInputToString;
    double result = 0;

    while (true)
    {
        //prompt option
        promptOption();

        cin >> optionInput;

        //exit condition
        if (optionInput == 7) {
            break;
        } 

        //invalid option input
        if (optionInput > OPTION_CNT || optionInput < 1) {
            cout << "invalid option.\n---------------------------------------" << endl;

            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }
        
        //prompt unit of data
        if (optionInput <= 3) {
            promptUnitOfData();
        }

        //prompt data
        promptData();
        
        //do Trig math & set optionInputInString var
        result = doTrig(optionInputToString, optionInput, g_dataInput);
        
        //print result
        cout << endl << optionInputToString << '(' << g_dataInput << ") = " << fixed << setprecision(3) << result;

        if (optionInput > 3) {
            cout << "(radian) / " << result * 180 / 3.14 << "(degree)";
        }

        cout << "\n---------------------------------------" << endl;
    }

    g_bDegreeFlag = false; 

    cout << "\nExit program...\n";

    return 0;
}

double doTrig(string& optionInputToString, int optionInput, double dataInput)
{
    switch (optionInput)
    {
    case 1:
        optionInputToString = "sin";
        return (g_bDegreeFlag) ? sin(dataInput * 3.14 / 180) : sin(dataInput);
    case 2:
        optionInputToString = "cos";
        return (g_bDegreeFlag) ? cos(dataInput * 3.14 / 180) : cos(dataInput);
    case 3:
        optionInputToString = "tan";
        return (g_bDegreeFlag) ? tan(dataInput * 3.14 / 180) : tan(dataInput);
    case 4:
        optionInputToString = "arcsin";
        return asin(dataInput);
    case 5:
        optionInputToString = "arccos";
        return acos(dataInput);
    case 6:
        optionInputToString = "artan";
        return atan(dataInput);
    default:
        return (INFINITY * 0.0);
        break;
    }
}

void promptOption(void)
{
    cout << "Unit Circle Trig Calc\n----------------------" << endl;

    for (int i = 0; i < OPTION_ROW_CNT; ++i) {
        cout << i + 1 << '.' << OPTIONS[i] << "    " << i + 1 + OPTION_ROW_CNT << '.' << OPTIONS[i + OPTION_ROW_CNT];

        if (OPTION_CNT % OPTION_ROW_CNT > i) {
            cout << '\t' << i + 1 + OPTION_ROW_CNT * 2 << '.' << OPTIONS[i + OPTION_ROW_CNT * 2];
        }

        cout << endl;
    }

    cout << "select option: ";
}

void promptUnitOfData(void)
{
    char c;

    while (true)
    {
        cout << "unit of data(D/degree, R/radian): ";

        cin >> c;

        if (c != 'D' && c != 'R') {
            cout << "invalid unit." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        g_bDegreeFlag = (c == 'D') ? true : false;

        break;
    }
}

void promptData(void)
{
    char c;

    while (true)
    {
        cout << "enter data: ";

        cin >> g_dataInput;

        if (cin.fail()) {
            cout << "invalid input. input must be numeric value" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        break;
    }
}