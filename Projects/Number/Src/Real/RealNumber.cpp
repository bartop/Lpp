
#include "RealNumber.hpp"
#include "RealNumberOperations.hpp"

namespace Lpp{


ResultOfComparison RealNumber::compare(const Shared<const RealNumber> &_realNumber) const{
	return Lpp::compare(this->realValue(), _realNumber->realValue());
}

NumberExchangeFormat RealNumber::numberValue() const{
	return NumberExchangeFormat(realValue(), REAL_ZERO);
}

}
