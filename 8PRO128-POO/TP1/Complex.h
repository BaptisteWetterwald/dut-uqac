#include <string>

class Complex
{
    public:
        Complex();
        Complex(float real, float imaginary);

        float getReal();
        float getImaginary();

        Complex add(Complex complex);
        Complex subtract(Complex complex);

        Complex multiplyBy(Complex complex);
        Complex divideBy(Complex complex);

        Complex opposite();
        Complex conjugate();

        Complex inverse();
        std::string toString();

        void print();

    private:
        float m_real, m_imaginary;
};
