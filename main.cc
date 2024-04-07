#include "include/System.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "\t\t _##_ Welcome to Flight Reservation System __##__ \t\t" << std::endl;

    System SYSTEM;
    SYSTEM.setupGraph(); // Set up the graph for shortest path calculations

    int choice;
    do {
        std::cout << "\nMenu:\n"
                  << "1. Add Flight\n"
                  << "2. Book Flight\n"
                  << "3. Display All Flights\n"
                  << "4. Display All Flights From Source\n"
                  << "5. Display Direct Flights To Destination\n"
                  << "6. Display Passenger List\n"
                  << "7. Display Baggage List\n"
                  << "8. Find Shortest Path Between Cities\n"
                  << "9. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int flight_number, capacity, distance;
                std::string source, destination;

                std::cout << "Enter flight number: ";
                std::cin >> flight_number;
                std::cout << "Enter flight capacity: ";
                std::cin >> capacity;
                std::cin.ignore(); // To consume the newline character
                std::cout << "Enter flight source: ";
                std::getline(std::cin, source);
                std::cout << "Enter flight destination: ";
                std::getline(std::cin, destination);
                std::cout << "Enter flight distance: ";
                std::cin >> distance;

                SYSTEM.addFlight(flight_number, capacity, source, destination, distance);
                break;
            }
            case 2: {
                int flight_number;
                std::string passenger_name;

                std::cout << "Enter flight number: ";
                std::cin >> flight_number;
                std::cin.ignore(); // To consume the newline character
                std::cout << "Enter passenger name: ";
                std::getline(std::cin, passenger_name);

                SYSTEM.bookFlight(flight_number, passenger_name);
                break;
            }
            case 3:
                SYSTEM.displayAvailableFlights();
                break;
            case 4: {
                std::string source;
                std::cout << "Enter source: ";
                std::cin.ignore();
                std::getline(std::cin, source);
                SYSTEM.displayAllFlightsFromSource(source);
                break;
            }
            case 5: {
                std::string destination;
                std::cout << "Enter destination: ";
                std::cin.ignore();
                std::getline(std::cin, destination);
                SYSTEM.displayDirectFlightsToDestination(destination);
                break;
            }
            case 6:
                SYSTEM.displayPassengerList();
                break;
            case 7:
                SYSTEM.displayBaggageList();
                break;
            case 8: {
                std::string source, destination;
                std::cout << "Enter source: ";
                std::cin.ignore();
                std::getline(std::cin, source);
                std::cout << "Enter destination: ";
                std::getline(std::cin, destination);
                SYSTEM.findShortestPath(source, destination);
                break;
            }
            case 9:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 9);

    return 0;
}
