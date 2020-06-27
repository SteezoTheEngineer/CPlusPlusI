#ifndef INHERITANCE_H
#define INHERITANCE_H

class Color{    
    protected:
     double m_Red, m_Green, m_Blue = 0;

    public:
        Color(double red, double green, double blue):m_Red(red), m_Green(green), m_Blue(blue){};
        Color add(Color a){
            return Color(a.m_Red+m_Red, a.m_Green+m_Green,a.m_Blue+m_Blue);
        }
};

class ColorA : public Color{
    private:
    double m_alpha = 0;
    
    public:
    ColorA(double red, double green, double blue, double alpha):Color(red, green, blue), m_alpha(alpha){};
    ColorA add(ColorA b){
    double m_alphaC = m_alpha + (1 - m_alpha)*b.m_alpha;
    return ColorA((b.m_alpha * b.m_Red + (1-b.m_alpha) * m_alpha * m_Red) * (1/m_alphaC), (b.m_alpha * b.m_Green + (1-b.m_alpha) * m_alpha * m_Green) * (1/m_alphaC), (b.m_alpha * b.m_Blue + (1-b.m_alpha) * m_alpha * m_Blue) * (1/m_alphaC), m_alphaC);
    }

};
#endif // INHERITANCE_H