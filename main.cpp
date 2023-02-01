// ***************************************************************************************************************** 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT8L 
// Names: ANG JIN NAN | TAI QI TONG | TAN XIN YI 
// IDs: 1211100925 | 1211102777 | 1211100903 
// Emails: 1211100925@student.mmu.edu.my | 1211102777@student.mmu.edu.my | 1211100903@student.mmu.edu.my 
// Phones: 0162601883 | 0105610242 | 0108410773 
// ***************************************************************************************************************** 

// #include "pf/helper.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;  
// using namespace pf;

class Board
{
    private:
        vector<vector<char>> map_;
        int dimX_, dimY_;

    public:
        Board(int dimX_ = 99, int dimY_ = 99);
        void init(int dimX, int dimY);
        void display(int dimX, int dimY);
        int getDimX() const;
        int getDimY() const;
        char getObject(int x, int y) const;
        void setObject(int x, int y, char ch);
};

class Alien
{
    private:
        int x_, y_;
        char alien_;

    public: 
        Alien();
        void landAlien(Board &board);
        int getX();
        int getY();
        char getDirection();
    
};

class Zombie
{
    // private:
    //     vector<int> numOfZombies{};
    //     vector<int> zombieLife{};
    //     vector<int> zombieAttack{};
    //     vector<int> zombieRange{};

    public:
        int id;
        int life;
        int attack;
        int range;
        int number;
        int xPos;
        int yPos;
};

// board
int Board::getDimX() const
{
    return dimX_;
}

int Board::getDimY() const
{
    return dimY_;
}

Board::Board(int dimX, int dimY)
{
    init(dimX, dimY);
}

void Board::init(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', 'h', '>', 'r', 'p', '<', '^', 'v'};
    int noOfObjects = 13; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}

void Board::display(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    cout << " -------------------------------" << endl;
    cout << " =        Alien VS Zombie      =" << endl;
    cout << " -------------------------------" << endl;
    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (i + 1);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j) // j==0...14
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl;
}

char Board::getObject(int x, int y) const
{
    return map_[-(y - 5)][x - 1];
}

void Board::setObject(int x, int y, char ch)
{
    map_[-(y - 5)][x - 1] = ch;
}

// Functions:
void displayMenu()
{
    system("cls");
    cout << " _______________________" << endl;
    cout << "|   Alien vs. Zombie   |" << endl;
    cout << "|----------------------|" << endl;
    cout << "| Select:              |" << endl;
    cout << "| 1 => Start Game      |" << endl;
    cout << "| 2 => Settings        |" << endl;
    cout << "|----------------------|" << endl;
    cout << "| Q => Quit            |" << endl;
    cout << "|______________________|" << endl;
    cout << endl;
}

void displayDefaultSetting(int &rows, int &columns, int &zombie)
{
    system("cls");
    cout << "Default Game Settings" << endl;
    cout << "---------------------" << endl;
    cout << "Board Rows        : " << rows << endl;
    cout << "Board Columns     : " << columns << endl;
    cout << "Zombie Count      : " << zombie << endl;

    cout << "Do you wish to change the game settings (y/n)? => ";
}
int newSetting(int &rows, int &columns, int &zombie)
{
    system("cls");
    cout << "Change Board Settings " << endl;
    cout << "---------------------" << endl;
    // rows
    do
    {
        cout << "Enter Rows        : ";
        cin >> rows;
        if (rows % 2 == 0 || rows < 3 || rows > 99)
            cout << "Try enter odd integer larger than 2" << endl;

    } while (rows % 2 == 0 || rows < 3);
    // columns
    do
    {
        cout << "Enter Columns     : ";
        cin >> columns;
        if (columns % 2 == 0 || columns < 3 || columns > 99)
            cout << "Try enter odd integer larger than 2" << endl;

    } while (columns % 2 == 0 || columns < 3);
    // zombie
    cout << "Change Zombie Settings   " << endl;
    cout << "-------------------------" << endl;
    do
    {
        cout << "Enter number of zombie        : ";
        cin >> zombie;
        if (zombie < 1 || zombie > 5)
            cout << "Try enter integer in range 1 to 5" << endl;

    } while (zombie < 1 || zombie > 5);
    return rows, columns, zombie;
}

//alien
// void Alien::landAlien(Board &board)
// {
//     char possibleHeading[] = {'^', '>', '<', 'v'};

//     x_ = rand() % board.getDimX() + 1;
//     y_ = rand() % board.getDimY() + 1;
//     alien_ = possibleHeading[rand() % 4];

//     board.setObject(x_, y_, alien_);
// }

// int Alien::getX()
// {
//     return x_;
// }

// int Alien::getY()
// {
//     return y_;
// }

// char Alien::getDirection()
// {
//     return alien_;
// }

// void alienLocation()
// {
//     Board board;
//     Alien alien;

//     alien.landAlien(board);
//     //board.display();
// }

