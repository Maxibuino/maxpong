#ifndef POONG_DISPLAY_OBJECT
#define POONG_DISPLAY_OBJECT

#include <Gamebuino-Meta.h>

class DisplayObject
{
    protected:

        // default display color
        static const Color DEFAULT_COLOR;

        Color color; // display color

        uint8_t w; // width
        uint8_t h; // height

        int8_t  x; // horizontal position
        int8_t  y; // vertical position

        int8_t  vx; // horizontal velocity
        int8_t  vy; // vertical velocity

    public:

        // constructor
        DisplayObject(
            uint8_t w,
            uint8_t h,
            int8_t  x,
            int8_t  y,
            int8_t  vx = 0,
            int8_t  vy = 0,
            Color   c = DISPLAY_DEFAULT_COLOR
        );

        // destructor
        ~DisplayObject();

        // accessors
        uint8_t getW();  // width
        uint8_t getH();  // height
        int8_t  getX();  // horizontal position
        int8_t  getY();  // vertical position
        int8_t  getVx(); // horizontal velocity
        int8_t  getVy(); // vertical velocity

        // mutators
        void setX(int8_t x);   // horizontal position
        void setY(int8_t y);   // vertical position
        void setVx(int8_t vx); // horizontal velocity
        void setVy(int8_t vy); // vertical velocity

        void move(); // handles motion
        void draw(); // graphic rendering
};

#endif