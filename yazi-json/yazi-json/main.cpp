#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "json.h"
#include "parser.h"

using namespace yazi::json;

#include <sys/time.h>

int main()
{
    try
    {
        ifstream fin("./test.json");
        stringstream ss;
        ss << fin.rdbuf();
        const string& data = ss.str();

        struct timeval tv;
        gettimeofday(&tv, NULL);
        int start_sec = tv.tv_sec;
        int start_usec = tv.tv_usec;
        const int max = 1;
        for (int i = 0; i < max; i++)
        {
            Json json;
            json.parse(data);
            std::cout << json.str() << std::endl;
            json.clear();
        }
        gettimeofday(&tv, NULL);
        int end_sec = tv.tv_sec;
        int end_usec = tv.tv_usec;
        double time_diff = (end_sec - start_sec) * 1000000 + (end_usec - start_usec);
        std::cout << time_diff / 1000 / max << "ms" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "catch exception: " << e.what() << std::endl;
    }
} 