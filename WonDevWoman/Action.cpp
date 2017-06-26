#include "Action.hpp"

#include "Unit.hpp"

#include <iostream>
#include <algorithm>

static const string directions[] =
{
    "N",
    "NE",
    "E",
    "SE",
    "S",
    "SW",
    "W",
    "NW"
};

static void GetDirections(const string& direction, int &outX, int &outY)
{
    static const int xDir[] =
    {
        0,
        1,
        1,
        1,
        0,
        -1,
        -1,
        -1
    };
    
    static const int yDir[] =
    {
        -1,
        -1,
        0,
        1,
        1,
        1,
        0,
        -1
    };
    
    /*int index = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (directions[i] == direction)
        {
            index = i;
            break;
        }
    }*/
    
    const size_t index = distance(begin(directions), find(begin(directions), end(directions), direction));
    outX = xDir[index];
    outY = yDir[index];
}

int Action::GetScore(const Unit& unit, const vector<string>& playArea) const
{
    const char current = playArea[unit.GetPosition().y][unit.GetPosition().x];
    
    int dirX;
    int dirY;
    
    GetDirections(dir1, dirX, dirY);
    
    const int nextY = unit.GetPosition().y + dirY;
    const int nextX = unit.GetPosition().x + dirX;
    const char move = playArea[nextY][nextX];
    
    GetDirections(dir2, dirX, dirY);
    
    const char build = playArea[nextY + dirY][nextX + dirX];
    
    int score = move == 1 + current ? 10 : 0;
    score += build == move ? 10 : 0;
    
    score += move == '3' ? 100 : 0;
    score += build == '3' ? -100 : 0;
    
    for (int i = 0; i < 8; ++i)
    {
        const string& dir = directions[i];
        int tempX;
        int tempY;
        
        GetDirections(dir, tempX, tempY);
        
        tempX = nextX + tempX;
        tempY = nextY + tempY;
        
        if (tempX < 0 || tempY < 0)
            continue;
        
        if (tempX >= playArea[0].length() || tempY >= playArea.size())
            continue;
        
        // const char val = playArea[tempY][tempX];
        
        //if (val == '.' || val == '4')
        //    continue;
        
        ++score;
    }
    
    cerr << "dir1: " << dir1 << " dir2: " << dir2 << ": " << score << " m: " << move << " b: " << build << endl;
    
    return score;
}

void Action::LoadFromInput()
{
    cin >> atype >> index >> dir1 >> dir2; cin.ignore();
}

void Action::Execute() const
{
    cout << atype << " " << index << " " << dir1 << " " << dir2 << endl;
}
