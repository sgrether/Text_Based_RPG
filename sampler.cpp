/**
    CS-11 Sampler Project
	sampler.cpp
    commands.txt
	Purpose: Play a role-playing game using with text and user-input commands

	@author Scott Grether
	@version 1.0 12/5/14
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

class Conditions {
public:
    /**
    Default constructor
    */
    Conditions();
    /**
    Overloaded constructor
    */
    Conditions(bool cheater);
    /**
    Lists all the possible commands that the player can input.
    param commands A vector of commands that player can enter
    param position The current position of the player
    */
    void listCommands(const vector<string>& commands, int position);
    /**
    Sets the dead variable to true if the player dies.
    param loser Changes variable to true
    */
    void death(bool loser);
    /**
    Sets the win variable to true if the player cheats.
    param god Changes variable to true
    */
    void setGod(bool god);
    /**
    Sets the position for the position() function.
    param command The input from the player
    param position The current position of the player
    */
    void quordinate(string command, int& position);
    /**
    Allows the player to move to different areas.
    param command The input from the player
    param position The current position of the player
    */
    void move(string command, int& position);
    /**
    Returns the win variable.
    */
    bool getWin() const;
    /**
    Returns the dead variable.
    */
    bool getDead() const;
    /**
    Returns the stick variable.
    */
    bool getStick() const;
    /**
    Returns the axe variable.
    */
    bool getAxe() const;
    /**
    Returns the shield variable.
    */
    bool getShield() const;
    /**
    Returns the owlBear variable.
    */
    bool getOwlBear() const;
    /**
    Returns the value of completedKey.
    return completedKey The value of the variable
    */
    bool getCompKey() const;
    /**
    Sets the win variable.
    param newWin Changes win
    */
    void setWin(bool newWin);
    /**
    Sets the dead variable.
    param newDead Changes dead
    */
    void setDead(bool newDead);
    /**
    Sets the stick variable.
    param newStick Changes stick
    */
    void setStick(bool newStick);
    /**
    Sets the axe variable.
    param newAxe Changes axe
    */
    void setAxe(bool newAxe);
    /**
    Sets the key1 variable.
    param newKey1 Changes key1
    */
    void setKey1(bool newKey1);
    /**
    Sets the key2 variable.
    param newKey2 Changes key2
    */
    void setKey2(bool newKey2);
    /**
    Sets the key3 variable.
    param newKey3 Changes key3
    */
    void setKey3(bool newKey3);
    /**
    Sets the shield variable.
    param newShield Changes shield
    */
    void setShield(bool newShield);
    /**
    Sets the broken variable.
    param newBroken Changes broken
    */
    void setBroken(bool newBroken);
    /**
    Sets the completedKey variable.
    param newCompKey Changes completedKey
    */
    void setCompKey(bool newCompKey);
    /**
    Sets the owlBear variable.
    param newOwlBear Changes owlBear
    */
    void setOwlBear (bool newOwlBear);
    /**
    Sets the locked variable.
    param newLock Changes locked
    */
    void setLocked(bool newLock);
    /**
    Sets the bird variable.
    param newBird Changes bird
    */
    void setBird(bool newBird);
    /**
    Allows the player to pick up items.
    param inventory Items the player is currently carrying
    param position The current position of the player
    */
    void grab(vector<string>& inventory, int position);
    /**
    Gives a description of the current location.
    param position The current position of the player
    */
    void description(int position);
    /**
    Combines the key pieces into one complete key.
    param inventory Items the player is currently carrying
    */
    void combineKeys(vector<string>& inventory);
private:
    bool win;
    bool dead;
    bool stick;
    bool axe;
    bool key1;
    bool key2;
    bool key3;
    bool shield;
    bool broken;
    bool completedKey;
    bool owlBear;
    bool locked;
    bool bird;
};

