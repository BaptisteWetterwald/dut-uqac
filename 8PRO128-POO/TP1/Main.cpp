#include <iostream>
#include "Complex.h"
#include <string>

void print(std::string, Complex);
void print(Complex);

int main()
{
    /*
     * Comments are expected results for z1 = 2+3i and z2 = -5+31i
     * Replace z1 and z2 with the ones you want at L16 and L20
    */

    // z1 = 2 + 3i
    Complex z1(2, 3);
    print("Chosen: z1 = ", z1);

    // z2 = -5 + 31i
    Complex z2(-5, 31);
    print("Chosen: z2 = ", z2);

    //Opposite: z1 = -2 - 3i
    std::cout << "Opposite of z1:\n";
    print(z1.opposite());

    //Conjugate: z1 = 2 - 3i
    std::cout << "Conjugate of z1:\n";
    print(z1.conjugate());

    try
    {
        //Inverse: 1/z1 = 2/13 - i*3/13
        std::cout << "Inverse of z1:\n";
        print("1/z = ", z1.inverse());
    }
	catch (std::overflow_error e)
	{
        std::cout << e.what();
        std::cout << "\n\n";
	}

    //Addition: z1 + z2 = -3 + 34i
    std::cout << "Addition (z1 + z2):\n";
    print(z1.add(z2));

    //Substraction: z1 - z2 = 7 - 28i
    std::cout << "Substraction (z1 - z2):\n";
    print(z1.subtract(z2));

    //Multiplication: z1 * z2 = -103 + 47i
    std::cout << "Multiplication(z1 * z2) :\n";
    print(z1.multiplyBy(z2));

    try
    {
        //Division: z1/z2 = 83/986 - i*77/986
        std::cout << "Division (z1 / z2):\n";
        print(z1.divideBy(z2));
    }
    catch (std::overflow_error e)
    {
        std::cout << e.what();
        std::cout << "\n\n";
    }

}

void print(const std::string prefix, Complex c)
{
    std::cout << prefix + c.toString() + "\n\n";
}

void print(Complex c)
{
    std::cout << c.toString() + "\n\n";
}

