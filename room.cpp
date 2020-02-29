/*
*	room.cpp
*	A source file that contains the Room class's member functions
*
****************************************/
#include "proj7.h"


Room::Room() {
	
}
	
Room::Room(int x, int y) {
	isPlayerHere = true;
	//Allocate memory
	xsize = x ;
	ysize = y;
	tilesArr = new Tile**[xsize+2];
	for (int i = 0; i < xsize+ 2; i++) { 
		tilesArr[i] = new Tile*[ysize+2];
	}
	
	//Assign walls
	for (int i=0; i < ysize+2; i++)
    {
    	tilesArr[0][i]=new Wall();
		tilesArr[0][i]->setStatus('*');
		tilesArr[xsize+1][i]=new Wall();
		tilesArr[xsize+1][i]->setStatus('*');
    }
	for (int i=0; i < xsize+2; i++)
    {
		tilesArr[i][0]=new Wall();
		tilesArr[i][0]->setStatus('*');
		tilesArr[i][ysize+1]=new Wall();
		tilesArr[i][ysize+1]->setStatus('*');
    }
	for(int i=1; i < xsize+1; i++) {
		for(int j=1; j < ysize+1; j++) {
			tilesArr[i][j] = new Tile();
		}
	}
		
}

Room::~Room() {
	printf("Room destrucor has been called\n");
}

char Room::getTile(int x, int y) {
	return tilesArr[x][y]->getStatus();
}

bool Room::getIsPlayerHere() {
	return isPlayerHere;
}

bool Room::getIsVisited(int x, int y) {
	return tilesArr[x][y]->getIsVisited();
}

int Room::getChest(int x, int y) {
	return tilesArr[x][y]->getAmount();
}

char* Room::getFileName(int x, int y) {
	return tilesArr[x][y]->getName();
}

int Room::getXSize() {
	return xsize;
}

int Room::getYSize() {
	return ysize;
}

void Room::setIsPlayerHere(bool p) {
	isPlayerHere = p;
}

void Room::setIsVisited(int x, int y, bool p) {
	tilesArr[x][y]->setIsVisited(p);
}

void Room::setIsPushed(int x, int y, bool p) {
	tilesArr[x][y]->setIsPushed(p);
}
		
void Room::printRoom() {	
	for(int j = 0; j < ysize+2; j++) {
		for(int i = 0; i < xsize+2; i++) {
			printf("%c", tilesArr[i][j]->getStatus());
		}
		printf("\n");
	}
}

void Room::setTiles(int x, int y, char c) {
	tilesArr[x][y]=new Tile();
	tilesArr[x][y]->setStatus(c);
}

void Room::setChest(int x, int y, char c, int a) {
	tilesArr[x][y] = new Chest(a);
	tilesArr[x][y]->setStatus(c);
	printf("Chest has %d\n", tilesArr[x][y]->getAmount());
}
void Room::setDoor(int x, int y, char c, char* n) {
	tilesArr[x][y] = new Door(n);
	tilesArr[x][y]->setStatus(c);
	printf("door's file name is  %s\n", tilesArr[x][y]->getName());
}

void Room::resetRoom(int x, int y) {
	//deallocate tiles
	for (int i = 0; i < xsize+ 2; i++) { 
		delete[] tilesArr[i];
	}
	delete[] tilesArr;
	
	//update xsize and ysize
	xsize = x;
	ysize = y;
	
	//reallocate tiles if size is more than zero
	if(xsize > 0 && ysize > 0) {
		tilesArr = new Tile**[xsize+2];
		for (int i = 0; i < xsize+ 2; i++) { 
			tilesArr[i] = new Tile*[ysize+2];
		}
		
		//Assign walls
		for (int i=0; i < ysize+2; i++)
	    {
	    	tilesArr[0][i]=new Wall();
			tilesArr[0][i]->setStatus('*');
			tilesArr[xsize+1][i]=new Wall();
			tilesArr[xsize+1][i]->setStatus('*');
	    }
		for (int i=0; i < xsize+2; i++)
	    {
			tilesArr[i][0]=new Wall();
			tilesArr[i][0]->setStatus('*');
			tilesArr[i][ysize+1]=new Wall();
			tilesArr[i][ysize+1]->setStatus('*');
	    }
		for(int i=1; i < xsize+1; i++) {
			for(int j=1; j < ysize+1; j++) {
				tilesArr[i][j] = new Tile();
			}
		}	
	}
}

