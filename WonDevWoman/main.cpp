#include <iostream>
#include <vector>

#include "Action.hpp"
#include "Unit.hpp"

int main()
{
    int size;
    cin >> size; cin.ignore();
    int unitsPerPlayer;
    cin >> unitsPerPlayer; cin.ignore();
    
    // game loop
    while (1)
    {
        vector<Action> legalActions;
        vector<Unit> ownUnits;
        vector<string> rows;
        
        for (int i = 0; i < size; i++) {
            string row;
            cin >> row; cin.ignore();
            rows.push_back(row);
        }
        for (int i = 0; i < unitsPerPlayer; i++)
        {
            Unit unit;
            unit.LoadFromInput();
            ownUnits.push_back(unit);
        }
        for (int i = 0; i < unitsPerPlayer; i++) {
            int otherX;
            int otherY;
            cin >> otherX >> otherY; cin.ignore();
        }
        int legalActionsC;
        cin >> legalActionsC; cin.ignore();
        for (int i = 0; i < legalActionsC; i++)
        {
            Action action;
            action.LoadFromInput();
            legalActions.push_back(action);
        }
        
        Action* takenAction = nullptr;
        int bestScore = -1;
        //for (Unit& unit : ownUnits)
        //{
            for (Action& act : legalActions)
            {
                Unit& unit = ownUnits[act.GetIndex()];
                int score = act.GetScore(unit, rows);
                if (score > bestScore)
                {
                    bestScore = score;
                    takenAction = &act;
                }
            }
       // }
        
        takenAction->Execute();
    }
}
