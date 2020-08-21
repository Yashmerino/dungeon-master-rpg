#pragma once
#include <string>

class NPC {
private:
    std::string name;
    int age;
    int weight;
    char sex;
    std::string story;

public:
    NPC(); //Constructors

    NPC(std::string nick, char type, int value, int value2);

    void SetStory(std::string text); //Setter for the story

    void SetName(std::string nick); //Setter for the name

    void SetAge(int value); //Setter for the age

    void SetWeight(int value); //Setter for the weight

    void SetSex(char type); //Setter for the sex

    void PrintInfo(); //Function to print info about the NPC

};