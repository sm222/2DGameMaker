#ifndef GM_CDEFINE_H
# define GM_CDEFINE_H

# include <raylib.h>
# include <unistd.h>
# include <stdio.h>

// C define
# define MAX_CANVAS  10
# define MAX_LAYER   100
# define VEC2(x,y)   (Vector2){x, y}
# define DEF_CAM     Camera2D{VEC2(0,0),VEC2(0,0), 0, 0}

struct RenderValue {
    bool                 Visible;
    bool                _Rander;
    Vector2*             Pos;
    Texture*             Texture;
    unsigned int         Depth;
    unsigned long long  _Id;
};

struct Canvas {
    // GAME
    Camera2D*       _Camera;
    size_t          _YG;
    size_t          _XG;
    RenderValue**   _Game;
    size_t          _SizeG[MAX_LAYER + 1];
    // UI
    size_t          _YU;
	size_t          _XU;
    size_t          _SizeU[MAX_LAYER + 1];
    RenderValue**   _Ui;
};





#endif // CDEFINE_H
