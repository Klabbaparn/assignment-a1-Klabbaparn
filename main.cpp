#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "Functions.cpp"

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Wrong amount of arguments"; //fail-checking
        return 0;
    }

    double get = 0;
    double sum = 0;
    int count = 0;
    std::string stringOfNumbers;
    std::ifstream f(argv[1]);
    if (!f.is_open())
    {
        std::cout << "File failed to open!" << std::endl; //fail-checking
        exit(EXIT_FAILURE);
    }
    while (f >> stringOfNumbers)
    {
        if (countOfChar(stringOfNumbers, '.') > 1 || //Check if string doesn't contain more than 1 dot.
            countOfChar(stringOfNumbers, '-') > 1 || //Check if string doesn't contain more than one subtraction
            countOfChar(stringOfNumbers, '+') > 1 || //Checks if string doesn't contain more than one addition
            !hasValidChars(stringOfNumbers))         //Checks that the strings only contains numbers
        {
            std::cout << "File is corrupt" << std::endl;
            return EXIT_FAILURE;
        }
        count++;
    }
    double *arrayOfNumbers = new double[count]; //Allocate a dynamic memory array
    f.clear();
    f.seekg(0); //Rewind the file

    int j = 0;
    while (f >> get)
    {
        sum += get;                   // Get the sum of the integers
        get = (int)(get * 1000 + .5); // Rounding
        get = (get / 1000);           // convert into 3 decimals
        arrayOfNumbers[j] = get;      // Insert numbers into array
        j++;
    }
    f.close();                      //Close file
    for (int k = 0; k < count; k++) //Loop and prints the numbers that are above average
        if (arrayOfNumbers[k] > (sum / count))
            std::cout << arrayOfNumbers[k] << " ";
    delete[] arrayOfNumbers; //Delete buffer to prevent memory leakage
    return 0;
}
