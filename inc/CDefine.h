#ifndef GM_CDEFINE_H
# define GM_CDEFINE_H

# include "SYSDefine.h"
# include <unistd.h>
# include <stdio.h>

// C - defines
# include "CType.h"
# include "Messages.h"
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
typedef unsigned long t_ID;

# define ID_VALID(objId) (objId == (t_ID)-1 ? 0 : objId)

typedef struct RenderValue {
  bool                 Visible;
  unsigned char        Type;
  t_ID                _Id;   //					!! Never changed after init
  CRenderType          CRenderType; //	?? use to store ptr of the obj
  char*               _name; // 				or type ? useful for debug log just do a str.c_str();
} t_RenderValue;

typedef struct layerData {
  Camera2D*      _cam;
  Camera3D*      _cam3D;
  unsigned char  _type;
} layerData;

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
