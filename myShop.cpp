#include "Barista.h"  // Include the Barista class definition
#include "order.h"  // Include the Order class definition
#include "shopQueue.h"  // Include the shopQueue class definition
#include <iostream>  // Include for standard input/output stream operations
#include <vector>  // Include for using the vector container
#include <fstream>  // Include for file stream operations
#include <array>  // Include for using the array container

using namespace std;  // Utilize the standard namespace to avoid prefixing std::

int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments is provided
    if(argc != 5) {
        puts("Error: Wrong number of arguments!");  // Print error message for incorrect arguments
        puts("Usage: ./run_simulation <inputFile> <numBaristas> <outputFile> <totalTime>");  // Display correct usage syntax
    }
    else {
        // Initialize shop queue
        ShopQueue shopQueue;

        // File stream for input
        ifstream f1;
        f1.open(argv[1]);  // Open the input file specified by the first argument

        // File stream for output
        ofstream f2;
        f2.open(argv[3]);  // Open the output file specified by the third argument

        // Convert number of baristas from string to integer
        int numB = atoi(argv[2]);
        // Convert total time from string to integer
        int total_time = atoi(argv[4]);

        // Vector to hold all baristas
        vector<Barista> baristas(numB);
        // Vector to store finished orders
        vector<Order> finishedOrders;

        // Print welcome message to the standard output
        puts("Welcome to Gompei's Coffee Shop!");
        // Print the number of baristas to the standard output
        cout << "------ # of Baristas: " << numB << " ------" << endl;

        f2 << setw(8) << "ID"  // Set width and write column names to the output file
           << setw(8) << "Arrival"
           << setw(8) << "Cook"
           << setw(8) << "Start"
           << setw(8) << "Wait" << "\n";

        int ID = 0;  // Declare ID variable
        int arrival = 0;  // Declare arrival time variable
        int cook_time = 0;  // Declare cook time variable

        while(f1 >> ID >> arrival >> cook_time) {  // Read ID, arrival, and cook times from input file
            shopQueue.addNewOrder(ID, arrival, cook_time, -1, -1);  // Add new order to the shop queue
        }

        for(int i = 0; i < numB; i++) {   // Loop through all baristas
            baristas.at(i).setID(i);     // Set ID for each barista
            baristas.at(i).setBusy(0);
            baristas.at(i).setStart(0);
            baristas.at(i).setDuration(0);
            baristas.at(i).setFreeTime(0);
        }

        for (int currentTime = 0; currentTime < total_time; currentTime++) {
            // Check if any barista has finished their task
            for (auto& barista : baristas) {
                if (barista.getBusy() && currentTime >= barista.getStart() + barista.getDuration()) {
                    barista.setBusy(false); // Task completed, barista is now free
                }
            }

            // Assign tasks to available baristas if orders are in the queue
            for (auto& barista : baristas) {
                if (!barista.getBusy() && !shopQueue.isEmpty()) {
                    Order currentOrder = *shopQueue.peekFrontOrder();
                    if (currentTime >= currentOrder.getArrival()) {
                        // Assign task to barista
                        currentOrder.setStart(currentTime);
                        currentOrder.setWait(currentTime - currentOrder.getArrival());
                        barista.setStart(currentTime);
                        barista.setDuration(currentOrder.getCook());
                        barista.setBusy(true);  // Barista is now busy

                        // Write the current order details to the output file during the simulation
                        f2 << std::setw(8) << currentOrder.getID()
                                << setw(8) << currentOrder.getArrival()
                                << setw(8) << currentOrder.getCook()
                                << setw(8) << currentOrder.getStart()
                                << setw(8) << currentOrder.getWait() << "\n";

                        finishedOrders.push_back(currentOrder);
                        shopQueue.removeFrontOrder();
                    }
                } 
                if (!barista.getBusy()) {
                    // Increase free time if barista is idle
                    barista.increaseFree();
                }
            }
        }

        int customersServed = finishedOrders.size();  // Count the number of customers served based on finished orders
        int numCustomersWaiting = shopQueue.getLength();  // Count the number of customers still waiting in the queue

        float totalWaitTime = 0;  // Initialize total wait time
        for (auto& order : finishedOrders) {  // Iterate through each order in finished orders
            totalWaitTime += order.getWait();  // Accumulate wait times
        }

        float averageWaitTime = (customersServed > 0) ? totalWaitTime / (float)customersServed : 0;  // Calculate average wait time if there are any served customers

        // Output the number of waiting and served customers
        cout << numCustomersWaiting << " customers are waiting for their order.\n";  
        cout << customersServed << " customers have been served.\n";
        cout << "The average wait time was " << fixed << setprecision(2) << averageWaitTime << " minutes.\n";  // Output average wait time, formatted to two decimal places

        for(int i = 0; i < numB; i++) {  // Loop through each barista
            float baristaIdle = (baristas.at(i).getFreeTime() / (float)total_time) * 100;  // Calculate and store the percentage of time each barista was idle
            // Output each barista's ID and their idle percentage
            cout << "Barista " << baristas.at(i).getID() << " was idle " << fixed << setprecision(2) << baristaIdle << "% of the time.\n";
        }

    }
}