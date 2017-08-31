
#pragma once

#ifndef _constexpr
#	ifdef NDEBUG
#		define _constexpr(arg) constexpr(arg)
#	else
#		define _constexpr
#	endif
#endif
