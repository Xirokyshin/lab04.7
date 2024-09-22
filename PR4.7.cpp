#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
	int n = 0;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

    // �������� ���������� � ������� �������
    if (xp <= 0 || xk <= 0) {
        cout << "x maye bytu > 0" << endl;
        return 1;
    }
	cout << fixed;
	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(10) << "ln(x)" << " |"
		<< setw(7) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-------------------------------------------------" << endl;

	x = xp;
    while (x <= xk)
    {
        // �������� ��������
        n = 0;
        a = 2 * (x - 1) / (x + 1); 
        S = a; 
        
        do {
            n++;
            // ���������� ������������
            R = pow(x - 1, 2 * n + 1) / ((2 * n + 1) * pow(x + 1, 2 * n + 1));
            S += R;
        } while (abs(R) >= eps);
        
        // ��������� ����������
        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(10) << setprecision(5) << log(x) << " |"
             << setw(10) << setprecision(5) << S << " |"
             << setw(5) << n << " |"
             << endl;
              
        x += dx;
    }

    cout << "-------------------------------------------------" << endl;
    return 0;
}