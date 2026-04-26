# Lognuts-S2

The second re-iteration of Lognuts. Dumps all previous functionality for the glory of recursive algorithms, sorting, and linked list data structures!

Lognuts-S2 is a C++ console-based auto repair shop management system. It efficiently handles customer bookings, service queues, mechanic assignments, and service histories using persistent JSON data storage.

## 🚀 Features

*   **Booking Service:** Register a new vehicle for service by inputting details like car brand, model, customer name, issue description, assigned mechanic, priority level (1-4), and pick-up date.
*   **Queue Management:** View the active service queue and dynamically sort it based on:
    *   **Date:** Ascending order (closest date first).
    *   **Urgency/Priority:** Descending order (highest priority first).
*   **Finish Service:** Mark a vehicle as finished by selecting the specific mechanic handling it. Moves the vehicle to the "Done" database history safely.
*   **Reschedule (Change Date):** Change the pick-up/service date of a vehicle using a recursive date verification system to prevent scheduling conflicts.
*   **Persistent Storage:** Automatically saves and loads database information (both Queue and Done states) using JSON.

## 🛠️ Tech Stack & Concepts

*   **Language:** C++11
*   **Data Structures:** Linked Lists (for dynamic Queue and History management)
*   **Algorithms:** Bubble Sort (for Queue sorting), Recursion (for Date availability validation)
*   **External Libraries:** [nlohmann/json](https://github.com/nlohmann/json)

## 💻 How to Build and Run

Make sure you have `g++` (GCC) installed on your system.

### Windows
Run the provided batch script from your Command Prompt or PowerShell:
```bat
.\build.bat
.\lognuts.exe
```

### Linux / macOS
Run the provided bash script from your terminal:
```bash
chmod +x build.sh
./build.sh
./lognuts
```
