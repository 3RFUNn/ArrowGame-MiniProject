#include <iostream>
#include <cmath>
#include <SDL.h>
#define sin45 0.707106781186547524400844362104849039284835937688474036588
void findRotatedCoordinate(double x_center,double y_center,double x,double y, double zavie,double &x_khoruji,double &y_khoruji)
{
    double degree = zavie*M_PI/180;
    x_khoruji = (x-x_center)*cos(degree) - (y-y_center)*sin(degree) + x_center;
    y_khoruji = (x-x_center)*sin(degree) + (y-y_center)*cos(degree) + y_center;
}
bool jordan (double x_A,double x_B,double x_C,double x_D,double y_A,double y_B,double y_C,double y_D,double x, double y)
{
    double S_ABC,S_ADC,S_PAB,S_PBC,S_PCD,S_PDA;
    S_ABC= fabs((x_A*(y_B-y_C)+x_B*(y_C-y_A)+x_C*(y_A-y_B)));
    S_ADC= fabs((x_C*(y_D-y_A)+x_D*(y_A-y_C)+x_A*(y_C-y_D)));
    S_PAB= fabs((x_A*(y_B-y)+x_B*(y-y_A)+x*(y_A-y_B)));
    S_PBC= fabs((x_B*(y_C-y)+x_C*(y-y_B)+x*(y_B-y_C)));
    S_PCD= fabs((x_C*(y_D-y)+x_D*(y-y_C)+x*(y_C-y_D)));
    S_PDA= fabs((x_A*(y_D-y)+x_D*(y-y_A)+x*(y_A-y_D)));
    return fabs(((S_PAB + S_PBC + S_PCD + S_PDA) - (S_ABC + S_ADC)) < 0.001) != 0;
}
// Determines whether the rect2 has intersection with rect1 while 45 degrees rotated

bool hasIntersectionRotated(SDL_Rect rect1,SDL_Rect rect2,bool rect1ChapeYaRasteAgeChapeTrueAgeRasteFalse,double zavieArrow)
{
    double x_A,y_A,x_B,y_B,x_C,y_C,x_D,y_D,x,y;
    double alamat = rect1ChapeYaRasteAgeChapeTrueAgeRasteFalse ? -1 : 1;
    double center_x = rect1.x+rect1.w/2;
    double center_y = rect1.y+rect1.h/2;
//    findRotatedCoordinate(center_x,center_y,rect1.x,rect1.y,alamat*45.0,x_A,x_B);
    findRotatedCoordinate(center_x,center_y,rect1.x,rect1.y,alamat*45.0,x_A,y_A);
    findRotatedCoordinate(center_x,center_y,rect1.x+rect1.w,rect1.y,alamat*45.0,x_B,y_B);
    findRotatedCoordinate(center_x,center_y,rect1.x,rect1.y+rect1.h,alamat*45.0,x_C,y_C);
    findRotatedCoordinate(center_x,center_y,rect1.x+rect1.w,rect1.y+rect1.h,alamat*45.0,x_D,y_D);
    findRotatedCoordinate(rect2.x+rect2.w/2,rect2.y+rect2.h/2,rect2.x+rect2.w/2,rect2.y,zavieArrow,x,y);
    return jordan(x_A,x_B,x_C,x_D,y_A,y_B,y_C,y_D,x,y);
}