#include <iostream>

#include "../include/System.h"

void System::displayAllFlightsFromSource(const std::string &source) {
  if (sources.find(source) != sources.end()) {
    std::cout << "#----------------------#" << std::endl;
    std::cout << "Flights from " << source << std::endl;
    for (int flight_number : sources[source]) {
      std::cout << "Flight " << flight_number << std::endl;
    }
  } else {
    std::cout << "No flights from " << source << std::endl;
  }
}

void System::displayDirectFlightsToDestination(const std::string &destination) {
  if (destinations.find(destination) != destinations.end()) {
    std::cout << "#----------------------#" << std::endl;
    std::cout << "Direct flights to " << destination << std::endl;
    for (int flight_number : destinations[destination]) {
      std::cout << "Flight " << flight_number << std::endl;
    }
  } else {
    std::cout << "No direct flights to " << destination << std::endl;
  }
}

void System::displayAvailableFlights() {
  std::cout << "#----------------------#" << std::endl;
  for (Flight flight : flights) {
    std::cout << "Flight Number : " << flight.flight_number << std::endl;
    std::cout << "Source : " << flight.source << std::endl;
    std::cout << "Destination : " << flight.destination << std::endl;
    std::cout << "Distance : " << flight.distance << std::endl;
    std::cout << "Capacity : " << flight.capacity << std::endl;
    std::cout << "Available Seat Count : "<< flight.capacity - flight.booked_seats << std::endl;
  }
}

void System::displayPassengerList()
{
    std::cout << "#----------------------#" << std::endl;
    std::cout << "Passenger List" << std::endl;
    for (const Passenger &passenger : passengers) {
        std::cout << "Passenger Name: " << passenger.name << std::endl;
        std::cout << "Flight Number: " << passenger.flight_number << std::endl;
        std::cout << "Ticket ID: " << passenger.flight_ticket_Id << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

void System::displayBaggageList() {
    std::cout << "#----------------------#" << std::endl;
    std::cout << "Baggage List" << std::endl;
    for (const Baggage &item : baggage) {
        std::cout << "Baggage ID: " << item.baggageId << std::endl;
        std::cout << "Weight: " << item.baggageWeight << " kg" << std::endl;
        std::cout << "Size: " << item.baggageSize << " cubic inches" << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}


// Display menu system 
void System::displayMenu() {
    int choice;
    do {
        // Display menu options
        std::cout << "1. Add Flight\n2. Book Flight\n3. Display Flights\n4. Display Passengers\n5. Display Baggage\n6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Process user choice
        switch (choice) {
            case 1:
                void addFlight(int flight_number, int capacity, const std::string &source,
                 const std::string &destination, int distance);                       // Call function to add a flight
                break;
            case 2:
                void bookFlight(int flight_number, std::string passenger_name); //book flight display
                break;
            case 3:
                void displayAvailableFlights();  // available flight display
                break;
            case 4:
                void displayPassengerList();     // passangers list display
                break;
            case 5:
                void displayBaggageList();       // Call function to display baggage
                break;
            case 6:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 6);
}




