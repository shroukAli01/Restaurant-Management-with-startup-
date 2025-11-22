#include "Cook.h"

//  Constructor 
Cook::Cook(int id, ORD_TYPE t, int spd, int bo, int breakDur)
{
    ID = id;
    type = t;
    speed = spd;

    BO = bo;
    BreakDuration = breakDur;

    BreakRemaining = 0;
    OrdersSinceBreak = 0;

    Available = true;

    CurrentOrder = nullptr;
    RemainingTime = 0;
}

//  Destructor 
Cook::~Cook()
{
   
}

// Setters 
void Cook::setID(int id) { ID = id; }
void Cook::setType(ORD_TYPE t) { type = t; }
void Cook::SetSpeed(int s) { speed = s; }
void Cook::SetBO(int bo) { BO = bo; }
void Cook::SetBreakDuration(int bd) { BreakDuration = bd; }

//  Getters
int Cook::GetID() const { return ID; }
ORD_TYPE Cook::GetType() const { return type; }
int Cook::GetSpeed() const { return speed; }
int Cook::GetBO() const { return BO; }
int Cook::GetBreakDuration() const { return BreakDuration; }
int Cook::GetBreakRemaining() const { return BreakRemaining; }

bool Cook::IsAvailable() const { return Available; }
void Cook::SetAvailable(bool a) { Available = a; }

//  Break Handling 
void Cook::StartBreak()
{
    Available = false;
    BreakRemaining = BreakDuration;
}

void Cook::UpdateBreak()
{
    if (BreakRemaining > 0)
    {
        BreakRemaining--;

        if (BreakRemaining == 0)
            ResetBreak();
    }
}

bool Cook::InBreak() const
{
    return BreakRemaining > 0;
}

void Cook::ResetBreak()
{
    BreakRemaining = 0;
    OrdersSinceBreak = 0;
    Available = true;
}

// ---------- Order Handling ----------
void Cook::AssignOrder(Order* o, int prepTime)
{
    CurrentOrder = o;
    RemainingTime = prepTime;
    Available = false;

    OrderAssigned();
}

void Cook::FreeOrder()
{
    CurrentOrder = nullptr;
    RemainingTime = 0;
    Available = true;
}

Order* Cook::GetCurrentOrder() const
{
    return CurrentOrder;
}

bool Cook::IsBusy() const
{
    return CurrentOrder != nullptr;
}

void Cook::OrderAssigned()
{
    OrdersSinceBreak++;

    if (OrdersSinceBreak >= BO)
        StartBreak();
}

void Cook::UpdateCooking()
{
    if (RemainingTime > 0)
    {
        RemainingTime--;

        if (RemainingTime == 0)
            FreeOrder();
    }
}
