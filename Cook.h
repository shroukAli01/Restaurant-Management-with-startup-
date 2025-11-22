#pragma once

#include "..\Defs.h"

class Order;

class Cook
{
private:
    int ID;
    ORD_TYPE type;      // (V/N/V)
    int speed;          

  
    int BO;                 // Break Order count
    int BreakDuration;      
    int BreakRemaining;     
    int OrdersSinceBreak;

    bool Available;

    Order* CurrentOrder;    
    int RemainingTime;      

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

    // Getters 
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

    //  Order Handling 
    void AssignOrder(Order* o, int prepTime);
    void FreeOrder();
    Order* GetCurrentOrder() const;
    bool IsBusy() const;

    void OrderAssigned();        // for BO counter
    void UpdateCooking();        
};

