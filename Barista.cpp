#include "Barista.h"  // Include the header file for Barista class

using namespace std;

// Default constructor: Initializes the Barista with default values
Barista::Barista() {
    ID = -1;  // Unique identifier for the Barista (default to -1, indicating unset)
    is_busy = -1;  // Indicates if the Barista is busy (-1 for unset)
    task_start = -1;  // When the Barista started the current task
    task_duration = -1;  // Duration of the current task
    free_time = -1;  // Time when the Barista will become free
}

// Parameterized constructor: Initializes the Barista with custom values
Barista::Barista(int a, int b, int c, int d, int e) {
    ID = a;  // Sets the Barista's ID
    is_busy = b;  // Whether the Barista is busy
    task_start = c;  // When the Barista started the task
    task_duration = d;  // Duration of the current task
    free_time = e;  // When the Barista will be free
}

// Setters for Barista attributes
void Barista::setID(int a) {
    ID = a;  // Set the Barista ID
}

void Barista::setBusy(int a) {
    is_busy = a;  // Set whether the Barista is busy
}

void Barista::setStart(int a) {
    task_start = a;  // Set the task start time
}

void Barista::setDuration(int a) {
    task_duration = a;  // Set the task duration
}

void Barista::setFreeTime(int a) {
    free_time = a;  // Set the Barista's free time
}

// Increases the Barista's free time by 1 unit (could be a minute/hour)
void Barista::increaseFree() {
    free_time += 1;
}

// Print the Barista details for debugging or logging
void Barista::printBarista() {
    cout << "Barista ID: " << ID << "\n"
         << "Is Busy: " << (is_busy ? "Yes" : "No") << "\n"
         << "Task Start: " << task_start << "\n"
         << "Task Duration: " << task_duration << "\n"
         << "Free Time: " << free_time << "\n";
}

// Getters for Barista attributes
int Barista::getID() {
    return ID;  // Return the Barista's ID
}

int Barista::getBusy() {
    return is_busy;  // Return whether the Barista is busy
}

int Barista::getStart() {
    return task_start;  // Return the task start time
}

int Barista::getDuration() {
    return task_duration;  // Return the task duration
}

int Barista::getFreeTime() {
    return free_time;  // Return the Barista's free time
}

// Overloaded << operator for easy printing of Barista objects
ostream& operator<<(ostream& os, Barista& barista) {
    os << "Barista ID: " << barista.getID() << "\n"
       << "Is Busy: " << (barista.getBusy() ? "Yes" : "No") << "\n"
       << "Task Start: " << barista.getStart() << "\n"
       << "Task Duration: " << barista.getDuration() << "\n"
       << "Free Time: " << barista.getFreeTime() << "\n";
    return os;
}

