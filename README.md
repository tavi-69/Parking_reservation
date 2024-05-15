# Parking Management System in C++

This project is a simple parking management system developed in C++ to practice programming skills. It allows users to manage parking lots by adding, removing, and monitoring parking slots.

## Features

- **Add Parking Slots**: Users can add parking slots with unique IDs.
- **Remove Parking Slots**: Users can remove parking slots by ID.
- **Park Car**: Users can park a car in a specific parking slot for a specified duration.
- **Check Parking Status**: Users can check the status of all parking slots.
- **Prevent Invalid Inputs**: The program prevents users from entering 0 or negative values for parking duration or skipping time.
- **Expand Parking Capacity**: To add more parking lots, users need to update the `my_structs.h` file and increment the `max_capacity` variable.

## Usage

1. Clone the repository: `git clone https://github.com/your_username/parking-management.git`
2. Compile the program: `make`
3. Run the executable: `./parking_management`

## How to Add More Parking Lots

If you want to add more parking lots:

1. Open `my_structs.h`.
2. Add more IDs in the list (e.g., `ID-008`, `ID-009`, `ID-010`, etc.).
3. Increment the variable `max_capacity` by the number of IDs added.

## Note

The program currently does not detect string or character inputs. It assumes valid inputs for simplicity.

Feel free to contribute to the project by adding more features or improving existing ones!

