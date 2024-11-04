myShop.cpp
Aziel Habtemichael
10/12/24

This program simulates a coffee shop operation using several classes and files to manage orders and barista interactions. The simulation uses input from a file to process orders through a system of queues and baristas, each with their own attributes and methods for handling coffee preparation and customer service.

The project consists of multiple files:
- `Barista.cpp` and `Barista.h`: Define the Barista class and its methods.
- `order.cpp` and `order.h`: Define the Order class with details on customer orders.
- `shopQueue.h`: Handles the queue system of the coffee shop.
- `myShop.cpp`: The main program that runs the simulation.
- `makefile`: Used to compile and link the project files efficiently.

To compile the program, run the following command:
g++ -Wall myShop.cpp Barista.cpp order.cpp shopQueue.cpp -o run_simulation

Alternatively, to compile the program, you can use the provided makefile with the following command:
make

To run the program, use the following command:
./run_simulation inputFile.txt numBaristas outputFile.txt totalTime

Input examples can be formatted as follows:
./run_simulation orders.txt 3 results.txt 480

Sources: I worked alone on this assignment.