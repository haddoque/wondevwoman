#pragma once

#include <vector>
#include <string>

class Unit;

using namespace std;

class Action
{
public:
    int GetScore(const Unit& unit, const vector<string>& playArea) const;
    int GetIndex() const { return index; }
    
    void LoadFromInput();
    void Execute() const;
    
private:
    string atype;
    int index;
    string dir1;
    string dir2;
};
