// // map_at.cpp
// // compile with: /EHsc
// #include <map>
// #include <iostream>
// #include <math.h>
// #include <string>
// #include <SDL.h>
// #include <SDL_image.h>
// #include <stdio.h>
// #include <stdlib.h>
// typedef std::map<std::string, SDL_Rect> Mymap;
// int main(int argc, char *argv[])
//     {
//     Mymap c1;
//     SDL_Rect a = {1,1,1,1};
//     c1.insert(Mymap::value_type("AB", a));
//     // c1.insert(Mymap::value_type("BC", 2));
//     // c1.insert(Mymap::value_type("CD", 3));

// // find and show elements
// std::string a = "AD"; std::string b = "AD";
//     std::cout << "c1.at(AB) == " << c1.at("AB").h << "HEllo " << std::endl;
//     // std::cout << "c1.at('b') == " << c1.at("BC") << std::endl;
//     // std::cout << "c1.at('c') == " << c1.at("CD") << std::endl;

//     return (0);
//     }