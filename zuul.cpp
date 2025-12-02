#include <iostream>
#include <cstring>
#include <vector>
#include "room.cpp"
using namespace std;

void createRooms () {
  Room205 = Room("One of the five boring office rooms. The walls are peeling.");
  Room206 = Room("One of the five boring office rooms. There is a coffee machine.");
  Room207 = Room("One of the five boring office rooms. Two people are arguing about phones.");
  Room208 = Room("One of the five boring office rooms. The couches are very green.");
  Room209 = Room("One of the five boring office rooms. Someone is eating a banana.");
  PublicSpace = Room("People are chatting all around. There are some lawyers and convicts talking with eachother.");
  Council Chamber = Room("20 council members are discussing taxes that need to be eliminated");
  Looter = Room("There is a looter in this deep alleyway. They try to steal your stuff but you block theme easily. However, they drop something blue.");
  Outskirts = Room("You are now in the far edges of the city. Any further from here is illegal. Do you dare to go?");
  GlitchyStreet = Room("You ventured toward the unknown street. Cars are split in half and floating in the air. The street is seperated and moving constantly. There is nobody here.");
  TheHole = Room("You went even more and now see a massive sinkhole. It is surrounded by orange flower petals.");
  TownHall = Room("A wedding is taking place in the town hall right now. You sneak in and take some cake.");
  CedarStreet = Room("This street has several cedar trees that the sidewalk is almost hard to cross.");
  GemShop = Room("This store cuts gems in order to show their true beauty, not the raw.");
  OakStreet = Room("This street has a roundabout in the middle where a Grand Oak Tree stands. Many people go here for a tourist destination.");
  RedHouse = Room("This is an abandoned barn that is falling apart. You thought ruby key would be here lol.");
  YellowHouse = Room("This is your neighbor's house. They invite you in and you see a whole display of yellow keys.");
  Home = Room("This is your house. You are a regular person who does regular things.");
  Dog = Room("Your dog is barking constantly. However, it starts speaking English and states that you need to bring 5 keys and drop them at the dog.");
  ElmStreet = Room("Elm Street is very chaotic. Parades happen every single week on a Friday.");
  PetStore = Room("This store gives you memories of when you first bought your dog.");
  Grocery = Room("This store is where you get all your food. The produce is fresh as usual. However, a tomato is a bit shinier than usual.");
  Arcade = Room("The arcade is where most of the 10 year olds go. You can see a disgruntled employee that looks like they may faint");
  Room205.addExit("", )		  
} 
