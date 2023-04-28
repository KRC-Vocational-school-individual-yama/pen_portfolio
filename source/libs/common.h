#pragma once

template<typename NAME>
struct Vec2 {
	NAME x, y;
};

template<typename NAME>
struct Circle {
	Vec2<NAME> pos;
	NAME radius;
};

inline Vec2<int> Vec2Zero() { return Vec2<int>{0, 0}; }
