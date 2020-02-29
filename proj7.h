/*
*	proj7.h
*	A header file for a Dungeon Crawler game
*
****************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>

// Global variables

// Classes and structs
class Tile
{
	private:
		bool isPlayerHere;
		bool isVisited;
		bool isPushed;
		char status;
		
	public:	
		Tile();
		~Tile();
		virtual int getAmount();
		virtual char* getName();
		bool getIsPlayerHere();
		bool getIsVisited();
		bool getIsPushed();
		char getStatus();
		void setStatus(char c);
		void setIsPlayerHere(bool p);
		void setIsVisited(bool p);
		void setIsPushed(bool p);
};

class Chest : public Tile
{
	private:
		int amount;
	public:		
		Chest();
		Chest(int a);
		int getAmount();
		void setAmount(int a);
};

class Door : public Tile
{
	private:
		char* name;
	public:	
		Door();
		Door(char* name);
		char* getName();
		void setName(char* n);		
};

class Wall : public Tile
{
	private:
	public:	
		Wall();	
};

/*class MyNode 
{
	private:
		Tile* tile;
		char move;
		MyNode* pNext;
		
	public:	
		MyNode() {
			
		}
	
		void pushNode (MyNode ** hd, Tile* t, char m) {
			MyNode* ptr = (MyNode*) malloc (sizeof(MyNode));
		 	ptr->tile = t;
		 	ptr->move = m;
		 	ptr->pNext = *hd;       // note that hd must be "de-referenced" when used 
		 	*hd = ptr;             //   the unary * operator is the "de-reference" operator 	
		}
		
		void popNode (MyNode** hd)
		{
		 MyNode* ptr = *hd;
		
		 if (ptr != NULL)
		   {
		    *hd = ptr->pNext; 
		    free (ptr);
		   }
		}
		
		void printSolution (MyNode* hd)
		{
		  if(hd == NULL) {
		 	return;
		  }
		  else {
		  	printSolution(hd->pNext);
		  	printf ("->%c\n", hd->move);   // access the value at the node 
		  	return;
		  }
		 printf ("\n");
		}
		
		bool isEmpty (MyNode* hd)
		{
			if (hd == NULL) {
			 	return true;
			 }  
			 else {
			 	return false;
			}  
		}
};*/

class MyLNode
{
 private:
  int x;
  int y;
  MyLNode* next;
  
 public:
  MyLNode (int px, int py);
  MyLNode (int px, int py, MyLNode* n);
  
  void setElem (int px, int py);
  int getX ();
  int getY();
  void setNext (MyLNode* n);
  MyLNode* getNext();
};

// the list class for the linked list
//  This contains all of the operations and data for the
//  list as a whole
//  This class relies heavily on the MyLNode class
class MyList
{
 private:
  MyLNode* head;
  void copyNode (MyLNode* pNode);  
  
 public:
  MyList();              // default constructor
  MyList(const MyList&); // copy constructor
  ~MyList();             // destructor   

  int getX();
  int getY();
  void show();
  void printRec(MyLNode* head);
  void insert (int px, int py);
  void pop();
  void remove (int px, int py);
  void removeAll ();
  void makeCopy (const MyList& p);

  MyList& operator= ( const MyList& p);
  int getListLength();
  int getNthValueX(int n);
};

class Room
{
	private:
		int xsize, ysize;
		Tile*** tilesArr; 
		bool isPlayerHere;
		MyList stack;
		
	public:
		Room();
		Room(int x, int y);
		~Room();
		char getTile(int x, int y);
		bool getIsPlayerHere();
		bool getIsPlayerHereTile(int x, int y);
		bool getIsVisited(int x, int y);
		int getChest(int x, int y);
		char* getFileName(int x, int y);
		int getXSize();
		int getYSize();
		void setIsPlayerHere(bool p);
		void setIsPlayerHerePerTile(int x, int y, bool p);
		void setIsVisited(int x, int y, bool p);
		void setIsPushed(int x, int y, bool p);
		void printRoom();
		void setTiles(int x, int y, char c);
		void setChest(int x, int y, char c, int a);
		void setDoor(int x, int y, char c, char* name);
		
		void resetRoom(int x, int y);
		void setAllTilesUnvisited();
		bool dfs(int x, int y);		
		void resetStack();	
};

class Player
{
	private:
		int gold;
		int numTiles;
		int x;
		int y;
	
	public:
		Player();
		int getGold();
		int getNumTiles();
		int getX();
		int getY();
		void addGold(int a);
		void addNumTiles(int t);
		void setX(int px);
		void setY(int py);
		void move(int px, int py);	
};


class Game 
{
	private:
		Room room;
		Player player;
		
	public:
		Game() {
			
		}
		
		Game(int x, int y) {
			room = Room(x, y);
		}
		
		int getPlayerX() {
			return player.getX();
		}
		
		int getPlayerY() {
			return player.getY();
		}
		
		char getTile(int x, int y) {
			return room.getTile(x,y);
		}
		
		int getChestAmount(int x, int y) {
			return room.getChest(x,y);
		}
		
		bool getIsPlayerHere() {
			return room.getIsPlayerHere();
		}
		
		int getScore() {
			return player.getGold();
		}
		
		bool isValidMove(int x, int y);
		
		void setPlayerX(int x) {
			player.setX(x);
		}
		
		void setPlayerY(int y) {
			player.setY(y);
		}
		
		void setPlayerXY(int x, int y) {
			player.move(x,y);
		}
		
		// The main loop for reading file input
		void processRoomCommands (FILE* inFile);
		
		//Depth-First Search Algorithm
		void dfs();
		
		//Deallocate memory and exit
		void exitGame();
		
		/*void setRoom(int x, int y) {
			room = Room(x, y);
		}*/
		
		void printRoom() {
			room.printRoom();
		}
		
		void doMove(int x, int y, int px, int py);
		
		void setTiles(int x, int y, char c) {
			room.setTiles(x, y, c);
		}
};


