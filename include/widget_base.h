#ifndef __WIDGET_BASE_H__
#define __WIDGET_BASE_H__

namespace widget_class
{

template<typename T>
class WidgetBase 
{
  public:

  // Pure virtual functions to be implemented by child classes 
  virtual ~WidgetBase(){}
  virtual T& operator[](const size_t i) =0;
  virtual const T& operator[](const size_t i) const =0;
  virtual T& at(const size_t i) =0;
  virtual const T& at(const size_t i) const =0;
  virtual const size_t size() const =0;
  virtual void changeAlias(const std::string& new_alias) =0;
  virtual const std::string& getAlias() const =0;
  virtual void resize(const size_t new_size) =0;
  virtual void clear() =0;

  protected:
  virtual void printOutput(const std::string& ouput_string) const =0;

};

} // end of widget_class namespace
#endif