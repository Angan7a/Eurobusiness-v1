#pragma once
#include "Player.hpp"

class StatePlayer
{
public:
    virtual ~StatePlayer() = default;
    virtual int action(int) = 0;
    virtual void increaseNumberOfRounds() = 0;
    virtual bool canPlayerLeavePrison() = 0;
};

class Free : public StatePlayer
{
public:
    int action(int number) { return number; }
    void increaseNumberOfRounds() {}
    bool canPlayerLeavePrison() { return false; }
};

class InPrison : public StatePlayer
{
    int roundInPrison = 0;
public:
    int action(int)
    { 
        return 0;
    }
    void increaseNumberOfRounds() 
    { 
        roundInPrison++;
    }
    bool canPlayerLeavePrison()
    {
        if (roundInPrison > 1) 
            return true;
        return false;
    }
};
