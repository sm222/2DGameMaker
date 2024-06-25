#ifndef GM_CDEFINE_H
# define GM_CDEFINE_H

# include "SYSDefine.h"
# include <unistd.h>
# include <stdio.h>

// C - define

//

# define MAX_CANVAS  10
# define MAX_LAYER   50
# define DEF_UI      10
# define DEF_LAYER   10
# define NB_ITEM     5

// - - macro
// Vec 2D
# define VEC2(x,y)   (Vector2){x, y}
# define VEC2DEF     (VEC2(0,0))
// cam 2D
# define DEFCAM      Camera2D{VEC2(0,0),VEC2(0,0), 0, 0}
// Font
# define DEFFONT     (Font){FONT_DEFAULT}

typedef unsigned long long t_ID;
typedef unsigned int       t_Depth;


//Expression1 ? Expression2 : Expression3;

# define ID_VALID(objId) (objId == (t_ID)-1 ? 0 : objId)

typedef struct RenderLine {
  Vector2 start;
  Vector2 end;
  float   thick;
  Color   color;
} RenderLine;

typedef struct RenderRect {
  Rectangle rectangle;
  float     angle;
  Color     color;
} RenderRect;


typedef union CRenderType {
  RenderLine*     line;
  RenderRect*     rect;
} CRenderType;


typedef struct RenderValue {
  bool                 Visible;
  bool                _Render;
  unsigned char        Type;
  CRenderType          CRenderType;
  //Vector2*             Pos;
  //Texture*             Texture;
  t_Depth              Depth;
  t_ID                _Id;
  //* char*           _name // or type ? useful for debug log 
  //* to print what type of obj was made, just do a str.c_str(); 
} t_RenderValue;

typedef struct Layers {
  size_t            _SizeRenderList;
  t_RenderValue***  _RenderList;
  size_t            _LenRenderList[MAX_LAYER + 1];
  size_t            _ItemNumber[MAX_LAYER + 1];
} t_Layers;


typedef struct Canvas {
  Camera2D*              _Camera;
    // GAME                //
  t_Layers               _Game;
    // UI                  //
  t_Layers               _Ui;
} t_Canvas;


#endif // CDEFINE_H
