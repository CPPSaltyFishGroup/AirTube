#pragma once
namespace Tools {
	//promise origin be in [min,max].
	template<typename T>
	inline T clamp(T max, T min, T origin) {
		return origin < min ? min : (origin > max ? max : origin);
	}

}