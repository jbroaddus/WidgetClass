#ifndef __WIDGET_BASE_H__
#define __WIDGET_BASE_H__

namespace widget_class
{

template<typename T>
class WidgetBase 
{
  public:

  // Pure virtual functions to be implemented by child classes 
  virtual T& operator[](const size_t i) =0;
  virtual const size_t size() const =0;

} 

} // end of widget_class namespace
#endif