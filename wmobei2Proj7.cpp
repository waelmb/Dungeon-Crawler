/*
*	wmobei2Proj7.cpp
*	A source file that contains main function for a Dungeon Crawler game
*
****************************************/
#include "proj7.h"

void Game::processRoomCommands (FILE* inFile)
{
	char  buffer[300];
	char* input;
	
	input = fgets ( buffer, 300, inFile );   // get a line of input
	
	// loop until all lines are read from the input
	while (input != NULL)
	{
		// process each line of input using the strtok functions 
		char* command;
		command = strtok (input , " \n\t");
		
		//printf ("*%s*\n", command);
		
		if ( command == NULL ) {
			printf ("Blank Line\n");	
		}
		
		else if ( strcmp (command, "q") == 0) {
			/*deallocate tiles
			for(int i = 1; i < size; i++) {
				islands[i].removeAll();	
			}*/
			
			exit(1);	
		}
		//assign starting position
		else if (strcmp (command, "S") == 0) {
			int val1 = 0;
			int val2 = 0;
			
			// get an integer value from the input
			char* next = strtok (NULL, " \n\t");
			if ( next == NULL )
			{
			 printf ("Integer value expected\n");
			 return;
			}
			val1 = atoi ( next );
			if ( val1 == 0 && strcmp (next, "0") != 0)
			{
			 printf ("Integer value expected\n");
			 return;
			}
			
			// get another integer value from the input
			next = strtok (NULL, " \n\t");
			if ( next == NULL )
			{
			 printf ("Integer value expected\n");
			 return;
			}
			val2 = atoi ( next );
			if ( val2 == 0 && strcmp (next, "0") != 0)
			{
			 printf ("Integer value expected\n");
			 return;
			}
			
			//set starting positions
			printf ("Setting starting position at %d %d\n", val1, val2);
			room.setTiles(val1, val2, 'P');
			player.move(val1, val2);
		}
		//assign obstacles
		else if (strcmp (command, "O") == 0) {
			int val1 = 0;
			int val2 = 0;
			
			// get an integer value from the input
			char* next = strtok (NULL, " \n\t");
			if ( next == NULL )
			{
			 printf ("Integer value expected\n");
			 return;
			}
			val1 = atoi ( next );
			if ( val1 == 0 && strcmp (next, "0") != 0)
			{
			 printf ("Integer value expected\n");
			 return;
			}
			
			// get another integer value from the input
			next = strtok (NULL, " \n\t");
			if ( next == NULL )
			{
			 printf ("Integer value expected\n");
			 return;
			}
			val2 = atoi ( next );
			if ( val2 == 0 && strcmp (next, "0") != 0)
			{
			 printf ("Integer value expected\n");
			 return;
			}
			
			//set obstacles
			printf ("Setting an obstacle at %d %d\n", val1, val2);
			room.setTiles(val1, val2, '*');	
		}
		//assign chests
		else if (strcmp (command, "C") == 0) {
			int val1 = 0;
			int val2 = 0;
			int val3 = 0;
			
			// get an integer value from the input
			char* next = strtok (NULL, " \n\t");
			if ( next == NULL )
			{
			 printf ("Integer value expected\n");
			 return;
			}
			val1 = atoi ( next );
			if ( val1 == 0 && strcmp (next, "0") != 0)
			{
			 printf ("Integer value expected\n");
			 return;
			}
			
			// get another integer value from the input
			next = strtok (NULL, " \n\t");
			if ( next == NULL )
			{
			 printf ("Integer value expected\n");
			 return;
			}
			val2 = atoi ( next );
			if ( val2 == 0 && strcmp (next, "0") != 0)
			{
			 printf ("Integer value expected\n");
			 return;
			}
			
			// get another integer value from the input
			next = strtok (NULL, " \n\t");
			if ( next == NULL )
			{
			 printf ("Integer value expected\n");
			 return;
			}
			val3 = atoi ( next );
			if ( val3 == 0 && strcmp (next, "0") != 0)
			{
			 printf ("Integer value expected\n");
			 return;
			}
			
			//set obstacles
			printf ("Setting a chest at %d %d with the value %d\n", val1, val2, val3);
			//room.setTiles(val1, val2, 'C');	
			room.setChest(val1, val2, 'C', val3);
		}
		//assign doors
		else if (strcmp (command, "D") == 0) {
			int val1 = 0;
			int val2 = 0;
			
			// get an integer value from the input
			char* next = strtok (NULL, " \n\t");
			if ( next == NULL )
			{
			 printf ("Integer value expected\n");
			 return;
			}
			val1 = atoi ( next );
			if ( val1 == 0 && strcmp (next, "0") != 0)
			{
			 printf ("Integer value expected\n");
			 return;
			}
			
			// get another integer value from the input
			next = strtok (NULL, " \n\t");
			if ( next == NULL )
			{
			 printf ("Integer value expected\n");
			 return;
			}
			val2 = atoi ( next );
			if ( val2 == 0 && strcmp (next, "0") != 0)
			{
			 printf ("Integer value expected\n");
			 return;
			}
			
			// get a filename from the input
			char* fname = strtok (NULL, "\r\n\t");
			if ( fname == NULL )
			{
				printf ("Filename expected\n");
				return;
			}
			
			//set door
			printf ("Setting a door at %d %d with the file %s\n", val1, val2, fname);
			room.setDoor(val1, val2, 'D', fname);	
		}
		//assign exists
		else if (strcmp (command, "E") == 0) {
			int val1 = 0;
			int val2 = 0;
			
			// get an integer value from the input
			char* next = strtok (NULL, " \n\t");
			if ( next == NULL )
			{
			 printf ("Integer value expected\n");
			 return;
			}
			val1 = atoi ( next );
			if ( val1 == 0 && strcmp (next, "0") != 0)
			{
			 printf ("Integer value expected\n");
			 return;
			}
			
			// get another integer value from the input
			next = strtok (NULL, " \n\t");
			if ( next == NULL )
			{
			 printf ("Integer value expected\n");
			 return;
			}
			val2 = atoi ( next );
			if ( val2 == 0 && strcmp (next, "0") != 0)
			{
			 printf ("Integer value expected\n");
			 return;
			}
			
			//set exit position
			printf ("Setting exit position at %d %d\n", val1, val2);
			room.setTiles(val1, val2, 'E');
		}
		
		input = fgets ( buffer, 300, inFile );   // get the next line of input
		
	}
}

