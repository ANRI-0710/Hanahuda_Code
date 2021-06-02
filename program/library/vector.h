#pragma once
#include <DirectXMath.h>

namespace t2k {
	class Quaternion;
	class Vector3 final : public DirectX::XMFLOAT3 {
	public :
		Vector3():DirectX::XMFLOAT3(0, 0, 0) {}
		Vector3( const float xx, const float yy, const float zz ) : DirectX::XMFLOAT3(xx, yy, zz) {}
		Vector3(DirectX::XMVECTOR& v) { DirectX::XMStoreFloat3(this, v) ; }
		Vector3(DirectX::XMFLOAT3& v) : DirectX::XMFLOAT3(v.x, v.y, v.z) {}

		//-----------------------------------------------------------------------------------------------------
		//
		// operator
		//
		inline operator DirectX::XMVECTOR() { return DirectX::XMLoadFloat3(&DirectX::XMFLOAT3(*this)); }

		Vector3& operator = (DirectX::XMVECTOR& other);
		Vector3& operator = (const float other);

		Vector3 operator * (const float other) const;
		Vector3 operator * (const Vector3& other) const;
		Vector3& operator *= (const float other);
		Vector3& operator *= (const Vector3& other);

		Vector3 operator / (const float other) const;
		Vector3 operator / (const Vector3& other) const;
		Vector3& operator /= (const float other);
		Vector3& operator /= (const Vector3& other);

		Vector3 operator + (const Vector3& other) const;
		Vector3& operator += (const Vector3& other);
		Vector3 operator - (const Vector3& other) const;
		Vector3& operator -= (const Vector3& other);

		//-----------------------------------------------------------------------------------------------------
		//
		// inline function
		//
		inline float dot(const Vector3& v) { return DirectX::XMVector3Dot(*this, Vector3(v)).m128_f32[0];}
		inline float angle(const Vector3& v) { 
			Vector3 t1 = *this;
			Vector3 t2 = v;
			t1.normalize();
			t2.normalize();
			return acosf( t1.dot(t2) );
		}
		inline Vector3 cross(const Vector3& v) { DirectX::XMVector3Cross(*this, Vector3(v)); return *this; }
		inline void normalize() { *this = DirectX::XMVector3Normalize(Vector3(*this)); }
		inline float length() { return DirectX::XMVector3Length(*this).m128_f32[0]; }
		static inline Vector3 transformCoord(Vector3 &v, const DirectX::XMMATRIX &m) { return DirectX::XMVector3TransformCoord(v, m); }

		//-----------------------------------------------------------------------------------------------------
		//
		// function
		//
		static Vector3 normalize(const Vector3 &v);
		static Vector3 transformCoord(Vector3 &v, const Quaternion &q);

	};
}
