
#include <iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
class game {
public:
    bool gameOver;
    int w = 22;
    int h = 20;
    int x, y, fruitX, fruitY;
    int tailX[100], tailY[100];
    int score;
    enum eDirection { stop = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;

    void setup();
    void draw();
    void input();
    void logic();
    };

    void game::setup() {

        gameOver = false;
        dir = stop;
        x = w / 2;
        y = h / 2;
        fruitX = x-2;
        fruitY =y-2;
        score = 0;

    }
    void game::draw() {

        system("cls");
        for (int i = 0; i < w; i++)
        {
            cout << "#";
        }

        for (int i = 0; i < h; i++)
        {
            cout << endl;
            cout << "#";
            for (int j = 0; j < 20; j++)
            {
                if (x == i && j == y)
                {
                    cout << "O";
                }
                else if (fruitX == i && fruitY == j)
                {
                    cout << "F";
                    
                }
                else 
                   cout << " ";
               

            }

            cout << "#";
        }
        cout << endl;

        for (int i = 0; i < w; i++)
        {
            cout << "#";

        }
        cout << endl;
        cout << "score : " << score<<endl;


    }
    void game::input() {
        if (_kbhit())
           
        {
           
            switch (_getch())
            {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'q':
                gameOver = true;
                break;
            }

        }
    }
    void game::logic() {
      
        switch (dir) {
        case LEFT:
            y--;
            break;
        case RIGHT:
            y++;
            break;
        case UP:
            x--;
            break;
        case DOWN:
            x++;
            break;
        default:
            break;

        }
        if (x<0 || x>w || y<0 || y>h) {
            gameOver = true;
        }
        if (x == fruitX && y == fruitY) {

            score += 10;
            fruitX = rand()%h;
            fruitY = rand()%w;


        }
    }
    int main()
    {
        game p;
        p.setup();
        
        while (!p.gameOver) {
            p.draw();
            p.input();
            p.logic();
            Sleep(20);
            
        }
        
     

        return 0;
    }
