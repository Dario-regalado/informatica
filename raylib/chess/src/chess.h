/**
 * @file chess.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include "raylib.h"
using namespace std;


class Chess {
 public:
  Chess();
  int grid[8][8];
  void drawpositions(int, int); //dibuja las casillas que puedes mover tu pieza
  void griddraw();
  void drawpieces();
  void update1(int, int, int, int);
  void print();

  
 private:
  Texture2D peon_blanco_, alfil_blanco_, caballo_blanco_, rey_blanco_, reina_blanco_, torre_blanco_;
  Texture2D peon_negro_, alfil_negro_, caballo_negro_, rey_negro_, reina_negro_, torre_negro_;
  void initialize();
  int numRows_;
  int numCols_;
  int celSize_;
  bool isValidPosition(int, int);
  void drawRookMoves(int x, int y);
  void drawKnightMoves(int x, int y);
  void drawBishopMoves(int x, int y);
  void drawQueenMoves(int x, int y);
  void drawKingMoves(int x, int y);
  void drawPawnMoves(int x, int y, bool isWhite);
 
};
/**
 * 0 = null
 * 1 = torre blanca
 * 2 = caballo blanco
 * 3 = alfil blanco
 * 4 = reina blanco
 * 5 = rey blanco
 * 6 = peon blanco
 * 
 * 7 = torre negro
 * 8 = caballo negro
 * 9 = afil negro
 * 10 = reina negro
 * 11 = rey negro
 * 12 = peon negro
 */