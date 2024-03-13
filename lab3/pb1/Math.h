#pragma once
class Math
{
public:
    static int Add(int, int);
    static int Add(int, int, int);
    static int Add(double, double); //asa e data in enunt, cu int
    static int Add(double, double, double); //asa e data in enunt, cu int
    static int Mul(int, int);
    static int Mul(int, int, int);
    static int Mul(double, double); //asa e data in enunt, cu int
    static int Mul(double, double, double); //asa e data in enunt, cu int
    static int Add(int count, ...); // sums up a list of integers
    static char* Add(const char*, const char*);
};