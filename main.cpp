// *************************************************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT8L
// Names: ANG JIN NAN | TAI QI TONG | TAN XIN YI
// IDs: 1211100925 | 1211102777 | 1211100903
// Emails: 1211100925@student.mmu.edu.my | 1211102777@student.mmu.edu.my | 1211100903@student.mmu.edu.my
// Phones: 0162601883 | 0105610242 | 0108410773
// *************************************************************************************************************

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

class Board
{
private:
    vector<vector<char>> map_;
    int dimX_, dimY_;
    int inputrow;
    int inputcol;

public:
    Board(int dimX_ = 99, int dimY_ = 99);
    void init(int dimX, int dimY);
    void display(int dimX, int dimY);
    int getDimX();
    int getDimY();    
    int getrow() const;
    int getcol() const;
    char getObject(int x, int y) const;
    void setObject(int x, int y, char ch);
    void chgArrow(int inputrow, int inputcol, int rows, int columns, int &zombie, string newarrow);
    void hitObject(int Alien_xPos, int Alien_yPos);
    // void generateRandomTrail(int &rows, int &columns);
};

class Alien
{
private:
    int AlienId;    // A
    int Alien_xPos; // rows
    int Alien_yPos; // columns

public:
    Alien();
    void setAlien(Board &board);
    int getxPos() const;
    int getyPos() const;
    void moveUp(Board &board, int dimY, int columns, int rows, int zombie, string hit);
    void moveDown(Board &board, int dimY, int rows, int columns, int zombie, string hit);
    void moveLeft(Board &board, int &columns, int rows, int zombie, string hit);
    void moveRight(Board &board, int &columns, int rows, int zombie, string hit);
};

class Zombie
{
private:
    vector<int> numOfZombies{};
    vector<int> zombieLife{};
    vector<int> zombieAttack{};
    vector<int> zombieRange{};

public:
    int id;
    int life;
    int attack;
    int range;
    int number;
    int xPos;
    int yPos;
    const int minLife = 50;
    const int maxLife = 250;
    const int minAttack = 5;
    const int maxAttack = 25;
    const int minRange = 1;
    const int maxRange = 5;
    const int maxZombie = 4;
    void assignZombies(Board &board, int &zombies);
};

// board
int Board::getDimX()
{
    return dimX_;
}

int Board::getDimY()
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
    map_[dimY_ - y][x - 1] = ch;
}

int Board::getrow() const
{
    return inputrow;
}

int Board::getcol() const
{
    return inputcol;
}

// void Board::generateRandomTrail(int &rows, int &columns)
// {
//     for (int i = 0; i < rows, ++i)
//     {
//         for 
//     }
// }

vector<Zombie> zombies;
vector<int> alienAttribute{100, 0};
void characterAttribute(int &zombie)
{
    cout << "Alien   : Life  " << alienAttribute[0] << ",  Attack  " << alienAttribute[1] << endl;
    for (int i = 0; i < zombie; i++)
    {
        cout << "Zombie " << zombies[i].id << ": Life   " << zombies[i].life << ",  Attack  " << zombies[i].attack << ",  Range  " << zombies[i].range << endl;
    }
}

void Board::chgArrow(int inputrow, int inputcol, int rows, int columns, int &zombie, string newarrow)
{
    char oriarrow;
    cout<<"Enter row, column and direction -> ";
    cin >> inputrow;
    cin >> inputcol;
    cin >> newarrow;
    cout << endl;

    for (int i = 0; i < 99; ++i)
    {
        if(inputrow == i)
        {
            for (int j = 0; j < 99; ++j)
            {
                if(inputcol == j)
                {

                    oriarrow = map_[i-1][j-1];
                    if(map_[i-1][j-1]=='^' || map_[i-1][j-1]=='v' || map_[i-1][j-1]=='<' || map_[i-1][j-1]=='>')
                    {    
                        if(newarrow == "up")
                        {
                            map_[i - 1][j - 1] = '^';
                            display(columns, rows);
                            characterAttribute(zombie);
                            cout<< endl << "Arrow " << oriarrow << " is switched to ^. "<<endl;
                        }

                        else if(newarrow == "down")
                        {
                            map_[i - 1][j - 1] = 'v';
                            display(columns, rows);
                            characterAttribute(zombie);
                            cout<< endl << "Arrow " << oriarrow << " is switched to v. "<<endl;
                        }

                        else if(newarrow == "left")
                        {
                            map_[i - 1][j - 1] = '<';
                            display(columns, rows);
                            characterAttribute(zombie);
                            cout<< endl << "Arrow " << oriarrow << " is switched to <. "<<endl;
                        }

                        else if(newarrow == "right")
                        {
                            map_[i - 1][j - 1] = '>';
                            display(columns, rows);
                            characterAttribute(zombie);
                            cout<< endl << "Arrow " << map_[i-1][j-1]<< " is switched to >. "<<endl;
                        }
                        else
                        {
                            cout << "Please enter a valid input of direction!" << endl;
                            cin.clear();
                            cin.ignore();
                        }
                    }
                    else
                    {
                        cout<< "Input rows and columns are not accessible!"<<endl;
                    }
                }
            }
        }
    } 
}


