#ifndef TRACE_H
#define TRACE_H
#include <string>
#include <SFML/Graphics.hpp>

class Trace{
protected:
   int netID;
   int layer;
   bool selected;
public:
   Trace(const int&netID_, const  int& lay);
   virtual ~Trace();
   int getLayer() const;
   int getnetID() const;
   void setselec(bool s);

   virtual void draw(sf::RenderWindow& window) const =0;
   virtual bool contains(sf::Vector2f point) const=0;
};



#endif
