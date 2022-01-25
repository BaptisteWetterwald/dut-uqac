#include <iostream>
#include "Complex.h"

int main()
{
    /*
     * Comments are expected results for z1 = 2+3i and z2 = -5+31i
     * Replace z1 and z2 with the ones you want at line 15 and line 19
    */

    //*****************************************
    //                  Init

    // z1 = 2 + 3i
    const Complex z1(2, 3);
    z1.print("Chosen: z1 = ");

    // z2 = -5 + 31i
    const Complex z2(-5, 31);
	z2.print("Chosen: z2 = ");

	//               End of init
    //*****************************************

    //Opposite: z1 = -2 - 3i
    std::cout << "Opposite of z1:\n";
    z1.opposite().print();

    //Conjugate: z1 = 2 - 3i
    std::cout << "Conjugate of z1:\n";
    z1.conjugate().print();

    try
    {
        //Inverse: 1/z1 = 2/13 - i*3/13
        std::cout << "Inverse of z1:\n";
        z1.inverse().print("1/z1 = ");
    }
	catch (const std::overflow_error &e)
	{
	    std::cout << e.what();
	    std::cout << "\n\n";
	}

    //Addition: z1 + z2 = -3 + 34i
    std::cout << "Addition (z1 + z2):\n";
    z1.add(z2).print();

    //Substraction: z1 - z2 = 7 - 28i
    std::cout << "Substraction (z1 - z2):\n";
    z1.subtract(z2).print();

    //Multiplication: z1 * z2 = -103 + 47i
    std::cout << "Multiplication (z1 * z2) :\n";
    z1.multiplyBy(z2).print();

    try
    {
        //Division: z1/z2 = 83/986 - i*77/986
        std::cout << "Division (z1 / z2):\n";
        z1.divideBy(z2).print();
    }
	catch (const std::overflow_error &e)
	{
	    std::cout << e.what();
	    std::cout << "\n\n";
	}
}