class Character {
public:
    //constructor
    Character();
    /**
    Calls the getWin() function in Conditions.
    return cond.getWin() function call to condition class
    */
    bool getWin();
    /**
    Calls the getDead() function in Conditions.
    return cond.getDead() Function call to condition class
    */
    bool getDead();
    /**
    Calls the setCompKey() Function in Conditions.
    return cond.setCompKey() Function in Conditions.
    */
    bool getCompKey();
    /**
    Calls the getAxe() function in Conditions.
    return getAxe() Returns the value of axe
    */
    bool getAxe();
    /**
    Calls the getShield() function in Conditions.
    return getShield() Returns the value of shield
    */
    bool getShield();
    /**
    Calls the description() function in Conditions.
    param position the current position of the character
    */
    void callDescription(int position);
    /**
    Calls the grab() function in Conditions.
    param inventory the items the character currently has
    param position the current position of the character
    */
    void callGrab(vector<string>& inventory, int position);
    /**
    Calls the listCommands() function in Conditions.
    param inventory the items the character currently has
    param position the current position of the character
    */
    void callListCommands(const vector<string>& commands, int position);
    /**
    Calls the move() function in Conditions.
    param command the input of the user
    param position the current position of the character
    */
    void callMove(string command, int& position);
    /**
    Lets the character attack.
    param position the current position of the character
    */
    void attack(int position);
    /**
    Adds the weapons attack to the characters power.
    */
    void addWeapon();
    /**
    Adds the shields defense to the characters defense.
    */
    void addShield();
    /**
    Calculates damage to and from the owlBear.
    */
    void combat();
    /**
    Calls the combineKeys() function from conditions.
    param inventory The items the character currently has
    */
    void combineKeys(vector<string>& inventory);
    /*
    Calls the setGod() function in Conditions.
    param command The users input
    */
    void setGod(bool god);
private:
    Conditions cond;
    int power;
    int defense;
    int health;
    int owlBearHealth;
    int owlBearAttack;
};

/**
Lists the items the player currently has.
param inventory The items the player is currently carrying
*/
void listItems(const vector<string>& inventory);
/**
Adds an item to the players inventory.
param inventory The items the player is currently carrying
param position The current position of the player
*/
void addItem(vector<string>& inventory, int position);

/**
    position 1 = Forest Entrance
    position 2 = Forest Path1
    position 3 = Clearing
    position 4 = Forest Path 2
    position 5 = Cave Entrance
    position 6 = Cabin
    position 7 = Cave
    position 8 = Cabin Interior
    position 9 = Tree
*/

int main() {
    vector<string> inventory;
    inventory.push_back("Empty");
    vector<string> commands;
    ifstream fin;
    fin.open("commands.txt");
    if (fin.fail()) {
        cout << "Input file failed to open.\n";
        exit(-1);
    }
    string next;
    while (fin >> next) {
        commands.push_back(next);
    }
    fin.close();
    Character player;
    int position = 1, done = 0;
    cout << "Welcome!\n"
         << "If you need help just type 'help'\n\n";
    string command = "empty";
    player.callDescription(position);
    cout << endl;
    while (command != "quit" && player.getWin() == false && player.getDead() == false) {
        cin >> command;
        cout << endl;
        if (command == "help") {
            player.callListCommands(commands, position);
        } else if (command == "look") {
            player.callDescription(position);
            cout << endl;
        } else if (command == "move") {
            player.callMove(command, position);
            player.callDescription(position);
            cout << endl;
        } else if (command == "climb") {
            player.callMove(command, position);
            player.callDescription(position);
        } else if (command == "inventory") {
            listItems(inventory);
        } else if (command == "grab") {
            player.callGrab(inventory, position);
        } else if (command == "attack") {
            player.attack(position);
            cout << endl;
        } else if (command == "god") {
            player.setGod(true);
        } else if (command == "quit") {
        } else {
            cout << "Invalid command.\n\n";
        }
        if (player.getCompKey() == true && done == 0) {
            player.combineKeys(inventory);
            done = 1;
        }
        if (player.getAxe() == true) {
            player.addWeapon();
        }
        if (player.getShield() == true) {
            player.addShield();
        }
    }
    ofstream fout("winner.txt");
    if (fout.fail()) {
        cout << "Output file failed to open.\n";
        exit(-1);
    }
    if (player.getDead() == true) {
        cout << "You have died.\n";
        fout << "You were killed by the mighty Owl Bear!\n"
             << "Try not to do that again.";
    } else if (player.getWin() == true) {
        cout << "Congratulations! You win!\n";
        fout << "You bested the mighty nesting bird, destroyed \n"
             << "the impenetrable wooden wagon, and slayed the mighty "
             << "Owl Bear!\n"
             << "Congratulations on your victory!!";
    } else {
        cout << "Goodbye.\n";
        fout << "Quitter.";
    }
    fout.close();
        
    return 0;
}

