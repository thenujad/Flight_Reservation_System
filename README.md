
# Flight Reservation System

Welcome to the Flight Reservation System project! 
This system is designed to manage flights, bookings, passengers, baggage, and more.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [How to Use](#how-to-use)
- [Implementation Details](#implementation-details)
- [Contributing](#contributing)

## Introduction

This Flight Reservation System is a console-based application that allows users to manage flights, 
book tickets, track passengers, and monitor baggage. It's designed to provide a simple and efficient
way to handle various aspects of a flight reservation system.

## Features

- **Add Flight:** Add new flights with details such as flight number, capacity, source, destination, and distance.

- **Book Flight:** Book seats on available flights for passengers, reducing available seat count.

- **Display Flights:** View all available flights, flights from a specific source, or direct flights to a destination.

- **Display Passengers:** View a list of passengers along with their booked flights and ticket IDs.

- **Display Baggage:** View a list of baggage items, including baggage ID, weight, and size.

- **Find Shortest Path:** Utilize Dijkstra's algorithm to find the shortest path between two destinations.

- **Menu System:** An interactive menu system for user interaction.

## How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/thenujad/FlightReservationSystem.git
   ```

2. Compile the code:
   ```bash
   g++ -o FRS.exe main.cc src/System.cc src/Display.cc src/Process.cc
   ```

3. Run the executable:
   ```bash
   ./FRS.exe
   ```

4. Follow the on-screen prompts to interact with the Flight Reservation System.

## Implementation Details

- The system is implemented in C++.
- Flight information, passenger details, and baggage data are stored in appropriate data structures.
- Dijkstra's algorithm is used to find the shortest path between two destinations.

## Contributing

Contributions are welcome! Feel free to open issues, submit pull requests, or provide suggestions to improve the system.
