#pragma once
#include <string>

class Complex
{
    public:
        Complex();
        Complex(float real, float imaginary);

        [[nodiscard]] float getReal() const;
        [[nodiscard]] float getImaginary() const;

        [[nodiscard]] Complex add(Complex complex) const;
        [[nodiscard]] Complex subtract(Complex complex) const;

        [[nodiscard]] Complex multiplyBy(Complex complex) const;
        [[nodiscard]] Complex divideBy(Complex complex) const;

        [[nodiscard]] Complex opposite() const;
        [[nodiscard]] Complex conjugate() const;

        [[nodiscard]] Complex inverse() const;
        [[nodiscard]] std::string toString() const;

        void print() const;
        void print(std::string prefix) const;

    private:
        float m_real, m_imaginary;
};