# Stacks-and-Queues
Create, add, and delete, and work with a stack or queue using a linked-list or array. C++ homework for CSCI-2270

CSCI-2270
Assignment 2
Instructor: Boese
Linked List
Communication Between Towers Part 1
Objectives
• Create, traverse, add, and delete to/from a linked-list
Background
Communication between towers
In the Lord of the Rings trilogy, there is a scene where the first beacon is lit in the
towers of Minas Tirith. The second beacon then sees the fire, and knows to light its
fire to send a signal to the third beacon, and so forth. This was a means of
communicating in the days before telegraphs were invented as it was much faster
than sending a human rider to deliver a message. Communication towers were
equipped with signaling mechanisms, such as mirrors, that could spell out messages
using the positions of the mirrors.
Today, there are several examples of communication networks that are conceptually
similar, but much more technically advanced, that route messages through multiple
hubs between the sender and the receiver. For example, when you type a URL into a
web browser, a request is sent through a network of service providers to the
destination, and then packets of information are sent back to your machine. If I type
www.google.com from my home in Boulder, my request follows this path:
1 192.168.2.1 (192.168.2.1)
2 c-24-9-60-1.hsd1.co.comcast.net (24.9.60.1)
3 te-9-7-ur02.boulder.co.denver.comcast.net
4 xe-13-3-1-0-ar01.aurora.co.denver.comcast.net
5 he-3-10-0-0-cr01.denver.co.ibone.comcast.net (68.86.92.25)
te-1-1-0-4-cr01.chicago.il.ibone.comcast.net (68.86.95.205)
6 xe-2-0-0-0-pe01.910fifteenth.co.ibone.comcast.net (68.86.82.2)
7 as15169-1-c.910fifteenth.co.ibone.comcast.net (23.30.206.106)
8 72.14.234.57 (72.14.234.57)
9 209.85.251.111 (209.85.251.111)
10 den03s06-in-f16.1e100.net (74.125.225.208)
Each IP address is a hop in the network for my request, which is received at each
service provider and then forwarded to the next service provider in the network,
depending on the final destination of the message.
(Note: I got this path by typing traceroute www.google.com in a terminal window.
From campus, you will see a different path.)
Build your own communications network
In this assignment, you’re going to simulate a communications network using a
linked list. Each node in your linked list will represent a city and you need to be able
to send a message between nodes from one side of the country to the other. Your
program also needs to provide the capability to update the network by adding cities
and still be able to transmit the message.
(Note: I’ll refer to the linked list as the network throughout this document.)
Include the following cities in your network:
Los Angeles
Phoenix
Denver
Dallas
Atlanta
New York
Implement each city as a struct with (use the starter code)
• a name,
• a pointer connecting it to the next city in the network, and
• a place to store the message being sent. (The message is a string.)
• an integer for the number of messages that have been sent through this city
When you initially build your network, the order of the cities should be the same as
the order listed above. After the network is built, you will provide the option of
adding additional cities.
First, display a menu
When your program starts, you should display a menu that presents the user with
options for how to run your program. The menu needs to look like the one shown
here:
The user will select the number for the menu option and your program should
respond accordingly to that number. Your menu options need to have the following
functionality.
1. Build Network: This option builds the linked list using the cities listed above in
the order they are listed. Each city needs to have a name, a pointer to the next city,
and a message value, which will initially be an empty string. This option should be
selected first to build the network, and can be selected anytime the user wants to
rebuild the starting network after adding cities. As part of the Build Network
functionality, you should print the name of each city in the network once the
network is built in the following format by calling the function for #2:
Los Angeles -> Phoenix -> Denver -> Dallas -> Atlanta -> New York -> NULL
Here is a screenshot showing the format that is expected:
2. Print Network Path: This option prints out the linked list in order from the head
to the tail by following the next pointer for each city. You should print the name of
each city. The function could be very useful to you when debugging your code. The
format should be the same as shown above.
There is one space before and after each arrow which is a dash and a >
3. Transmit Message: This option reads in from the user the message to transmit,
and transmits the message starting at the beginning of the network and ending at
the city specified. Each city in which the message passes through updates their
numberMessages variable to account for the number of messages passed through
that city.
For example:
4. Add City: This option allows the user to add a new city to the network. If the user
selects this option, then they should be prompted for the name of the city and the
city that the new city should follow in the network. For example, if the user wants to
add Tucson after Phoenix in the network, then the first four cities in the network
would be:
Los Angeles -> Phoenix -> Tucson -> Denver…
If the user wants to add a new city to the head of the network, e.g. replace Los
Angeles as the starting city, then they should type First when prompted for the
previous city and your code should handle this special case.
Here is a screenshot showing the expected output for the add city functionality
when the user selects Add City from the menu.
5. Delete City: Delete one of the cities in the network. If the user selects this option,
then they should be prompted for the name of the city to delete.
6. Clear Network: Deletes all cities in the network. Inside the deleteEntireNetwork
function, as each node is deleted, print the name of the city being deleted.
7. Quit: This option allows the user to exit the program.
For each of the options presented (except Quit), after the user makes their choice
and your code runs for that option, you should re-display the menu to allow the user
to select another option.
Program Specifications
• Use the starter code on the website HW2-LinkedListNetwork.cpp and do not
modify what is provided, only add to it.
• Your code needs to be readable, efficient, and accomplish the task provided.
• Make sure your code is commented enough to describe what it is doing.
Include a comment block at the top of the .cpp file with your name,
assignment number, and course instructor, and anyone you worked with.
• You must fill in the functions as specified. You do not need any additional
functions.
Submitting Your Code:
Zip your HW2-LinkedListNetwork.cpp file into a zipped file named
HW2_[yourFirstName]_[yourLastName].zip and submit to Moodle.
