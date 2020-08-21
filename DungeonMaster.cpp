#include "DungeonMaster.h"
#include <iostream>

    bool DungeonMaster::CheckInteger(std::string str) { //Check if string is a integer
        for (int i = 0; i < str.length(); i++)
            if (isdigit(str[i]) == false)
                return false;
            else
                return true;
    }

    DungeonMaster::DungeonMaster() : name("Van"), sex('M'), age("20"), weight("80"), hp(100) { //Constructor

    }

    void DungeonMaster::GetInventory() { //Getter for the inventory
        std::cout << std::endl;
        for (int slot = 0; slot < Inventory.size(); slot++) {
            std::cout << slot << ". " << Inventory[slot].GetName() << std::endl;
        }
        if (Inventory.size() == 0) {
            std::cout << "Your inventory is empty!" << std::endl;
        }
    }

    void DungeonMaster::GetItem(int slot) { //Getter for the item
        if (slot >= Inventory.size()) {
            std::cout << "\nError. There is nothing: ";
        }
        else {
            Inventory[slot].PrintInfo();
        }
    }

    int DungeonMaster::GetHP() { //Getter for the HP
        return hp;
    }

    std::string DungeonMaster::GetName() { //Getter for the name
        return name;
    }

    void DungeonMaster::SetInventory(int slot, Item item) { //Setter for the inventory
        if (slot >= Inventory.size()) {
            Inventory.resize(slot + 1);
        }

        size_t vSize = Inventory.size();
        Inventory[slot] = item;
    }

    void DungeonMaster::DeleteInventory(int slot) { //Deletes last item from the inventory
        Inventory.erase(Inventory.begin() + slot);
    }

    void DungeonMaster::SetHP(int hp) { //Setter for the HP
        this->hp = hp;
    }

    void DungeonMaster::SetName() { //Setter for the name
        std::string nick;
        std::cin >> nick;
        name = nick;
    }

    void DungeonMaster::SetAge() { //Setter for the age
        std::string value;
        std::cin >> value;
        while (!CheckInteger(value)) {
            std::cout << "Error. Only a number: ";
            std::cin >> value;
            if (CheckInteger(value)) {
                age = value;
            }
        }
    }

    void DungeonMaster::SetWeight() { //Setter for the weight
        std::string value;
        std::cin >> value;
        while (!CheckInteger(value)) {
            std::cout << "Error. Only a number: ";
            std::cin >> value;
            if (CheckInteger(value)) {
                age = value;
            }
        }
    }

    void DungeonMaster::SetSex() { //Setter for the sex
        std::cin >> sex;
        while (sex != 'f' && sex != 'm' && sex != 'M' && sex != 'F') {
            std::cout << "Error. Only F or M: ";
            std::cin >> sex;
        }
    }

    void DungeonMaster::PrintInfo() { //Printing info about the character
        std::cout << "\nYour character's name is: " << name << ".\nIt is " << age << " years old." << "\nIt weighs " << weight << " kg." << "\nIt's sex is: " << (char)toupper(sex) << "." << std::endl;
    }

    int DungeonMaster::Attack() { //Attacking
        return rand() % 100;
    }

    int DungeonMaster::Defense() { //Defending
        return rand() % 50;
    }

    int DungeonMaster::Heal() { //Heal
        return hp + 30;
    }
