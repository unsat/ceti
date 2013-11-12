#ifndef BASIC_TYPES_H__
#define BASIC_TYPES_H__

#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cassert>
#include <type_traits>

using std::string;
using std::vector;
using std::cout;
using std::endl;

namespace crest{
  class DT{
  public:
    DT();
    DT(const DT &);
    DT(long long int);
    DT(double);
    long long int i = 0;
    double d = 0.0;
    bool is_int = false;

    friend std::ostream& operator<< (std::ostream &os, const DT &dt){
      if (dt.is_int) os << dt.i << "i";
      else os << dt.d << "d";
      return os;
    }


  };

  typedef int branch_id_t;
  typedef long long int value_t;
  typedef unsigned int func_id_t;
  typedef unsigned int var_t;
  typedef unsigned long int addr_t;

  static const branch_id_t kCallId = -1;
  static const branch_id_t kReturnId = -2;

  namespace c_ops{
    enum compare_op_t {EQ = 0, NEQ = 1, GT = 2, LE = 3, LT = 4, GE = 5};
    //enum class compare_op_t_m {EQ_m = 0, NEQ_m = 1, GT_m = 2, LE_m = 3, LT_m = 4, GE_m = 5};
    enum binary_op_t {ADD, SUBTRACT, MULTIPLY, DIVIDE, MOD, SHIFT_L, CONCRETE};
    enum unary_op_t {NEGATE, LOGICAL_NOT, BITWISE_NOT};
  }
  using c_ops::compare_op_t;
  using c_ops::binary_op_t;
  using c_ops::unary_op_t;

  //using c_ops::compare_op_t_m;

  compare_op_t NegateCompareOp(compare_op_t op);

  namespace c_types{
    enum type_t { U_CHAR = 0,       CHAR = 1,
		  U_SHORT = 2,      SHORT = 3,
		  U_INT = 4,        INT = 5,
		  U_LONG = 6,       LONG = 7,
		  U_LONG_LONG = 8,  LONG_LONG = 9,

		  FLOAT = 10,       DOUBLE = 11
    };
  }
  using c_types::type_t;

  value_t CastTo(value_t val, type_t type);
  //value_t2 CastTo(value_t2 val, type_t type);

  extern const string op_str[];


  template<typename T>
    constexpr string container2str(const T &ms){
    std::stringstream ss;
    auto i = ms.size();
    ss << ms.size() << " [" ;
    for(const auto &m: ms){
      ss << m;
      if (--i) ss << ", ";
    }
    ss << "]";
    return ss.str();
  }

  template<typename T>
    constexpr string container2str(const vector<T *> &ms){
    std::stringstream ss;
    auto i = ms.size();
    ss << ms.size() << " [" ;
    for(const auto &p: ms){
      ss << *p;
      if (--i) ss << ", ";
    }
    ss << "]";
    return ss.str();
  }

  template<typename T>
    constexpr string z3strs(const vector<T *> &ms){
    std::stringstream ss;
    auto i = ms.size();
    ss << ms.size() << " [" ;
    for(const auto &p: ms){
      ss << p->expr_str();
      if (--i) ss << ", ";
    }
    ss << "]";
    return ss.str();
  }


  template<typename T1, typename T2>
    constexpr string container2str(const std::map<T1,T2> &mmap){
    std::stringstream ss;
    auto i = mmap.size();
    
    ss << mmap.size() << " [" ;
    for(const auto &it: mmap){
      ss <<  "(" << it.first << "," << it.second << ")";
      if (--i) ss << ", ";
    }
    ss << "]";
    return ss.str();
  }

}//namespace crest

#endif  // BASE_BASIC_TYPES_H__ 
