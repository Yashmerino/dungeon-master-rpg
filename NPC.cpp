#include "NPC.h"
#include <iostream>

    NPC::NPC() : name("Unknown"), sex('N'), age(0), weight(0), story("Unknown") { //Constructors

    }

    NPC::NPC(std::string nick, char type, int value, int value2) {
        name = nick;
        sex = type;
        age = value;
        weight = value2;
    }

    void NPC::SetStory(std::string text) { //Setter for the story
        story = text;
    }

    void NPC::SetName(std::string nick) { //Setter for the name
        name = nick;
    }

    void NPC::SetAge(int value) { //Setter for the age
        age = value;
    }

    void NPC::SetWeight(int value) { //Setter for the weight
        weight = value;
    }

    void NPC::SetSex(char type) { //Setter for the sex
        sex = type;
    }

    void NPC::PrintInfo() { //Function to print info about the NPC
        std::cout << "\nNPC's name is: " << name << ".\nIt is " << age << " years old." << "\nIt weighs " << weight << " kg." << "\nIt's sex is: " << (char)toupper(sex) << "." << std::endl;
        std::cout << "\nHis story: " << story << "." << std::endl << std::endl;
    }
