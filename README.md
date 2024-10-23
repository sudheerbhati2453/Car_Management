# Smart Cab Allocation System for Efficient Trip Planning


## Overview
This project is a **Smart Cab Allocation System** designed to optimize cab management, tracking, and booking using **C++**. It focuses on providing an efficient solution to allocate cabs to users based on their proximity to the trip start location, ensuring minimal travel distance and time. The system incorporates real-time cab tracking, fault-tolerant mechanisms, and scalable algorithms for smooth and fast operation.

## Key Features
- **Cab Allocation Optimization**: Efficiently suggests the nearest available cab based on real-time location data.
- **Cab Management**: Tracks the current status (engaged or available) and location of all cabs in the system.
- **Employee Cab Search**: Provides an optimized interface for employees to find nearby cabs currently in use.
- **Fault Tolerance**: Handles system failures and ensures data consistency using backup and recovery strategies.
- **Real-time Tracking**: Integrates real-time location data for accurate cab allocation and trip planning.

## Project Structure

### Core Modules
1. **Cab Allocation Optimization**:
   - The algorithm selects the best cab by calculating the distance from the trip's starting point and assigns it based on availability.

2. **Cab Management**:
   - Real-time tracking of all cabs, storing their location, status (engaged or available), and ID.

3. **Booking System**:
   - Employees can search for nearby cabs that are currently engaged, providing them with fast and efficient booking recommendations.

## Technologies Used
- **C++**: Core language for high performance and low-level memory control.
- **Object-Oriented Programming (OOP)**: Follows OOP principles for modular and maintainable code.
- **Data Structures**: Efficient structures are used to manage real-time cab data for fast lookups.
- **Real-Time Tracking**: Supports real-time updates for accurate cab suggestions.

## How to Run the Project

### Clone the Repository:
```bash
git clone https://github.com/your-repository/smart-cab-allocation-system.git
cd smart-cab-allocation-system

### Compile the Code:
To compile the project, use any C++ compiler (e.g., g++):

bash
Copy code
g++ main.cpp -o cab_system
### Run the Program:
Once compiled, run the program:
bash
Copy code
./cab_system
Sample Test:
Test the system with sample input data (cab latitude, longitude, status, and trip start location). The system will output the nearest available cab.

### Video Demonstration
Check out the detailed video demo on Google Drive showcasing how the system works, including cab tracking, real-time updates, and the cab allocation process:

Watch the Demonstration Video
(https://drive.google.com/file/d/1Krt-nK4pd2YJ3HUsYwG-F6igN-2EtoJi/view?usp=sharing)`
