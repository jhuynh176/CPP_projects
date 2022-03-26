//header declaration
#include "profile.hpp"

//library
#include <iostream>

  Profile::Profile(std::string new_name, int new_age, std::string new_city, std::string new_country, std::string new_pronouns)
  : 
  name(new_name),
  age(new_age),
  city(new_city),
  country(new_country),
  pronouns(new_pronouns)
  {};

  std::string Profile::view_profile(){
    std::string profile_info = 
                        "Name: " + name
                        + "\nAge: " + std::to_string(age)
                        + "\nCity: " + city
                        + "\nPronouns: " + pronouns;
    //hobbies
    profile_info += "\nHobbies: ";
    for(auto c : hobbies) profile_info += "\n\t - " + c;

    return profile_info;
  }

  void Profile::add_hobby(std::string new_hobby){
    hobbies.push_back(new_hobby);
  }