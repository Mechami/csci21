/*
 * Name        : lab_3.cpp
 * Author      : Philip Muzzall
 * Description : Using branching statements, looping statements and string and
 *               character functions complete the functions
 */

#include "lab_3.h"

/*
 * Tell the story of Goldilocks. For example, if item is "bed" and number is 1,
 * the story will say "This bed is too soft". "item" parameter will be passed
 * in as all lowercase characters
 * Cases:
 * -item: "porridge", number: 1, return "This porridge is too hot"
 * -item: "porridge", number: 2, return "This porridge is too cold"
 * -item: "porridge", number: 3, return "This porridge is just right"
 * -item: "chair", number: 1, return "This chair is too big"
 * -item: "chair", number: 2, return "This chair is too small"
 * -item: "chair", number: 3, return "This chair is just right"
 * -item: "bed", number: 1, return "This bed is too hard"
 * -item: "bed", number: 2, return "This bed is too soft"
 * -item: "bed", number: 3, return "This bed is just right"
 * @param string item - Represents the item in the story ("porridge", "chair",
 *                      and "bed" are the only legal values -- will default to
 *                      "bed" on invalid argument)
 * @param int number - which item (1, 2, and 3 are the only legal values -- will
 *                     default to 3 on invalid argument)
 * @return string - The output string specified in the documentation above
 */

string Goldilocks(string item, int number) {
  string ptemps[3] = {
  "This porridge is too hot",
  "This porridge is too cold",
  "This porridge is just right"
  };

  string csizes[3] = {
  "This chair is too big",
  "This chair is too small",
  "This chair is just right",
  };

  string bfirms[3] = {
  "This bed is too hard",
  "This bed is too soft",
  "This bed is just right",
  };

  string result = "";
  bool valid = (number < 4 && number > 0);
  int choice = number - 1;

  if (item == "porridge") {
    result = valid? ptemps[choice] : ptemps[2];
  } else if (item == "chair") {
    result = valid? csizes[choice] : csizes[2];
  } else {
    result = valid? bfirms[choice] : bfirms[2];
  }

  return result;
}

/*
 * Compute the outcome of a round of a rock-scissor-paper game. Lowercase or
 * uppercase values for player_one and player_two arguments are acceptable.
 * Possible inputs: 'R' rock, 'S' scissor, 'P' paper
 * Conditions
 * -rocks beats scissors
 * -scissors beats paper
 * -paper beats rock
 * @param char player_one - Represents player one's "play" ('R', 'S', or 'P')
 * @param char player_two - Represents player two's "play" ('R', 'S', or 'P')
 * @return int - 1 if player one wins, 2 if player two wins, 3 on a draw,
 *               0 if invalud inputs
 */
int RockScissorPaper(char player_one, char player_two) {
  int ply1choice = static_cast<int>(tolower(player_one));
  int ply2choice = static_cast<int>(tolower(player_two));
  int winnermode = 0;

  switch (ply1choice)
  {
    case 0x70:
    {
      if (ply2choice == 0x72) {
        winnermode = 1;
      } else if (ply2choice == 0x73) {
        winnermode = 2;
      } else if (ply2choice == 0x70) {
        winnermode = 3;
      }

      break;
    }
    case 0x72:
    {
      if (ply2choice == 0x73) {
        winnermode = 1;
      } else if (ply2choice == 0x70) {
        winnermode = 2;
      } else if (ply2choice == 0x72) {
        winnermode = 3;
      }

      break;
    }
    case 0x73:
    {
      if (ply2choice == 0x70) {
        winnermode = 1;
      } else if (ply2choice == 0x72) {
        winnermode = 2;
      } else if (ply2choice == 0x73) {
        winnermode = 3;
      }

      break;
    }
    default:
    {
      // Do nothing
      break;
    }
  }

  return winnermode;
}

/*
 * Return the input string with all characters converted to lowercase.
 * @param string input - The string that will be converted to all lowercase
 * @return string - a string containing the converted input string
 */
string ToLower(string input) {
  for (size_t i = 0; i < input.length(); i++)
  {
    if (isupper(input[i])) {
      input[i] = tolower(input[i]);
    }
  }

  return input;
}

/*
 * Return the input string with all characters converted to uppercase.
 * @param string input - The string that will be converted to all uppercase
 * @return string - a string containing the converted input string
 */
string ToUpper(string input) {
  for (size_t i = 0; i < input.length(); i++)
  {
    if (islower(input[i])) {
      input[i] = toupper(input[i]);
    }
  }

  return input;
}
