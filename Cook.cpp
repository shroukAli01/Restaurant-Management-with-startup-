#include "Cook.h"


Cook::Cook()
{
}


Cook::~Cook()
{
}


int Cook::GetID() const
{
	return ID;
}


ORD_TYPE Cook::GetType() const
{
	return type;
}


void Cook::setID(int id)
{
	ID = id;
}

void Cook::setType(ORD_TYPE t)
{
	type = t;
}
#pragma once

#include "..\Defs.h"

// Forward declaration (علشان Order لسه هتتعامل في Phase 2)
class Order;

class Cook
{
private:
    int ID;
    ORD_TYPE type;      // (VIP/Normal/Vegan)
    int speed;          // dishes per timestep

    // ---- Additions from your Cook.h ----
    int BO;                 // Break Order count
    int BreakDuration;      // total break duration
    int BreakRemaining;     
    int OrdersSinceBreak;

    bool Available;

    Order* CurrentOrder;    // pointer to assigned order
    int RemainingTime;      // time left to finish the order

public:

    // Constructor
    Cook(int id = 0, ORD_TYPE t = TYPE_NRM, int speed = 0,
         int bo = 0, int breakDur = 0);

    //Destructor
    ~Cook();

    //Setters
    void setID(int id);
    void setType(ORD_TYPE t);
    void SetSpeed(int s);
    void SetBO(int bo);
    void SetBreakDuration(int bd);

    //  Getters 
	int GetID() const;
    ORD_TYPE GetType() const;
    int GetSpeed() const;
    int GetBO() const;
    int GetBreakDuration() const;
    int GetBreakRemaining() const;

    bool IsAvailable() const;
    void SetAvailable(bool a);

    //  Break Handling 
    void StartBreak();
    void UpdateBreak();
    bool InBreak() const;
    void ResetBreak();

    //Order Handling 
    void AssignOrder(Order* o, int prepTime);
    void FreeOrder();
    Order* GetCurrentOrder() const;
    bool IsBusy() const;

    void OrderAssigned();        // for BO counter
    void UpdateCooking();        // decrease remaining time
};



