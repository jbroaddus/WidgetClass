#ifndef __WIDGET_SMART_H__
#define __WIDGET_SMART_H__

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

namespace widget_class 
{

// Rule of five (Ro5) widget class w/ raw pointer RAII
template<typename T>
class WidgetSmart : public WidgetBase<T> 
{

  public:

  // default constructor
  WidgetSmart();

  // Overloaded Parameterized constructor
  WidgetSmart(const size_t i, const std::string& init_alias="", const bool RAII_output=false);

  // User defined destructor (necessitates Ro5)
  virtual ~WidgetSmart();

  // copy constructor
  WidgetSmart(const WidgetSmart<T>& rhs);

  // move constructor
  WidgetSmart(WidgetSmart<T>&& rhs);

  // copy assignment operator
  WidgetSmart<T>& operator=(const WidgetSmart<T>& rhs);

  // move assignment operator
  WidgetSmart<T>& operator=(WidgetSmart<T>&& rhs);

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
  std::unique_ptr<T[]> allocated_resource_;
  bool RAII_output_;

};

// default constructor
template<typename T> 
WidgetSmart<T>::WidgetSmart()
  : alias_(""), size_(10), allocated_resource_(std::make_unique(T[10])), RAII_output_(true)
{
  if (RAII_output_)
    printOutput("Default constructor()");
}

// Overloaded Parameterized constructor
template<typename T> 
WidgetSmart<T>::WidgetSmart(const size_t i, const std::string& init_alias="", const bool RAII_output=false)
  : size_(i), alias_(init_alias), allocated_resource_(std::make_unique(T[size_])), RAII_output_(RAII_output)
{
  if (RAII_output_)
    printOutput("Parameterized Constructor ()");
}

// User defined destructor (necessitates Ro5)

template<typename T>
WidgetSmart<T>::~WidgetSmart()
{}

// copy constructor
template<typename T>
WidgetSmart<T>::WidgetSmart(const WidgetSmart<T>& rhs)
  : alias_(rhs.alias_), size_(rhs.size_), allocated_resource_(std::make_unique(T[size_])), RAII_output_(rhs.RAII_output_)
{
  if (RAII_output_)
    printOutput("Copy constructor ()");
  for (int i = 0; i < size_; ++i)
    allocated_resource_[i] = rhs.allocated_resource_[i];
}

// move constructor
template<typename T>
WidgetSmart<T>::WidgetSmart(WidgetSmart<T>&& rhs)
  : alias_(std::move(rhs.alias_)), size_(rhs.size_), allocated_resource_(std::move(rhs.alias_)), RAII_output_(rhs.RAII_output_)
{}

// copy assignment operator
template<typename T>
WidgetSmart<T>& WidgetSmart<T>::operator=(const WidgetSmart<T>& rhs)
{
  if (RAII_output_)
    printOutput("Copy = operator ()");
  if (this == &rhs)
    return *this:
  alias_ = rhs.alias_;
  size_ rhs.size_;
  RAII_output_ = rhs.RAII_output_;
  allocated_resource_ = nullptr;
  allocated_resource_ = std::make_unique(T[size_]);
  for (int i = 0; i < size_; ++i) 
    allocated_resource_[i] = rhs.allocated_resource_[i];
  return *this;
}

// move assignment operator
template<typename T>
WidgetSmart<T>& WidgetSmart<T>::operator=(WidgetSmart<T>&& rhs)
{}

// Overriden inherrited functions
template<typename T>
T& WidgetSmart<T>::operator[](const size_t i) 
{} 

template<typename T>
const T& WidgetSmart<T>::operator[](const size_t i) const 
{} 

template<typename T>
T& WidgetSmart<T>::at(const size_t i) 
{} 

template<typename T>
const T& WidgetSmart<T>::at(const size_t i) const 
{} 

template<typename T>
const size_t WidgetSmart<T>::size() const 
{} 

template<typename T>
void WidgetSmart<T>::changeAlias(const std::string& new_alias) 
{} 

template<typename T>
const std::string& WidgetSmart<T>::getAlias() const 
{} 

template<typename T>
void WidgetSmart<T>::resize(const size_t new_size) 
{} 

template<typename T>
void WidgetSmart<T>::clear() 
{} 


}
#endif 