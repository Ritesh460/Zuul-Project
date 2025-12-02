#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include "items.h"
using namespace std;

struct Exit {
  char direction[20];
  class Room* goRoom;
}

class Room {
  private:
    char description[200];
    vector<Exit> exits;
    vector<Items> item;
  public:
    Room(const char* desc);
    const char* getDescription();
    void addExit(const char* direction, Room* neighbor);
    Room* getExit(const char* direction);
    vector<Exit>& getExits();

    void addItem(const Items& item);
    bool hasItem(const char name[]);
    Items dropItem(const char name[]);	    
    vector<Items>& getItems();
};
#endif



