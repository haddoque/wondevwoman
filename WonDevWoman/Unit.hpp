#pragma once

#include "Vector2.hpp"

class Unit
{
public:
    const Vector2& GetPosition() const { return position; }
    
    void LoadFromInput();
    
private:
    Vector2 position;
};
