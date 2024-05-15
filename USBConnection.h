
#ifndef USBCONNECTION_H
#define USBCONNECTION_H

#include <stack>
#include <memory>

class USBConnection {
public:
    ~USBConnection(); // Destructor

    // Public static function to create a new object
    static std::shared_ptr<USBConnection> create();

private:
    // Private constructor
    USBConnection(int id);

    // ID of the USBConnection
    int ID;

    // Static stack to keep track of available IDs
    static std::stack<int> ids;
};

#endif // USBCONNECTION_H
