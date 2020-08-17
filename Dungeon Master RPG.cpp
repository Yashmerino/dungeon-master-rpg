#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

string quest; //Global vars
int choose1;
int choose2;
bool action = true;

class DungeonMaster { //Dungeon Master class
private:
    string name; //Vars
    char sex;
    int age;
    int weight;
    int hp;

public:
    DungeonMaster() : name("Van"), sex('M'), age(20), weight(80), hp(100) {

    }

    int GetHP() { //Getter for the HP
        return hp;
    }

    void SetHP(int value) { //Setter for the HP
        hp = value;
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

    void PrintInfo() { //Printing info about the character
        cout << endl;
        cout << "Your character's name is: " << name << ".\nIt is " << age << " years old." << "\nIt weighs " << weight << " kg." << "\nIt's sex is: " << (char)toupper(sex) << "." << endl;
    }

    int Attack() { //Attacking
        srand(time(NULL));
        return rand() % 100;
    }

    int Defense() { //Defending
        srand(time(NULL));
        return rand() % 100;
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

class Enemy {
private:
    int hp;

public:
    Enemy() : hp(100) {

    }

    int GetHP() { //Getter for the HP
        return hp;
    }

    void SetHP(int value) { //Setter for the HP
        hp = value;
    }

    int Attack() { //Attacking
        return rand() % 100;
    }

    int Defense() { //Defending
        return rand() % 100;
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
        case 1:
            npc1.PrintInfo();
            break;
        case 2:
            ShowQuest();
            break;
        case 3:
            cout << "\nYou reached " << location1 << "." << endl;
            action = false;
            break;
        case 4:
            cin.get();
            exit(0);
        }
    }
}

int DamageEnemy(Enemy& mob, DungeonMaster& dm) { //Attack while fighting
    return mob.GetHP() - abs((dm.Attack() - mob.Defense()));
}

int DamageHero(Enemy& mob, DungeonMaster& dm) { //Attack while fighting
    return dm.GetHP() - abs((mob.Attack() - dm.Defense()));
}

int DefenseHero(Enemy& mob, DungeonMaster& dm) { //Defense while fighting
    return dm.GetHP() - (mob.Attack() / 5);
}

int DefenseEnemy(Enemy& mob, DungeonMaster& dm) { //Defense while fighting
    return mob.GetHP() - (dm.Attack() / 5);
}

void Duel(Enemy& mob, DungeonMaster& dm) { //Duel function
    action = true;
    while (action) {
        cout << "\nYour HP: " << dm.GetHP() << "\nEnemy's HP: " << mob.GetHP() << endl;
        cout << "1. Attack 2. Defense" << endl;
        cin >> choose1;

        switch (choose1) {
        case 1:
            choose2 = rand() % 2;

            if (choose2 == 1) {
                mob.SetHP(DamageEnemy(mob, dm));
                dm.SetHP(DamageHero(mob, dm));
            }
            else {
            mob.SetHP(DefenseEnemy(mob, dm));
        }

            break;
        case 2:        
            choose2 = rand() % 2;

            if (choose2 == 1)
                dm.SetHP(DefenseHero(mob, dm));
            else
                break;

            break;
        }
 
        if (mob.GetHP() <= 0) {
            mob.SetHP(0);
            if (dm.GetHP() <= 0) {
                dm.SetHP(0);
                cout << "\nYour HP: " << dm.GetHP() << "\nEnemy's HP: " << mob.GetHP() << endl;
                cout << "\nYou killed the enemy but died from bleeding!" << endl;
                cin.get();
                exit(0);
            }
            cout << "\nYour HP: " << dm.GetHP() << "\nEnemy's HP: " << mob.GetHP() << endl;
            cout << "\nYou killed the enemy!" << endl;
            action = false;
        }
        else if (dm.GetHP() <= 0) {
            dm.SetHP(0);
            if (mob.GetHP() <= 0) {
                mob.SetHP(0);
            }
            cout << "\nYour HP: " << dm.GetHP() << "\nEnemy's HP: " << mob.GetHP() << endl;
            cout << "\nYou died." << endl;
            cin.get();
            exit(0);

        }
    }
    dm.SetHP(100);
}

int main() {

    srand(time(NULL)); //Random

    DungeonMaster hero; //Creatting hero
    cout << "Welcome to the Dungeon Master RPG.\nCreate your character.\nType a name for it: ";
    //hero.SetName(); //Setting it's name

    //cout << "It's age: ";
    //hero.SetAge(); //Setting it's age

    //cout << "It's weight: ";
    //hero.SetWeight(); //Setting it's weight

    //cout << "It's sex (only F or M): ";
    //hero.SetSex(); //Setting it's sex

    //hero.PrintInfo(); //Printing info about the character

    cout << "\nYou are DungeonBorn. Your destiny is to find and clear every dungeon in the world!\nGo talk with Sirbu." << endl;
    QuestUpdated("Talk with Sirbu.");

    NPC Sirbu; //Creatting a NPC
    Sirbu.SetName("Sirbu");
    Sirbu.SetAge(19);
    Sirbu.SetWeight(67);
    Sirbu.SetSex('M');

    cout << "You reached the Gym." << endl; //Gameplay
    while (action) {
        cout << "1. Who are you?\n2. Who i'm i?" << endl;
        cin >> choose1;

        switch (choose1) {
        case 1:
            cout << "\nSirbu: I am Sirbu, i am the first DungeonBorn. Our world is attacked by Fratescu's army. You need to visit Topala's Dungeon to find his cum, it'll help you to save Pelivan from Fratescu.\n" << endl;
            QuestUpdated("Visit Topala's Dungeon");
            cout << "2. Who i'm i?" << endl;
            cin >> choose2;

            switch (choose2) {
            case 2:
                cout << "\nSirbu: You are the last DungeonBorn, you were summoned by the Gamart to save our world!\n" << endl;
                break;
            }
            break;
        case 2:
            cout << "\nYou are the last DungeonBorn, you were summoned by the Gamart to save our world!\n" << endl;
            cout << "1. Who are you?" << endl;
            cin >> choose2;

            switch (choose2) {
            case 1:
                cout << "\nI am Sirbu, i am the first DungeonBorn. Our world is attacked by Fratescu's army. You need to visit Topala's Dungeon to find his cum, it'll help you to save Pelivan from Fratescu.\n" << endl;
                QuestUpdated("Visit Topala's Dungeon");
                break;
            }

            break;
        }
        action = false;
    }

    DefaultChoose("Info about Sirbu", "Topala's Dungeon", Sirbu);

    cout << "\nThere is a skeleton! You need to kill him!" << endl;
    action = true;
    Enemy skeleton1;
    Duel(skeleton1, hero);

    cin.get();
    return 0;
}