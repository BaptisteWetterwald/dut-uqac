#include "Complex.h"
#include <iostream>
#include <format>
#include <string>

Complex::Complex()
{
	m_real = m_imaginary = 0;
}

Complex::Complex(const float real, const float imaginary)
{
	m_real = real;
	m_imaginary = imaginary;
}

float Complex::getReal() const
{
	return m_real;
}

float Complex::getImaginary() const
{
	return m_imaginary;
}

Complex Complex::add(const Complex complex) const
{
	return Complex(m_real + complex.getReal(), m_imaginary + complex.getImaginary());
}

Complex Complex::subtract(const Complex complex) const
{
	return Complex(m_real - complex.getReal(), m_imaginary - complex.getImaginary());
}

Complex Complex::multiplyBy(const Complex complex) const
{
	return Complex(
		m_real * complex.getReal() - m_imaginary * complex.getImaginary(),
		m_real * complex.getImaginary() + m_imaginary * complex.getReal()
	);
}

Complex Complex::divideBy(const Complex complex) const
{
	if (!(complex.getReal() == 0 && complex.getImaginary() == 0))
	{
		const float a = m_real;
		const float b = m_imaginary;
		const float c = complex.getReal();
		const float d = complex.getImaginary();

		const float real = (a*c + b*d) / (c*c + d*d);
		const float imaginary = (b*c - a*d) / (c*c + d*d);

		return Complex(real, imaginary);
	}
	throw std::overflow_error("Cannot divide by 0.");
}

Complex Complex::opposite() const
{
	return Complex(-m_real, -m_imaginary);
}


Complex Complex::conjugate() const
{
	return Complex(m_real, -m_imaginary);
}

Complex Complex::inverse() const
{
	if (m_real == 0 && m_imaginary == 0)
		throw std::overflow_error("Cannot divide by 0.");
	const float a = m_real;
	const float b = m_imaginary;

	return Complex(a/(a*a+b*b), -b/(a*a+b*b));
}


void Complex::print() const
{
	std::cout << this->toString() + "\n\n";
}

void Complex::print(const std::string prefix) const
{
	std::cout << prefix + this->toString() + "\n\n";
}

std::string Complex::toString() const
{
	std::string s;
	
	if (m_real == 0 && m_imaginary == 0) // a=0 & b=0
		s = "0";
	else
	{
		std::string sImaginary;

		const std::string sReal = m_real != 0 ? std::format("{:g}", m_real) : "";

		if (m_imaginary != 0)
		{
			if (m_imaginary != -1 && m_imaginary != 1)
				sImaginary = (m_imaginary > 0 ? (m_real != 0 ? "+" : "") : "") + std::format("{:g}", m_imaginary);
			else
				sImaginary = m_imaginary == -1 ? "-" : (m_real != 0 ? "+" : "");
			sImaginary += "i";
		}
		
		s = sReal + sImaginary;
	}

	return s;
}