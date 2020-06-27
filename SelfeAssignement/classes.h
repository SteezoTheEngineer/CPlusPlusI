#ifndef CLASSES_H
#define CLASSES_H

class Color{    
    private:
     int m_Red, m_Green, m_Blue =0;

    public:
        Color(int red, int green, int blue):m_Red(red), m_Green(green), m_Blue(blue){};
        Color add(Color y){
            return Color(y.m_Red+m_Red, y.m_Green+m_Green,y.m_Blue+m_Blue);
        }
};
#endif // CLASSES_H