#include <iostream>

void input_answer(int &answer);
void question1(int &answer);
void question2(int &answer);
void question3(int &answer);
void question4(int &answer);
void highest_house(int &max);

int gryffindor = 0,
    hufflepuff = 0,
    ravenclaw = 0,
    slytherin = 0;

int main() {
  int answer1, answer2, answer3, answer4;
  int max = 0;
  std::cout << "The Sorting Hat Quiz!" << std::endl;
  question1(answer1);
  question2(answer2);
  question3(answer3);
  question4(answer4);

  highest_house(max);

  system("pause");
}

void input_answer(int &answer) {
  std::cout << "Enter your answer: ";
  std::cin >> answer;
}

void question1(int &answer) {
  std::cout << "Q1) When I'm dead, I want people to remember me as:" << std::endl
            << "\n  1) The Good"
            << "\n  2) The Great"
            << "\n  3) The Wise"  
            << "\n  4) The Bold" << std::endl;
  input_answer(answer);

  if (answer == 1) hufflepuff++;
  else if (answer == 2) slytherin++;
  else if (answer == 3) ravenclaw++;
  else if (answer ==4) gryffindor++;
  else std::cout << "Invalid input." << std::endl;
}

void question2(int &answer) {
  std::cout << "\nQ2) Dawn or Dusk?" << std::endl
            << "\n  1) Dawn"
            << "\n  2) Dusk" << std::endl;
  input_answer(answer);

  if (answer == 1) gryffindor++, ravenclaw++;
  else if (answer == 2) hufflepuff++, slytherin++;
  else std::cout << "Invalid input." << std::endl;
}

void question3(int &answer) {
  std::cout << "\nQ3) Which kind of instrument most pleases your ear?" << std::endl
            << "\n  1) The violin"
            << "\n  2) The trumpet"
            << "\n  3) The piano"
            << "\n  4) The drum" << std::endl;
  input_answer(answer);
  if (answer == 1) slytherin++;
  else if (answer == 2) hufflepuff++;
  else if (answer == 3) ravenclaw++;
  else if (answer == 4) gryffindor++;
  else std::cout << "Invalid input." << std::endl;
}

void question4(int &answer) {
    std::cout << "\nQ4) Which road tempts you most?" << std::endl
              << "\n  1) The wide, sunny grassy lane"
              << "\n  2) The narrow, dark, lantern-lit alley"
              << "\n  3) The twisting, leaf-strewn path through woods"
              << "\n  4) The cobbled street lined (ancient buildings)" << std::endl;
  input_answer(answer);
  if (answer == 1) hufflepuff++;
  else if (answer == 2) slytherin++;
  else if (answer == 3) gryffindor++;
  else if (answer == 4) ravenclaw++;
  else std::cout << "Invalid input." << std::endl;
}

void highest_house(int &max){
  std::string house = "";

  if (gryffindor > max) {
    max = gryffindor;
    house = "Gryffindor";
  }
  else if (hufflepuff > max) {
    max = hufflepuff;
    house = "Hufflepuff";
  }
  else if (ravenclaw > max) {
    max = ravenclaw;
    house = "Ravenclaw";
  }
  else if (slytherin > max) {
    max = slytherin;
    house = "Slytherin";
  }

  std::cout << "\n" << house << " is the winner!\n";
}