Conditions::Conditions() {
    win = false;
    dead = false;
    stick = false;
    axe = false;
    key1 = false;
    key2 = false;
    key3 = false;
    shield = false;
    broken = false;
    completedKey = false;
    owlBear = true;
    locked = true;
    bird = true;
}

Conditions::Conditions(bool cheater) {
    win = cheater;
    dead = false;
    stick = false;
    axe = false;
    key1 = false;
    key2 = false;
    key3 = false;
    shield = false;
    broken = false;
    completedKey = false;
    owlBear = true;
    locked = true;
    bird = true;
}

bool Conditions::getWin() const {
    return win;
}

bool Conditions::getDead() const {
    return dead;
}

bool Conditions::getAxe() const {
    return axe;
}

bool Conditions::getShield() const {
    return shield;
}

bool Conditions::getStick() const {
    return stick;
}

bool Conditions::getOwlBear() const {
    return owlBear;
}

bool Conditions::getCompKey() const {
    return completedKey;
}

void Conditions::death(bool loser) {
    dead = loser;
}

void Conditions::setWin(bool newWin) {
    win = newWin;
}

void Conditions::setDead(bool newDead) {
    dead = newDead;
}

void Conditions::setGod(bool god) {
    win = god;
}

void Conditions::setStick(bool newStick) {
    stick = newStick;
}
void Conditions::setAxe(bool newAxe) {
    axe = newAxe;
}
void Conditions::setKey1(bool newKey1) {
    key1 = newKey1;
}
void Conditions::setKey2(bool newKey2) {
    key2 = newKey2;
}
void Conditions::setKey3(bool newKey3) {
    key3 = newKey3;
}
void Conditions::setShield(bool newShield) {
    shield = newShield;
}
void Conditions::setBroken(bool newBroken) {
    broken = newBroken;
}
void Conditions::setCompKey(bool newCompKey) {
    completedKey = newCompKey;
}
void Conditions::setOwlBear(bool newOwlBear) {
    owlBear = newOwlBear;
}
void Conditions::setLocked(bool newLock) {
    locked = newLock;
}

void Conditions::setBird(bool newBird) {
    bird = newBird;
}

void Conditions::listCommands(const vector<string>& commands, int position) {
    cout << "Commands:\n";
    if (position == 1) {
        for (unsigned i = 0; i < commands.size() - 3; i++) {
            cout << commands[i] << endl;
        }
    } else if (position == 2) {
        for (unsigned i = 0; i < commands.size() - 3; i++) {
            cout << commands[i] << endl;
        }
        cout << commands[6] << endl;
        if (stick == false) {
            cout << commands[4] << endl;
        }
    } else if (position == 3) {
        for (unsigned i = 0; i < commands.size() - 3; i++) {
            cout << commands[i] << endl;
        }
        if (axe == true && broken == false) {
            cout << commands[5] << endl;
        } else if (broken == true && key2 == false) {
            cout << commands[4] << endl;
        }
    } else if (position == 4) {
        for (unsigned i = 0; i < commands.size() - 3; i++) {
            cout << commands[i] << endl;
        }
        if (shield == false) {
            cout << commands[4] << endl;
        }
    } else if (position == 5) {
        for (unsigned i = 0; i < commands.size() - 3; i++) {
            cout << commands[i] << endl;
        }
        if (owlBear == true) {
            cout << commands[5] << endl;
        } else if (owlBear == false && locked == false) {
            cout << commands[4] << endl;
        }
    } else if (position == 6) {
        for (unsigned i = 0; i < commands.size() - 3; i++) {
            cout << commands[i] << endl;
        }
        if (axe == false) {
            cout << commands[4] << endl;
        }
    } else if (position == 7) {
        for (unsigned i = 0; i < commands.size() - 3; i++) {
            cout << commands[i] << endl;
        }
        cout << commands[4] << endl;
    } else if (position == 8) {
        for (unsigned i = 0; i < commands.size() - 3; i++) {
            cout << commands[i] << endl;
        }
        if (key3 == false) {
            cout << commands[4] << endl;
        }
    } else if (position == 9) {
        for (unsigned i = 0; i < commands.size() - 3; i++) {
            cout << commands[i] << endl;
        }
        if (bird == true) {
            cout << commands[5] << endl;
        } else if (bird == false && key1 == false) {
            cout << commands[4] << endl;
        }
    }
    cout << endl;
}

