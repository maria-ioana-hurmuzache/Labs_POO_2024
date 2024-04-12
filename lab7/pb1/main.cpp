#include <iostream>

//implementare cu unsigned long long int
/*float operator"" _Kelvin(unsigned long long int x)
{
    return float(x) - 273.15f;
}

float operator"" _Fahrenheit(unsigned long long int x)
{
    return (float(x) - 32) / 1.8f;
}*/

//implementare cu const char*
float operator"" _Kelvin(const char* x)
{
    float y=1, value=0, p10=0.1f;
    if ((*x) == '-')
    {
        y = -1;
        x++;
    }
    while ((*x) != '.' && (*x)!=0)
    {
        value = value * 10 + (*x) - '0';
        x++;
    }
    if ((*x) == '.')
    {
        x++;
        while ((*x) != 0)
        {
            value = value + p10 * ((*x) - '0');
            x++;
            p10 *= 0.1f;
        }
    }
    return (value * y) - 273.15f;
}

float operator"" _Fahrenheit(const char* x)
{
    float y = 1, value = 0, p10=0.1f;
    if ((*x) == '-')
    {
        y = -1;
        x++;
    }
    while ((*x) != '.' && (*x) != 0)
    {
        value = value * 10 + (*x) - '0';
        x++;
    }
    if ((*x) == '.')
    {
        x++;
        while ((*x) != 0)
        {
            value = value + p10 * ((*x) - '0');
            x++;
            p10 *= 0.1f;
        }
    }
    return ((value * y) - 32)/1.8f;
}

int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    std::cout << a << ' ' << b << '\n';
    return 0;
}
