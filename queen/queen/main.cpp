//
//  main.cpp
//  queen
//
//  Created by Manny Juarez on 6/6/16.
//  Copyright © 2016 Manny Juarez. All rights reserved.
//

#define N 8

int board[N][N];

void initialize(int board[N][N]){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      board[i][j] = 0;
    }
  }
}


bool isSafe(int x, int y){
  
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if( ((i == x) || (j == y) ||(abs(i-x) == abs(j-y))) && board[i][j] == 1  )
        return false;
    }
  }
  return true;
}


int done=0;
void placeQueen(int x, int y){
  
  if(y == N){
    done++;
    return;
  }
  
  for(int i=0; x+i < N; i++){
    if(!done && isSafe(x+i, y)){
      board[x+i][y] = 1;
      placeQueen(0, y+1);
      if(!done) board[x+i][y] = 0;
    }
  }
}


void printBoard(){
  if(!done) return;
  printf("\n\n");
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      printf("%2d ", board[i][j]);
    }
    printf("\n\n");
  }
}

void placeEightQueens(){
  initialize(board);
  placeQueen(0, 0);
  printBoard();
  if(!done) printf("\nNOT POSSIBLE");
  done = 0;
}

int main(){
  
  placeEightQueens();
  
  return 0;
}
