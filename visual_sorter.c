#include <raylib.h>
#include <stdlib.h>
#include <time.h> //for randomness

//TODO: time the thing and print it

#define WIDTH 700 
#define HEIGHT 700
#define COUNT 100 // XXX 233 is max limit before the int division for the width of the bar results in 0


int numbers[COUNT];
int step_i = 0;

void randomize_array(){
  srand(time(NULL)^clock()); //this is kinda bad but for this use case it gives more than enough randomness
  for(int i=0; i<COUNT; i++){
    numbers[i] = rand()%(HEIGHT - 50);
  }
}

void draw_bars(Color color, bool justone){
  if(justone){ 
    float posx =  1+(float)step_i/COUNT*WIDTH;
    float posy =  HEIGHT - numbers[step_i];
    DrawRectangle(posx, posy, WIDTH/COUNT-2, numbers[step_i], color); 
  }
  else{
    for(int i = 0; i < COUNT; i++)
      {
        float posx =  1+(float)i/COUNT*WIDTH;
        float posy =  HEIGHT - numbers[i];
        DrawRectangle(posx, posy, WIDTH/COUNT-2, numbers[i], color);  
      }
  }
}

void swap_in_numbers(int idx1, int idx2){
  int temp = numbers[idx1];
  numbers[idx1] = numbers[idx2];
  numbers[idx2] = temp;
}

void sorted(){
  SetTargetFPS(60);
  step_i = 0;
  while(step_i != COUNT)
  {
    BeginDrawing();
    ClearBackground(BLACK);
    draw_bars(LIME, true);
    EndDrawing();

    step_i+=2;
  }
  ClearBackground(BLACK);
  BeginDrawing();
  draw_bars(LIME, false);
  EndDrawing();
}

bool sort_step(){  //in this first demo, the sort function implements selection sort
  if (step_i >= COUNT-1) {
    return true; //sorted

  }
  int min_idx = step_i;
  for(int j = step_i+1; j<COUNT; j++){
    if(numbers[j]<numbers[min_idx]){
      min_idx = j;
    }
  }
  swap_in_numbers(step_i, min_idx);
  step_i++;
  BeginDrawing();
  ClearBackground(BLACK);
  draw_bars(RED, false);
  EndDrawing();
  return false;
}


int main(){
	InitWindow(WIDTH, HEIGHT, "Sorter Visualizer");
  SetTargetFPS(15);
  randomize_array();
  BeginDrawing();
  draw_bars(YELLOW, false);
  EndDrawing();
  WaitTime(3);
  ClearBackground(BLACK);
	while(!WindowShouldClose()){
    if( sort_step() ){
      sorted();
      break;
    }
	}
  WaitTime(5);
	CloseWindow();
}
