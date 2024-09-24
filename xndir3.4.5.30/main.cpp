#include <iostream>
#include "polynomial.hpp"


int main() {
    Polynomial poly1;
    Polynomial poly2;

    //3x^3 + 2x^2 + 5x^1
    poly1.addTerm(3, 3);
    poly1.addTerm(2, 2);
    poly1.addTerm(5, 1);

  //1x^2 + 4x^1 + 6x^0
    poly2.addTerm(1, 2);
    poly2.addTerm(4, 1);
    poly2.addTerm(6, 0);

    std::cout << "Polynomial 1: ";
    poly1.print();
    std::cout << "Polynomial 2: ";
    poly2.print();

    
    Polynomial diff = poly1.subtract(poly2);
    std::cout << "Subtraction :";
    diff.print();

    
    Polynomial product = poly1.multiply(poly2);
    std::cout << "Multiplication: ";
    product.print();

    double x = 2.0;
    double result = poly1.arjeqTvyalKetum(x);
    std::cout << "Value of polynomial at x = " << x << " is: " << result << std::endl;

    return 0;
}
