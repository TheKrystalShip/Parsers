#include "TKS/Parsers/csv.h"

#include <iostream>
#include <filesystem>
#include <vector>
#include <thread>

int main(int argc, char *argv[])
{
    typedef TKS::Parsers::CSV::Row csv_row_t;

    std::string fileName("example.csv");

    if (!std::filesystem::exists(fileName))
    {
        std::cout << "ERROR: file " << fileName << " not found, exiting" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream file(fileName);

    for (csv_row_t row : TKS::Parsers::CSV::Range(file))
    {
        std::cout << row << "\n";
    }
}
