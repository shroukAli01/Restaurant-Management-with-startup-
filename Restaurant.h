#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "LinkedList.h"
#include "..\Events\Event.h"

#include "Order.h"
#include "Cook.h"
// it is the maestro of the project
class Restaurant
{
private:
    GUI* pGUI;
    Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file


    /// ==> 
    //	DEMO-related members. Should be removed in phases 1&2
    Queue<Order*> DEMO_Queue;	//Important: This is just for demo
    /// ==>

    // waiting list 
    LinkedList<Order*> WaitingNormal;
    LinkedList<Order*> WaitingVegan;
    PriorityQueue<Order*> WaitingVIP;

    LinkedList<Order*> InService;
    LinkedList<Order*> Finished;

public:
    Restaurant();
    ~Restaurant();


    void RunSimulation();
    void SimpleSimulator();
    void ExecuteEvents(int CurrentTimeStep);

    // File loading
    void LoadFile();

    // move between lists
    void MoveOneOrderToInService();
    void MoveOneOrderToFinished();

    // Fill GUI list
    void FillDrawingList();



    void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2
    void AddtoDemoQueue(Order* po);	//adds an order to the demo queue

    /// ================================================================================================== 



};

#endif












