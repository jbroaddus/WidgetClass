#ifndef __WIDGET_RAW_H__
#define __WIDGET_RAW_H__

#include <iostream>
#include <stdexcept>
#include <string>

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
  virtual ~WidgetRaw();

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
  const T& operator[](const size_t i) const override;
  T& at(const size_t i) override;
  const T& at(const size_t i) const override;
  const size_t size() const override;
  void changeAlias(const std::string& new_alias) override;
  const std::string& getAlias() const override;
  void resize(const size_t new_size) override;
  void clear() override;
  

  private:

  // private member functions
  void printOutput(const std::string& output_string) const override;

  // private member variables
  std::string alias_;
  size_t size_;
  T* allocated_resource_;
  bool RAII_output_;

};


// public member function definitions
template<typename T>
WidgetRaw<T>::WidgetRaw() 
  : alias_(""), size_(10), allocated_resource_(new T[10]), RAII_output_(true)
{
  if(RAII_output_)
    printOutput("Default constructor ()");
}

template<typename T>
WidgetRaw<T>::WidgetRaw(const size_t i, const std::string& init_alias, const bool RAII_output)
  : size_(i), alias_(init_alias), allocated_resource_(new T[10]), RAII_output_(RAII_output)
{
  if(RAII_output_)
    printOutput("Parameterized constructor ()");

}

template<typename T>
WidgetRaw<T>::~WidgetRaw() 
{
  if(RAII_output_)
    printOutput("Destructor ()");
  delete[] allocated_resource_;
}

template<typename T>
WidgetRaw<T>::WidgetRaw(const WidgetRaw<T>& rhs)
  : alias_(rhs.alias_), size_(rhs.size_), allocated_resource_(new T[size_]), RAII_output_(rhs.RAII_output_)
{
  if(RAII_output_)
    printOutput("Copy constructor ()");
  for (int i = 0; i < size_; ++i)
    allocated_resource_[i] = rhs.allocated_resource_[i];
}

template<typename T> 
WidgetRaw<T>::WidgetRaw(WidgetRaw<T>&& rhs)
: alias_(std::move(rhs.alias_)), size_(rhs.size_), RAII_output_(rhs.RAII_output_)
{
  if(RAII_output_)
    printOutput("Move constructor ()");
  allocated_resource_ = rhs.allocated_resource_;
  rhs.allocated_resource_ = nullptr;    
  rhs.size_ = 0;
}


template<typename T>
WidgetRaw<T>& WidgetRaw<T>::operator=(const WidgetRaw<T>& rhs) 
{
  if(RAII_output_)
    printOutput("Copy = operator ()");
  if (this == &rhs)
    return *this;
  alias_ = rhs.alias_;
  size_ = rhs.size_;
  RAII_output_ = rhs.RAII_output_;
  delete[] allocated_resource_;
  allocated_resource_ = new T[size_];
  for (int i = 0; i < size_; ++i) 
    allocated_resource_[i] = rhs.allocated_resource_[i];
  return *this;
}


template<typename T>
WidgetRaw<T>& WidgetRaw<T>::operator=(WidgetRaw<T>&& rhs)   
{
  if(RAII_output_)
    printOutput("Move = operator ()");
  if (this == &rhs)
    return *this;
  alias_ = std::move(rhs.alias_);
  size_ = rhs.size_;
  RAII_output_ = rhs.RAII_output_;
  delete[] allocated_resource_;
  allocated_resource_ = rhs.allocated_resource_;
  rhs.allocated_resource_= nullptr;
  rhs.size_ = 0;
  return *this;
}

template<typename T>
T& WidgetRaw<T>::operator[](const size_t i) 
{
  return allocated_resource_[i];
}

template<typename T>
const T& WidgetRaw<T>::operator[](const size_t i) const
{
  return allocated_resource_[i];
}

template<typename T>
T& WidgetRaw<T>::at(const size_t i) 
{
  if (i < 0 || i > size_ - 1)
    throw std::out_of_range("Exceeds range of indices: " + std::to_string(i));
  
  return allocated_resource_[i];
}

template<typename T>
const T& WidgetRaw<T>::at(const size_t i) const 
{
  if (i < 0 || i > size_ - 1)
    throw std::out_of_range("Exceeds range of indices: " + std::to_string(i));
  
  return allocated_resource_[i];
}

template<typename T>
const size_t WidgetRaw<T>::size() const 
{
  return size_;
}

template<typename T>
void WidgetRaw<T>::changeAlias(const std::string& new_alias) 
{
  alias_ = new_alias;
}

template<typename T>
const std::string& WidgetRaw<T>::getAlias() const 
{
  return alias_;
}

// Will truncate the old array if new_size < size_
template<typename T>
void WidgetRaw<T>::resize(const size_t new_size) 
{
  T* new_allocated_resource = new T[new_size];
  for (int i = 0; i < (new_size > size_ ? size_ : new_size); ++i) 
    new_allocated_resource[i] = allocated_resource_[i];
  delete[] allocated_resource_;
  allocated_resource_ = new_allocated_resource;
  size_ = new_size;
}

template<typename T>
void WidgetRaw<T>::clear() 
{
  delete[] allocated_resource_;
  size_ = 0;
}

template<typename T>
void WidgetRaw<T>::printOutput(const std::string& output_string) const
{
  std::cout << "WidgetRawOUT(" << alias_ << " <" << this << ">) - " << output_string << std::endl;
}


} // end of widget_class namespace

#endif