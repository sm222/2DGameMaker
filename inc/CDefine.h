#ifndef GM_CDEFINE_H
# define GM_CDEFINE_H

# include "SYSDefine.h"
# include <unistd.h>
# include <stdio.h>

// C - define

//

# define MAX_CANVAS  10
# define MAX_LAYER   100
# define DEF_UI      10
# define DEF_LAYER   10
# define NB_ITEM     5
# define VEC2(x,y)   (Vector2){x, y}
# define DEF_CAM     Camera2D{VEC2(0,0),VEC2(0,0), 0, 0}

typedef unsigned long long t_ID;
typedef unsigned int       t_Depth;

extern t_ID              _id;

# define ID_NB       ((_id))
# define ID_GET      ((++ID_NB))

//Expression1 ? Expression2 : Expression3;

# define ID_VALID ((_id == (t_ID)-1 ? 0 : ID_GET))

typedef struct RenderValue {
  bool                 Visible;
  bool                _Render;
  Vector2*             Pos;
  Texture*             Texture;
  t_Depth              Depth;
  t_ID                _Id;
} t_RenderValue;

typedef struct Layers {
  size_t            _SizeRenderList;
  t_RenderValue***  _RenderList;
  size_t            _LenRenderList[MAX_LAYER + 1];
  size_t            _ItemNumber[MAX_LAYER + 1];
} t_Layers;


typedef struct Canvas {
  Camera2D*              _Camera;
  size_t                 _YCamera; // can rm probably
  size_t                 _XCamera; // can rm probably
    // GAME                //
  t_Layers               _Game;
    // UI                  //
  t_Layers               _Ui;
} t_Canvas;


#endif // CDEFINE_H
