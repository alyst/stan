#ifndef STAN_SERVICES_ARGUMENTS_ARG_MIN_DEPTH_HPP
#define STAN_SERVICES_ARGUMENTS_ARG_MIN_DEPTH_HPP

#include <stan/services/arguments/singleton_argument.hpp>

namespace stan {
  namespace services {

    class arg_min_depth: public int_argument {
    public:
      arg_min_depth(): int_argument() {
        _name = "min_depth";
        _description = "Minimum tree depth";
        _validity = "0 < min_depth";
        _default = "0";
        _default_value = 0;
        _constrained = true;
        _good_value = 2.0;
        _bad_value = -1.0;
        _value = _default_value;
      }

      bool is_valid(int value) { return value > 0; }
    };

  }  // services
}  // stan

#endif
