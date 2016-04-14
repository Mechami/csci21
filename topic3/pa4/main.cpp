#include <iostream>
#include <fstream>
#include <cstdlib> // For atoi
#include <cctype> // For isalpha and atoi
#include <ctime> // For clock_t
#include "dlist.h"
using namespace std;

// Explicitly instantiate an DList for string and int
template class DList<string>;
template class DList<int>;

/**
 * @brief RunChairs
 * Runs the musical chairs program
 *
 * @param file_name - The file name to read the list of players and songs from
 */
void RunChairs(const char* file_name);

/**
 * @brief ReadLine
 * Reads a line from the file
 *
 * @param file - The file stream object
 * @return string - A line from the file if good otherwise a blank string
 */
string ReadLine(ifstream& file);

/**
 * @brief PickPlayer
 * Picks a player out of a list using the count variable
 * Wraps around if the count variable is larger than the list length
 *
 * @param list - The list to choose from
 * @param count - The index of the player to pick
 * @return int - An index representing the chosen player
 */
unsigned PickPlayer(DList<string>& list, unsigned count);

/**
 * @brief Sleep
 * Sleeps the current thread for the specified amount of time
 *
 * @param seconds - The amount of time to sleep for
 */
void Sleep(unsigned long seconds);

int main(int argc, char** argv) {
  // If no file name bonk
  if (argc < 2) {
	  cout << "Please specify a filename." << endl;
  }
  // If extra args bonk
  else if (argc > 2) {
	  cout << "Too many arguments; Please specify only the file name." << endl;
  }
  // Otherwise run the chairs
  else {
	  RunChairs(argv[1]);
  }

  return 0;
}

void RunChairs(const char* file_name) {
  // Create lists for the players and songs
  DList<string> players;
  DList<string> eliminated_players;
  DList<int> songs;

  // Create the filestream for input file
  ifstream player_list(file_name);

  // While the filestream is good
  while (player_list.good()) {
	// Read in a line
	string line = ReadLine(player_list);
	// Then insert it into the appropriate list depending on its contents
	isalpha(line[0])? players.insert(line) : songs.insert(atoi(line.c_str()));
  }

  // Then list the players and the number of songs
  cout << "List of Players: " << endl
	   << players.to_string(false) << endl;
  cout << "Number of songs: " << songs.length() << endl;

  // While we have songs to play
  while (songs.length() > 0) {
	// Get the first song in the list
	int song = songs.getFront();
	// Show it to the user
	cout << "Current song is " << song << " seconds long." << endl;
	// Then remove it from the list
	songs.popFront();
	// Next sleep for the duration of the song
	Sleep(song);
	// Pick an odd-man out
	string player = players[PickPlayer(players, song)];
	// Announce that the odd-man out has been eliminated
	cout << player << " has been eliminated." << endl;
	// Remove that player from the list
	players.removeFirst(player);
	// And then add them into the eliminated players list
	eliminated_players.insert(player);
  }

  // After the loop is finished announce the winner
  cout << "The winner is " << players.getFront() << endl;
}

string ReadLine(ifstream& file) {
  // Create our return value
  string line = "";

  // If the file is good
  if (file.good()) {
	// Then read in the line
	file >> line;
  }

  // Then send it back
  return line;
}

unsigned PickPlayer(DList<string>& list, unsigned count) {
  // Create our index
  unsigned index = 0;

  // While the counter is greater than zero
  while (count > 0) {
	// If the index is the same as the size of the list
	// Set it to zero otherwise increment it
	(index == (list.length() - 1))? index = 0 : index++;
	// Decrement the counter
	count--;
  }

  // Return the index back to the caller
  return index;
}

void Sleep(unsigned long seconds) {
  // Cache the initial time here
  clock_t t = clock();

  // Keep looping while the elapsed time from now since function start
  // is not equal to or greater than the specified amount of seconds
  while (static_cast<unsigned long>((clock() - t) / CLOCKS_PER_SEC) < seconds);
}
