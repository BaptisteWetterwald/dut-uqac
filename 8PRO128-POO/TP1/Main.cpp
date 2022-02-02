#include <iostream>
#include "Complex.h"

int main()
{
    /*
     * Comments are expected results for z1 = 2+3i and z2 = -5+31i
    */

    //*****************************************
    //                  Init

    // z1 = 2 + 3i
    float real, imaginary;
    std::cout << "Enter real part of z1: ";
    std::cin >> real;
    std::cout << "Enter imaginary part of z1: ";
    std::cin >> imaginary;
    const Complex z1(real, imaginary);
    z1.print("Chosen: z1 = ");

    // z2 = -5 + 31i
    std::cout << "Enter real part of z2: ";
    std::cin >> real;
    std::cout << "Enter imaginary part of z2: ";
    std::cin >> imaginary;
    const Complex z2(real, imaginary);
	z2.print("Chosen: z2 = ");

	//               End of init
    //*****************************************

    //Opposite: z1 = -2 - 3i
    std::cout << "Opposite of z1:" << std::endl;
    z1.opposite().print();

    //Conjugate: z1 = 2 - 3i
    std::cout << "Conjugate of z1:" << std::endl;
    z1.conjugate().print();

    try
    {
        //Inverse: 1/z1 = 2/13 - i*3/13
        std::cout << "Inverse of z1:" << std::endl;
        z1.inverse().print("1/z1 = ");
    }
	catch (const std::overflow_error &e)
	{
	    std::cout << e.what() << std::endl << std::endl;
	}

    //Addition: z1 + z2 = -3 + 34i
    std::cout << "Addition (z1 + z2):" << std::endl;
    z1.add(z2).print();

    //Substraction: z1 - z2 = 7 - 28i
    std::cout << "Substraction (z1 - z2):" << std::endl;
    z1.subtract(z2).print();

    //Multiplication: z1 * z2 = -103 + 47i
    std::cout << "Multiplication (z1 * z2) :" << std::endl;
    z1.multiplyBy(z2).print();

    try
    {
        //Division: z1/z2 = 83/986 - i*77/986
        std::cout << "Division (z1 / z2):" << std::endl;
        z1.divideBy(z2).print();
    }
	catch (const std::overflow_error &e)
	{
	    std::cout << e.what() << std::endl << std::endl;
	}
}