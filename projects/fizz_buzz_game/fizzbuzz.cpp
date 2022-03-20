#include <iostream>

void introduction();
void engine(int &start, int end);

int main() {

  int start = 1;
  const int end = 100;

  introduction();
  engine(start, end);

  return 0;
}

void introduction() {
  std::cout << "Welcome to Fizz Buzz Automated Game!" << std::endl;
  std::cout << "This program will output numbers from 1 to 100." << std::endl;
  std::cout << "- For multiples of 3, print 'Fizz'" << std::endl;
  std::cout << "- For multiples of 5, print 'Buzz'" << std::endl;
  std::cout << "- For multiples of 3 and 5, print 'FizzBuzz'" << std::endl;
  std::cout << "\n";
}

void engine(int &start, int end) {
  do {
    if (start % 3 == 0 && start % 5 == 0)
      std::cout << "FizzBuzz" << std::endl;
    else if (start % 3 == 0) 
      std::cout << "Fizz" << std::endl;
    else if (start % 5 == 0)
      std::cout << "Buzz" << std::endl;
    else
      std::cout << start << std::endl;
    start++;
  } while (start <= end);
}