bool Game::isValidMove(int x, int y) {
	//If move is colliding into a wall
	if (room.getTile(x, y) == '*') {
		printf ("You can't move into a wall\n");
		return false;
	}
	//If move is valid
	else {
		return true;
	}
}
void Game::doMove(int x, int y, int px, int py) {
	//do move according to the input
	
	if (room.getTile(x, y) == 'C') {
		int gold = room.getChest(x,y);
		printf ("You're moving into a chest with %d gold\n", gold);
		player.addGold(gold);
		printf ("Player now has %d gold'\n", player.getGold());
		//move the player to the next position
		player.addNumTiles(1);
		player.move(x,y);
		room.setTiles(px, py, ' ');
		room.setTiles(x, y, 'P');		
	}
	//If player is moving into a door
	else if (room.getTile(x, y) == 'D') {
		printf ("You're moving into a door\n");
		//move the player to the next position
		player.addNumTiles(1);
		
		//FIXME
		//open file 
		//Initialization
		FILE *src;
		char buffer[300];
		char* line;
		
		/* Try to open the input file. */
		if ( ( src = fopen( room.getFileName(x, y), "r" )) == NULL )
		{
			printf ( "Can't open input file: %s", room.getFileName(x, y) );
			this->exitGame();
		}
		
		
		/* read in the size, starting and ending positions in the maze */
		//Verify that its a valid input. A vaild input is more than zero.
		int xsize, ysize;
		
		//line = fgets (buffer, 300, src);
		fscanf(src, "%d %d", &xsize, &ysize);
		//printf("%s", line);
		if(xsize <= 0 || ysize <= 0) {
			printf("Inputs %d, %d are out of range for the size of the room.\n", xsize, ysize);
			exit(-1);
		} else {
			printf("Room size is %d by %d.\n", xsize, ysize);
		}
		
		//load a new room 
		room.resetRoom(xsize, ysize);
		 
		//initialize the game
		this->processRoomCommands(src);
		fclose(src);
	}
	//If player is moving into an exit
	else if (room.getTile(x, y) == 'E') {
		printf ("You're moving into an exit\n");
		//FIXME: add tile?
		//report score
		printf ("Your final score is: %d\n", player.getGold());
		printf ("The number of steps is: %d\n", player.getNumTiles());
		
		//exit
		this->exitGame();
	}
	else {
		//move the player to the next position
		player.addNumTiles(1);
		player.move(x,y);
		room.setTiles(px, py, ' ');
		room.setTiles(x, y, 'P');
	}
}

