#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int CreateInt();
int CheckInt(char c[]);

class Point {
protected:
	int Xcoord;
	int Ycoord;
public:
	Point() {
		Xcoord = 100;
		Ycoord = 100;
	}
	Point(int x, int y) {
		Xcoord = x;
		Ycoord = y;
	}
	void operator=(Point& newPoint) {
		Xcoord = newPoint.Xcoord;
		Ycoord = newPoint.Ycoord;
	}
	void SetX(int x) { Xcoord = x; }
	void SetY(int y) { Ycoord = y; }
	int GetX() { return Xcoord; }
	int GetY() { return Ycoord; }
	void TableOutput() {
		cout <<"|" << setw(5) << Xcoord << "|" << setw(5) << Ycoord << "|" << endl;
		cout << "------------------" << endl;
	}
};

class Edge {
protected:
	int edge;
public:
	Edge() {
		edge = 1;
	}
	Edge(int e) {
		edge = e;
	}
	void operator=(Edge& newEdge) {
		edge = newEdge.edge;
	}
	void SetA(int a) { this->edge = a; }
	int GetA(){ return edge; }
};

enum Figure {
	CIRCLE,
	TRIANGLE,
	SQUARE,
};

class CorrectFigure : public Point, protected Edge {
protected:
	Figure figure;
public:
	CorrectFigure() {
		figure = CIRCLE;
	}
	CorrectFigure(Figure& fig) {
		figure = fig;
	}
	CorrectFigure(Point point, Edge edge, Figure figure) {
		this->Xcoord = point.GetX();
		this->Ycoord = point.GetY();
		this->edge = edge.GetA();
		this->figure = figure;
	}
	void operator=(CorrectFigure& newCF) {
		Xcoord = newCF.Xcoord;
		Ycoord = newCF.Ycoord;
		edge = newCF.edge;
		figure = newCF.figure;
	}
	void SetFigure(Figure f) {
		figure = f;
	}
	int GetEdge() { return edge; }
	Figure GetFigure() { return figure; }
};

class MathOperations {
protected:
	double perimetr;
	double square;
public:
	MathOperations() {
		perimetr = 0;
		square = 0;
	}
	void SetPerimetr(double per) { perimetr = per; }
	void SetSquare(double sq) { square = sq; }
};

enum MyColor {
	RED,
	YELLOW,
	GREEN,
	BLUE,
	BLACK,
	WHITE,
	MAGENTA,
	CYAN
};

class ColoredFigure : public CorrectFigure, protected MathOperations {
protected:
	MyColor color;
public:
	ColoredFigure() {
		color = RED;
		switch (figure) {
		case CIRCLE:
		{
			perimetr = 2 * 3.14 * edge;
			square = 3.14 * edge * edge;
		}
		case TRIANGLE:
		{
			perimetr = 3 * edge;
			square = 0.87 * edge * edge;
		}
		case SQUARE:
		{
			perimetr = 4 * edge;
			square = edge * edge;
		}
		}
	}
	ColoredFigure(CorrectFigure& fig) {
		figure = fig.GetFigure();
		edge = fig.GetEdge();
		color = GREEN;
		switch (figure) {
		case CIRCLE:
		{
			perimetr = 2 * 3.14 * edge;
			square = 3.14 * edge * edge;
		}
		case TRIANGLE:
		{
			perimetr = 3 * edge;
			square = 0.87 * edge * edge;
		}
		case SQUARE:
		{
			perimetr = 4 * edge;
			square = edge * edge;
		}
		Xcoord = fig.GetX();
		Ycoord = fig.GetY();
		}
	}
	ColoredFigure(CorrectFigure& fig, MyColor myc) {
		figure = fig.GetFigure();
		edge = fig.GetEdge();
		color = myc;
		switch (figure) {
		case CIRCLE:
		{
			perimetr = 2 * 3.14 * edge;
			square = 3.14 * edge * edge;
		}
		case TRIANGLE:
		{
			perimetr = 3 * edge;
			square = 0.87 * edge * edge;
		}
		case SQUARE:
		{
			perimetr = 4 * edge;
			square = edge * edge;
		}
		Xcoord = fig.GetX();
		Ycoord = fig.GetY();
		}
	}
	double GetPerimetr() { return perimetr; }
	double GetSquare() { return square; }
	void operator=(ColoredFigure& newCF) {
		Xcoord = newCF.Xcoord;
		Ycoord = newCF.Ycoord;
		edge = newCF.edge;
		figure = newCF.figure;
		color = newCF.color;
		perimetr = newCF.perimetr;
		square = newCF.square;
	}
	void SetColor(MyColor color) {
		this->color = color;
	}
	MyColor GetColor() { return color; }
};

