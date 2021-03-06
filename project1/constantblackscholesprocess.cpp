
#include "constantblackscholesprocess.hpp"
#include <iostream>
#include <ql/processes/eulerdiscretization.hpp>

namespace QuantLib {

	ConstantBlackScholesProcess::ConstantBlackScholesProcess(double S_, double r_, double sigma_, double q_)
	: StochasticProcess1D(ext::make_shared<EulerDiscretization>()),
	  S(S_), r(r_), sigma(sigma_), q(q_) {}

    Real ConstantBlackScholesProcess::x0() const {
        return S;
    }

    Real ConstantBlackScholesProcess::drift(Time t, Real x) const {
	// Returns µ(t,x) which is r(t) - q(t) - 0.5 sigma(t,x)^2
        return r - q - 0.5*sigma*sigma;
    }

    Real ConstantBlackScholesProcess::diffusion(Time t, Real x) const {
	// Returns sigma(t,x), constant here?
        return sigma;
    }

    Real ConstantBlackScholesProcess::apply(Real x0, Real dx) const {
	// Drifts x by dx, meant for log(x)
        return x0 * std::exp(dx);
    }

}
