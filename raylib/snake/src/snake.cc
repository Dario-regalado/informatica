/**
 * @file snake.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "snake.h"

Snake::Snake() {
  lenght_ = 1;
  direccion_ = north;
  ingame_ = true;
  nrow_ = 20;
  ncol_ = 20;
  cellsize_ = 600 / nrow_;
  for (int i = 0; i < nrow_; i++) {
    for (int j = 0; j < ncol_; j++)
    {
      grid[i][j] = 0;
    }
  }
  pos.push_front(new dll_node_t<Pair>(Pair(20/2, 20/2)));
}

void Snake::DrawBackground(){
  for (int i = 0; i < GetNrow(); i++) {
    for (int j = 0; j < GetNcol(); j++) {
      if ((i + j)%2 == 0)
        DrawRectangle(i * GetCellsize()+1, j * GetCellsize()+1, GetCellsize()-1, GetCellsize()-1, GREEN);
      else
        DrawRectangle(i * GetCellsize()+1, j * GetCellsize()+1, GetCellsize()-1, GetCellsize()-1, LIGHTGRAY);
    }
  }
}

void Snake::DrawSnake() {
  dll_node_t<Pair>* aux = pos.get_head();
  while(aux != NULL) {
    DrawRectangle(aux->get_data().row * cellsize_, aux->get_data().col * cellsize_, cellsize_, cellsize_, BLUE);
    aux = aux->get_next();
  }
}

void Snake::Update(Direction direccion) {
  Pair temp = pos.get_head()->get_data();
  switch (direccion)
  {
  case north:
    temp.col--;
    break;
  case south:
    temp.col++;
    break;
  case east:
    temp.row++;
    break;
  case west:
    temp.row--;
    break;
  default:
    break;
  }
  //comprobar si esta dentro de los bordes y o si colisiona consigo mismo
  if(temp.row > nrow_ || temp.col > ncol_) ingame_ = false;

  dll_node_t<Pair>* aux = pos.get_head();
  while (aux != NULL) {
    if(temp == aux->get_data()) ingame_ = false;
    aux = aux->get_next();
  }
  if(ingame_){
    pos.push_front(new dll_node_t<Pair>(Pair(temp)));
    // si no come manzana, la cola se mueve tb
    if(grid[temp.row][temp.col] != 2) pos.pop_back();
  }
}