class ColoredFigureOnBackground : public ColoredFigure {
protected:
	MyColor background;
public:
	ColoredFigureOnBackground() {
		background = WHITE;
	}
	ColoredFigureOnBackground(ColoredFigure& coloredFig) {
		color = coloredFig.GetColor();
		background = WHITE;
		perimetr = coloredFig.GetPerimetr();
		square = coloredFig.GetSquare();
		figure = coloredFig.GetFigure();
		Xcoord = coloredFig.GetX();
		Ycoord = coloredFig.GetY();
		edge = coloredFig.GetEdge();
	}
	ColoredFigureOnBackground(ColoredFigure& coloredFig, MyColor myc) {
		color = coloredFig.GetColor();
		perimetr = coloredFig.GetPerimetr();
		square = coloredFig.GetSquare();
		figure = coloredFig.GetFigure();
		Xcoord = coloredFig.GetX();
		Ycoord = coloredFig.GetY();
		edge = coloredFig.GetEdge();
		background = myc;
	}
	void operator=(ColoredFigureOnBackground& newCF) {
		ColoredFigure:: operator=(newCF);
		background = newCF.background;
	}
	MyColor GetBackColor() { return background; }

};

void PrintPoints(Point* points, int pointsQuantity) {
	cout << "------------------" << endl;
	cout << "|№п/п|  X  |  Y  |" << endl;
	cout << "------------------" << endl;
	for (int i = 0; i < pointsQuantity; i++) {
		cout << "|" << setw(4) << i + 1; points[i].TableOutput();
	}
	cout << endl;
}

void PrintEdges(Edge* edges, int EdgesQuantity) {
	cout << "------------------" << endl;
	cout << "|№п/п|Длина ребра|" << endl;
	cout << "------------------" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "|" << setw(4) << i + 1 << "|" << setw(11) << edges[i].GetA() << "|" << endl;
		cout << "------------------" << endl;
	}
	cout << endl;
}

void ShowCircle(ColoredFigureOnBackground& fig) {
	MyColor color = fig.GetColor();
	double perimetr = fig.GetPerimetr();
	double square = fig.GetSquare();
	int Xcoord = fig.GetX();
	int Ycoord = fig.GetY();
	int edge = fig.GetEdge();
	MyColor background = fig.GetBackColor();
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(1000, 1000), "Anechka sdelala");
	// Главный цикл приложения: выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				window.close(); // тогда закрываем его
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Установка цвета фона
		switch (background) {
		case BLACK:
			window.clear(Color::Black);
			break;
		case WHITE:
			window.clear(Color::White);
			break;
		case RED:
			window.clear(Color::Red);
			break;
		case YELLOW:
			window.clear(Color::Yellow);
			break;
		case GREEN:
			window.clear(Color::Green);
			break;
		case BLUE:
			window.clear(Color::Blue);
			break;
		case MAGENTA:
			window.clear(Color::Magenta);
			break;
		case CYAN:
			window.clear(Color::Cyan);
			break;
		}
		// Создаем фигуру - круг
		CircleShape circle(edge);

		// Закрашиваем наш круг 
		///////////////////////////////////////////////////////////////////////////////////////////////
		switch (color) {
		case BLACK:
			circle.setFillColor(Color::Black);
			break;
		case WHITE:
			circle.setFillColor(Color::White);
			break;
		case RED:
			circle.setFillColor(Color::Red);
			break;
		case YELLOW:
			circle.setFillColor(Color::Yellow);
			break;
		case GREEN:
			circle.setFillColor(Color::Green);
			break;
		case BLUE:
			circle.setFillColor(Color::Blue);
			break;
		case MAGENTA:
			circle.setFillColor(Color::Magenta);
			break;
		case CYAN:
			circle.setFillColor(Color::Cyan);
			break;
		}
		circle.move(Xcoord, Ycoord);
		// Отрисовка круга
		window.draw(circle);
		// Отрисовка окна
		window.display();
	}
	cout << "Длина окружности: " << perimetr << endl;
	cout << "Площадь круга: " << square << endl;
}