void Room::setAllTilesUnvisited() {
	for(int j = 0; j < ysize+2; j++) {
		for(int i = 0; i < xsize+2; i++) {
			tilesArr[i][j]->setIsVisited(false);
		}
	}
}
bool Room::dfs(int x, int y) {
	while(true) {
		//printf("dfs: currently processing %d, %d\n", x, y);
		//stack.show();
		
		//Go down if not blocked nor visited
		 if(tilesArr[x][y+1]->getStatus() != '*' && tilesArr[x][y+1]->getIsVisited() == false) {
			
			//push location
			//if(tilesArr[x][y]->getIsPushed() == false) {
				stack.insert(x,y);
			//	tilesArr[x][y]->setIsPushed(true);
			//}
			
			//go down
			y = y + 1;
			//mark new location as visited
			tilesArr[x][y]->setIsVisited(true);
		}
		
		//Go up if not blocked nor visited
		else if(tilesArr[x][y-1]->getStatus() != '*' && tilesArr[x][y-1]->getIsVisited() == false) {
			//push location
			//if(tilesArr[x][y]->getIsPushed() == false) {
				stack.insert(x,y);
			//	tilesArr[x][y]->setIsPushed(true);
			//}
			//go up
			y = y - 1;
			//mark new location as visited
			tilesArr[x][y]->setIsVisited(true);
		}	
			
		//Go right if not blocked nor visited
		else if(tilesArr[x+1][y]->getStatus() != '*' && tilesArr[x+1][y]->getIsVisited() == false) {
			//push location
			//if(tilesArr[x][y]->getIsPushed() == false) {
				stack.insert(x,y);
			//	tilesArr[x][y]->setIsPushed(true);
			//}
			//go right
			x = x + 1;
			//mark new location as visited
			tilesArr[x][y]->setIsVisited(true);
		}
		
		//Go left if not blocked nor visited
		else if(tilesArr[x-1][y]->getStatus() != '*' && tilesArr[x-1][y]->getIsVisited() == false) {
			//push location
			//if(tilesArr[x][y]->getIsPushed() == false) {
				stack.insert(x,y);
			//	tilesArr[x][y]->setIsPushed(true);
			//}
			//go left
			x = x - 1;
			//mark new location as visited
			tilesArr[x][y]->setIsVisited(true);
		}
			
			
		//Else, pop the stack and take a step back
		else {
			//printf("stack elements are: %d\n", stack.getListLength());
			//If the stack is empty, then there is no solution
			if(stack.getListLength() == 0) {
				printf("There is no door in this room.\n");
				break;
			}
				//pop the stack and take a step back
			else {
				stack.pop();
				if(stack.getListLength() != 0) {
					x = stack.getX();
					y = stack.getY();	
				}
			}
			
			/*
			//check if all positions have been checked, otherwise run dfs again
			else if (tilesArr[x][y+1]->getStatus() != '*' && tilesArr[x][y+1]->getIsVisited() == false) {
				this->dfs(x,y);
			}
			else if(tilesArr[x][y-1]->getStatus() != '*' && tilesArr[x][y-1]->getIsVisited() == false) {
				this->dfs(x,y);
			}
			else if(tilesArr[x+1][y]->getStatus() != '*' && tilesArr[x+1][y]->getIsVisited() == false) {
				this->dfs(x,y);
			}
			else if(tilesArr[x-1][y]->getStatus() != '*' && tilesArr[x-1][y]->getIsVisited() == false) {
				this->dfs(x,y);
			} */
		
			
		}
		//break the loop when the end has been reached
		if(tilesArr[x][y]->getStatus() == 'D') {
				//print solution
				printf("Solution path to a door using DFS is the following:\n");
				stack.show();
				break;
		}
	}
}

void Room::resetStack() {
	stack.removeAll();
}
//MyLNode methods
MyLNode::MyLNode (int px, int py)
{
  x = px;
  y = py;
  next = NULL;
}
  
MyLNode::MyLNode (int px, int py, MyLNode* n)
{
  x = px;
  y = py;
  next = n;
}

void MyLNode::setElem (int px, int py)
{
  x = px;
  y = py;
}

int MyLNode::getX ()
{
  return x;
}

