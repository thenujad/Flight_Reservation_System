#include "../include/System.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>


void System::addFlight(int flight_number, int capacity,
                       const std::string &source,
                       const std::string &destination, int distance) {
  Flight newFlight{flight_number, capacity, capacity,
                   destination,   source,   distance};
  flights.push_back(newFlight);

  destinations[destination].push_back(flight_number);
  sources[source].push_back(flight_number);

  std::cout << "Flight " << flight_number << " is added. Source:" << source
            << ". Destination : " << destination << std::endl;
}

void System::bookFlight(int flight_number, std::string passenger_name) {
  Flight res_flight = System::getFlight(flight_number);
  if (res_flight.flight_number != -999 && res_flight.booked_seats > 0) {
    Passenger passenger{passenger_name, flight_number};
    res_flight.booked_seats--;
    std::cout << passenger_name << " booked the flight "
              << res_flight.flight_number << " from " << res_flight.source
              << " to " << res_flight.destination << "." << std::endl;
  } else {
    std::cout << "No flight found" << std::endl;
  }

    int ticketId =  System::generateTicketID();
    Passenger passenger{passenger_name, flight_number, ticketId};
    passengers.push_back(passenger);

}

void System::baggageTracking(const std::string &baggageId, double baggageWeight, double baggageSize) {

    Baggage newBaggage{baggageId, baggageWeight, baggageSize};
    baggage.push_back(newBaggage);
    std::cout << "Baggage with ID " << baggageId << " added to the system." << std::endl;

}

// Add a function to find the shortest path between two destinations using Dijkstra's algorithm
void System::findShortestPath(const std::string &source, const std::string &destination) {
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<>> pq;
    std::unordered_map<std::string, int> distance;

    // Initialize all distances to a large value
    for (const auto &node : graph) {
        distance[node.first] = INT_MAX;
    }

    distance[source] = 0;   // Set the distance of the source vertex to 0
    pq.push(std::make_pair(0, source)); // Enqueue the source vertex with distance 0

    // Dijkstra's algorithm loop
    while (!pq.empty()) {
        std::string current_vertex = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        // Process each neighboring vertex
        for (const auto &edge : graph[current_vertex]) {
            int new_distance = current_distance + edge.second; // edge.second is the weight

            // If a shorter path is found, update the distance and enqueue the vertex
            if (new_distance < distance[edge.first]) { // edge.first is the destination
                distance[edge.first] = new_distance;
                pq.push(std::make_pair(new_distance, edge.first));
            }
        }
    }

    // Output the shortest path from source to destination
    std::cout << "Shortest path from " << source << " to " << destination << " is: ";
    std::cout << distance[destination] << " units." << std::endl;
}



bool System::isValidFlightNumber(int flight_number) {
 
    if (flight_number <= 0) {
        std::cout << "Invalid flight number. Flight number must be a positive integer." << std::endl;
        return false;
    }

    if (flight_number >= 100 && flight_number <= 999) {
        return true;
    } else {
        std::cout << "Invalid flight number. Flight number must be between 100 and 999." << std::endl;
        return false;
    }
}

bool System::isValidDestination(const std::string &destination) {

    // Additional check: Destination should not contain special characters or numbers
    if (!std::all_of(destination.begin(), destination.end(), ::isalpha)) {
        std::cout << "Invalid destination. Destination should only contain alphabetic characters." << std::endl;
        return false;
    }

    // Check if destination is not empty
    if (!destination.empty()) {
        return true;
    } else {
        std::cout << "Invalid destination. Destination cannot be empty." << std::endl;
        return false;
    }
}