void Conditions::description(int position) {
    if (position == 1) {
        cout << "You find yourself at the mouth of a small forest\n";
    } else if (position == 2 && stick == false) {
        cout << "You find yourself on a small forest path.\n"
             << "There is a stick to the side of the path,"
             << " and a bird's nest in a nearby tree.\n";
    } else if (position == 2 && stick == true) {
        cout << "You find yourself on a small forest path.\n"
             << "There is a bird's nest in a nearby tree.\n";
    } else if (position == 3 && broken == false) {
        cout << "You find yourself in a small clearing.\n"
             << "There are three paths leading out of the clearing, "
             << "and a moss-covered wagon in the center.\n";
    } else if (position == 3 && broken == true) {
        cout << "You find yourself in a small clearing.\n"
             << "There are three paths leading out of the clearing, "
             << "and a moss-covered wagon with a large hole in the side, "
             << "sitting in the center.\n";
    } else if (position == 4 && shield == false) {
        cout << "You find yourself on a small path, "
             << "and there is a cliff in the distance.\n"
             << "There is also a small wooden shield lying to the "
             << "side of the path.\n";
    } else if (position == 4 && shield == true) {
        cout << "You find yourself on a small path, "
             << "and there is a cliff in the distance.\n";
    } else if (position == 5 && owlBear == true) {
        cout << "You find yourself at the base of the cliff.\n"
             << "There is a menacing looking owl-bear patrolling "
             << "in front of a suspicious looking section of the cliff.\n";
    } else if (position == 5 && owlBear == false) {
        cout << "You find yourself at the base of the cliff.\n"
             << "There is a suspicious looking area in the cliff face.\n";
    } else if (position == 6 && axe == false) {
        cout << "You find yourself in front of a small, "
             << "moss-covered cabin.\n"
             << "There is an axe propped up against the side of the cabin, "
             << "and a broken window above it.\n";
    } else if (position == 6 && axe == true) {
        cout << "You find yourself in front of a small, "
             << "moss-covered cabin.\n"
             << "There is a broken window on the side of the cabin.\n";
    } else if (position == 7) {
        cout << "You find yourself inside a small cave.\n"
             << "There is a small altar with a wooden box resting on top of it.\n";
    } else if (position == 8 && key3 == false) {
        cout << "The inside of the cabin is mostly bare, "
             << "but there is an odd object on the table.\n";
    } else if (position == 8 && key3 == true) {
        cout << "The inside of the cabin is mostly bare.\n";
    } else if (position == 9 && bird == true && key1 == false) {
        cout << "There is a bird in the nest, and underneath "
             << "the bird is an odd object.\n\n";
    } else if (position == 9 && bird == false && key1 == false) {
        cout << "The nest is empty aside from the odd object.\n";
    } else if (position == 9 && bird == false && key1 == true) {
        cout << "The nest is empty.\n";
    }
}

void Conditions::quordinate(string command, int& position) {
    if (position == 1) {
        position = 2;
    } else if (position == 2 && command == "north") {
        position = 3;
    } else if (position == 2 && command == "south") {
        position = 1;
    } else if (position == 2 && command == "climb") {
        position = 9;
    } else if (position == 3 && command == "north") {
        position = 4;
    } else if (position == 3 && command == "east") {
        position = 6;
    } else if (position == 3 && command == "south") {
        position = 2;
    } else if (position == 4 && command == "north") {
        position = 5;
    } else if (position == 4 && command == "south") {
        position = 3;
    } else if (position == 5 && command == "enter" && completedKey == true) {
        position = 7;
    } else if (position == 5 && command == "enter" && completedKey == false) {
        cout << "The door is locked\n\n";
    } else if (position == 5 && command == "south") {
        position = 4;
    } else if (position == 6 && command == "enter") {
        position = 8;
    } else if (position == 6 && command == "west") {
        position = 3;
    } else if (position == 8) {
        position = 6;
    } else if (position == 9) {
        position = 2;
    }
}