void ShowAngle(ColoredFigureOnBackground& fig, int angles) {
	MyColor color = fig.GetColor();
	double perimetr = fig.GetPerimetr();
	double square = fig.GetSquare();
	int Xcoord = fig.GetX();
	int Ycoord = fig.GetY();
	int edge = fig.GetEdge();
	MyColor background = fig.GetBackColor();
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(1000, 1000), "Anechka sdelala");
	// Главный цикл приложения: выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				window.close(); // тогда закрываем его
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Установка цвета фона
		switch (background) {
		case BLACK:
			window.clear(Color::Black);
			break;
		case WHITE:
			window.clear(Color::White);
			break;
		case RED:
			window.clear(Color::Red);
			break;
		case YELLOW:
			window.clear(Color::Yellow);
			break;
		case GREEN:
			window.clear(Color::Green);
			break;
		case BLUE:
			window.clear(Color::Blue);
			break;
		case MAGENTA:
			window.clear(Color::Magenta);
			break;
		case CYAN:
			window.clear(Color::Cyan);
			break;
		}
		// Создаем треугольник
		CircleShape triangle(edge, angles);
		triangle.setPosition(Xcoord, Ycoord); // устанавливаем начальную позицию справа от круга
		switch (color) {
		case BLACK:
			triangle.setFillColor(Color::Black);
			break;
		case WHITE:
			triangle.setFillColor(Color::White);
			break;
		case RED:
			triangle.setFillColor(Color::Red);
			break;
		case YELLOW:
			triangle.setFillColor(Color::Yellow);
			break;
		case GREEN:
			triangle.setFillColor(Color::Green);
			break;
		case BLUE:
			triangle.setFillColor(Color::Blue);
			break;
		case MAGENTA:
			triangle.setFillColor(Color::Magenta);
			break;
		case CYAN:
			triangle.setFillColor(Color::Cyan);
			break;
		}
		window.draw(triangle); // отрисовка треугольника
		// Отрисовка окна
		window.display();
	}
	cout << "Периметр: " << perimetr << endl;
	cout << "Площадь: " << square << endl;
}

void ShowFigure(ColoredFigureOnBackground& fig) {
	Figure figure = fig.GetFigure();
	switch (figure) {
	case CIRCLE:
		ShowCircle(fig);
		break;
	case TRIANGLE:
		ShowAngle(fig, 3);
		break;
	case SQUARE:
		ShowAngle(fig, 4);
		break;
	}

}

