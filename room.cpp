#include "room.h"

Room::Room(const char* desc) {
  strcpy(description,desc);
}

const char* getDescription() {
  return description;
}

void Room::addExit(const char* direction, Room* neighbor) {
  Exit e;
  strcpy(e.direction,direction);
  e.goRoom = neighbor;
  exits.push_back(e);
}

Room* Room::getExit(const char* direction) {
  for (int i = 0; i < exits.size(); i++) {
    if (strcmp(exits[i].direction, direction) == 0) {
      return exits[i].toRoom;
    }
  }
}

vector<Exit>& Room::getExits() {
  return exits;
}

void Room::addItem(const Items& item) {
  items.push_back(item);
}

bool Room::hasItem(const char name[]) {
 for (int i = 0; i< items.size(); i++) {
   if (strcmp(items[i].name, name) == 0) {
     return true;
   }
 }
}

Items dropItem(const char name[]) {
  for (int i = 0; i < items.size(); i++) {
    if (strcmp(items[i].name, name) == 0) {
      Item temp = items[i];
      items.erase(items.begin() + i);
      return temp;
    }
  }
  
  Item notFound;
  strcpy(NotFound.name, "NULL");
  return notFound;
}

vector<Items>& Room::getItems() {
  return items;
}

