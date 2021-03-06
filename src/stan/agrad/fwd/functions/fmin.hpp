#ifndef __STAN__AGRAD__FWD__FUNCTIONS__FMIN_HPP__
#define __STAN__AGRAD__FWD__FUNCTIONS__FMIN_HPP__

#include <stan/agrad/fwd/fvar.hpp>
#include <stan/meta/traits.hpp>
#include <stan/math/constants.hpp>

namespace stan {

  namespace agrad {

    template <typename T>
    inline
    fvar<T>
    fmin(const fvar<T>& x1, const fvar<T>& x2) {
      using std::min;
      using stan::math::NOT_A_NUMBER;
      if(x1.val_ < x2.val_)
        return fvar<T>(x1.val_, x1.d_);
      else if(x1.val_ == x2.val_)
        return fvar<T>(x1.val_, NOT_A_NUMBER);
      else 
        return fvar<T>(x2.val_, x2.d_);              
    }

    template <typename T>
    inline
    fvar<T>
    fmin(const double x1, const fvar<T>& x2) {
      using std::min;
      using stan::math::NOT_A_NUMBER;
      if(x1 < x2.val_)
        return fvar<T>(x1, 0.0);
      else if(x1 == x2.val_)
        return fvar<T>(x2.val_, NOT_A_NUMBER);
      else 
        return fvar<T>(x2.val_, x2.d_);               
    }

    template <typename T>
    inline
    fvar<T>
    fmin(const fvar<T>& x1, const double x2) {
      using std::min;
      using stan::math::NOT_A_NUMBER;
      if(x1.val_ < x2)
        return fvar<T>(x1.val_, x1.d_);
      else if(x1.val_ == x2)
        return fvar<T>(x1.val_, NOT_A_NUMBER);
      else 
        return fvar<T>(x2, 0.0);
    }
  }
}
#endif
