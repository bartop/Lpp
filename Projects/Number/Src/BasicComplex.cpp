
#include "Number.hpp"
#include "BasicComplex.hpp"
#include "RealNumber.hpp"

namespace Lpp{

namespace
{

class BasicComplex final : public Number{
public:
	BasicComplex(
		Shared<const RealNumber> _realPart,
		Shared<const RealNumber> _imaginaryPart
	);

	NumberExchangeFormat numberValue() const final override;

private:
	const Shared<const RealNumber> m_realPart;
	const Shared<const RealNumber> m_imaginaryPart;
};

BasicComplex::BasicComplex(Shared<const RealNumber> _realPart,
    Shared<const RealNumber> _imaginaryPart) : m_realPart(_realPart),
	m_imaginaryPart(_imaginaryPart){}

NumberExchangeFormat BasicComplex::numberValue() const{
	return NumberExchangeFormat(m_realPart->realValue(),
			m_imaginaryPart->realValue());
}

}

Unique<Number> basicComplex(
	Shared<const RealNumber> _realPart,
	Shared<const RealNumber> _imaginaryPart
){
	return makeUnique<BasicComplex>(_realPart, _imaginaryPart);
}

}
