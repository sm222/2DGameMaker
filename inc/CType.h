#ifndef CTYPE_H
# define CTYPE_H

# include "SYSDefine.h"

/*
*  DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color);
*/
typedef struct RenderLine {
  Vector2 start;
  Vector2 end;
  float   thick;
  Color   color;
} RenderLine;

/*
*  DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color);
*/
typedef struct RenderRect {
  Rectangle rectangle;
  float     angle;
  Color     color;
} RenderRect;

typedef struct RenderText {
  char*     str;     // def NULL
  Font      font;    // def (Font){FONT_DEFAULT}
  float     size;    // def 10
  float     spacing; // def 1
  Color     tint;    // def WHITE
} RenderText;

/*
*  DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color);
*  DrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color);
*/
typedef struct RenderTriangle {
  Vector2   v1;
  Vector2   v2;
  Vector2   v3;
  Color     color;
  bool      full;
} RenderTriangle;

/*
*  DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
*/
typedef struct RenderTexture {
  Vector2   position;
  float     rotation;
  float     scale;
  Color     color;
} RenderTexture;

typedef union CRenderType {
  RenderLine*         line;
  RenderRect*         rect;
  RenderText*         text;
  RenderTriangle*     tria;
  RenderTexture*      tex;
} CRenderType;

#endif // CTYPE_H