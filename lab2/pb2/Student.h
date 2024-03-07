#pragma once
class Student
{
private:
	char Name[40];
	float Mathematics, English, History;
public:
	bool SetName(const char nume[]);
	char* GetName();
	bool SetMathematics(float value);
	float GetMathematics();
	bool SetEnglish(float value);
	float GetEnglish();
	bool SetHistory(float value);
	float GetHistory();
	float GetAverage();
};