
#include "USBConnection.h"

// Initialize the stack with available IDs
std::stack<int> USBConnection::ids({3, 2, 1});

// Private constructor
USBConnection::USBConnection(int id) : ID(id) {}

// Destructor
USBConnection::~USBConnection() {
    // Return the ID to the stack when the object is destroyed
    ids.push(ID);
}

// Static function to create a new object
std::shared_ptr<USBConnection> USBConnection::create() {
    if (ids.empty()) {
        return nullptr; // No available IDs
    }
    int newID = ids.top();
    ids.pop();
    // Use make_shared to handle object creation and memory management
    return std::make_shared<USBConnection>(newID);
}