void Conditions::move(string command, int& position) {
    if (position == 1) {
        quordinate(command, position);
    } else if (position == 2 && command == "climb") {
        quordinate(command, position);
    } else if (position == 2 && command == "move") {
        do {
            cout << "Which direction? (north, south) \n\n";
            cin >> command;
            cout << endl;
            if (command == "north" || command == "south") {
                quordinate(command, position);
            } else {
                cout << "Invalid Direction.\n\n";
            }
        } while (command != "north" && command != "south");
    } else if (position == 3) {
        do {
            cout << "Which direction? (north, east, south) \n\n";
            cin >> command;
            cout << endl;
            if (command == "north" || command == "south" || command == "east") {
                quordinate(command, position);
            } else {
                cout << "Invalid Direction.\n\n";
            }
        } while (command != "north" && command != "south" && command != "east");
    } else if (position == 4) {
        do {
            cout << "Which direction? (north, south) \n\n";
            cin >> command;
            cout << endl;
            if (command == "north" || command == "south") {
                quordinate(command, position);
            } else {
                cout << "Invalid Direction.\n\n";
            }
        } while (command != "north" && command != "south");
    } else if (position == 5) {
        do {
            cout << "Which direction? (enter, south) \n\n";
            cin >> command;
            cout << endl;
            if (command == "enter" || command == "south") {
                quordinate(command, position);
            } else {
                cout << "Invalid Direction.\n\n";
            }
        } while (command != "enter" && command != "south");
    } else if (position == 6) {
        do {
            cout << "Which direction? (enter, west) \n\n";
            cin >> command;
            cout << endl;
            if (command == "enter" || command == "west") {
                quordinate(command, position);
            } else {
                cout << "Invalid Direction.\n\n";
            }
        } while (command != "enter" && command != "west");
    } else if (position == 8) {
        quordinate(command, position);
    } else if (position == 9) {
        quordinate(command, position);
    }
}

void Conditions::grab(vector<string>& inventory, int position) {
    if (position == 2 || position == 3 || position == 6 || position == 7 || position == 8 || position == 4 || position == 9) {
        if (position == 2 && stick == true) {
            cout << "There is nothing to grab.\n\n";
        }else if (position == 2 && stick == false) {
            cout << "You pick up the stick.\n\n";
            addItem(inventory, position);
            stick = true;
        } else if (position == 3 && broken == false) {
            cout << "There is nothing to grab.\n\n";
        } else if (position == 3 && broken == true && key2 == false) {
            cout << "You pick up the key piece.\n\n";
            addItem(inventory, position);
            key2 = true;
        } else if (position == 3 && key2 == true) {
            cout << "There is nothing to grab.\n\n";
        } else if (position == 4 && shield == false) {
            cout << "You pick up the shield.\n\n";
            addItem(inventory, position);
            shield = true;
        } else if (position == 4 && shield == true) {
            cout << "There is nothing to pick up.\n\n";
        } else if (position == 6 && axe == false) {
            cout << "You pick up the axe.\n\n";
            addItem(inventory, position);
            axe = true;
        } else if (position == 6 && axe == true) {
            cout << "There is nothing to grab.\n\n";
        } else if (position == 8 && key3 == false) {
            cout << "You pick up the key piece.\n\n";
            addItem(inventory, position);
            key3 = true;
        } else if (position == 8 && key3 == true) {
            cout << "There is nothing to grab.\n\n";
        } else if (position == 9 && bird == false && key1 == false) {
            cout << "You pick up the key piece.\n\n";
            addItem(inventory, position);
            key1 = true;
        } else if (position == 9 && key1 == true && bird == false) {
            cout << "There is nothing to grab.\n\n";
        } else if (position == 9 && bird == true && key1 == false) {
            cout << "You cannot grab the object, there's a bird in the way.\n\n";
        } else if (position == 7) {
            cout << "You pick up the box.\n"
                 << "Inside is your missing sock.\n\n";
            addItem(inventory, position);
            setWin(true);
        }
    } else {
        cout << "There is nothing to grab.\n\n";
    }
    if (key1 == true && key2 == true && key3 == true) {
        completedKey = true;
    }
}