// alien
Alien::Alien()
{
}

void Alien::setAlien(Board &board)
{
    char AlienId = 'A';
    Alien_xPos = ((board.getDimX() + 1) / 2);
    Alien_yPos = ((board.getDimY() + 1) / 2);
    board.setObject(Alien_xPos, Alien_yPos, AlienId);
}

int Alien::getxPos() const
{
    return Alien_xPos;
}

int Alien::getyPos() const
{
    return Alien_yPos;
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
        cout << "Enter number of zombie   : ";
        cin >> zombie;
        if (zombie < 1 || zombie > 9)
            cout << "Try enter integer in range 1 to 9" << endl;

    } while (zombie < 1 || zombie > 9);
    return rows, columns, zombie;
}

// Generates a random number within the specified range
int randomNumber(int min, int max)
{
    return min + (rand() % (int)(max - min + 1));
}

// Initializes the attributes of the zombies
void Zombie::assignZombies(Board &board, int &zombie)
{

    for (int i = 0; i < zombie; i++)
    {
        vector<char> zchar{'1', '2', '3', '4'};
        Zombie z;
        xPos = rand() % board.getDimX();
        yPos = rand() % board.getDimY();
        z.id = i + 1;
        z.life = randomNumber(minLife, maxLife);
        z.attack = randomNumber(minAttack, maxAttack);
        z.range = randomNumber(minRange, maxRange);
        board.setObject(xPos, yPos, zchar[i]);
        zombies.push_back(z);
    }
}

void Board::hitObject(int Alien_xPos, int Alien_yPos)
{
    if (map_[Alien_xPos -1][Alien_yPos -1] == ' ')
    {
        cout << "Alien found nothing." << endl;
    }
    
    else if (map_[Alien_xPos - 1][Alien_yPos -1] == 'h')
    {
        cout << "Alien finds a health pack. " << endl;
        cout << "Alien's life increased by 20. " << endl;
        alienAttribute[0] = alienAttribute[0] + 20;
    }
    
    else if (map_[Alien_xPos - 1][Alien_yPos -1] == '^')
    {
        cout << "Alien finds an up arrow. " << endl;
        cout << "Alien's attack increased by 20. " << endl;
        alienAttribute[1] = alienAttribute[1] + 20;
    }

    else if (map_[Alien_xPos - 1][Alien_yPos -1] == '>')
    {
        cout << "Alien finds an right arrow. " << endl;
        cout << "Alien's attack increased by 20. " << endl;
        alienAttribute[1] = alienAttribute[1] + 20;
    }
    
    else if (map_[Alien_xPos - 1][Alien_yPos -1] == '<')
    {
        cout << "Alien finds an left arrow. " << endl;
        cout << "Alien's attack increased by 20. " << endl;
        alienAttribute[1] = alienAttribute[1] + 20;
    }
    
    else if (map_[Alien_xPos - 1][Alien_yPos -1] == 'v')
    {
        cout << "Alien finds an down arrow. " << endl;
        cout << "Alien's attack increased by 20. " << endl;
        alienAttribute[1] = alienAttribute[1] + 20;
    }
}

// Alien movement
void Alien::moveUp(Board &board, int dimY, int rows, int columns, int zombie, string hit)
{
    bool up = false;
    if (Alien_yPos + 1 <= rows)
    {
        up = true;
        do
        {
            system("cls");
            int upY = Alien_yPos + 1;
            board.setObject(Alien_xPos, upY, 'A');
            board.setObject(Alien_xPos, Alien_yPos, '.');
            Alien_yPos = upY;
            board.display(columns, rows);
            cout << endl;
            characterAttribute(zombie);
            board.hitObject(Alien_xPos, Alien_yPos);
            if (Alien_yPos == rows)
            {
                up = false;
            }
            system("pause");
        } while (up);
    }
    board.setObject(Alien_xPos, Alien_yPos, 'A');
    board.display(columns, rows);
    cout << endl;
    characterAttribute(zombie);

}

