#include <stdio.h>
#include <raylib.h>
#include <unistd.h>

#define WIDTH 1200
#define HEIGHT 600

#define LEN_LIST 20
#define LIST_MAX 100
#define GAP 5

const int l_value =(WIDTH-(GAP *(LEN_LIST+2))) /LEN_LIST ;

int values[LEN_LIST] = {17,100,27,63,71,87,42,26,01,52,65,96,61,28,36,14,75,46,56,15};
Vector4 past_values[20];

int main(int argc, char *argv[]) {
  InitWindow(WIDTH, HEIGHT, "Sort Graphic");
  SetTargetFPS(60);

  while(!WindowShouldClose()) {
    int prev_value = 0;
    Vector2 start = (Vector2) {l_value * 0.66 + GAP,HEIGHT - GAP*1.5};
    BeginDrawing();
    for (int i=0; i<LEN_LIST; i++ ) {
      Vector2 start2 = (Vector2) {l_value * 0.66 +GAP,HEIGHT - GAP*1.5};
      for (int i = 0; i<LEN_LIST; i++) {
        Vector2 end2 = (Vector2) {start2.x, HEIGHT - (values[i] *(HEIGHT / LIST_MAX) +(GAP*2)) + values[i]/GAP};
        DrawLineEx(start2, end2, l_value ,GRAY);
        start2.x += l_value + GAP ;
      }

      if(values[i] <= values[i-1] && prev_value!= 0) {
        prev_value = values[i-1]; 
        values[i-1] = values[i];
        values[i] = prev_value;
        Vector2 r_start = (Vector2) {start.x - (l_value + GAP), start.y};
        Vector2 r_end = (Vector2) {start.x - (l_value + GAP), HEIGHT - (values[i-1] *(HEIGHT / LIST_MAX) + (GAP * 2))+ values[i-1]/GAP};
        DrawLineEx(r_start, r_end,l_value ,RED);
        usleep(10000);  
      }


      prev_value = values[i];
      Vector2 end = (Vector2) {start.x, HEIGHT - (values[i] *(HEIGHT / LIST_MAX) + (GAP * 2))+ values[i]/GAP};
      DrawLineEx(start,end,l_value ,GREEN);
      start.x += l_value + GAP ;
      ClearBackground(BLACK);
    }
    //printf("\ninit\n");
    //for (int i = 0; i < 20; i++) printf("list: %d", values[i]);
    EndDrawing();
  }
  return 0;
}
