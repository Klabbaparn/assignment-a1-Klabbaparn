#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

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
    std::string countIntegers;
    std::ifstream f(argv[1]);
    while (f >> countIntegers)
        ++count; //Count how many integers the file contains
    double *buffer = new double[count]; //Allocate a dynamic memory array
    f.clear();
    f.seekg(0); //Rewind the file

    if (!f.is_open())
    {
        std::cout << "File failed to open!" << std::endl; //fail-checking
        return 0;
    }
    else if (f.is_open())
    {
        std::cout << "File is open" << std::endl; //Prints if file opens
    }
    int j = 0;
    while (f >> get)
    {
        sum += get;      // Get the sum of the integers
        get = (int)(get*1000+.5); //rounding
        get = (get/1000); // convert into 3 decimals
        buffer[j] = get; // Insert integers into array
        j++;
    }
    f.close();                      //Close file 
    for (int k = 0; k < count; k++) //Loop and prints the numbers that are above average
        if (buffer[k] > (sum/count))
            std::cout << buffer[k] << " ";
    delete[] buffer; //Delete buffer to prevent memory leakage
    return 0;
}
