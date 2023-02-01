# Alien vs. Zombie

Game Introduction   : 
Alien vs. Zombie is a game that combines puzzle, path-planning and strategy. Players must navigates the path for alien to charge its attack in order to eliminate the zombies. The player will win once the alien defeated all zombies. 

[alienvszombie.jpg](https://drive.google.com/file/d/1_B8DFHVSKUzg1RBCE_Q2ySC21yqygPKZ/view?usp=sharing) <- open by using MMU email account :D

YouTube link [Video Demo](https://youtu.be/lFmwh_RUcJQ)

## Compilation Instructions
1. Input 'gcc -v' to check whether is it the latest version 
2. Change directory to where you save this code
3. To compile and run the code in .exe, input 'g++ main.cpp'

## User Manual

- 3 option will be presented on the main menu. User can either select 'Start Game','Settings' or 'Quit' 
    1. Start Game : Game board will be displayed.
    2. Settings : User will be able to change game board settings.
    3. Quit : User can quit game.

### 1. Start Game 
- The game board will be displayed as a two-dimensional board that contains game characters and objects.
- Game characters involves Alien(User) and Zombies, while the objects involves arrow, health, pod and rock.
- User can input command in order to control the Alien.
    a) up    : Alien will move up.
    b) down  : Alien will move down.
    c) left  : Alien will move left.
    d) right : Alien will move right.
    e) arrow : Switch the direction of an arrow object in the game board. (The player will be asked to enter the row and column of the arrow object
               to switch, followed by the direction of the arrow object to switch to.)
    f) help  : List and describe the commands that the player can use in the game.
    g) save  : Save the current game to a file.(User will be asked to enter the name of the file to save to)
    h) load  : Load a saved game from a file. (User will be asked to enter the name of the file to load from)
- Game Objects can be interact with Alien.
    a) Arrow  : ^ (up), v (down), < (left), > (right)
                ~ Changes Alien’s direction of movement.
                ~ Adds 20 attack to Alien.
    b) Health : h 
                ~ Adds 20 life to Alien.
    c) Pod    : p 
                ~ Instantly inflicts 10 damage to Zombie when hit by Alien.
    d) Rock   : r 
                ~ Hides a game object (except Rock and Trail) beneath it.
                ~ Reveals the hidden game object when hit by Alien.
                ~ Stops the Alien from moving.

### 2. Settings
- User can customize the default game settings. The settings mainly change the board by customizing rows, columns and the number of zombies.

### 3. Quit Game
- Quit the game. User will be asked to confirm his/her decision.

Please DO NOT change the Progress Log below. Leave it as it is.

## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors
- Ang Jin Nan
- Tai Qi Tong
- Tan Xin Yi


