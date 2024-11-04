#ifndef BARISTA_H
#define BARISTA_H

#include <iostream>

using namespace std;


/******************************************
* Barista Class
* Creates a Barista that keeps track of the
* current order information
******************************************/
class Barista {
	public:
	    /************************************************
		* Barista()
		* Default Constructor
		* Sets ID, task_start and task_duration to -1
		* Sets is_busy and free_time to 0
		************************************************/
		Barista();

		/************************************************
		* Barista(int, int, int, int, int)
		* Constructor
		* Sets member variables int the following order:
		* ID, is_busy, task_start, task_duration, free_time
		************************************************/
		Barista(int, int, int, int, int);
		
		// Sets ID
		void setID(int);

		// Sets is_busy
		void setBusy(int);

		// Sets task_start
		void setStart(int);

		// sets task_duration
		void setDuration(int);

		// sets free_time
		void setFreeTime(int);

		// increases free_time by 1
		void increaseFree();

		// prints the Barista member variables to the terminal
		void printBarista();

		// returns is_busy
		int getBusy();

		// returns task_start
		int getStart();

		// returns task_duration
		int getDuration();

		// returns free_time
		int getFreeTime();

		// returns ID
		int getID();
		
		// prints the Barista member variables to the ostream parameter
		friend ostream& operator<<(ostream&, Barista);
	
	private:
		int ID;					
		int is_busy;			// 1 for busy
		int task_start;			// time when this task was started
		int task_duration;		// how long the task takes to complete
		int free_time;			// total idle time of the Barista
};

#endif // BARISTA_H