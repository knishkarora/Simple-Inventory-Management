# Inventory Management System

## Overview
The Inventory Management System is a C++ program based on Object-Oriented Programming (OOP) principles, designed to help businesses efficiently manage their raw materials and orders. The system provides functionality to add materials, place orders, track stock levels, and manage order completion.

## Features
- **Raw Material Management**
  - Add new materials to the inventory.
  - Update existing material quantities.
  - Display all available materials.
  
- **Order Management**
  - Create and store new orders.
  - Calculate total cost based on material prices.
  - Track and complete orders.
  
- **Stock Management**
  - Monitor material levels.
  - Identify materials that need to be reordered.

- **Interactive Menu System**
  - User-friendly command-line interface to navigate options.
  - Options to add materials, place orders, check stock, and complete orders.

### Prerequisites
- A C++ compiler (G++ or MSVC recommended)
- Command-line interface (Terminal, CMD, or PowerShell)

## Usage
1. Run the program.
2. Choose an option from the menu:
   - **1** -> Add a new raw material.
   - **2** -> Display all materials.
   - **3** -> Place a new order.
   - **4** -> View existing orders.
   - **5** -> Check stock status.
   - **6** -> Mark an order as completed.
   - **0** -> Exit the system.

## Code Structure
### Classes
- **`RawMaterial`**
  - Stores material details (ID, name, quantity, reorder level, price).
  - Allows updates to material quantity and reorder checks.
  
- **`Order`**
  - Represents an order with an ID, associated material ID, quantity, and total cost.
  - Supports marking orders as completed.
  
- **`InventoryManagementSystem`**
  - Manages lists of materials and orders.
  - Handles adding materials, placing orders, updating stock, and displaying records.

## Future Improvements
- Implement file storage to save and retrieve inventory data.
- Add a graphical user interface (GUI).
- Integrate database support for better data management.

## License
This project is released under the MIT License.

## Author
- **Knishk Arora**

