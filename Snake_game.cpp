#include <iostream>
#include <cstdlib>  // For system("clear")
#include <ctime>    // For srand() and rand()

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitPositionX, fruitPositionY, score;
int tailX[100], tailY[100];
int ntail;

enum directions { Stop = 0, Left, Right, Up, Down };
directions dir;

void setup() {
    gameOver = false;
    dir = Stop;
    x = width / 2;
    y = height / 2;
    fruitPositionX = rand() % width;
    fruitPositionY = rand() % height;
    score = 0;
    ntail = 0;  // Initialize ntail
}

void draw() {
    system("clear");  // Clears the screen 
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                cout << "#";
            else if (i == y && j == x)
                cout << "O";
            else if (i == fruitPositionY && j == fruitPositionX)
                cout << "F";
            else {
                bool print = false;
                for (int k = 0; k < ntail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        print = true;
                        break;  // Exit the loop once the tail is found
                    }
                }
                if (!print)
                    cout << " ";
            }
        }
        cout << endl;
    }
    cout << "Score: " << score << endl;
}

void input() {
    char ch;
    cin >> ch;  // Waits for user input
    switch (ch) {
        case 'w':
            dir = Up;
            break;
        case 'a':
            dir = Left;
            break;
        case 's':
            dir = Down;
            break;
        case 'd':
            dir = Right;
            break;
        case 'x':
            gameOver = true;
            break;
    }
}

void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < ntail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case Up:
            y--;
            break;
        case Left:
            x--;
            break;
        case Right:
            x++;
            break;
        case Down:
            y++;
            break;
        default:
            break;
    }

    // Boundary collision detection (basic)
    if (x <= 0 || x >= width - 1 || y <= 0 || y >= height - 1) {
        gameOver = true;
        cout << ".................GAME OVER....................";
    }

    // Tail collision detection
    for (int i = 0; i < ntail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = true;
            cout << ".................GAME OVER....................";
        }
    }

    // Fruit collection logic
    if (x == fruitPositionX && y == fruitPositionY) {
        score += 10;
        fruitPositionX = rand() % width;
        fruitPositionY = rand() % height;
        ntail++;
    }
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
    }
    return 0;
}

