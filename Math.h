#pragma once

#define M_PI 3.14159265358979323846f
#define M_RADPI	57.295779513082f
#define M_PI_F ((float)(M_PI))
#define RAD2DEG(x) ((float)(x) * (float)(180.f / M_PI_F))
#define DEG2RAD(x) ((float)(x) * (float)(M_PI_F / 180.f))

#define powf(a, b) ((a) * (a))

namespace globals
{
	class matrix_4x4
	{
	public:
		float m[16];
	};

	class vector_3
	{
	public:
		float x, y, z;

		inline  vector_3() {
			x = y = z = 0.0f;
		}

		inline  vector_3(float X, float Y, float Z) {
			x = X; y = Y; z = Z;
		}

		inline float& operator[](int i) {
			return ((float*)this)[i];
		}

		inline float operator[](int i) const {
			return ((float*)this)[i];
		}

		inline vector_3& operator+=(float v) {
			x += v; y += v; z += v; return *this;
		}

		inline vector_3& operator-=(float v) {
			x -= v; y -= v; z -= v; return *this;
		}

		inline vector_3& operator-=(const vector_3& v) {
			x -= v.x; y -= v.y; z -= v.z; return *this;
		}

		inline vector_3 operator*(float v) const {
			return vector_3(x * v, y * v, z * v);
		}

		inline vector_3 operator/(float v) const {
			return vector_3(x / v, y / v, z / v);
		}

		inline vector_3& operator+=(const vector_3& v) {
			x += v.x; y += v.y; z += v.z; return *this;
		}

		inline vector_3 operator-(const vector_3& v) const {
			return vector_3(x - v.x, y - v.y, z - v.z);
		}

		inline vector_3 operator+(const vector_3& v) const {
			return vector_3(x + v.x, y + v.y, z + v.z);
		}

		inline vector_3& operator/=(float v) {
			x /= v; y /= v; z /= v; return *this;
		}

		int get_distance(vector_3 b)
		{
			return int(sqrt(powf(b.x - x, 2.0) + powf(b.y - y, 2.0) + powf(b.z - z, 2.0)));
		}

		inline bool Zero() const
		{
			return (x > -0.1f && x < 0.1f && y > -0.1f && y < 0.1f && z > -0.1f && z < 0.1f);
		}

		inline float length()
		{
			return sqrt((x * x) + (y * y) + (z * z));
		}

		float Dot(vector_3 input) const
		{
			return (x * input.x) + (y * input.y) + (z * input.z);
		}
	};

	class vector_4
	{
	public:
		float x, y, z, w;

		inline vector_4() {
			x = y = z = w = 0.0f;
		}

		inline vector_4(float X, float Y, float Z, float W) {
			x = X; y = Y; z = Z; w = W;
		}
		
		inline vector_4& operator+=(float v) {
			x += v; y += v; z += v; w += v; return *this;
		}

		inline vector_4& operator-=(float v) {
			x -= v; y -= v; z -= v; w -= v; return *this;
		}

		inline vector_4& operator-=(const vector_4& v) {
			x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this;
		}

		inline vector_4 operator*(float v) const {
			return vector_4(x * v, y * v, z * v, w * v);
		}

		inline vector_4 operator/(float v) const {
			return vector_4(x / v, y / v, z / v, w / v);
		}

		inline vector_4& operator+=(const vector_4& v) {
			x += v.x; y += v.y; z += v.z; w += v.w; return *this;
		}

		inline vector_4 operator-(const vector_4& v) const {
			return vector_4(x - v.x, y - v.y, z - v.z, w - v.w);
		}

		inline vector_4 operator+(const vector_4& v) const {
			return vector_4(x + v.x, y + v.y, z + v.z, w + v.w);
		}

		inline vector_4& operator/=(float v) {
			x /= v; y /= v; z /= v; w /= v; return *this;
		}
	};

	class vector_2
	{
	public:
		float x, y;

		inline vector_2() {
			x = y = 0.0f;
		}

		inline vector_2(float X, float Y) {
			x = X; y = Y;
		}

		__forceinline float Dot(const vector_2& v2) {
			return x * v2.x + y * v2.y;
		}

		inline float& operator[](int i) {
			return ((float*)this)[i];
		}

		inline vector_2 operator+(float v) const {
			return vector_2(x + v, y + v);
		}

		inline vector_2 operator-(float v) const {
			return vector_2(x - v, y - v);
		}

		inline vector_2& operator+=(float v) {
			x += v; y += v; return *this;
		}

		inline vector_2& operator*=(float v) {
			x *= v; y *= v; return *this;
		}

		inline vector_2& operator/=(float v) {
			x /= v; y /= v; return *this;
		}

		inline vector_2 operator-(const vector_2& v) const {
			return vector_2(x - v.x, y - v.y);
		}

		inline vector_2 operator+(const vector_2& v) const {
			return vector_2(x + v.x, y + v.y);
		}

