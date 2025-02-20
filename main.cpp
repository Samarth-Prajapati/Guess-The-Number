#include <iostream>
#include <random>
#include <ctime>
using namespace std;
class Game
{
private:
    int number, up, down, guess, attempts = 0;

public:
    Game() {}
    Game(int number, int up, int down);
    void guessNumber();
};
int main()
{
    int number, up, down;
    cout << " -- GUESS THE NUMBER GAME -- " << endl;
    cout << " --------------------------- " << endl;
    cout << " Enter your range ( Greater ) : " << endl;
    cin >> up;
    cout << " Enter your range ( Lower ) : " << endl;
    cin >> down;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(down, up);
    number = dist(gen);
    Game g(number, up, down);
    g.guessNumber();
    return 0;
}
Game::Game(int number, int up, int down)
{
    this->up = up;
    this->down = down;
    this->number = number;
}
void Game::guessNumber()
{
    cout << " --------------------------- " << endl;
    cout << " Guess the number ( between " << this->down << " - " << this->up << " ) :" << endl;
    while (true)
    {
        cin >> guess;
        attempts++;
        if (guess > number)
        {
            cout << " You predicted bigger number , go down . " << endl;
        }
        else if (guess < number)
        {
            cout << " You predicted smaller number , go up . " << endl;
        }
        else if (number == guess)
        {
            cout << " Congratulations , you predicted correct number in " << attempts << " attempts . " << endl;
            exit(0);
        }
        else
        {
            cout << " Invalid number , try again . " << endl;
        }
    }
}