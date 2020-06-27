#ifndef COLOR_H
#define ICOLOR_H

class Color{    
    protected:
     double m_Red, m_Green, m_Blue = 0;

    public:
        Color(double red, double green, double blue):m_Red(red), m_Green(green), m_Blue(blue){};
        Color add(Color a){
            return Color(a.m_Red+m_Red, a.m_Green+m_Green,a.m_Blue+m_Blue);
        }
};
#endif // COLOR_H