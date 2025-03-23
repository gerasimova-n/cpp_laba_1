#include <iostream>
#include <string>
using namespace std;

class CompNum {
private:
	float mod;
	float arg;

public:
	CompNum(float m = 0.0, float a = 0.0) : mod(m), arg(a) { }

	void setMod(float mod) { this->mod = mod; }
	void setArg(float arg) { this->arg = arg; }
	float getMod() const { return CompNum::mod; }
	float getArg() const { return CompNum::arg; }

	//Ввод числа
	friend istream& operator>> (istream& in, CompNum& num);

	//Вывод числа
	friend ostream& operator<< (ostream& out, const CompNum& num);

	//сложить
	CompNum operator+ (const CompNum& num) const {
		CompNum sum;
		sum.setMod(mod + num.mod);
		sum.setArg(arg + num.arg);
		return sum;
	}

	//умножить
	CompNum operator* (const CompNum& num) const {
		CompNum comp;
		comp.setMod(mod * num.mod);
		comp.setArg(arg + num.arg);
		return comp;
	}

	//Возведение в степень
	void powNum(int a) {
		float b = mod;
		for (int i = 1; i < a; i++) {
			mod *= b;
		}
		arg *= a;
	}
};

ostream& operator<< (ostream& out, const CompNum& num) {
	int a = (int)num.arg % 360;
	string radian;
	switch (a) {
	case 0:
		radian = "0"; break;
	case 30:
		radian = "Pi/6"; break;
	case 45:
		radian = "Pi/4"; break;
	case 60:
		radian = "Pi/3"; break;
	case 90:
		radian = "Pi/2"; break;
	case 120:
		radian = "2Pi/3"; break;
	case 135:
		radian = "3Pi/4"; break;
	case 150:
		radian = "5Pi/6"; break;
	case 180:
		radian = "Pi"; break;
	default:
		radian = to_string((float)a / 180) + " Pi";
	}
	out << num.mod << " * (cos(" << radian << ") + i * sin(" << radian << "))";
	return out;
}

istream& operator>> (istream& in, CompNum& num) {
	float m, a;
	in >> m >> a;
	num.setMod(m);
	num.setArg(a);
	return in;
}

int main() {
	setlocale(LC_ALL, "Russian");
	CompNum num1, num2;
	cout << "Введите модуль и аргумент первого числа в градусах: ";
	while (!(cin >> num1)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Вы неправильно ввели переменную, давайте заново: ";
	}
	cout << "Введите модуль и аргумент второго числа в градусах: ";
	while (!(cin >> num2)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Вы неправильно ввели переменную, давайте заново: ";
	}

	cout << "Результат сложения чисел: " << num1 + num2 << endl;
	cout << "Результат умножения чисел: " << num1 * num2 << endl;

	int p;
	cout << "Возвести число 1 в степень: ";
	while (!(cin >> p)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Вы неправильно ввели переменную, давайте заново: ";
	}
	num1.powNum(p);
	cout << "Результат возведения в степень: " << num1 << endl;

}