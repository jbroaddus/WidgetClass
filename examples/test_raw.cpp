#include <iostream>

#include "widget.h"

template<typename T>
void printRawWidgetByValue(const widget_class::WidgetRaw<T> widget_obj)
{
  for (size_t i = 0; i < widget_obj.size(); ++i)
    std::cout << widget_obj[i] << ' ';
  std::cout << std::endl;
}


int main(int argc, char** argv) 
{
  widget_class::WidgetRaw<int> wr_obj;
  wr_obj.changeAlias("widgetraw_obj1");
  std::cout << "Widget_size: " << wr_obj.size() << std::endl; 
  std::cout << std::endl;
  printRawWidgetByValue<int>(wr_obj);
  // attempting to access out of bounds
  try 
  {
    wr_obj.at(10);
  }
  catch(const std::exception& e)
  {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  return 0;
}


