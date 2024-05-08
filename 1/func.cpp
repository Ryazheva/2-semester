﻿#include "func.hpp"
#include <ctime>
#include <fstream>
#include <string>

namespace Date
{
    void Number(const std::string& fileName)
    {
        std::ifstream inFile(fileName); 
        int k = 0;
        if (inFile.is_open())
        {
            inFile >> k; 
        }
        inFile.close();
        k++;

        std::ofstream outFile(fileName); 
        if (outFile.is_open()) 
        {
            outFile << k << " ";
            outFile.close();
        }
    }

    void Time(const std::string& fileName)
    {
        time_t now = time(0);
        tm* timeinfo = localtime(&now);
        std::ofstream outFile(fileName, std::ios_base::app);
        if (outFile.is_open())
        {
            outFile << 1900 + timeinfo->tm_year << "."
                << 1 + timeinfo->tm_mon << "."
                << timeinfo->tm_mday << " "
                << timeinfo->tm_hour << ":"
                << timeinfo->tm_min << ":"
                << timeinfo->tm_sec << std::endl;
            outFile.close();
        }
    }
}