#include "NPC.h"
#include <iostream>

    NPC::NPC() : name("Unknown"), sex('N'), age(0), weight(0), story("Unknown") { //Constructors

    }

    NPC::NPC(std::string name, char sex, int age, int weight) : name(name), sex(sex), age(age), weight(weight) {
    }

    void NPC::SetStory(std::string story) { //Setter for the story
        this->story = story;
    }

    void NPC::SetName(std::string name) { //Setter for the name
        this->name = name;
    }

    void NPC::SetAge(int age) { //Setter for the age
        this->age = age;
    }

    void NPC::SetWeight(int weight) { //Setter for the weight
        this->weight = weight;
    }

    void NPC::SetSex(char sex) { //Setter for the sex
       this->sex = sex;
    }

    void NPC::PrintInfo() { //Function to print info about the NPC
        std::cout << "\nNPC's name is: " << name << ".\nIt is " << age << " years old." << "\nIt weighs " << weight << " kg." << "\nIt's sex is: " << (char)toupper(sex) << "." << std::endl;
        std::cout << "\nHis story: " << story << "." << std::endl << std::endl;
    }
