
#include <ql/stochasticprocess.hpp>

namespace QuantLib {

    class ConstantBlackScholesProcess : public StochasticProcess1D {
      public:
	/* Equation :  d\ln S(t) = (r(t) - q(t) - \frac{\sigma(t, S)^2}{2}) dt + \sigma dW_t. */
	
	// Constructor
        ConstantBlackScholesProcess(double S_, double r_, double sigma_, double q_);

	// Interface with StochasticProcess1D
        Real x0() const;
        Real drift(Time t, Real x) const;
        Real diffusion(Time t, Real x) const;
        Real apply(Real x0, Real dx) const;

      private:
        double S;
        double r;
        double sigma;
        double q;
    };
    
}


