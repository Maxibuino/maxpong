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
    uint8_t getH();
    int8_t getY();

    //Mutateurs
    void setY(int8_t y);

    void tick();
    void draw();

};


#endif