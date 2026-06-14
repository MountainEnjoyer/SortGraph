#include <stdio.h>
#include <raylib.h>

#define WIDTH 1200
#define HEIGHT 600

#define LEN_LIST 20
#define LIST_MAX 100

int l_value =((WIDTH - (LEN_LIST + 2)) / LEN_LIST);
int values[LEN_LIST] = {17,92,27,63,71,87,42,26,01,52,65,96,61,28,36,14,75,46,56,15};
Vector4 past_values[20];

int main(int argc, char *argv[]) {
  InitWindow(WIDTH, HEIGHT, "Sort Graphic");
  SetTargetFPS(60);

  while(!WindowShouldClose()) {
    int prev_value = 0;
    Vector2 start = (Vector2) {1,HEIGHT / 5 - LIST_MAX};
    BeginDrawing();
    ClearBackground(BLACK);
    for (int i=0; i<LEN_LIST; i++ ) {
      if(values[i] <=prev_value && prev_value!= 0) {
        values[i-1] = values[i];
        values[i] = prev_value;
      }

      prev_value = values[i];
      Vector2 end = (Vector2) {start.x, values[i] *HEIGHT / LIST_MAX};
      DrawLineEx(start,end,l_value ,GREEN);
      start.x += l_value + 1;
      Vector2 start2 = (Vector2) {1,HEIGHT - LIST_MAX/5};
      for (int i = 0; i<LEN_LIST; i++) {
        Vector2 end = (Vector2) {start2.x, values[i] *HEIGHT / LIST_MAX};
        DrawLineEx(start2,end,l_value ,GRAY);
        start2.x += l_value + 1;

      }
    }
    printf("\ninit\n");
    for (int i = 0; i < 20; i++) printf("list: %d", values[i]);
    EndDrawing();
  }
  return 0;
}
