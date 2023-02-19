# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtu.be/VHwymZGM8bM).

## Minimum Requirements

#### 1. MENU PAGE
- user menu
- setting
- customize game board dimensions
- customize number of zombies

#### 2. GAME BOARD
- display game board
- display game objects
- display game characters
- dimensions of game board in odd number
- display row and columns number correctly 
- characters should not move outside the game board
- change arrow direction 

#### 3. ATTRIBUTES
- display attributes
- assign random values to attributes
- each zombie have different attributes
- zombie range lower than dimensions of game board

#### 4. ALIEN ON GAMEBOARD
- alien placed at center of game board
- alien movable
- alien change direction with arrow sign 
- display trail
- trail reset
- alien stop while encounter rock and zombies
- hide a game object under rock

#### 5. ZOMBIES ON GAMEBOARD
- display multiple zombies
- zombie cannot move to locations occupied by other zombies
- remove defeated zombies

#### 6. LIFE AND ATTACK
- alien hit object
- characters take turns to attack

#### 7. GAME COMMAND
- arrow command
- help command
- save game
- load game
- return menu
- quit game
- play again

- game end while zombie or alien win
- handle invalid input



### Completed

List all the features completed.

1.  User Menu
2.  Setting
3.  Customize game board
4.  Customize number of zombies
5.  Display game board
6.  Display game objects
7.  Display game characters
8.  Dimensions of game board in odd number
9.  Number of rows and columns displayed correctly 
10. Characters move inside game board
11. Change arrow direction 
12. Display attributes
13. Random attributes 
14. Each zombie have different attributes 
15. Alien's default position 
16. Alien movement
17. Display trail
18. Multiple zombies
19. Zombie in range
20. Arrow command
21. Help command
22. Return menu
23. Quit game
24. Play again
25. Handle invalid input

### To Do (Incomplete Requirements)

List all the features not yet done. Remove this section if there is no incomplete requirements.

1.  Alien change direction with arrow sign 
2.  Trail reset
3.  Alien stop while encounter rock and zombies
4.  Hide game object under rock
5.  Zombie cannot move to locations occupied by other zombies
6.  Remove defeated zombies
7.  Alien hit object
8.  Characters take turns to attack
9.  Load game
10. Play again 
11. Game end


## Additional Features

Describe the additional features that has been implemented.
#### menu page with start game, setting and quit choices


## Contributions

List down the contribution of each group members.

### Ang Jin Nan

1.  Display setting
2.  Help Command
3.  Quit Game
4.  Display alien attributes randomly
5.  Display trail
6.  Return menu
7.  Save game
8.  Quit game
9.  Handle invallid input
10. Submission Part 1 : Work on code displaying in video demo
11. Submission Part 2 : Work on video demonstration and documentation

### Tai Qi Tong

1.  Display user menu
2.  Display game objects
3.  Number of rows and columns displayed correctly 
4.  Arrow command
5.  Display Alien
6.  Alien movable inside game board
8.  Alien placed at center
9.  Change arrow direction with user command
10. Submission Part 1 : Work on code explaination in video demo
11. Submission Part 2 : Work on video demonstration and documentation

### Tan Xin Yi

1.  Display game board
2.  Customize game board dimensions
3.  Customize number of zombies
4.  Dimensions of game board in odd number
5.  Display zombie
6.  Display zombie attribute randomly 
7.  Zombie attribute in range
8.  Different attributes of each zombies
9.  Display multiple zombies
10. Submission Part 1 : Work on Documentation
11. Submission Part 2 : Work on video demonstration and documentation


## Problems Encountered & Solutions

Describe the problems encountered and provide the solutions / plan for the solutions.

1.  Unable to add zombies into game board                         : Zombies class and board class were linked.
1.  Symbols were printed when assigning zombies in board	   	  : vector<char> were written to fix the zombies figure.
2.  Unable to add alien into the board                            : Alien were linked with setObject function.
3.  Alien cant place at center                                    : Set alien function with equation were written to fix the position at the center of every board.
4.  Alien can't move                                              : Game board were linked with alien movement function.
5.  Unable to change arrow direction                              : Game board were connected with arrow.
6.  Unable to change attribute                                    : hitObject function were linked with game board and characters.
7.  Unable to reset trail with game objects                       : Plan to link the setObject function with trail.
8.  Characters unable to attack                                   : Plan to connect attributes with characters and hitObject function.
9.  Unable to map hit object with the correct coordinate on board : Plan to find the correct coordinate.
10.  Unable to move zombie                                        : Plan to write a zombie movement's function 
11.  Unable to display save game                                  : Game board and zombie were saved but board unable to display, plan to connect board with it.
12. Unable to load game                                           : Since board can't be printed, hence saved game can't be loaded too. No solution :(