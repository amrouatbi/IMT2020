
#include <ql/stochasticprocess.hpp>

namespace QuantLib {

    class ConstantBlackScholesProcess : public StochasticProcess1D {
      public:
	/* Equation :  d\ln S(t) = (r(t) - q(t) - \frac{\sigma(t, S)^2}{2}) dt + \sigma dW_t. */
	
	// Constructor
        ConstantBlackScholesProcess(const Real& S,
                   const Rate& r,
                   const Volatility& sigma,
		   const Rate& q);

	// Interface with StochasticProcess1D
        Real x0() const;
        Real drift(Time t, Real x) const;
        Real diffusion(Time t, Real x) const;
        Real apply(Real x0, Real dx) const;

      private:
        Real S ;
        Rate r;
        Volatility sigma ;
        Real q;
    };
    
}


