#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::ostream;
using std::setw;


/******************************************
* Order Class
* Creates a Order that keeps track of
* the coffee shop order
******************************************/
class Order {
	public:

		/************************************************
		* Order()
		* Default Constructor
		* Sets all member variables to -1
		************************************************/
		Order();

		/************************************************
		* Order(int, int, int, int, int)
		* Constructor
		* Sets member variables int the following order:
		* ID, arrival, cook_time, start_time, wait_time
		************************************************/
		Order(int, int, int, int, int);

		// sets start_time
		void setStart(int);

		// sets wait_time
		void setWait(int);

		// sets cook_time
		void setCook(int);

		// sets arrival
		void setArrival(int);

		// set ID
		void setID(int);

		// returns cook_time
		int getCook();

		// returns arrival
		int getArrival();

		// returns ID
		int getID();

		// returns wait_time
		int getWait();

		// returns start_time
		int getStart();

		// prints the order information to the terminal
		void printOrder();

		// prints the order information to the ostream parameter
		friend ostream& operator<<(ostream&, Order);
	
	private:
		int ID;
		int arrival;		// when the customer placed the order
		int cook_time;		// how long it takes to make the order
		int start_time;		// what time the barista started making the order
		int wait_time;		// start_time - arrival
};

#endif // ORDER_H