//zombies
int randLife() // Randomize zombie life.
{
    int lastLife;
    int life[4] = {100, 150, 200, 250};
    lastLife = life[rand() % 4];
    return lastLife;
}

int randAttack() // Randomize zombie attack.
{
    int ultAttack;
    int attack[2] = {10, 15};
    ultAttack = attack[rand() % 2];
    return ultAttack;
}

int randRange() // Randomize zombie range.
{
    int lastRange;
    int range[5] = {1, 2, 3, 4, 5};
    lastRange = range[rand() % 5];
    return lastRange;
}

int **PositionZombie(int &zombie)
{
    int **placeZombie = new int *[zombie];
    for (int i = 0; i < zombie; i++)
    {
        placeZombie[i] = new int[2];
    }
    return placeZombie;
}

void generateZombieProperties(int &life, int &attack, int &range)
{
    life = randLife();
    attack = randAttack();
    range = randRange();
}

vector<Zombie> zombies;

// void generateZombies(int &numOfZombies, int &rows, int &columns, string **arr, int **placeZombie) {
//     for (int i = 0; i < numOfZombies; ++i) {
//         Zombie z;
//         z.number = i;
//         z.life = randLife();
//         z.attack = randAttack();
//         z.range = randRange();
//         int randRow, randColumn;
//         do {
//             randRow = rand() % rows;
//             randColumn = rand() % columns;
//         } while (arr[randRow][randColumn] != ".");
//         z.xPos = randRow;
//         z.yPos = randColumn;
//         arr[randRow][randColumn] = to_string(i+1);
//         zombies.push_back(z);
//     }
// }

void displayHelp()
{
    cout << "Commands" << endl;
    cout << "1. up    - Move up. " << endl;
    cout << "2. down  - Move down. " << endl;
    cout << "3. left  - Move left. " << endl;
    cout << "4. right - Move right. " << endl;
    cout << "5. arrow - Change the direction of an arrow. " << endl;
    cout << "6. help  - Display these user commands. " << endl;
    cout << "7. save  - Save the game. " << endl;
    cout << "8. load  - Load a game. " << endl;
    cout << "9. menu  - Return menu. " << endl;
}

string displayCommand(string &command)
{
    cout << "Command> ";
    cin >> command;
    cout << endl;
    if (command == "help")
        {
            displayHelp();
            cout << endl;
            // system("pause");
        }
    else if(command == "up" || command == "down" || command == "left" || command == "right")
    {
        if (command == "up")
        {

        }
        else if (command == " down")
        {

        }
        else if (command == "left")
        {
                    
        }
        else if (command == "right")
        {

        }
    }
    else if (command == "arrow")
    {
                
    }
    else if (command == "save")
    {

    }
    else if (command == "load")
    {

    }
    else if (command == "menu")
    {
        displayMenu();
        cout << endl;
        // system("pause");
    }
    else
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid selection, please try again!" << endl;
        cout << "You can view the help command by entering 'help'. "<< endl;
        cout << endl;
        cout << "Command> ";
        cin >> command;
        
        // system("pause");
    }
    return command;
}

void displayGame(int &rows, int &columns, int &zombie)
{
    Board board;
    board.display(columns, rows);
}

// main
int main()
{
    int rows = 5;
    int columns = 9;
    int zombie = 1;
    char choice;
    char choose;
    string command;
    bool done = false;
    int **placeZombie = PositionZombie(zombie);
    string **arr;
    Board board;
    Zombie zombies;
    do
    {
        // srand(time(NULL));
        displayMenu();
        cout << "choice => ";
        cin >> choice;
        choice = toupper(choice);
        cout << endl;
        switch (choice)
        {
        case '1':
            // srand(time(NULL));
            displayGame(rows, columns, zombie);
            // alienLocation();
            cout << endl;
            //generateZombies(zombie, rows, columns, arr, placeZombie);
            displayCommand(command);
            break;
        case '2':
            // system("cls");
            displayDefaultSetting(rows, columns, zombie);
            cin >> choose;
            cout << endl;
            if (choose == 'y'|| choose == 'Y')
            {
                newSetting(rows, columns, zombie);
                cout << "Settings Updated. " << endl;
                cout << endl;
                system("cls");
                displayGame(rows, columns, zombie);
                cout << endl;
                displayCommand(command);
                break;
            }
            else if (choose == 'n' || choose == 'N')
            {
                cout << endl;
                cout << "Game Loading..." << endl;
                cout << endl;
                system("cls"); 
                displayGame(rows, columns, zombie);
                cout << endl;
                displayCommand(command);
            }
            else
            {
                cin.clear();
                cin.ignore();
                cout << "Invalid selection, please try again!" << endl;
                cout << endl;
                cin >> choose;
                // system("pause");
            }
        case 'Q':
            done = true;
            cout << "GOOD BYE!!" << endl;
            // system("pause");
        default:
            cout << "Invalid selection, please try again!" << endl;
            cout << endl;
            // system("pause");
        }
        system("pause");
    } while (!done);
}