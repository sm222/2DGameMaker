#ifndef GM_CDEFINE_H
# define GM_CDEFINE_H

# include "SYSDefine.h"
# include <unistd.h>
# include <stdio.h>

// C - define
# include "CType.h"
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

// type
typedef unsigned long long t_ID;
typedef unsigned int       t_Depth;

# define ID_VALID(objId) (objId == (t_ID)-1 ? 0 : objId)

typedef struct RenderValue {
  bool                 Visible;
  unsigned char        Type;
  t_Depth              Depth;
  t_ID                _Id;
  CRenderType          CRenderType; //?use to store ptr of the obj
  /*
! Vector2*             Pos;
! Texture*             Texture;
* char*               _name // or type ? useful for debug log 
* to print what type of obj was made, just do a str.c_str();
* could also do remove by name
  */
} t_RenderValue;

typedef struct Layers {
  size_t            _SizeRenderList;
  t_RenderValue***  _RenderList;
  size_t            _LenRenderList[MAX_LAYER + 1];
  size_t            _ItemNumber[MAX_LAYER + 1];
  bool              _Edit[MAX_LAYER + 1];
} t_Layers;


typedef struct Canvas {
  Camera2D*              _Camera;
    // GAME                //
  t_Layers               _Game;
    // UI                  //
  t_Layers               _Ui;
} t_Canvas;


#endif // CDEFINE_H
