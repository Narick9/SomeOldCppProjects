#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;


/////////	const	//////////

const unsigned x = 20;
const unsigned y = 8;
char field[x][y];
const double Hz = 8;

/////////	logic	/////////


void Sleeping()
{
	Sleep(1000 / Hz);
}

unsigned get_const_x();
unsigned get_const_y();

struct coor
{
	coor(int x_vvod = 0, int y_vvod = 0) { x = x_vvod, y = y_vvod; }
	~coor() {}
	int x = 0;
	int y = 0;

	void set_coor(unsigned x_vvod, unsigned y_vvod)
	{
		x = x_vvod;
		y = y_vvod;
	}
};

coor snake_position[x * y];						//Координаты каждой клетки змеи
unsigned snake_size = 3;								//размер змеи

struct apple :coor
{
	apple() {}
	~apple() {}
	void show_apple()
	{
		field[x][y] = apple_picter;
	}
	void new_apple()								//Яблочко для роста
	{
		int x_rand = rand() % (get_const_x() - 4) + 2;					//x от coor
		int y_rand = rand() % (get_const_y() - 4) + 2;					//y от coor
		int score = 0;
		for (unsigned i = 0; i < snake_size; i++)
		{
			if (x_rand != snake_position[i].x || y_rand != snake_position[i].y)
			{
				score++;
			}
		}
		if (score == snake_size)
		{
			x = x_rand;
			y = y_rand;
		}
		else
			new_apple();
	}

	char apple_picter = '$';
};

unsigned get_const_x()
{
	return x;
}
unsigned get_const_y()
{
	return y;
}

apple ap;

struct snake
{
	snake() { }
	~snake() { }

	void movement()								//считывает клавиши и меняет координаты головы змеи
	{
		char* slovo = new char;
		*slovo = trend;
		if (_kbhit())
		{
			*slovo = _getch();
		}
		switch (*slovo)
		{
		case 'w':
			if (trend != 's')
			{
				y_snake -= 1;
				trend = *slovo;
			}
			else							//иначе движение продолжается по направлению 
			{
				y_snake += 1;
			}
			break;
		case 'a':
			if (trend != 'd')
			{
				x_snake -= 1;
				trend = *slovo;
			}
			else
			{
				x_snake += 1;
			}
			break;
		case 's':
			if (trend != 'w')
			{
				y_snake += 1;
				trend = *slovo;
			}
			else
			{
				y_snake -= 1;
			}
			break;
		case 'd':
			if (trend != 'a')
			{
				x_snake += 1;
				trend = *slovo;
			}
			else
			{
				x_snake -= 1;
			}
			break;
		}
		delete slovo;
	}
	bool check_snake()						//проверяет, не врезалась ли голова змеи
	{
		if (field[x_snake][y_snake] == ' ')
		{
			return true;
		}
		else if (field[x_snake][y_snake] == ap.apple_picter)
		{
			snake_size++;
			ap.new_apple();
			return true;
		}
		else
		{
			return false;
		}
	}
	bool check_vvod(char vvod)					//проверяет ввод
	{
		switch (vvod)
		{
		case 'w':
			if (trend != 's')
				return true;
		case 'a':
			if (trend != 'd')
				return true;
		case 's':
			if (trend != 'w')
				return true;
		case 'd':
			if (trend != 'a')
				return true;
		default:
			return false;
		}
	}
	void energy();									//Отвечает за анимацию
	void clear();		//В разделе image
	void snake_start()						//Строит змейку
	{
		for (unsigned i = 1; i <= snake_size; i++)
		{
			snake_position[i - 1].set_coor(x_snake - i, y_snake);
		}
	}

	char snake_picter = 'x';							//Рисунок клетки тела змеи
	char trend = 'd';								//задает направление движения
	unsigned x_snake = 8,							//просто подходящее место
		y_snake = 5;								//с координатами есть аномалия! Отсчёт в массиве идет с начала поля, а не с границ
};

///////////		image		////////////

void snake::clear()									//Чистит поле от лишнего мусора
{

	for (int i = 0; i < y; i++)			/*	просто заполнить пространство	*/
	{
		for (int k = 0; k < x; k++)
		{
			field[k][i] = ' ';
		}
	}
}

void snake::energy()								//Отвечает за анимацию
{
	//coor_snake.i++;

	for (int i = snake_size - 1; i > 0; --i)
	{
		snake_position[i].set_coor(snake_position[i - 1].x, snake_position[i - 1].y);
	}

	snake_position[0].set_coor(x_snake, y_snake);

	field[x_snake][y_snake] = 'O';
	for (unsigned i = 1; i < snake_size; i++)				//Первый уже записан
	{
		field[snake_position[i].x][snake_position[i].y] = snake_picter;
	}
}

void show(bool no_end = true)								//рисует картинку
{
	for (int i = 0; i < y; i++)
	{
		for (int k = 0; k < x; k++)
		{
			cout << field[k][i];
		}
		cout << endl;
	}
	if (no_end)
	{
		Sleeping();
		system("cls");
	}
}

void location()									//строит поле
{
	for (int k = 0; k < y; ++k)
	{
		for (int i = 0; i < x; ++i)
		{
			if (k == 0 || k == y - 1 || i == 0 || i == x - 1) //k не может достич l без помощи, также как и i 
			{
				field[i][k] = '#';
			}
			else
			{
				//field[i][k] = ' '; 
			}
		}
	}
}

///////////		start		////////////////

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "_____________SNAKE_____________\n\n\n";
	cout << "Начать?\n";
	system("pause");
	snake u;
	srand(time(0));

	bool ask = true;
	char slovo = 'n';
	do
	{
		system("cls");

		u.x_snake = 8;				//также, как и в классе/структуре snake. Чтобы при новой игре было новое место старта
		u.y_snake = 5;
		u.trend = 'd';
		int fp = 0;
		ask = true;
		ap.new_apple();
		u.snake_start();
		snake_size = 3;

		while (ask)					//порядок команд не менать 
		{
			cout << "_____________SNAKE_____________\n\n\n";
			cout << "x: " << u.x_snake 			//не знаю почему так
				<< "\ny: " << u.y_snake
				<< "\nlevel " << snake_size << endl;
			fp++;
			cout << "fp: " << fp << "\n";


			u.clear();
			u.energy();
			location();					//строит поле
			ap.show_apple();
			u.movement();			//считывает клавиши и меняет координаты головы змеи

			if (!u.check_snake())				//проверяет, не врезалась ли голова змеи
			{
				ask = false;
				show(false);
				break;
			}
			show();						//рисует картинку
		}

		cout << "_____________END GAME_____________\n"
			"Хотите продолжить? y/n \n";
		cin >> slovo;
	} while (slovo == 'y');
	cout << "\nexit\n\n\n";
	system("pause");
	return 0;
}