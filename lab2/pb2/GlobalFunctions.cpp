#include <cstring>
#include "GlobalFunctions.h"
//am considerat ca numele se compara tinand cont de ordinea lor alfabetica, caz in care valoarea "mai mare" este de fapt numele care este alfabetic mai jos pe lista
short int compareName(Student& s1, Student& s2)
{
	if ((strcmp(s1.GetName(), s2.GetName())) < 0)
		return -1;
	if ((strcmp(s1.GetName(), s2.GetName())) == 0)
		return 0;
	return 1;
}

short int compareMathematics(Student& s1, Student& s2)
{
	if (s1.GetMathematics() < s2.GetMathematics())
		return -1;
	if (s1.GetMathematics() == s2.GetMathematics())
		return 0;
	return 1;
}

short int compareEnglish(Student& s1, Student& s2)
{
	if (s1.GetEnglish() < s2.GetEnglish())
		return -1;
	if (s1.GetEnglish() == s2.GetEnglish())
		return 0;
	return 1;
}

short int compareHistory(Student& s1, Student& s2)
{
	if (s1.GetHistory() < s2.GetHistory())
		return -1;
	if (s1.GetHistory() == s2.GetHistory())
		return 0;
	return 1;
}

short int compareAverage(Student& s1, Student& s2)
{
	if (s1.GetAverage() < s2.GetAverage())
		return -1;
	if (s1.GetAverage() == s2.GetAverage())
		return 0;
	return 1;
}
