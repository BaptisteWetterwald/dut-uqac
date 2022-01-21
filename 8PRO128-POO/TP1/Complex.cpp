#include "Complex.h"
#include <iostream>
#include <format>
#include <string>

Complex::Complex()
{
	m_real = m_imaginary = 0;
}

Complex::Complex(float real, float imaginary)
{
	m_real = real;
	m_imaginary = imaginary;
}

float Complex::getReal()
{
	return m_real;
}

float Complex::getImaginary()
{
	return m_imaginary;
}

Complex Complex::add(Complex complex)
{
	return Complex(m_real + complex.getReal(), m_imaginary + complex.getImaginary());
}

Complex Complex::subtract(Complex complex)
{
	return Complex(m_real - complex.getReal(), m_imaginary - complex.getImaginary());
}

Complex Complex::multiplyBy(Complex complex)
{
	return Complex(
		m_real * complex.getReal() - m_imaginary * complex.getImaginary(),
		m_real * complex.getImaginary() + m_imaginary * complex.getReal()
	);
}

Complex Complex::divideBy(Complex complex)
{
	if (!(complex.getReal() == 0 && complex.getImaginary() == 0))
	{
		float a = m_real;
		float b = m_imaginary;
		float c = complex.getReal();
		float d = complex.getImaginary();

		float real = (a*c + b*d) / (c*c + d*d);
		float imaginary = (b*c - a*d) / (c*c + d*d);

		return Complex(real, imaginary);
	}
	throw std::overflow_error("Cannot divide by 0.");
}

Complex Complex::opposite()
{
	return Complex(-m_real, -m_imaginary);
}


Complex Complex::conjugate()
{
	return Complex(m_real, -m_imaginary);
}

Complex Complex::inverse()
{
	if (m_real == 0 && m_imaginary == 0)
		throw std::overflow_error("Cannot divide by 0.");
	float a = m_real;
	float b = m_imaginary;

	return Complex(a/(a*a+b*b), -b/(a*a+b*b));
}


void Complex::print()
{
	std::cout << this->toString() + "\n\n";
}

void Complex::print(std::string prefix)
{
	std::cout << prefix + this->toString() + "\n\n";
}

std::string Complex::toString()
{
	std::string s;
	if (m_real == 0 && m_imaginary == 0) // a=0 & b=0
		s = "0";
	else if (m_imaginary == 0) // a!=0 & b=0
		s = std::format("{:g}", m_real);
	else if (m_real == 0) // a=0 & b!=0
		if (m_imaginary == 1) // a=0 & b=1
			s = "i";
		else if (m_imaginary == -1) // a=0 & b=(-1)
			s = "- i";
		else // a=0 & b!=0, b!=(-1), b!=1
			s = std::format("{:g}", m_imaginary) + "i";
	else // a!=0 & b!=0
		s = std::format("{:g}", m_real) + (m_imaginary>0 ? "+" + std::format("{:g}", m_imaginary) : std::format("{:g}", m_imaginary)) + +"i";
	return s;
}