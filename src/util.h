#pragma once


#if !defined ASSERT
#	if defined _DEBUG || defined DEBUG
#		include <assert.h>
#		define ASSERT(_cond_) assert(_cond_)
#	else
#		define ASSERT(_cond_)
#	endif
#endif

#if !defined VERIFY
#	if defined _DEBUG || defined DEBUG
#		define VERIFY(_cond_) ASSERT(_cond_)
#	else
#		define VERIFY(_cond_) _cond_
#	endif
#endif

#if !defined BREAK
#	define BREAK() ASSERT(false)
#endif

