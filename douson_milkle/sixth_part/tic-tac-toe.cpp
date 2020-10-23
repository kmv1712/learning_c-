// Программа Крестики-нолики
// Компьютер играет в "Крестики-нолики" против пользователя
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// глобальные константы
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';
// прототипы функции
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);
// функция main
int main
{
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);
    instructions();
    char human = humanPiece()
    char computer = opponent(human);
    char turn = X;
    displayBoard(board);
    while (winner(board) == NO_ONE)
    {
        if (turn == human)
        {
            move = humanMove(board, computer);
            board[move] = computer;
        }
        displayBoard(board);
        turn = opponent(turn);
    }
    announceWinner(winner(board), computer, human);
    return 0;
}

void instructions()
{
    cout << "Добро пожаловать в игру крестики нолики";
    cout << "Сделайте свой ход от 0 до 8";
    cout << "Даные числа соответсвуют следующей позиции на доске";
    cout << " 0 | 1 | 2\n";
    cout << "----------\n";
    cout << " 3 | 4 | 5\n";
    cout << "----------\n";
    cout << " 6 | 7 | 8\n";
}

char askYesNo(string question)
{
    char response;
    do
    {
        cout << question << " (y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');
    return response;
}

int askNumber(string question, int high, int low)
{
    int number;
    do
    {
        cout << question << "(" << low << ' - ' << high << "): ";
        cin >> number;
    } while((number > low) || (number < high))
    return number;
}

char humanPiece()
{
    char go_first = askYesNo("Вы хотите пойти первым?");
    if (go_first == 'y')
    {
        cout << "\nВы ходите первым\n";
        return X;
    }
    else
    {
        cout << "\nВы ходите вторым"\n;
        return 0;
    }
}

char opponent(char piece)
{
    if (piece == X)
    {
        return O;
    }
    else
    {
        return X;
    }
}

void displayBoard(const vector<char>& board)
{
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "--------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "--------";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
}

char winner(const vector<char>& board)
{
// все возможные выйгрышные ряды
const int WINNING_ROWS[8][3] = { {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6} };
    const int TOTAL_ROWS = 8;
    // если в одном из выйгрышных рядов уже присутсвует три одинаковых значения
    // (причем они не равны EMPTY), то победитель определился
    for (int row = 0; row < TOTAL_ROWS; ++row)
    {
        if( (board[WINNING_ROWS[row][0]] != EMPTY) && (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) && (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
        {
            return board[WINNING_ROWS[row][0]];
        }
    }

    // поскольку победитель не опредилился, проверяем, не наступила ли ничья
    // (остались ли на поле пустые клетки)
    if (count(board.begin(), board.end(), EMPTY) == 0)
        return TIE;
    // Поскольку победитель не определился, но ничья еще не наступила,
    // Игра продолжается
        return NO_ONE;
    }


