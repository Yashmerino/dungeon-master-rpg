#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

string quest; //Global vars
int choose1;
int choose2;
bool action = true;

class Item {
private:
    string name; //Item's name
    int price; //Item's price
    string purpose; //Item's attribute. Attack, Defense, Quest.

public:
    Item() : name("Unknown"), price(0), purpose("Unknown") { //Constructors

    }

    Item(string nick, int value, string purp) {
        name = nick;
        price = value;
        purpose = purp;
    }

    string GetName() { //Getter for the name of the item
        return name;
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
        cout << "Item's name is: " << name << ".\nIt costs " << price << " gold." << "\nIt's purpose is " << purpose << "." << endl;
    }

};

class DungeonMaster { //Dungeon Master class
private:
    string name; //Vars
    char sex;
    int age;
    int weight;
    int hp;
    vector<Item> Inventory;

public:
    DungeonMaster() : name("Van"), sex('M'), age(20), weight(80), hp(100) { //Constructor

    }

    void GetInventory() { //Getter for the inventory
        cout << endl;
        for (int slot = 0; slot < Inventory.size(); slot++) {
            cout << slot << ". " << Inventory[slot].GetName() << endl;
        }
        if (Inventory.size() == 0) {
            cout << "Your inventory is empty!" << endl;
        }
    }

    void GetItem(int slot) { //Getter for the item
        Inventory[slot].PrintInfo();
    }

    int GetHP() { //Getter for the HP
        return hp;
    }

    string GetName() { //Getter for the name
        return name;
    }

    void SetInventory(int slot, Item stuff) { //Setter for the inventory
        if (slot >= Inventory.size()) {
            Inventory.resize(slot+1);
        }

        size_t vSize = Inventory.size();
        Inventory[slot] = stuff;
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
        cout << "\nYour character's name is: " << name << ".\nIt is " << age << " years old." << "\nIt weighs " << weight << " kg." << "\nIt's sex is: " << (char)toupper(sex) << "." << endl;
    }

    int Attack() { //Attacking
        srand(time(NULL));
        return rand() % 100;
    }

    int Defense() { //Defending
        srand(time(NULL));
        return rand() % 100;
    }

    int Heal() { //Heal
        return hp + 30;
    }

};

class NPC {
private:
    string name;
    int age;
    int weight;
    char sex;
    string story;

public:
    NPC() : name("Unknown"), sex('N'), age(0), weight(0), story("Unknown") { //Constructors

    }

    NPC(string nick, char type, int value, int value2) {
        name = nick;
        sex = type;
        age = value;
        weight = value2;
    }

    void SetStory(string text) { //Setter for the story
        story = text;
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
        cout << "\nNPC's name is: " << name << ".\nIt is " << age << " years old." << "\nIt weighs " << weight << " kg." << "\nIt's sex is: " << (char)toupper(sex) << "." << endl;
        cout << "\nHis story: " << story << "." << endl << endl;
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
        return rand() % 80;
    }

    int Defense() { //Defending
        return rand() % 100;
    }

};

void QuestUpdated(string task) { //Updatting the quest
    quest = task;
}

void ShowQuest() { //Showing your current quest
    cout << "\nYour main quest is to " << quest << "." << endl << endl;
}

