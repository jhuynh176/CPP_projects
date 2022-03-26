//header declaration
#include "profile.hpp"

//library
#include <iostream>

int main() {
  Profile sam("Sam Drakkila",
              30,
              "New York",
              "USA",
              "he/him");
  //add hobbies
  sam.add_hobby("listening to audiobooks and podcasts");
  sam.add_hobby("playing rec sports like bowling and kickball");
  sam.add_hobby("writing a speculative fiction novel");
  sam.add_hobby("reading advice columns");
  
  std::string profile_info = sam.view_profile();  
  std::cout << profile_info << std::endl;
}