#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool arePair(char Open, char Close)
{
    if (Open == '(' && Close == ')')
        return true;
    else if (Open == '{' && Close == '}')
        return true;
    else if (Open == '[' && Close == ']')
        return true;
    else
        return false;
}
bool areBalanced(string Exp)
{
    stack<char> S;
    for (int i = 0; i < Exp.length(); i++)
    {
        if (Exp[i] == '(' || Exp[i] == '{' || Exp[i] == '[')
            S.push(Exp[i]);
        else if (Exp[i] == ')' || Exp[i] == '}' || Exp[i] == ']')
        {
            if (S.empty() || !arePair(S.top(), Exp[i]))
                return false;
            else
                S.pop();
        }
    }
    return S.empty();
}
int main()
{
    string Exp;
    cout << "Enter an expression: ";
    cin >> Exp;
    if (areBalanced(Exp))
        cout << "Balanced\n";
    else
        cout << "Not balanced\n";

    system("pause");
}