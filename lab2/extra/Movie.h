#pragma once
class MovieSeries;
class Movie
{
private:
	char name[260];
	int year, length;
	double score;
	friend class MovieSeries;
public:
	bool set_name(const char name[]);
	const char* get_name();
	bool set_score(double score);
	double get_score();
	bool set_year(int year);
	int get_year();
	bool set_length(int length);
	int get_length();
	int get_passed_years();
};