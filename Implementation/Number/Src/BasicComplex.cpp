
#include "BasicComplex.hpp"
#include "RealNumber.hpp"

namespace Lpp{

BasicComplex::BasicComplex(std::shared_ptr<const RealNumber> _realPart,
    std::shared_ptr<const RealNumber> _imaginaryPart) : m_realPart(_realPart),
	m_imaginaryPart(_imaginaryPart){}

NumberExchangeFormat BasicComplex::numberValue() const{
	return NumberExchangeFormat(m_realPart->realValue(),
			m_imaginaryPart->realValue());
}

}
