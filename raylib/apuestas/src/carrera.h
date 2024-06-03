/**
 * @file carrera.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include "raylib.h"
using namespace std;

class Carrera {
 public:
  Carrera(int, int, int);
  void update();
  void print();
  int winer();
  void reinitialize();
 private:
  int widht_screen_;
  int height_screen_;
  int pixel_;
  int n_caballos_;
  Texture2D caballo_;
  vector<int> desplazamiento_;
};