void Alien::moveDown(Board &board, int dimY, int rows, int columns, int zombie, string hit)
{
    bool downing = false;
    if (rows - Alien_yPos >= 0)
    {
        downing = true;
        do
        {
            system("cls");
            int downY = Alien_yPos - 1;
            board.setObject(Alien_xPos, downY, 'A');
            board.setObject(Alien_xPos, Alien_yPos, '.');
            Alien_yPos = downY;
            board.display(columns, rows);
            cout << endl;
            characterAttribute(zombie);
            board.hitObject(Alien_xPos, Alien_yPos);
            if (Alien_yPos == 1)
            {
                downing = false;
            }
            system("pause");
        } while (downing);
    }
    board.setObject(Alien_xPos, Alien_yPos, 'A');
    board.display(columns, rows);
    cout << endl;
    characterAttribute(zombie);
}

void Alien::moveRight(Board &board, int &columns, int rows, int zombie, string hit)
{
    bool right = false;
    if (Alien_xPos + 1 <= columns)
    {  
        right = true;
        do
        {
            system("cls");
            int rightX = Alien_xPos + 1;
            board.setObject(rightX, Alien_yPos, 'A');
            board.setObject(Alien_xPos,Alien_yPos,'.');
            Alien_xPos = rightX;
            board.display(columns, rows);
            cout << endl;
            characterAttribute(zombie);
            board.hitObject(Alien_xPos, Alien_yPos);
            if (Alien_xPos == columns)
            {
                right = false;
            }
            system("pause");
        } while (right);
    }
    board.setObject(Alien_xPos, Alien_yPos, 'A');
    board.display(columns, rows);
    cout << endl;
    characterAttribute(zombie);
}

void Alien::moveLeft(Board &board, int &columns, int rows, int zombie, string hit)
{
    bool left = false;
    if (columns - Alien_xPos >= 0)
    {
        left = true;
        do
        {
            system("cls");
            int leftX = Alien_xPos - 1;
            board.setObject(leftX, Alien_yPos, 'A');
            board.setObject(Alien_xPos, Alien_yPos, '.');
            Alien_xPos = leftX;
            board.display(columns, rows);
            cout << endl;
            characterAttribute(zombie);
            board.hitObject(Alien_xPos, Alien_yPos);
            if (Alien_xPos == 1)
            {
                left = false;
            }
            system("pause");
        } while (left);
    }
    board.setObject(Alien_xPos, Alien_yPos, 'A');
    board.display(columns, rows);
    cout << endl;
    characterAttribute(zombie);
}

// Command
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
    cout << "9. quit  - Quit game. " << endl;
}

void displayGame(int &rows, int &columns, int &zombie)
{
    int dimX;
    int dimY;
    int Alien_xPos, Alien_yPos;
    int inputcol;
    int inputrow;
    char random[50][50];
    int zombieData[4][4];
    int dimX_;
    int dimY_;
    Alien alien;
    Zombie zombies;
    Board board(columns, rows);
    string hit;
    Alien moveUp(Board board, int dimY);
    Alien moveDown(Board board, int dimY);
    Alien moveRight(Board board, int columns);
    Alien moveLeft(Board board);
    alien.setAlien(board);
    zombies.assignZombies(board, zombie);
    board.display(columns, rows);
    characterAttribute(zombie);
    bool quit = false;
    string command;
    string newarrow;
    do
    {
        cout << endl;
        cout << "Command ->";
        cin >> command;
        cout << endl;
        if (command == "up")
        {
            alien.moveUp(board, dimY, rows, columns, zombie, hit); 
        }
        else if (command == "down")
        {
            alien.moveDown(board, dimY, rows, columns, zombie, hit);
        }
        else if (command == "left")
        {
            alien.moveLeft(board, columns, rows, zombie, hit);
        }
        else if (command == "right")
        {
            alien.moveRight(board, columns, rows, zombie, hit);
        }
        else if (command == "arrow")
        {
            board.chgArrow(inputrow, inputcol, rows, columns, zombie, newarrow);
            // characterAttribute(zombie);
        }
        else if (command == "help")
        {
            displayHelp();
            cout << endl;
        }
        else if (command == "save")
        {
            const int m = columns, n = rows;
            string name;
            cout << "Choose a name to save current file: ";
            cin >> name;
            string file = ".txt";
            string fileName = name + file;
                    ofstream MyFile(fileName);
                    MyFile << rows << endl
                           << columns << endl
                           << zombie << endl;
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < columns; j++)
                        {
                            MyFile << random[i][j] << endl;
                        }
                    }
                    MyFile << alienAttribute[0] << endl;
                    MyFile.close();
            //         for (int z = 0; z < zombie; z++)
            //         {
            //             for (int j = 0; j < 7; j++)
            //             {
            //                 MyFile << zombieData[z][j] << endl;
            //             }
            // }
        }
        else if (command == "load")
        {
            const int m = columns, n = rows;
            string name;
                    cout << "Enter the name of your file: ";
                    cin >> name;
                    string file = ".txt";
                    string fileName = name + file;
                    ifstream MyFile;
                    char check;
                    MyFile.open(fileName);
                    if (MyFile.fail())
                    {
                        cout << "File does not exist" << endl;
                    }
                    else
                    {
                        MyFile >> rows;
                        MyFile >> columns;
                        MyFile >> zombie;
                        for (int i = 0; i < rows; i++)
                        {
                            for (int j = 0; j < columns; j++)
                            {
                                MyFile >> random[i][j];
                                // cout << random[i][j] << "|";
                            }
                            // cout << endl;
                        }
                        // for (int z = 0; z <= zombie; z++)
                        // {
                        //     for (int j = 0; j <= 7; j++)
                        //     {
                        //         MyFile >> zombieData[z][j];
                        //     }
                        // }
                        MyFile.close();
                        board.display(dimX, dimY);
                        system("pause");
                        system("cls");
                    }
        }
        else if (command == "quit")
        {
            bool gameQuit = false;
            while (!gameQuit)
            {
                char comfirmation;
                cout << "Do you want to quit the game (y/n)? " << endl;
                cin >> comfirmation;
                comfirmation = toupper(comfirmation);
                cout << endl;
                if (comfirmation == 'Y')
                {
                    gameQuit = true;
                    cout << "Good Bye! " << endl;
                    quit = true;
                }
                else if (comfirmation == 'N')
                {
                    gameQuit = true;
                }
                else
                {
                    cout << "Invalid selection, please try again!" << endl;
                    cout << endl;
                }
            }
        }
        else
        {
            cout << "Invalid selection, please try again!" << endl;
            cout << "You can view the help command by entering 'help'. " << endl;
            cout << endl;
        }
    } while (!quit);
}

