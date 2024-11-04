#include "order.h"

Order::Order(){
	ID = -1;
	arrival = -1;
	cook_time = -1;
	start_time = -1;
	wait_time = -1;
}
Order::Order(int a, int b, int c, int d, int e){
	ID = a;
	arrival = b;
	cook_time = c;
	start_time = d;
	wait_time = e;
}

void Order::setStart(int num){
	start_time = num;
}

void Order::setWait(int num){
	wait_time = num;
}
void Order::setCook(int num){
	cook_time = num;
}

void Order::setArrival(int num){
	arrival = num;
}

void Order::setID(int num){
	ID = num;
}

int Order::getCook(){
	return cook_time;
}

int Order::getArrival(){
	return arrival;
}

int Order::getID(){
	return ID;
}

int Order::getWait(){
	return wait_time;
}

int Order::getStart(){
	return start_time;
}

void Order::printOrder(){
	cout << ID << " " << arrival << " ";
	cout << cook_time << " " << start_time;
	cout << " " << wait_time << endl;
}

ostream& operator<<(ostream& out, Order thisOrder){
	int w = 8;
	out << setw(w)<< thisOrder.getID() << setw(w)<< thisOrder.getArrival() << setw(w);
	out << thisOrder.getCook() << setw(w) << thisOrder.getStart();
	out << setw(w) << thisOrder.getWait();
	return out;
}