#include "room.h" //inherit from h file
//room constrctors -> description, add exit, get exit
Room::Room(const char* desc) {
  strcpy(description,desc);
}

const char* Room::getDescription() {
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
      return exits[i].goRoom;
    }
  }
  return nullptr;
}

vector<Exit>& Room::getExits() {
  return exits;
}
//items -> add item, has item, drop item, vector return
void Room::addItem(const Items& item) {
  items.push_back(item);
}

bool Room::hasItem(const char name[]) {
 for (int i = 0; i< items.size(); i++) {
   if (strcmp(items[i].name, name) == 0) {
     return true;
   }
 }
 return false;
}

Items Room::dropItem(const char name[]) {
  for (int i = 0; i < items.size(); i++) {
    if (strcmp(items[i].name, name) == 0) {
      Items temp = items[i];
      items.erase(items.begin() + i);
      return temp;
    }
  }
  
  Items notFound;
  strcpy(notFound.name, "NULL");
  return notFound;
}

vector<Items>& Room::getItems() {
  return items;
}

