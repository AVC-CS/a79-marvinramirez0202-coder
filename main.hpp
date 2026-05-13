#ifndef MAIN_HPP
#define MAIN_HPP

// Vector intro: makeVector, insertVector, deleteVector

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void makeVector(vector<int> &);
void insertVector(vector<int> &, int);
int deleteVector(vector<int> &, int);
int randnum(void);
int getInput(void);
void printVector(vector<int>);

void makeVector(vector<int> &number)
{
    // TODO: fill the vector with random integers in [0, 20), then sort it.
    for(int i = 0; i < number.size(); i++){
        number[i] = rand() % 20;
    }
    sort(number.begin(), number.end());
}

void insertVector(vector<int> &number, int usernum)
{
    // TODO: insert usernum into the sorted vector while keeping it sorted.
    
    for(auto it = number.begin(); it != number.end(); it++){
        if(*it > usernum){
            number.insert(it, usernum);
            return;
        }
    }
    number.insert(number.end(), usernum);

}

int deleteVector(vector<int> &number, int usernum)
{
    // TODO: erase EVERY occurrence of usernum from the vector.
    vector<int>::iterator it;
    int count = 0;
    it = find(number.begin(), number.end(), usernum);
    while(it != number.end()){
        number.erase(it);
        count++;
        it = find(number.begin(), number.end(), usernum);
    }
    if(count == 0)
        return -1;
    return count;
}

int getInput(void)
{
    int num;
    cout << "Enter your input\n";
    cin >> num;
    return num;
}

int randnum(void)
{
    return rand() % 100;
}

void printVector(vector<int> number)
{
    for (auto iter = number.begin(); iter != number.end(); iter++)
        cout << setw(5) << *iter;
    cout << endl;
}

#endif