void Game::dfs() {
	//mark all tiles unvisited
	for(int j = 0; j < room.getYSize()+2; j++) {
		for(int i = 0; i < room.getXSize()+2; i++) {
			room.setIsVisited(i, j, false);
			//room.setIsPushed(i, j, false);
		}
	}
	
	room.setIsVisited(player.getX(), player.getY(), true);
	//call dfs
	room.dfs(player.getX(), player.getY());
	
	//reset stack
	room.resetStack();
}

void Game::exitGame() {
	//FIXME
	//deallocate memory
	room.resetRoom(0,0);
	
	//exit
	exit(-1);
}

void showCommands()
{
   printf ("The commands for this project are:\n");
   printf ("  W to move up \n");
   printf ("  A to move to the left\n");
   printf ("  S to move down\n");
   printf ("  D to move to the right\n");
   printf ("  H to show list of commands\n");
   printf ("  G to print a player's score'\n");
   printf ("  F to find a path to a door using DFS and print the path'\n");
   //printf ("  B to find the Shortest path to the nearest door using BFS and print the path'\n");
   printf ("  Q to quit \n");
   printf ("  C in the map is a chest \n");
   printf ("  D in the map is a door \n");
   printf ("  E in the map is an exit \n");
}
 
int main (int argc, char** argv)
{
	//Initialization
	FILE *src;
	char buffer[300];
	char* line;
	
	/* Try to open the input file. */
	if ( ( src = fopen( argv[1], "r" )) == NULL )
	{
		printf ( "Can't open input file: %s", argv[1] );
		exit(-1);
	}
	
	
	/* read in the size, starting and ending positions in the maze */
	//Verify that its a valid input. A vaild input is more than zero.
	int xsize, ysize;
	
	//line = fgets (buffer, 300, src);
	fscanf(src, "%d %d", &xsize, &ysize);
	//printf("%s", line);
	if(xsize <= 0 || ysize <= 0) {
		printf("Inputs %d, %d are out of range for the size of the room.\n", xsize, ysize);
		exit(-1);
	} else {
		printf("Room size is %d by %d.\n", xsize, ysize);
	}
	
	//initialize the game
	Game game(xsize, ysize);
	game.processRoomCommands(src);
	fclose(src);
	
	// call the method that reads and parses the input
	showCommands();
	
	//While player is in the room
	//Event Loop
  	while (true) {
  		//Display the room
		game.printRoom();
		
		//Get user input
		// process each line of input using the strtok functions 
	    char command;
	    scanf ("%s", &command);
	
	    printf ("*%c*\n", command);
	    
	    //quit the game
	    if (command == 'Q') {
	    	game.exitGame();	
		}
		//Move up if possible
		else if (command == 'W') {
			int px = game.getPlayerX();
			int py = game.getPlayerY();
			
			if(game.isValidMove(px, py-1)) {
				printf ("W is valid\n" );
				game.doMove(px, py-1, px, py);
			}
		}
		//Move to the left if possible
		else if (command == 'A') {
			int px = game.getPlayerX();
			int py = game.getPlayerY();
			
			if(game.isValidMove(px-1, py)) {
				printf ("A is valid\n" );
				game.doMove(px-1, py, px, py);
			}
		}
		//Move to down if possible
		else if (command == 'S') {
			int px = game.getPlayerX();
			int py = game.getPlayerY();
			
			if(game.isValidMove(px, py+1)) {
				printf ("S is valid\n" );
				game.doMove(px, py+1, px, py);
			}
		}
		//Move to the right if possible
		else if (command == 'D') {
			int px = game.getPlayerX();
			int py = game.getPlayerY();
			
			if(game.isValidMove(px+1, py)) {
				printf ("A is valid\n" );
				game.doMove(px+1, py, px, py);
			}
		}
		//Display commands
		else if (command == 'H') {
			showCommands();
		}
		//Display score
		else if (command == 'G') {
			printf ("Score is %d\n", game.getScore());
		}
		//find a path to a door using DFS and print the path
		else if (command == 'F') {
			game.dfs();
		}
		//find the Shortest path to the nearest door using BFS and print the path
		else if (command == 'D') {
			
		
		}
		 	
	}
   
  printf ("Goodbye\n");
  return 1;
 }
