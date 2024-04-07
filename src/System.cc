#include "../include/System.h"

Flight System::getFlight(int flight_number) {
  for (Flight &flight : flights) {
    if (flight.flight_number == flight_number) {
      return flight;
    }
  }
  Flight f{-999, -999, -999, "", "", 0};
  return f;
}


int System::lastTicketID = 0; 

int System::generateTicketID() {
    return ++lastTicketID; 
}



void System::setupGraph() {

    graph = {
        {"Long Island", {{"New York", 50}}},
        {"Los Angeles", {{"New York", 900}}},
        {"New York", {{"Miami", 750}}}
    };
}
