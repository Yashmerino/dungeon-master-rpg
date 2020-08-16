#include <iostream>
#include <string>

using namespace std;

string quest; //Vars
char choose1;
char choose2;
bool action = true;

class DungeonMaster { //Dungeon Master class
private:
    string name; //Vars
    char sex;
    int age;
    int weight;

public:
    DungeonMaster() : name("Van"), sex('M'), age(20), weight(80) {

    }

    void SetName() { //Setter for the name
        string nick;
        cin >> nick;
        name = nick;
    }

    void SetAge() { //Setter for the age
        int value;
        cin >> value;
        age = value;
    }

    void SetWeight() { //Setter for the weight
        int value;
        cin >> value;
        weight = value;
    }

    void SetSex() { //Setter for the sex
        cin >> sex;
        while (sex != 'f' && sex != 'm' && sex != 'M' && sex != 'F') {
            cout << "Error. Only F or M: ";
            cin >> sex;
        }
    }

    void PrintInfo() { //Function to print info about the character
        cout << endl;
        cout << "Your character's name is: " << name << ".\nIt is " << age << " years old." << "\nIt weighs " << weight << " kg." << "\nIt's sex is: " << (char)toupper(sex) << "." << endl;
    }

};

class NPC {
private:
    string name;
    int age;
    int weight;
    char sex;

public:
    NPC() : name("Unknown"), sex('N'), age(0), weight(0) {

    }

    void SetName(string nick) { //Setter for the name
        name = nick;
    }

    void SetAge(int value) { //Setter for the age
        age = value;
    }

    void SetWeight(int value) { //Setter for the weight
        weight = value;
    }

    void SetSex(char type) { //Setter for the sex
        sex = type;
    }

    void PrintInfo() { //Function to print info about the NPC
        cout << endl;
        cout << "NPC's name is: " << name << ".\nIt is " << age << " years old." << "\nIt weighs " << weight << " kg." << "\nIt's sex is: " << (char)toupper(sex) << "." << endl;
    }

};

class Item {
private:
    string name; //Item's name
    int price; //Item's price
    string purpose; //Item's attribute. Attack, Defense, Quest.

public:
    Item() : name("Unknown"), price(0), purpose("Unknown") {

    }

    void SetName(string nick) { //Setter for item's name
        name = nick;
    }
    void SetPrice(int value) { //Setter for item's price
        price = value;
    }
    void SetPurpose(string type) { //Setter for item's purpose
        purpose = type;
    }

    void PrintInfo() { //Function to print info about the item
        cout << endl;
        cout << "Item's name is: " << name << ".\nIt costs " << price << " gold." << "\nIt is for the " << purpose << "." << endl;
    }

};

void QuestUpdated(string task) { //Updatting the quest
    quest = task;
}

void ShowQuest() { //Showing your current quest
    cout << "\nYour main quest is to " << quest << "." << endl;
}

void DefaultChoose(string infonpc1, string location1, NPC npc1) { //Default selection menu
    action = true;

    while (action) {
        cout << "\n1. " << infonpc1 << ".\n2. Check your current quest." << "\n3. Go to " << location1 << ".\n4. Exit the game." << endl;
        cin >> choose1;
        switch (choose1) {
        case '1':
            npc1.PrintInfo();
            break;
        case '2':
            ShowQuest();
            break;
        case '3':
            cout << "\nYou reached " << location1 << "." << endl;
            action = false;
            break;
        case '4':
            cin.get();
            exit(0);
        }
    }
}

int main()
{
    DungeonMaster hero; //Creatting hero
    cout << "Welcome to the Dungeon Master RPG.\nCreate your character.\nType a name for it: ";
    hero.SetName(); //Setting it's name

    cout << "It's age: ";
    hero.SetAge(); //Setting it's age

    cout << "It's weight: ";
    hero.SetWeight(); //Setting it's weight

    cout << "It's sex (only F or M): ";
    hero.SetSex(); //Setting it's sex

    hero.PrintInfo(); //Printing info about the character
    
    cout << "\n\nYou are DungeonBorn. Your destiny is to find and clear every dungeon in the world!\nGo talk with Sirbu." << endl;
    QuestUpdated("Talk with Sirbu.");

    NPC Sirbu; //Creatting a NPC
    Sirbu.SetName("Sirbu");
    Sirbu.SetAge(19);
    Sirbu.SetWeight(67);
    Sirbu.SetSex('M');

    cout << "You reached the Gym." << endl;
    while (action) {
        cout << "1. Who are you?\n2. Who i'm i?" << endl;
        cin >> choose1;

        switch (choose1) {
        case '1':
            cout << "\nSirbu: I am Sirbu, i am the first DungeonBorn. Our world is attacked by Fratescu's army. You need to visit Topala's Dungeon to find his cum, it'll help you to save Pelivan from Fratescu.\n" << endl;
            QuestUpdated("Visit Topala's Dungeon");
            cout << "2. Who i'm i?" << endl;
            cin >> choose2;

            switch (choose2) {
            case '2':
                cout << "\nSirbu: You are the last DungeonBorn, you were summoned by the Gamart to save our world!\n" << endl;
                break;
            }
            break;

        case '2':
            cout << "\nYou are the last DungeonBorn, you were summoned by the Gamart to save our world!\n" << endl;
            cout << "1. Who are you?" << endl;
            cin >> choose2;

            switch (choose2) {
            case '1':
                cout << "\nI am Sirbu, i am the first Dungeonborn. Our world is attacked by Fratescu's army. You need to visit Topala's Dungeon to find his cum, it'll help you to save Pelivan from Fratescu.\n" << endl;
                QuestUpdated("Visit Topala's Dungeon");
                break;
            }

            break; 
        }
        action = false;
    }

    DefaultChoose("Info about Sirbu", "Topala's Dungeon", Sirbu);

    action = true;

    while (action) {

    }

    cin.get();
    return 0;
}
