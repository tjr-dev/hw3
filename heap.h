#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <utility>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());
  
  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;



private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> data;
  int d;
  PComparator comp;
  

};

// Add implementation of member functions here
/*
Heap(int m=2, PComparator c = PComparator()); done
~Heap(); done
bool empty() const; done
size_t size() const; done
void push(const T& item); done
T const & top() const; big func
void pop(); big func

*/
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : d(m), comp(c) {

};

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {

}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return data.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return data.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  int i = data.size();
  data.push_back(item);
  while (i > 0) {
    if (comp(data.at(i), data.at((i-1)/d))) {
      std::swap(data.at(i), data.at((i-1)/d));
    } else {
      break;
    }
    i = (i - 1) / d;
  }
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("error - top called on empty heap");

  }

  return data.at(0);

  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("error - pop called on empty heap");
  }

  std::swap(data.at(0), data.at(data.size()-1));
  data.pop_back();

  size_t i = 0;


  while (((d*i +1) < data.size()) ) { // condition should be while at least 1 child exists

    size_t index = (d*i + 1);
    T bestNode = data.at(index);

    size_t numChildren; // should go to "d / remaining children", which one is smaller
    // d children when it is full - otherwise it should be data.size()-index children
    // full when data.size() > d*i + d
    if (data.size() > (d*i + d)) {
      numChildren = d;
    } else {
      numChildren = data.size() - index;
    }
    
    for (size_t j = 1; j < numChildren; j++) { 
      if (comp((data.at(d*i + 1 + j)), bestNode)) {
        bestNode = data.at(d*i + 1 + j);
        index = (d*i + 1 +j);
      }
    }
    if (comp(data.at(index), data.at(i))) {
      std::swap(data.at(i), data.at(index));
    } else {
      break;
    }
    i = index;
  }
}



#endif

