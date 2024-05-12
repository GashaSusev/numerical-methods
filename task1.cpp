#include <iostream> 
#include <cmath> 
#include <iomanip> 
#include <algorithm> 

int fCounter = 0; 
int counter = 0; 
long double f(long double x) {
  fCounter++; return pow(x,5) + 5 * pow(x, 4) - 3 * pow(x, 3) + 2 * pow(x, 2) + x - 5; 
} 
long double quadraticInterpolation(long double leftBorder, long double rightBorder,long double epsilon) { 
  long double x0 = leftBorder; 
  long double x2 = rightBorder; 
  long double x1 = (x0 + x2) / 2; 
  while (abs(f(x2)) > epsilon) { 
    counter++; 

    long double f0 = f(x0); 
    long double f1 = f(x1); 
    long double f2 = f(x2); 
    long double a0 = f2; 
    long double a1 = (f1 - f2) / (x1 - x2); 
    long double a2 = ((f0 - f2) / (x0 - x2) - (f1 - f2) / (x1 - x2)) / (x0 - x1); 

    long double a = a2; 
    long double b = a2 * (x2 - x1) + a1; 
    long double c = a0; 

    long 	double discriminant = b*b - 4 * a * c; 
    if (discriminant < 0) discriminant = 0; 
    long double z; long double root1 = (-b + sqrt(discriminant)) / (2 * a); 
    long double root2 = (-b - sqrt(discriminant)) / (2 * a); 
    if (abs(root1) < abs(root2)) z = root1; 
    else z = root2; 


    x0 = x1; 
    x1 = x2; 
    x2 = x2 + z; 
  } 
  return x2; 
} 
int main() { 
  long double leftBord = 0; 
  long double rightBord = 10; 
  long double eps = pow(10, -6); 
  long double answer = quadraticInterpolation(leftBord, rightBord, eps); 
  std::cout <<"ans: " << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << answer<<" function: "<<f(answer)<<std::endl; std::cout << "fun: " << fCounter << std::endl; 
  std::cout << "iterations: " << counter << std::endl;
  return 0; 
}
