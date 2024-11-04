#ifndef SHOPQUEUE_H
#define SHOPQUEUE_H

#include <memory>
#include "order.h"

using namespace std;


/******************************************
* Node struct
* contains a pointer to a customer order
* and a pointer to the next Node
******************************************/
struct Node {
  shared_ptr<Order> data;
  shared_ptr<Node> next;
};


/******************************************
* ShopQueue class
* Creates a FIFO queue of Nodes
******************************************/
class ShopQueue {
  public:

  	/************************************************
	* ShopQueue()
	* Default Constructor
	* Sets front and back to nullptr
	* Sets length to 0
	************************************************/
    ShopQueue();

	/************************************************
	* addNewOrder(int, int, int, int, int)
	* Allocates a new Order on the heap and initalizes
	* with the parameters. Allocates a new Node on the heap
	* Adds the Node to the end of the queue
	************************************************/
    void addNewOrder(int, int, int, int, int);

	// Returns the length of the queue
    int getLength();

	// returns true if the queue is empty
    bool isEmpty();

	// Returns a pointer to the Order at the front of the queue
    shared_ptr<Order> peekFrontOrder();

	// Removes the front Node and returns a pointer
	// to the Order that was removed
    shared_ptr<Order> removeFrontOrder();

	// Returns the lenght of the queue
    int numItems();
	
  private:
    shared_ptr<Node> front;
    shared_ptr<Node> back;
    int length;
};

#endif // SHOPQUEUE_H