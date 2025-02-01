#include <iostream>
#include <string>
using namespace std;
const int MAX_MATERIALS = 50;
const int MAX_ORDERS = 50;
class RawMaterial
{
private:
int materialID;
string materialName;
int quantity;
int reorderLevel;
double pricePerUnit;
public:
RawMaterial() : materialID(0), materialName(""), quantity(0), reorderLevel(0), pricePerUnit(0.0) {}
void inputMaterial(int id, string name, int qty, int reorderLvl, double price)
{
materialID = id;
materialName = name;
quantity = qty;
reorderLevel = reorderLvl;
pricePerUnit = price;
}
void displayMaterial()
{
cout << "ID: " << materialID << ", Name: " << materialName << ", Quantity: " << quantity
<< ", Minimum stock: " << reorderLevel << ", Price per Unit: " << pricePerUnit << endl;
}
void updateQuantity(int qty)
{
quantity += qty;
}
bool checkReorder()
{
return quantity < reorderLevel;
}
int getMaterialID() const { return materialID; }
string getMaterialName() const { return materialName; }
int getQuantity() const { return quantity; }
double getPricePerUnit() const { return pricePerUnit; }
void reduceQuantity(int qty) { quantity -= qty; }
};
class Order
{
private:
int orderID;
int materialID;
int quantity;
double totalCost;
string status;
public:
Order() : orderID(0), materialID(0), quantity(0), totalCost(0.0), status("Pending") {}
void inputOrder(int id, int matID, int qty, double unitPrice)
{
orderID = id;
materialID = matID;
quantity = qty;
totalCost = qty * unitPrice;
status = "Pending";
}
void displayOrder()
{
cout << "Order ID: " << orderID << ", Material ID: " << materialID
<< ", Quantity: " << quantity << ", Total Cost: " << totalCost
<< ", Status: " << status << endl;
}
void markCompleted() { status = "Completed"; }
int getOrderID() const { return orderID; }
int getMaterialID() const { return materialID; }
int getQuantity() const { return quantity; }
double getTotalCost() const { return totalCost; }
bool isCompleted() const { return status == "Completed"; }
};
class InventoryManagementSystem
{
private:
RawMaterial materials[MAX_MATERIALS];
Order orders[MAX_ORDERS];
int materialCount;
int orderCount;
public:
InventoryManagementSystem() : materialCount(0), orderCount(0) {}
void addMaterial()
{
int id, qty, reorderLvl;
string name;
double price;
cout << "Enter Material ID: ";
cin >> id;
cout << "Enter Material Name: ";
cin.ignore();
getline(cin, name);
cout << "Enter Quantity: ";
cin >> qty;
cout << "Enter minimum stock Level: ";
cin >> reorderLvl;
cout << "Enter Price per Unit: ";
cin >> price;
// Check if material with same ID and name already exists
bool found = false;
for (int i = 0; i < materialCount; ++i)
{
if (materials[i].getMaterialID() == id && materials[i].getMaterialName() == name)
{
materials[i].updateQuantity(qty); // Add quantity to existing material
found = true;
cout << "Material quantity updated successfully!\n";
break;
}
}
if (!found)
{ // If no existing material found, add new entry
materials[materialCount].inputMaterial(id, name, qty, reorderLvl, price);
materialCount++;
cout << "Material added successfully!\n";
}
}
void addOrder()
{
if (orderCount >= MAX_ORDERS)
{
cout << "Order storage is full.\n";
return;
}
int id, matID, qty;
cout << "Enter Order ID: ";
cin >> id;
cout << "Enter Material ID for Order: ";
cin >> matID;
cout << "Enter Quantity: ";
cin >> qty;
// Find the material to retrieve its price per unit
bool found = false;
double unitPrice = 0.0;
for (int i = 0; i < materialCount; ++i)
{
if (materials[i].getMaterialID() == matID)
{
unitPrice = materials[i].getPricePerUnit();
found = true;
break;
}
}
if (!found)
{
cout << "Material not found.\n";
return;
}
// Calculate total cost and add order
orders[orderCount].inputOrder(id, matID, qty, unitPrice);
cout << "Order added successfully! Total cost to pay: " << orders[orderCount].getTotalCost() << endl;
orderCount++;
}
void displayMaterials()
{
if (materialCount == 0)
{
cout << "No materials available.\n";
return;
}
cout << "\n--- Raw Materials ---\n";
for (int i = 0; i < materialCount; ++i)
{
materials[i].displayMaterial();
}
}
void displayOrders()
{
if (orderCount == 0)
{
cout << "No orders available.\n";
return;
}
cout << "\n--- Orders ---\n";
for (int i = 0; i < orderCount; ++i)
{
orders[i].displayOrder();
}
}
void markOrderAsCompleted()
{
int orderID;
cout << "Enter Order ID to mark as complete: ";
cin >> orderID;
bool foundOrder = false;
for (int i = 0; i < orderCount; ++i)
{
if (orders[i].getOrderID() == orderID && !orders[i].isCompleted())
{
// Find the material in stock and reduce the quantity
for (int j = 0; j < materialCount; ++j)
{
if (materials[j].getMaterialID() == orders[i].getMaterialID())
{
if (materials[j].getQuantity() >= orders[i].getQuantity())
{
materials[j].reduceQuantity(orders[i].getQuantity());
orders[i].markCompleted();
cout << "Order marked as completed and stock updated.\n";
}
else
{
cout << "Not enough stock to complete the order.\n";
}
foundOrder = true;
break;
}
}
break;
}
}
if (!foundOrder)
{
cout << "Order not found or already completed.\n";
}
}
void manageStock()
{
cout << "\n--- Stock Management ---\n";
for (int i = 0; i < materialCount; ++i)
{
if (materials[i].checkReorder())
{
cout << "Material " << materials[i].getMaterialName() << " needs to be reordered.\n";
}
}
}
void displayMenu()
{
int choice;
do
{
cout << "\n";
cout << "==============================================================\n";
cout << " ||| Inventory Management System |||\n";
cout << "==============================================================\n";
cout << " | 1 | -> Add Raw Material |\n";
cout << " | 2 | -> Display Materials |\n";
cout << " | 3 | -> Add Order |\n";
cout << " | 4 | -> Display Orders |\n";
cout << " | 5 | -> Manage Stock |\n";
cout << " | 6 | -> Mark Order as Completed |\n";
cout << " | 0 | -> Exit |\n";
cout << "==============================================================\n";
cout << "Please enter your choice (0-6): ";
cin >> choice;
switch (choice)
{
case 1:
addMaterial();
break;
case 2:
displayMaterials();
break;
case 3:
addOrder();
break;
case 4:
displayOrders();
break;
case 5:
manageStock();
break;
case 6:
markOrderAsCompleted();
break;
case 0:
cout << "Exiting system.\n";
break;
default:
cout << "Invalid choice. Please try again.\n";
}
} while (choice != 0);
}
};
int main()
{
InventoryManagementSystem i1;
i1.displayMenu();
return 0;
}