void Conditions::combineKeys(vector<string>& inventory) {
    int temp = -1, count = 0;
    while (count < 3) {
        if (inventory[inventory.size() - 1] == "Key Piece") {
            inventory.pop_back();
        } else {
            for (unsigned i = 0; i < inventory.size(); i++) {
                if (inventory[i] == "Key Piece" && temp < 0) {
                    temp = i;
                }
            }
            inventory[temp] = inventory[inventory.size() - 1];
            inventory.pop_back();
        }
        count++;
    }
    inventory.push_back("Key");
}

Character::Character() {
    power = 1;
    defense = 0;
    health = 10;
    owlBearHealth = 20;
    owlBearAttack = 6;
}

bool Character::getWin() {
    return cond.getWin();
}
bool Character::getDead() {
    return cond.getDead();
}

bool Character::getCompKey() {
    return cond.getCompKey();
}

bool Character::getAxe() {
    return cond.getAxe();
}
    
bool Character::getShield() {
    return cond.getShield();
}

void Character::callDescription(int position) {
    cond.description(position);
}

void Character::callGrab(vector<string>& inventory, int position) {
    cond.grab(inventory, position);
}

void Character::callListCommands(const vector<string>& commands, int position) {
    cond.listCommands(commands, position);
}

void Character::callMove(string command, int& position) {
    cond.move(command, position);
}

void Character::attack(int position) {
    if (position == 9 && cond.getStick() == false) {
        cout << "The bird pecks at your fingers, and remains in it's nest.\n"
             << "What did you expect to happen?\n";
    } else if (position == 9 && cond.getStick() == true) {
        cout << "You scare the bird away with your stick...jerk\n";
        bool temp = false;
        cond.setBird(temp);
    } else if (position == 3 && cond.getAxe() == true) {
        cout << "You hack through the wall of the cabin, "
             << "revealing an odd object inside.\n";
        bool temp = true;
        cond.setBroken(temp);
    } else if (position == 3 && cond.getAxe() == false) {
        cout << "Nice try Hercules, but this cabin is too tough "
             << "for a bare knuckle beat down.\n";
    } else if (position == 5 && cond.getOwlBear() == true) {
        cout << "You take a swing at the Owl Bear and he swings back.\n";
        combat();
        if (owlBearHealth <= 0) {
            bool temp = false;
            cond.setOwlBear(temp);
            cout << "You defeat the mighty OwlBear!\n";
        } else if (health <= 0) {
            bool temp = true;
            cond.setDead(temp);
        }
    } else if (position == 5 && cond.getOwlBear() == false) {
        cout << "Calm down, There's nothing to attack.\n"
             << "You already killed it...murderer.\n";
    }
}

void Character::addWeapon() {
    power = 5;
}

void Character::addShield() {
    defense = 5;
}

void Character::combat() {
    owlBearHealth -= power;
    health -= owlBearAttack - defense;
    cout << "Health = " << health << endl;
}

void Character::combineKeys(vector<string>& inventory) {
    cond.combineKeys(inventory);
}

void Character::setGod(bool god) {
    cond.setGod(god);
}

void listItems(const vector<string>& inventory) {
    for (unsigned i = 0; i < inventory.size(); i++) {
        cout << inventory[i] << endl;
    }
    cout << endl;
}

void addItem(vector<string>& inventory, int position) {
    if (inventory[0] == "Empty") {
        if (position == 2) {
            inventory[0] = "Stick";
        } else if (position == 3) {
            inventory[0] = "Key Piece";
        } else if (position == 4) {
            inventory[0] = "Shield";
        } else if (position == 6) {
            inventory[0] = "Axe";
        } else if (position == 8) {
            inventory[0] = "Key Piece";
        } else if (position == 9) {
            inventory[0] = "Key Piece";
        } else if (position == 7) {
            inventory[0] = "Special Item";
        }
    } else {
        if (position == 2) {
            inventory.push_back("Stick");
        } else if (position == 3) {
            inventory.push_back("Key Piece");
        } else if (position == 4) {
            inventory.push_back("Shield");
        } else if (position == 6) {
            inventory.push_back("Axe");
        } else if (position == 8) {
            inventory.push_back("Key Piece");
        } else if (position == 9) {
            inventory.push_back("Key Piece");
        } else if (position == 7) {
            inventory.push_back("Special Item");
        }
    }
}