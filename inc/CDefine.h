#ifndef GM_CDEFINE_H
# define GM_CDEFINE_H

# include "SYSDefine.h"
# include <unistd.h>
# include <stdio.h>

// C - define

//

# define MAX_CANVAS  10
# define MAX_LAYER   100
# define DEF_UI      50
# define DEF_LAYER   50
# define VEC2(x,y)   (Vector2){x, y}
# define DEF_CAM     Camera2D{VEC2(0,0),VEC2(0,0), 0, 0}

typedef unsigned long long t_ID;
typedef unsigned int       t_Depth;

t_ID                 _id;

# define ID_GET      ((++_id))
# define ID_NB       ((_id))

//Expression1 ? Expression2 : Expression3;

# define ID_VALID ((_id == (t_ID)-1 ? 0 : ID_GET))

struct RenderValue {
  bool                 Visible;
  bool                _Render;
  Vector2*             Pos;
  Texture*             Texture;
  t_Depth              Depth;
  t_ID                 _Id;
};

struct Canvas {
    // GAME                //
  Camera2D*              _Camera;
  size_t                 _YG;
  size_t                 _XG;
  struct RenderValue**   _Game;
  size_t                 _GameSize;
  size_t                 _SizeG[MAX_LAYER + 1];
    // UI                  //
  size_t                 _YU; //uu
  size_t                 _XU; //uu
  struct RenderValue**   _Ui;
  size_t                 _UiSize;
  size_t                 _SizeU[MAX_LAYER + 1];
};

#endif // CDEFINE_H