		inline vector_2& operator+=(const vector_2& v) {
			x += v.x; y += v.y; return *this;
		}

		inline vector_2& operator-=(const vector_2& v) {
			x -= v.x; y -= v.y; return *this;
		}

		inline vector_2 operator/(float v) const {
			return vector_2(x / v, y / v);
		}

		inline vector_2 operator*(float v) const {
			return vector_2(x * v, y * v);
		}

		inline vector_2 operator/(const vector_2& v) const {
			return vector_2(x / v.x, y / v.y);
		}

		inline bool Zero() const {
			return (x > -0.1f && x < 0.1f && y > -0.1f && y < 0.1f);
		}
	};

	__forceinline auto fast_sqrt(float x) -> float
	{
		union { int i; float x; } u;
		u.x = x; u.i = (u.i >> 1) + 0x1FC00000;
		u.x = u.x + x / u.x;
		return .25f * u.x + x / u.x;
	}

	__forceinline auto fast_round(double number) -> float
	{
		return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
	}

	__forceinline auto normalize_angle(vector_4& angle) -> void
	{
		if (angle.x > 180.f)
			angle.x -= fast_round(angle.x / 360) * 360.f;
		else if (angle.x < -180.f)
			angle.x += fast_round(angle.x / 360) * -360.f;

		if (angle.y > 180.f)
			angle.y -= fast_round(angle.y / 360) * 360.f;
		else if (angle.y < -180.f)
			angle.y += fast_round(angle.y / 360) * -360.f;

		if (angle.z > 180.f)
			angle.z -= fast_round(angle.z / 360) * 360.f;
		else if (angle.z < -180.f)
			angle.z += fast_round(angle.z / 360) * -360.f;

		if (angle.w > 180.f)
			angle.w -= fast_round(angle.w / 360) * 360.f;
		else if (angle.w < -180.f)
			angle.w += fast_round(angle.w / 360) * -360.f;
	}

	__forceinline auto get_eye_distance(float angle, long line_length) -> float
	{
		if (angle == 180.0f) return 0;

		return sin(DEG2RAD(angle)) * line_length;
	}

	__forceinline auto distance_between_cross(vector_2 screen_position, D2D1_SIZE_U window_size) -> float
	{
		int screen_center_x = window_size.width / 2;
		int screen_center_y = window_size.height / 2;

		float y_dist = (screen_position.y - screen_center_y);
		float x_dist = (screen_position.x - screen_center_x);

		return float(fast_sqrt(powf(y_dist, 2) + powf(x_dist, 2)));
	}

	__forceinline auto calc_angle(vector_3 camera_world, vector_3 target_world) ->  vector_3
	{
		vector_3 delta = target_world - camera_world;

		float x = asinf(delta.z / delta.length()) * (180.0f / M_PI);
		float z = atanf(delta.y / delta.x) * (180.0f / M_PI);

		if (delta.x >= 0.0f) z += 180.0f;

		if (x > 180.0f) x -= 360.0f;

		if (x < -180.0f) x += 360.0f;

		return  vector_3(x, 0.0f, z + 90.0f);
	}

	__forceinline auto calc_quat(globals::vector_3 euler) -> globals::vector_4
	{
		globals::vector_4 quaternion;

		float yaw = (euler.z * 0.01745329251f) * 0.5f;
		float sy = sinf(yaw);
		float cy = cosf(yaw);
		float roll = (euler.x * 0.01745329251f) * 0.5f;
		float sr = sinf(roll);
		float cr = cosf(roll);

		constexpr auto sp = 0.0f;
		constexpr auto cp = 1.0f;

		quaternion.x = cy * sr * cp - sy * cr * sp;
		quaternion.y = cy * cr * sp + sy * sr * cp;
		quaternion.z = sy * cr * cp - cy * sr * sp;
		quaternion.w = cy * cr * cp + sy * sr * sp;

		return quaternion;
	}

	__forceinline auto quaternion_to_euler(vector_4 q) -> vector_3
	{
		vector_3 euler;

		float unit = (q.x * q.x) + (q.y * q.y) + (q.z * q.z) + (q.w * q.w);
		float test = q.x * q.w - q.y * q.z;

		if (test > 0.4995f * unit) {
			euler.x = M_PI / 2;
			euler.y = 2.f * atan2f(q.y, q.x);
			euler.z = 0;
		}
		else if (test < -0.4995f * unit) {
			euler.x = -M_PI / 2;
			euler.y = -2.f * atan2f(q.y, q.x);
			euler.z = 0;
		}
		else {
			euler.x = asin(2.f * (q.w * q.x - q.y * q.z));
			euler.y = atan2f(2.f * q.w * q.y + 2.f * q.z * q.x, 1 - 2.f * (q.x * q.x + q.y * q.y));
			euler.z = atan2f(2.f * q.w * q.z + 2.f * q.x * q.y, 1 - 2.f * (q.z * q.z + q.x * q.x));
		}
		euler = euler * M_RADPI;

		return euler;
	}
}