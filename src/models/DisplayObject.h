#ifndef MAXPONG_DISPLAY_OBJECT
#define MAXPONG_DISPLAY_OBJECT

#include <Gamebuino-Meta.h>

class DisplayObject
{
    protected:

        // couleur par défaut de l'objet
        static const Color DEFAUT_COLOR;

        Color color; //Display Color

        uint8_t w; //largeur
        uint8_t h; //hauteur

        int8_t x; //position horizontale
        int8_t y; //position verticale

        int8_t vx; //vitesse horizontale
        int8_t vy; //vitesse verticale

    public:

    //Constructeur
    DisplayObject(
        uint8_t w,
        uint8_t h,
        int8_t x,
        int8_t y,
        int8_t vx = 0,
        int8_t vy = 0,
        Color   c = DISPLAY_DEFAULT_COLOR,

    );

    //Destructeur
    ~DisplayObject();

        //Accesseurs
        uint8_t getW();  // width
        uintx8_t getH();  // height
        int8_t  getX();  // horizontal position
        int8_t  getY();  // vertical position
        int8_t  getVx(); // horizontal velocity
        int8_t  getVy(); // vertical velocity

        //Mutateurs
        void setX(int8_t x);   // horizontal position
        void setY(int8_t y);   // vertical position
        void setVx(int8_t vx); // horizontal velocity
        void setVy(int8_t vy); // vertical velocity

        void move(); // handles motion
        void draw(); // graphic rendering

};


#endif