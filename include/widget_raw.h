#ifndef __WIDGET_RAW_H__
#define __WIDGET_RAW_H__

namespace widget_class 
{

// Rule of five (Ro5) widget class w/ raw pointer RAII
template<typename T>
class WidgetRaw : public WidgetBase<T> 
{

  public:

  // default constructor
  WidgetRaw();


  // Overloaded Parameterized constructor
  WidgetRaw(const size_t i, const std::string& init_alias="", const bool RAII_output=false);

  // User defined destructor (necessitates Ro5)
  ~WidgetRaw();

  // copy constructor
  WidgetRaw(const WidgetRaw<T>& rhs);

  // move constructor
  WidgetRaw(WidgetRaw<T>&& rhs);

  // copy assignment operator
  WidgetRaw<T>& operator=(const WidgetRaw<T>& rhs);

  // move assignment operator
  WidgetRaw<T>& operator=(WidgetRaw<T>&& rhs);

  // Overriden inherrited functions
  T& operator[](const size_t i) override;
  const size_t size() const override;
  void changeAlias(const std::string& new_alias) override;
  const std::string& getAlias() const override;
  void resize(const size_t new_size) override;
  void clear() override;
  

  private:

  // private member variables
  std::string alias_;
  size_t size_;
  T* allocated_resource_;
  bool RAII_output;

};

// public member function definitions
  template<typename T>
  WidgetRaw<T>::WidgetRaw() 
  {

  }

  template<typename T>
  WidgetRaw<T>::WidgetRaw(const size_t i, const std::string& init_alias="", const bool RAII_output=false) 
  {

  }

  template<typename T>
  WidgetRaw<T>::~WidgetRaw() 
  {

  }

  template<typename T>
  WidgetRaw<T>::WidgetRaw(const WidgetRaw<T>& rhs)
  {

  }

  template<typename T> 
  WidgetRaw<T>::WidgetRaw(WidgetRaw<T>&& rhs)
  {

  }

  template<typename T>
  WidgetRaw<T>& WidgetRaw<T>::operator=(const WidgetRaw<T>& rhs) 
  {

  }

  template<typename T>
  WidgetRaw<T>& WidgetRaw<T>::operator=(WidgetRaw<T>&& rhs) 
  {
  }

  template<typename T>
  T& WidgetRaw<T>::operator[](const size_t i) 
  {

  }

  template<typename T>
  const size_t WidgetRaw<T>::size() const 
  {

  }

  template<typename T>
  void WidgetRaw<T>::changeAlias(const std::string& new_alias) 
  {

  }

  template<typename T>
  const std::string& WidgetRaw<T>::getAlias() const 
  {

  }

  template<typename T>
  void WidgetRaw<T>::resize(const size_t new_size) 
  {

  }

  template<typename T>
  void WidgetRaw<T>::clear() 
  {

  }
  


} // end of widget_class namespace

#endif