void chgDefaultSetting(int rows, int columns, int zombie)
{
    displayDefaultSetting(rows, columns, zombie);
    bool chgSetting = false;
    while(!chgSetting)
    {
        char choose;
        cin >> choose;
        choose = toupper(choose);
        cout << endl;
        if (choose == 'Y')
        {
            newSetting(rows, columns, zombie);
            cout << endl;
            cout << "Settings Updated. " << endl;
            cout << endl;
            system("pause");
            system("cls");
            displayGame(rows, columns, zombie);
            cout << endl;
            chgSetting = true;
            // break;
        }
        else if (choose == 'N')
        {
            cout << endl;
            cout << "Game Loading..." << endl;
            cout << endl;
            system("pause");
            system("cls");
            displayGame(rows, columns, zombie);
            cout << endl;
            chgSetting = true;
        }
        else
        {
            cout << "Invalid selection, please try again!" << endl;
            cout << endl;
            displayDefaultSetting(rows, columns, zombie);
            chgSetting = false;
        }
    }
}

// main
int main()
{
    Board board;
    Zombie zombies;
    int rows = 5;
    int columns = 9;
    int zombie = 1;
    char choice;
    char confirm;
    bool done = false;
    srand(time(NULL));
    do
    {
        cout << " ________________________" << endl;
        cout << "|   Alien vs. Zombie    |" << endl;
        cout << "|-----------------------|" << endl;
        cout << "| Select:               |" << endl;
        cout << "| 1 => Start Game       |" << endl;
        cout << "| 2 => Settings         |" << endl;
        cout << "|-----------------------|" << endl;
        cout << "| Q => Quit             |" << endl;
        cout << "|_______________________|" << endl;
        cout << endl;
        cout << "choice => ";
        cin >> choice;
        choice = toupper(choice);
        cout << endl;
        system("cls");
        switch (choice)
        {
        case '1':
            displayGame(rows, columns, zombie);
            cout << endl;
            break;
        case '2':
            chgDefaultSetting(rows, columns, zombie);
        case 'Q':
            done = true;
            cout << "Do you really want to quit game (y/n)? " << endl;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y')
            {
                cout << "GOOD BYE!!" << endl;
                cout << endl;
                system("pause");
                break;
            }
            else if (confirm == 'n' || confirm == 'N')
            {
                displayGame(rows, columns, zombie);
                cout << endl;
            }
            else
            {
            }
            break;
        default:
            cout << "Invalid selection, please try again!" << endl;
            cout << endl;
        }
        system("pause");
        system("cls");
    } while (!done);
}