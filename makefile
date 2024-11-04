# This makefile is used as follows to regenerate files for the Barista program:
#   make Barista.o       -- Regenerates Barista.o by compiling
#   make order.o         -- Regenerates order.o by compiling
#   make shopQueue.o     -- Regenerates shopQueue.o by compiling
#   make myShop.o        -- Regenerates myshop.o by compiling
#   make run_simulation          -- Regenerates the executable run_simulation file by compiling
#   make                 -- Same as "make run_simulation"
#

run_simulation: Barista.o order.o shopQueue.o myShop.o
	g++ -g -Wall Barista.o order.o shopQueue.o myShop.o -lm -o run_simulation

Barista.o: Barista.h Barista.cpp
	g++ -g -Wall -c Barista.cpp

order.o: order.h order.cpp
	g++ -g -Wall -c order.cpp

shopQueue.o: shopQueue.h order.h shopQueue.cpp
	g++ -g -Wall -c shopQueue.cpp

myShop.o: myShop.cpp
	g++ -g -Wall -c myShop.cpp

clean:
	rm -f Barista.o order.o shopQueue.o myShop.o run_simulation

all: run_simulation