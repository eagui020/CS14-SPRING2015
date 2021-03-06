///
//  Eric Aguirre
//  861174273
//  5/25/15
//  Start by reading in the file and creating the word vector. Next, implement
//  one case of time checking for each lookup/insert. From there, loop the
//  process 10 times and find the avg for each. Lastly, place all of this into
//  a loop incrementing n until it is 50,000. Push results to a new file.
///
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <unordered_set>
#include <set>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <ios>

using namespace std;

int main() {
    using namespace chrono; // Chrono std
    
    srand(time(NULL)); // Seed random
    vector<string> wordsList;
    string word;
    unordered_set<string> unordSet;
    set<string> ordSet;
    ifstream readFile;
    ofstream writeFile;
    // check if file exists
    readFile.open("words.txt");
    if (readFile.is_open())
    {
        cout << "File opened." << endl;
        while (!readFile.eof())
        {
            // Push words into vector
            readFile >> word;
            wordsList.push_back(word);
        }
        readFile.close();
    }
    else
    {
        cout << "Error opening file" << endl;
        return 0;
    }
    writeFile.open("data.txt");
    if (writeFile.is_open())
    {
        for(int n = 5000; n <= 50000; n += 5000)
        {
            // Arrange at random
            for (int i = 0; i < n; ++i)
            {
                int randomPos = rand() % 50000;
                swap(wordsList[i], wordsList[randomPos]);
            }
            
            // Tree time
            milliseconds TreeInsertTotalTime(0); //total time taking for all 10
            milliseconds TreeQueryTotalTime(0);
            for (int i = 0; i < 10; ++i)
            {
                //time check to insert
                auto start = high_resolution_clock::now();
                for (int i = 0; i < n; ++i)
                {
                    ordSet.insert(wordsList[i]);
                }
                auto end = high_resolution_clock::now();
                TreeInsertTotalTime += duration_cast<milliseconds>(end-start);
                //time check to lookup
                auto start2 = high_resolution_clock::now();
                for (int i = 0; i < n; ++i)
                {
                    ordSet.find(wordsList[i]);
                }
                auto end2 = high_resolution_clock::now();
                //cast to milliseconds and add to total
                TreeQueryTotalTime += duration_cast<milliseconds>(end2-start2);
                ordSet.clear(); //clear set before relooping
            }
    
            auto TreeInsertAvgTime = (TreeInsertTotalTime / 10.0); //avg for 10
            auto TreeQueryAvgTime = ((TreeQueryTotalTime / 10.0) / n);
            // cout << TreeInsertAvgTime.count() << endl;
            // cout << TreeQueryAvgTime.count() << endl;
            
            // Hash time
            milliseconds HashInsertTotalTime(0);
            milliseconds HashQueryTotalTime(0);
            for (int i = 0; i < 10; ++i)
            {
                //all same process
                auto start = high_resolution_clock::now();
                for (int i = 0; i < n; ++i)
                {
                    unordSet.insert(wordsList[i]);
                }
                auto end = high_resolution_clock::now();
                HashInsertTotalTime += duration_cast<milliseconds>(end-start);
                
                auto start2 = high_resolution_clock::now();
                for (int i = 0; i < n; ++i)
                {
                    unordSet.find(wordsList[i]);
                }
                auto end2 = high_resolution_clock::now();
                HashQueryTotalTime += duration_cast<milliseconds>(end2-start2);
                unordSet.clear();
            }
            
            auto HashInsertAvgTime = (HashInsertTotalTime / 10.0); //avg for 10
            auto HashQueryAvgTime = ((HashQueryTotalTime/ 10.0) / n);
            // cout << HashInsertAvgTime.count() << endl;
            // cout << HashQueryAvgTime.count() << endl;
            
            // Push results to file
            writeFile.precision(6);
            writeFile << n << " ";
            writeFile << fixed << TreeInsertAvgTime.count() << " ";
            writeFile << HashInsertAvgTime.count() << " ";
            writeFile << TreeQueryAvgTime.count() << " ";
            writeFile << HashQueryAvgTime.count() << " ";
            writeFile << endl;
        }
        writeFile.close();
    }
    else
    {
        cout << "Error opening file" << endl;
        return 0;
    }
    
    return 0;
}