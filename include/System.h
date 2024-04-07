#ifndef SYSTEM_H
#define SYSTEM_H

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "Flight.h"
#include "Passenger.h"
#include "Baggage.h"

class System {
private:
  std::vector<Flight> flights;
  static int lastTicketID;
  std::vector<Passenger> passengers;
  std::vector<Baggage> baggage;
  std::unordered_map<std::string, std::vector<int>> destinations;
  std::unordered_map<std::string, std::vector<int>> sources;
  Flight getFlight(int flight_number);
  std::unordered_map<std::string, std::vector<int>> path;
  std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph;
  
public:
  void addFlight(int flight_number, int capacity, const std::string &source,
                 const std::string &destination, int distance);
  void bookFlight(int flight_number, std::string passenger_name);
  void displayAvailableFlights();
  void displayDirectFlightsToDestination(const std::string &destination);
  void displayAllFlightsFromSource(const std::string &source);
  void baggageTracking(const std::string &baggageId,double baggageWeight, double baggageSize);  // Baggage tracking method using Queue data structure

  void displayPassengerList();        // added Passangers list display
  void displayBaggageList();  // added Baggages list display 

  void findShortestPath(const std::string &source, const std::string &destination); // Add a function to find the shortest path between two destinations using Dijkstra's algorithm 

  bool isValidFlightNumber(int flight_number); // cheak validity of flight number

  bool isValidDestination(const std::string &destination); // cheak validity of destination

  void displayMenu(); // Display menu 

  void setupGraph(); // Method to setup the graph
  
  static int generateTicketID(); // Static method to generate a new ticket ID
};

#endif
