//Jordan Love - 2905840

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

class myGraph
{
    private:
    // std::vector<std::vector<std::string>> e;
    // std::vector<std::vector<std::string>> v;  

    public:
    myGraph()
    {
        //do work in assembleFragments
    }

    //helper function
    int overlapStrings(std::string str1, std::string str2, std::string &result)
    {
        int max = INT_MIN;
        int len1 = str1.length();
        int len2 = str2.length();
    
        //check suffix of first string with prefix of second string
        for (int i = 1; i <= std::min(len1, len2); i++)
        {
            // last i chars of first string against first i chars of second string
            if (str1.compare(len1 - i, i, str2, 0, i) == 0)
            {
                if (max < i)
                {
                    max = i;
                    result = str1 + str2.substr(i);
                }
            }
        }
        //check prefix of first string with suffix of second string
        for (int i = 1; i <= std::min(len1, len2); i++)
        {
            // first i chars of first string against last i chars of second string
            if (str1.compare(0, i, str2, len2 - i, i) == 0)
            {
                if (max < i)
                {
                    max = i;
                    result = str2 + str1.substr(i);
                }
            }
        }
        return max;
    }

    void assembleFragments(std::vector<std::string> & fragments, std::string &assembly) //assembly is result string
    {
        int size = fragments.size();
        while (size > 1)
        {
            //initialize indices
            int max = -1;
            int x = -1;
            int y = -1;

            for(int i = 0; i < size; i++)
            {
                for(int j = i + 1; j < size; j++)
                {
                    std::string str;
                    int r = overlapStrings(fragments[i], fragments[j], str);
                    if (max < r)
                    {
                        max = r;
                        x = i;
                        y = j;
                        assembly.assign(str);
                    }
                }
            }
            size--;

            //append strings into the first index of fragments if no overlap
            if (max == INT_MIN)
            {
                fragments[0] += fragments[size];
            }
            else
            {
                fragments[x] = assembly;
                fragments[y] = fragments[size];
            }
        }
    }

    ~myGraph()
    {

    }
};