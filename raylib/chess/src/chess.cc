/**
 * @file chess.cc
 * @author Dario Regalado Glez
 * @brief 
 * @version 0.1
 * @date 2024-04-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "chess.h"

Chess::Chess() {
  numRows_ = 8;
  numCols_ = 8;
  celSize_ = 100;
  int initialGrid[numRows_][numCols_] = {
        {7, 8, 9, 10, 11, 9, 8, 7},
        {12, 12, 12, 12, 12, 12, 12, 12}, 
        {0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0}, 
        {6, 6, 6, 6, 6, 6, 6, 6}, 
        {1, 2, 3, 4, 5, 3, 2, 1}
    };

  for (int i = 0; i < numRows_; ++i) {
        for (int j = 0; j < numCols_; ++j) {
            grid[j][i] = initialGrid[i][j];
        }
    }
  peon_blanco_ = LoadTexture("C:/raylib/chess/peon_blanco.png");
  alfil_blanco_ = LoadTexture("C:/raylib/chess/alfil_blanco.png");
  caballo_blanco_ = LoadTexture("C:/raylib/chess/caballo.png");
  rey_blanco_ = LoadTexture("C:/raylib/chess/rey_blanco.png");
  reina_blanco_ = LoadTexture("C:/raylib/chess/reina_blanca.png");
  torre_blanco_ = LoadTexture("C:/raylib/chess/torre_blanca.png");

  peon_negro_ = LoadTexture("C:/raylib/chess/peon_negro.png");
  alfil_negro_ = LoadTexture("C:/raylib/chess/alfil_negro.png");
  caballo_negro_ = LoadTexture("C:/raylib/chess/caballo_negro.png");
  rey_negro_ = LoadTexture("C:/raylib/chess/rey_negro.png");
  reina_negro_ = LoadTexture("C:/raylib/chess/reina_negra.png");
  torre_negro_ = LoadTexture("C:/raylib/chess/torre_negra.png");

}
/*

void Chess::initialize() {
  grid = {
        {7, 8, 9, 10, 11, 9, 8, 7},
        {12, 12, 12, 12, 12, 12, 12, 12}, 
        {0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0}, 
        {6, 6, 6, 6, 6, 6, 6, 6}, 
        {1, 2, 3, 4, 5, 3, 2, 1}
    };
}
*/
void Chess::griddraw() {
  int temp = 0;
  for (int row = 0; row < numRows_; row++)
  {
    for (int col = 0; col < numCols_; col++)
    {
      if (temp % 2 == 0)
        DrawRectangle(row * celSize_+1, col*celSize_+1, celSize_-1, celSize_-1, RED);    
      else 
        DrawRectangle(row * celSize_+1, col*celSize_+1, celSize_-1, celSize_-1, GREEN);
      temp++;
    } 
  } 
}

void Chess::drawpieces() {
  for (int i = 0; i < numRows_; i++)
  {
    for (int j = 0; j < numCols_; j++)
    {
      switch (grid[i][j]){
      case 0:
        break;
      case 1:
        DrawTexture(torre_blanco_, i * celSize_ + 5, j * celSize_ + 5, WHITE);
        break;
      case 2:
        DrawTexture(caballo_blanco_, i * celSize_ + 5, j * celSize_ + 5, WHITE);
        break;
      case 3:
        DrawTexture(alfil_blanco_, i * celSize_ + 5, j * celSize_ + 5, WHITE);
        break;  
      case 4:
        DrawTexture(reina_blanco_, i * celSize_ + 5, j * celSize_ + 5, WHITE);
        break;
      case 5:
        DrawTexture(rey_blanco_, i * celSize_ + 5, j * celSize_ + 5, WHITE);
        break;
      case 6:
        DrawTexture(peon_blanco_, i * celSize_ + 5, j * celSize_ + 5, WHITE);
        break;
      case 7:
        DrawTexture(torre_negro_, i * celSize_ + 5, j * celSize_ + 5, WHITE);
        break;
      case 8:
        DrawTexture(caballo_negro_, i * celSize_ + 5, j * celSize_ + 5, WHITE);
        break;
      case 9:
        DrawTexture(alfil_negro_, i * celSize_ + 5, j * celSize_ + 5, WHITE);
        break;
      case 10:
        DrawTexture(reina_negro_, i * celSize_ + 5, j * celSize_ + 5, WHITE);
        break;
      case 11:
        DrawTexture(rey_negro_, i * celSize_ + 5, j * celSize_ + 5, WHITE);
        break;
      case 12:
        DrawTexture(peon_negro_, i * celSize_ + 5, j * celSize_ + 5, WHITE);
        break;
      }
    } 
  }
}

