#include "shopQueue.h"
#include <iostream>
using namespace std;


ShopQueue::ShopQueue() {
  front = nullptr;
  back = nullptr;
  length = 0;
}

void ShopQueue::addNewOrder(int ID, int arrival, int cook_time, int start_time, int wait_time) {
 
  // Create new Order node
  shared_ptr<Order> newCust = make_shared<Order>(Order{ID, arrival, cook_time, start_time, wait_time});
  
  shared_ptr<Node> newNode = make_shared<Node>(Node{newCust,  nullptr});

  // Case 1: Queue is empty
  if (isEmpty()) {
    front = newNode;
    back = newNode;
  }
  // Case 2: Queue is not empty
  else {
    back->next = newNode;
    back = newNode;
  }

  length++;
}

int ShopQueue::getLength() {
  return length;
}
bool ShopQueue::isEmpty() {
  return length == 0;
}

shared_ptr<Order> ShopQueue::peekFrontOrder() {
  return front->data;
}

shared_ptr<Order> ShopQueue::removeFrontOrder() {
  // Case 1: Queue is empty
  if (length == 0){
    return nullptr;
  }
  else{
    shared_ptr<Order> data = front->data;

    // Case 2a: Last element in queue
    if (length == 1) {
      front = nullptr;
      back = nullptr;
    }
    // Case 2b: More than 1 element
    else {
      front = front->next;
    }

    length--;

    return data;
  }
 
}

int ShopQueue::numItems(){
  return length;
}