void DefaultChoose(string infonpc1, string location1, NPC& npc1, DungeonMaster& dm) { //Default selection menu
    action = true;

    while (action) {
        cout << "1. " << infonpc1 << ".\n2. Check your current quest." << "\n3. Go to " << location1 << ".\n4. Your inventory" << ".\n5. Exit the game." << endl;
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
            dm.GetInventory();
            cout << "You can check item's information by choosing it's slot. Type 9 to close the inventory." << endl;
            choose2 = 0;

            while (choose2 != 9) {
                cin >> choose2;
                if (choose2 == 9) {
                    break;
                }
                else {
                    dm.GetItem(choose2);
                    choose2 = 0;
                }
            }

            break;
        case 5:
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
    int healcount = 0;
    while (action) {
        cout << "\nYour HP: " << dm.GetHP() << "\nEnemy's HP: " << mob.GetHP() << endl;
        cout << "1. Attack 2. Defense 3. Heal(+30hp)" << endl;
        cin >> choose1;

        while (healcount == 1 && choose1 == 3) {
            cout << endl;
            cout << "You've already healed yourself!" << endl;
            cout << "1. Attack 2. Defense 3. Heal(+30hp)" << endl;
            cin >> choose1;
        }

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
        case 3:
            healcount = 1;

            if (dm.GetHP() == 100) {
                healcount = 0;
            }

            dm.SetHP(dm.Heal());

            if (dm.GetHP() > 100) {
                dm.SetHP(100);
                break;
            }
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
    hero.SetName(); //Setting it's name

    cout << "It's age: ";
    hero.SetAge(); //Setting it's age

    cout << "It's weight: ";
    hero.SetWeight(); //Setting it's weight

    cout << "It's sex (only F or M): ";
    hero.SetSex(); //Setting it's sex

    hero.PrintInfo(); //Printing info about the character

    cout << "\nYou are Dungeonborn. Your destiny is to save the world. But from who?\nGo talk with Sirbu." << endl;

    NPC Sirbu("Sirbu", 'M', 19, 67);
    Sirbu.SetStory("Sirbu is the first Dungeonborn. His destiny is to save our world from Fratescu, but he chose to write a game engine called: Sauce Game Engine. Due to this, you have to save the world instead of Sirbu");

    cout << "\nYou reached the Gym." << endl << endl;
    while (action) {
        cout << "1. Who are you?\n2. Who i'm i?" << endl;
        cin >> choose1;

        switch (choose1) {
        case 1:
            cout << "\nSirbu: I am Sirbu, i am the first Dungeonborn. Our world is attacked by Fratescu's army. You need to visit Topala's Dungeon to find his cum, it'll help you to save Pelivan from Fratescu.\n" << endl;
            QuestUpdated("visit Topala's Dungeon");
            cout << "2. Who i'm i?" << endl;
            cin >> choose2;

            switch (choose2) {
            case 2:
                cout << "\nSirbu: You are the last Dungeonborn, you were summoned by the Gamart to save our world!" << endl;
                break;
            }
            break;
        case 2:
            cout << "\nYou are the last Dungeonborn, you were summoned by the Gamart to save our world!\n" << endl;
            cout << "1. Who are you?" << endl;
            cin >> choose2;

            switch (choose2) {
            case 1:
                cout << "\nI am Sirbu, i am the first Dungeonborn. Our world is attacked by Fratescu's army. You need to visit Topala's Dungeon to find his cum, it'll help you to save Pelivan from Fratescu." << endl;
                QuestUpdated("visit Topala's Dungeon");
                break;
            }

            break;
        }
        action = false;
    }

    cout << endl;
    DefaultChoose("Info about Sirbu", "Topala's Dungeon", Sirbu, hero);
    QuestUpdated("find Topala's cum in the dungeon");

    cout << "\nThere is a skeleton! You have to to kill him!" << endl;
    action = true;
    Enemy skeleton1;
    Duel(skeleton1, hero);

    NPC Topala("Topala", 'M', 16, 56);
    Topala.SetStory("Topala is an old mage, he knows a lot about this world, he can help you to stop Fratescu. While talking to him don't turn your back to the cross.");
    cout << endl;
    DefaultChoose("Info about Topala", "next room", Topala, hero);

    cout << "\nThere are 2 vaca lui Topala! You have to fight them!" << endl;
    action = true;
    Enemy vaca1, vaca2;
    Duel(vaca1, hero);
    cout << "Next enemy:" << endl;
    Duel(vaca2, hero);

    cout << endl;
    DefaultChoose("Info about Topala", "next room", Topala, hero);

    cout << "\nThere is a bunelul lui Topala! You have to kill him!" << endl;
    action = true;
    Enemy bunelul;
    Duel(bunelul, hero);

    cout << endl;
    DefaultChoose("Info about Topala", "last room", Topala, hero);
    NPC Seriojka("Seriojka", 'M', 19, 70);
    Seriojka.SetStory("Seriojka is Topala's brother. They are called: Dva brata ebanata. He is also a great mage, but he's weak now due to Topala's runaway");
    cout << "\nSeriojka: Hello there Dungeonborn! (Press enter to continue the dialogue)" << endl; cin.get(); cin.get();
    cout << hero.GetName() << ": Hello, i guess..." << endl; cin.get();
    cout << "Seriojka: You're here to find Topala and his cum? Right?" << endl; cin.get();
    cout << hero.GetName() << ": Yes! But who the fuck are you?" << endl; cin.get();
    cout << "Seriojka: I'm his brother... But he betrayed us, he left us alone and gone to Bogdan's stadium. He said that he together with Bogdan has a plan how to stop Fratescu!" << endl; cin.get();
    cout << hero.GetName() << ": What? Is he insane? Only the Dungeonborn can stop him! They will die! And i need his cum to get the power of gods... Po wel nah!" << endl; cin.get();
    cout << "Seriojka: Yes, i do understand you, Dungeonborn... Go to Bogdan's stadion and talk with Topala, i think he'll listen to you. Take this key, this is the key to enter the stadium." << endl; cin.get();
    cout << "You got Bogdan's stadium key!" << endl;

    Item Stadium_key("Stadium Key", 500, "to enter Bogdan's stadium");
    hero.SetInventory(0, Stadium_key);

    cout << endl;
    QuestUpdated("visit Bogdan's stadium");
    DefaultChoose("Info about Seriojka", "Bogdan's stadium", Seriojka, hero);

    NPC Gamart("Gamart", 'M', 67, 80);
    Gamart.SetStory("Gamart is the king of Pelivan. He summoned you to save Pelivan. He was a Fratescu's great friend, before Fratescu attacked Pelivan");
    cout << "\nGamart: Stop there! You, Dungeonborn!" << endl; cin.get(); cin.get();
    cout << hero.GetName() << ": What? Who are you?" << endl; cin.get();
    cout << "Gamart: Imagine not knowing your summoner. I'm Gamart, i need to give you something, take this. You'll need to combine it with Topala's cum to learn the power of gods!" << endl; cin.get();
    cout << "You got fisting recipe!" << endl; cin.get();
    cout << hero.GetName() << ": Thanks, but can i ask you? Who is Fratescu? I just know that i need to save the world from him." << endl; cin.get();
    cout << "Gamart: Dungeonborn... I can't say it right now, you'll get it after you'll kill him. We were good friends with him, but everything changes. He decided to become the strongest human and become the new king of the world" << endl; cin.get();
    cout << hero.GetName() << ": But where does he get this power from?" << endl; cin.get();
    cout << "Gamart: He always had it... but we never thought he will use it against us. Enter the Bogdan's stadium, stop wasting time!" << endl; cin.get();

    Item Fisting_recipe("Fisting recipe", 1000, "to combine it it Topala's cum, to learn the power of gods");
    hero.SetInventory(1, Fisting_recipe);

    QuestUpdated("enter Bogdan's stadium");
    DefaultChoose("Info about Gamart", "Bogdan's stadium", Gamart, hero);

    cin.get();
    return 0;
}