MyColor ChooseColor() {
	MyColor choise;
	int menu;
	int cycle = 1;
	while (cycle) {
		cout << "1. Черный" << endl;
		cout << "2. Белый" << endl;
		cout << "3. Красный" << endl;
		cout << "4. Желтый" << endl;
		cout << "5. Зелёный" << endl;
		cout << "6. Голубой" << endl;
		cout << "7. Розовый" << endl;
		menu = CreateInt();
		switch (menu) {
		case 1: {
			return BLACK;
			cycle = 0;
			break;
		}
		case 2: {
			return WHITE;
			cycle = 0;
			break;
		}
		case 3: {
			return RED;
			cycle = 0;
			break;
		}
		case 4: {
			return YELLOW;
			cycle = 0;
			break;
		}
		case 5: {
			return GREEN;
			cycle = 0;
			break;
		}
		case 6: {
			return CYAN;
			cycle = 0;
			break;
		}
		case 7: {
			return MAGENTA;
			cycle = 0;
			break;
		}
		default:
		{
			cout << "Некорректный ввод" << endl;
			break;
		}
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Point points[10];
	points[0].SetX(10); points[0].SetY(10);
	points[1].SetX(50); points[1].SetY(50);
	points[2].SetX(100); points[2].SetY(150);
	points[3].SetX(100); points[3].SetY(100);
	points[4].SetX(150); points[4].SetY(150);
	points[5].SetX(150); points[5].SetY(100);
	points[6].SetX(200); points[6].SetY(200);
	points[7].SetX(10); points[7].SetY(200);
	points[8].SetX(200); points[8].SetY(10);
	points[9].SetX(200); points[9].SetY(50);
	Edge edges[5];
	edges[0].SetA(10);
	edges[1].SetA(20);
	edges[2].SetA(30);
	edges[3].SetA(40);
	edges[4].SetA(50);
	CorrectFigure corFig;
	int menu = 0;
	int cycle = 1;
	while (cycle) {
		cout << "Выберите необходимое действие:" << endl;
		cout << "1. Вывести точки" << endl;
		cout << "2. Вывести ребра" << endl;
		cout << "3. Создать фигуру" << endl;
		cout << "4. Нарисовать фигуру" << endl;
		cout << "5. Нарисовать фигуру на цветном фоне " << endl;
		cout << "6. Выйти" << endl;
		menu = CreateInt();
		switch (menu) {
		case 1: {
			PrintPoints(points, 10);
			break;
		}
		case 2: {
			PrintEdges(edges, 5);
			break;
		}
		case 3: {
			int point, edge;
			PrintPoints(points, 10); cout << "Выберите точку: "; point = CreateInt();
			if (point > 0 && point < 11) {
				point--;
				PrintEdges(edges, 5); cout << "Выберите длину ребра: "; edge = CreateInt();
				if (edge > 0 && edge < 6) {
					edge--;
					int menu1 = 0;
					cout << "Выберите фигуру, которую необходимо создать:" << endl;
					cout << "1. Круг" << endl;
					cout << "2. Треугольник" << endl;
					cout << "3. Квадрат" << endl;
					menu1 = CreateInt();
					switch (menu1) {
					case 1: {
						CorrectFigure n(points[point], edges[edge], CIRCLE);
						corFig = n;
						break;
					}
					case 2: {
						CorrectFigure n(points[point], edges[edge], TRIANGLE);
						corFig = n;
						break;
					}
					case 3: {
						CorrectFigure n(points[point], edges[edge], SQUARE);
						corFig = n;
						break;
					}
					default: {
						cout << "Некорректный ввод" << endl;
						break;
					}
					}
				}
				else {
					cout << "Некорректный ввод" << endl;
				}
			}
			else {
				cout << "Некорректный ввод" << endl;
			}
			break;
		}
		case 4: {
			//проверка на существование фигуры
			if (corFig.GetEdge() == 1) {
				cout << "Сначала создайте фигуру!" << endl;
			}
			else {
				cout << "Выберите цвет фигуры:" << endl;
				MyColor figCol = ChooseColor();
				ColoredFigure n(corFig, figCol);
				ColoredFigureOnBackground m (n, WHITE);
				ShowFigure(m);
			}
			break;
		case 5: {
			//проверка на существование фигуры
			if (corFig.GetEdge() == 1) {
				cout << "Сначала создайте фигуру!" << endl;
			}
			else {
				cout << "Выберите цвет фигуры:" << endl;
				MyColor figCol = ChooseColor();
				ColoredFigure n(corFig, figCol);
				cout << "Выберите цвет фона:" << endl;
				MyColor backCol = ChooseColor();
				ColoredFigureOnBackground m(n, backCol);
				ShowFigure(m);
			}
			break;
		}
		case 6: {
			cycle = 0;
			break;
		}
		default: {
			cout << "Некорректный ввод" << endl;
			break;
		}
		}
		}
	}
}

int CreateInt()
{
	char str[70] = "a";//заведомо ложное условие (не целое число)
	while (!CheckInt(str))
	{
		cin >> str;
		if (!CheckInt(str))
		{
			cout << "Некорректный ввод." << endl;
		}
	}
	int n = atoi(str);//перевод в целочисленный формат
	return n;
}

int CheckInt(char c[])
{
	for (int i = 0; i < strlen(c); i++)
	{
		if (c[i] > '9' || c[i] < '0')
		{
			return 0;//это не целое число
		}
	}
	return 1;//это целое число
}