#include "Student.h"
#include "GlobalFunctions.h"
#include <iostream>
using namespace std;

int main()
{
    Student s1, s2;
    s1.SetName("Danielescu Genoveva");
    cout << s1.GetName()<<'\n';
    s2.SetName("Ionescu Robert");
    cout << s2.GetName()<<'\n';
    s1.SetMathematics(7.3f);
    cout << s1.GetMathematics() << '\n';
    s2.SetMathematics(6.15f);
    cout << s2.GetMathematics() << '\n';
    s1.SetEnglish(9.65f);
    cout << s1.GetEnglish() << '\n';
    s2.SetEnglish(8.4f);
    cout << s2.GetEnglish() << '\n';
    s1.SetHistory(5.55f);
    cout << s1.GetHistory() << '\n';
    s2.SetHistory(7.86f);
    cout << s2.GetHistory() << '\n';
    cout << s1.GetAverage() << '\n';
    cout << s2.GetAverage() << '\n';
    cout << compareName(s1, s2) << '\n';
    cout << compareMathematics(s1, s2) << '\n';
    cout << compareEnglish(s1, s2) << '\n';
    cout << compareHistory(s1, s2) << '\n';
    cout << compareAverage(s1, s2) << '\n';
}
