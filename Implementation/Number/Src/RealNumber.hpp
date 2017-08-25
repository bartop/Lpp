
#pragma once

#include "RealNumberExchangeFormat.hpp"
#include "Number.hpp"
#include "../../Generic/Src/Ordinal.hpp"

namespace Lpp{

struct RealNumber :
	public Number,
	public Ordinal<RealNumber>{
public:
	ResultOfComparison compare(Shared<const RealNumber> _realNumber) const final override;
	NumberExchangeFormat numberValue() const final override;

	virtual RealNumberExchangeFormat realValue() const = 0;
};

}
