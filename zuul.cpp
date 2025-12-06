#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
using namespace std;

int main () {
//room instances
  Room* Room205 = new Room("This is Room 205, one of the five boring office rooms. The walls are peeling.");
  Room* Room206 = new Room("This is Room 206, one of the five boring office rooms. There is a coffee machine.");
  Room* Room207 = new Room("This is Room 207, one of the five boring office rooms. Two people are arguing about phones.");
  Room* Room208 = new Room("This is Room 208, one of the five boring office rooms. The couches are very green.");
  Room* Room209 = new Room("This is Room 209, one of the five boring office rooms. Someone is eating a banana.");
  Room* PublicSpace = new Room("This is the public space, people are chatting all around. There are some lawyers and convicts talking with eachother.");
  Room* CouncilChamber = new Room("This is the council chamber, 20 council members are discussing taxes that need to be eliminated");
  Room* Looter = new Room("There is a looter in this deep alleyway. They try to steal your stuff but you block them easily. However, they drop something blue.");
  Room* Outskirts = new Room("You are now in the outskirts of the city. Any further from here is illegal. Do you dare to go?");
  Room* GlitchyStreet = new Room("You ventured toward the glitchy street. Cars are split in half and floating in the air. The street is seperated and moving constantly. There is nobody here.");
  Room* TheHole = new Room("You went even more and now see a massive sinkhole. It is surrounded by orange flower petals.");
  Room* TownHall = new Room("A wedding is taking place in the town hall right now. You sneak in and take some cake.");
  Room* CedarStreet = new Room("This street has several cedar trees that the sidewalk is almost hard to cross.");
  Room* GemShop = new Room("This gemshop cuts gems in order to show their true beauty, not the raw.");
  Room* OakStreet = new Room("This is Oak street, it has a roundabout in the middle where a Grand Oak Tree stands. Many people go here for a tourist destination.");
  Room* RedHouse = new Room("This is an abandoned barn that is falling apart. You thought ruby key would be here lol.");
  Room* YellowHouse = new Room("This is your neighbor's house. They invite you in and you see a whole display of yellow keys.");
  Room* Home = new Room("This is your house. You are a regular person who does regular things.");
  Room* Dog = new Room("This is your dog's room, your dog is barking constantly. However, it starts speaking English and states that you need to bring 5 keys and drop them at the dog.");
  Room* ElmStreet = new Room("This is Elm Street, it is very chaotic. Parades happen every single week on a Friday.");
  Room* PetStore = new Room("This is the pet store, it gives you memories of when you first bought your dog.");
  Room* Grocery = new Room("This is the grocery, it is where you get all your food. The produce is fresh as usual. However, a tomato is a bit shinier than usual.");
  Room* Arcade = new Room("The arcade is where most of the 10 year olds go. You can see a disgruntled employee that looks like they may faint");
//room directions
  Room205->addExit("NORTH", Room208);
  Room205->addExit("WEST", Room206);
  Room205->addExit("SOUTH", CouncilChamber);
  
  Room206->addExit("EAST", Room205);
  Room206->addExit("NORTH", Room207);

  Room207->addExit("SOUTH", Room206);
  Room207->addExit("EAST", Room208);
  Room207->addExit("WEST", Room209);

  Room208->addExit("WEST", Room207);
  Room208->addExit("SOUTH", Room205);

  Room209->addExit("EAST", Room207);
  
  PublicSpace->addExit("EAST", CouncilChamber);

  CouncilChamber->addExit("WEST", PublicSpace);
  CouncilChamber->addExit("SOUTH", TownHall);
  CouncilChamber->addExit("NORTH", Room205);

  Looter->addExit("EAST", Outskirts);
  Looter->addExit("SOUTH", ElmStreet);

  Outskirts->addExit("WEST", Looter);
  Outskirts->addExit("SOUTH", GlitchyStreet);

  GlitchyStreet->addExit("SOUTH", TheHole);
  GlitchyStreet->addExit("NORTH", Outskirts);

  TheHole->addExit("NORTH", GlitchyStreet);
  
  TownHall->addExit("NORTH", CouncilChamber);
  TownHall->addExit("SOUTH", CedarStreet);

  CedarStreet->addExit("NORTH", TownHall);
  CedarStreet->addExit("SOUTH", GemShop);
  CedarStreet->addExit("WEST", OakStreet);

  GemShop->addExit("NORTH", CedarStreet);

  OakStreet->addExit("NORTH", RedHouse);
  OakStreet->addExit("EAST", CedarStreet);
  OakStreet->addExit("SOUTH", Home);
  OakStreet->addExit("WEST", ElmStreet);

  RedHouse->addExit("SOUTH", OakStreet);
  RedHouse->addExit("NORTH", YellowHouse);

  YellowHouse->addExit("SOUTH", RedHouse);

  Home->addExit("NORTH", OakStreet);
  Home->addExit("WEST", Dog);

  Dog->addExit("EAST", Home);

  ElmStreet->addExit("EAST", OakStreet);
  ElmStreet->addExit("WEST", PetStore);
  ElmStreet->addExit("SOUTH", Arcade);
  ElmStreet->addExit("NORTH", Looter);

  PetStore->addExit("EAST", ElmStreet);
  PetStore->addExit("NORTH", Grocery);
  
  Grocery->addExit("SOUTH", PetStore);
  
  Arcade->addExit("NORTH", ElmStreet);  

  Items rubyKey; 
  strcpy(rubyKey.name, "rubyKey");
  Items topazKey; 
  strcpy(topazKey.name, "topazKey");
  Items citrineKey; 
  strcpy(citrineKey.name, "citrineKey");
  Items emeraldKey; 
  strcpy(emeraldKey.name, "emeraldKey");
  Items sapphireKey; 
  strcpy(sapphireKey.name, "sapphireKey");
  
  Grocery->addItem(rubyKey);
  TheHole->addItem(topazKey);
  YellowHouse->addItem(citrineKey);
  Room208->addItem(emeraldKey);
  Looter->addItem(sapphireKey);

  Room* winningRoom = Dog; 

  vector<Items> inventory;
  Room* current = Home;  
//beginning lines with directions and commands
  cout << "Welcome to the Sentience!" << endl;
  cout << "Your goal: Find all 5 keys(ruby,topaz,citrine,emerald,and sapphire) and drop them into the DOG room." << endl;
  cout << "Commands: GO <direction>, GET <item>, DROP <item>, INVENTORY, QUIT:" << endl;
  char command[50];
//bool statement
  bool running = true;
//while loop for text adventure
  while (running) {
    //space line to make game neater and get description   
    cout << "\n-------------------------------------\n";
    cout << current->getDescription() << "\n";

    //show exits
    cout << "Exits: ";
    for (auto &e : current->getExits()) {
      cout << e.direction << " ";
    }
        cout << endl;

    //show items in room
    cout << "Items here: ";
    if (current->getItems().size() == 0) {
      cout << "None";
    }
    else {
      for (auto &i : current->getItems())
        cout << i.name << " ";
    }
    cout << endl;

    cout << "> ";
    cin.getline(command, 50);

    //parsing
    char first[20];
    char second[20];
    first[0] = second[0] = '\0';
    sscanf(command, "%s %s", first, second); //for this part I was confused how to parse so I search up how to place words together and it states the sscanfcommand is vital
    //QUIT 
    if (strcmp(first, "QUIT") == 0) {
      cout << "Thank you for playing";	    
      running = false;
    }
    //GO (movement)
    if (strcmp(first, "GO") == 0) {
      Room* next = current->getExit(second);
      if (next == nullptr) {
        cout << "You can't go that way.\n";
      } else {
        current = next;
      }
    }

    //GET (pick up item)
    else if (strcmp(first, "GET") == 0) {
      bool found = false;
      auto &items = current->getItems();

      for (int i = 0; i < items.size(); i++) {
        if (strcmp(items[i].name, second) == 0) {
          inventory.push_back(items[i]);
          items.erase(items.begin() + i);
          cout << "Picked up " << second << endl;
          found = true;
          break;
        }
      }
      if (!found) cout << "Item not found here.\n";
    }

    //DROP (drop item)
    else if (strcmp(first, "DROP") == 0) {
      bool dropped = false;

      for (int i = 0; i < inventory.size(); i++) {
        if (strcmp(inventory[i].name, second) == 0) {
          current->addItem(inventory[i]);
          inventory.erase(inventory.begin() + i);
          cout << "Dropped " << second << endl;
          dropped = true;
          break;
        }
      }
      if (!dropped) cout << "You don't have that item.\n";
    }

    //INVENTORY
    else if (strcmp(first, "INVENTORY") == 0) {
      cout << "Your inventory: ";
      if (inventory.size() == 0) {
        cout << "Empty.\n";
      } else {
        for (auto &i : inventory)
          cout << i.name << " ";
        cout << endl;
      }
    }

    //WIN CONDITION 
    if (current == winningRoom) {
      int count = 0;
      for (auto &i : current->getItems()) {
        if (strcmp(i.name, "rubyKey") == 0 ||
            strcmp(i.name, "topazKey") == 0 ||
            strcmp(i.name, "citrineKey") == 0 ||
            strcmp(i.name, "emeraldKey") == 0 ||
            strcmp(i.name, "sapphireKey") == 0) {
          count++;
        }
      }
      if (count == 5) {
        cout << "\nYOU WIN! Your dog thanks you for bringing all 5 keys to the vault, and stops its irrational behavior. Will that happen again?\n";
        running = false;
      }
    }

  }
} 