int MyLNode::getY ()
{
  return y;
}

void MyLNode::setNext (MyLNode* n)
{
  next = n;
}

MyLNode* MyLNode::getNext()
{
  return next;
}



//  Methods for the MyList class
MyList::MyList()
{
  head = NULL;
}

MyList::MyList ( const MyList &p)   //LINE 95
{
 //head = p.head;    // This code does Shallow Copy
 makeCopy (p);       // This code does a Deep Copy
}

int MyList::getX() {
	return head->getX();
}

int MyList::getY() {
	return head->getY();
}

// Code to make a copy of a list - doing a Deep Copy
//   This code uses the recursive method of copyNode()
//   copyNode() should be private since it is intended to only
//   be called by makeCopy()
void MyList::makeCopy ( const MyList &p)
{
 head = NULL;
 copyNode (p.head);
} 
 
void MyList::copyNode (MyLNode* pNode)
{
  if (pNode != NULL)
  {
    copyNode ( pNode->getNext() );

    // insert nodes at the front of the list while returning
    //   from the recursive calls  (adds values to the front
    //   in reverse order - this copies the list on O(n) time
    head = new MyLNode ( pNode->getX(), pNode->getY(), head );
  }
}

// method to print out all of the values in the list
void MyList::show()
{
  this->printRec(head);
  
  /*while ( tmp != NULL )
  {
    printf ("(%d, %d)", tmp->getX(), tmp->getY() );
    tmp = tmp->getNext();
  }*/
  printf ("\n");
}

void MyList::printRec(MyLNode* hd) {
	MyLNode* tmp = hd;
	
	if(tmp == NULL) {
		return;
	} else {
		this->printRec(tmp->getNext());
		printf ("(%d, %d)", tmp->getX(), tmp->getY() );
	}
}

void MyList::insert (int px, int py)
{
  MyLNode* tmp = new MyLNode (px, py);
  
  // this code just inserts the node at the beginning of the list
  tmp->setNext (head);
  head = tmp;

  /*the following code insert the node in increasing order in the list
  MyLNode* curr = head;
  MyLNode* prev = NULL;
  
  while ( ( curr != NULL ) && ( curr->getElem() < v1 ) )
  {
    prev = curr;
    curr = curr->getNext();
  }

  // set the next pointer in the new node to point to curr
  tmp->setNext ( curr );

  if ( prev == NULL ) // v1 becomes the in first/head node in list
    head = tmp;
  else
    prev->setNext( tmp ); */
}

void MyList::pop () {
	head = head->getNext();
}

void MyList::remove (int px, int py)
{
  MyLNode* curr = head;
  MyLNode* prev = NULL;
  
  while ( ( curr != NULL ) && ( curr->getX() != px ) && ( curr->getY() != py ) )
  {
    prev = curr;
    curr = curr->getNext();
  }

  if ( curr == NULL ) // v1 does not exist in list
    return;

  if ( prev == NULL ) // v1 is in first/head node in list
  {
    head = curr->getNext();
    delete curr;
  }
  else
  {
    prev->setNext( curr->getNext() );
    delete curr;
  }
}

  

void MyList::removeAll ()
{
  MyLNode* tmp = head;
  
  while ( tmp != NULL )
  {
    MyLNode* tmp2 = tmp;
    tmp = tmp->getNext();
    delete tmp2;
  }
  head = NULL;
}

MyList::~MyList()
{
  // doing a show() so we can see when the destructor is called
  printf ("In Destructor: ");

  // Note that removeAll() does same operation as required by destructor
  removeAll();
}

// the overloaded assignment operator
//
MyList& MyList::operator= (const MyList& p)
{
 if ( this == &p )   // both operands are the same
   return *this;     //   do nothing, just return

 removeAll();        // Deallocate the existing list

 makeCopy (p);       // Do a deep copy

 return *this;       // allow for "cascading assignments":  a = b = c;
}


int MyList::getListLength() {
  MyLNode* tmp = head;
  int n = 0;
  
  while ( tmp != NULL )
  {
    n++;
    tmp = tmp->getNext();
  }
  
  return n;
}

int MyList::getNthValueX(int n) {
  MyLNode* tmp = head;
  
  for(int i = 0; i < n; i++)
  {
    tmp = tmp->getNext();
  }
  
  return tmp->getX();	
}

