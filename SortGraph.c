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

int main() {
  InitWindow(WIDTH, HEIGHT, "Sort Graphic");
  SetTargetFPS(60);

  while(!WindowShouldClose()) {
    int prev_value = 0;
    Vector2 start = (Vector2) {l_value * 0.66 + GAP,HEIGHT - GAP*1.5};
    BeginDrawing();
    Vector2 start2 = (Vector2) {l_value * 0.66 +GAP,HEIGHT - GAP*1.5};
    for (int j = 0; j < LEN_LIST; j++) {
      Vector2 end2 = (Vector2) {start2.x, HEIGHT - (values[j] *(HEIGHT / LIST_MAX) +(GAP*2)) + values[j]/GAP};
      DrawLineEx(start2, end2, l_value ,GRAY);
      start2.x += l_value + GAP ;
    }

    for (int i=0; i < LEN_LIST; i++ ) {
      if(values[i] <= values[i-1] && prev_value!= 0) {
        values[i-1] = values[i];
        values[i] = prev_value;
        Vector2 r_start = (Vector2) {start.x - (l_value + GAP), start.y};
        Vector2 r_end = (Vector2) {start.x - (l_value + GAP), HEIGHT - (values[i-1] *(HEIGHT / LIST_MAX) + (GAP * 2))+ values[i-1]/GAP};
        DrawLineEx(r_start, r_end,l_value ,RED);
      }

      ClearBackground(BLACK);
      prev_value = values[i];
      start.x += l_value + GAP ;
    }
    sleep(1);
    printf("\ninit\n");
    for (int h = 0; h < 20; h++) printf(" %d", values[h]);
    EndDrawing();
  }
  return 0;
}