void Chess::update1(int x, int y, int new_x, int new_y) {
  x /= 100;
  y /= 100;
  new_x /= 100;
  new_y /= 100;
  if (isValidPosition(new_x, new_y) && grid[x][y] > 0) {
    if (grid[x][y] <= 6 && (grid[new_x][new_y] >= 7 || grid[new_x][new_y] == 0) ) {
      grid[new_x][new_y] = grid[x][y];
      grid[x][y] = 0;
    } else if(grid[x][y] >= 7 && (grid[new_x][new_y] <= 6 || grid[new_x][new_y] == 0)) {
      grid[new_x][new_y] = grid[x][y];
      grid[x][y] = 0;
    }
  }
}

bool Chess::isValidPosition(int x, int y) {
    return x >= 0 && x < numCols_ && y >= 0 && y < numRows_;
}

void Chess::drawRookMoves(int x, int y) {
    for (int i = 0; i < numRows_; ++i) {
        if (grid[x][i] == 0) {
            DrawCircle(x * celSize_ + celSize_ / 2, i * celSize_ + celSize_ / 2, 10, BLUE);  // Suponiendo 1 es color GREEN
        }
    }
    for (int i = 0; i < numCols_; ++i) {
        if (grid[i][y] == 0) {
            DrawCircle(i * celSize_ + celSize_ / 2, y * celSize_ + celSize_ / 2, 10, BLUE);
        }
    }
}

void Chess::drawKnightMoves(int x, int y) {
    const int knightMoves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    for (const auto& move : knightMoves) {
        int newX = x + move[0];
        int newY = y + move[1];
        if (isValidPosition(newX, newY) && grid[newX][newY] == 0) {
            DrawCircle(newX * celSize_ + celSize_ / 2, newY * celSize_ + celSize_ / 2, 10, BLUE);
        }
    }
}

void Chess::drawBishopMoves(int x, int y) {
    for (int i = 1; i < numRows_; ++i) {
        if (isValidPosition(x + i, y + i) && grid[x + i][y + i] == 0) {
            DrawCircle((x + i) * celSize_ + celSize_ / 2, (y + i) * celSize_ + celSize_ / 2, 10, BLUE);
        }
        if (isValidPosition(x - i, y + i) && grid[x - i][y + i] == 0) {
            DrawCircle((x - i) * celSize_ + celSize_ / 2, (y + i) * celSize_ + celSize_ / 2, 10, BLUE);
        }
        if (isValidPosition(x + i, y - i) && grid[x + i][y - i] == 0) {
            DrawCircle((x + i) * celSize_ + celSize_ / 2, (y - i) * celSize_ + celSize_ / 2, 10, BLUE);
        }
        if (isValidPosition(x - i, y - i) && grid[x - i][y - i] == 0) {
            DrawCircle((x - i) * celSize_ + celSize_ / 2, (y - i) * celSize_ + celSize_ / 2, 10, BLUE);
        }
    }
}

void Chess::drawQueenMoves(int x, int y) {
    drawRookMoves(x, y);
    drawBishopMoves(x, y);
}

void Chess::drawKingMoves(int x, int y) {
    const int kingMoves[8][2] = {
        {1, 0}, {1, 1}, {0, 1}, {-1, 1},
        {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
    };

    for (const auto& move : kingMoves) {
        int newX = x + move[0];
        int newY = y + move[1];
        if (isValidPosition(newX, newY) && grid[newX][newY] == 0) {
            DrawCircle(newX * celSize_ + celSize_ / 2, newY * celSize_ + celSize_ / 2, 10, BLUE);
        }
    }
}

void Chess::drawPawnMoves(int x, int y, bool isWhite) {
    int direction = isWhite ? -1 : 1;
    if (isValidPosition(x, y + direction) && grid[x][y + direction] == 0) {
        DrawCircle(x * celSize_ + celSize_ / 2, (y + direction) * celSize_ + celSize_ / 2, 10, BLUE);
    }
    // Add pawn's capture moves, initial two-step move, etc., if needed
}

void Chess::drawpositions(int x, int y) {
    x /= celSize_;
    y /= celSize_;
    int piece = grid[x][y];

    switch (piece) {
        case 0:
            break;
        case 1: // Torre blanca
        case 7: // Torre negra
            drawRookMoves(x, y);
            break;
        case 2: // Caballo blanco
        case 8: // Caballo negro
            drawKnightMoves(x, y);
            break;
        case 3: // Alfil blanco
        case 9: // Alfil negro
            drawBishopMoves(x, y);
            break;
        case 4: // Reina blanca
        case 10: // Reina negra
            drawQueenMoves(x, y);
            break;
        case 5: // Rey blanco
        case 11: // Rey negro
            drawKingMoves(x, y);
            break;
        case 6: // Peón blanco
            drawPawnMoves(x, y, true);
            break;
        case 12: // Peón negro
            drawPawnMoves(x, y, false);
            break;
        default:
            break;
    }
}

void Chess::print() {
  for (int row = 0; row < numRows_; row++)
  {
    for (int col = 0; col < numCols_; col++)
    {
      cout << grid[row][col] << " ";
    }
    cout << endl;
  }
    cout << endl;
    cout << endl;
}




