#include "Item.h"
#include <iostream>

    Item::Item() : name("Unknown"), price(0), purpose("Unknown") { //Constructors

    }

    Item::Item(std::string nick, int value, std::string purp) {
        name = nick;
        price = value;
        purpose = purp;
    }

    std::string Item::GetName() { //Getter for the name of the item
        return name;
    }

    void Item::SetName(std::string nick) { //Setter for item's name
        name = nick;
    }
    void Item::SetPrice(int value) { //Setter for item's price
        price = value;
    }
    void Item::SetPurpose(std::string type) { //Setter for item's purpose
        purpose = type;
    }

    void Item::PrintInfo() { //Function to print info about the item
        std::cout << std::endl;
        std::cout << "Item's name is: " << name << ".\nIt costs " << price << " gold." << "\nIt's purpose is " << purpose << "." << std::endl;
    }
