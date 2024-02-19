#include <windows.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

ostream& XM_CALLCONV operator<< (ostream& os, FXMVECTOR v)
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ", " << dest.w << ")";
	return os;
}

ostream& XM_CALLCONV operator<< (ostream& os, FXMMATRIX m)
{
	for (int i = 0; i < 4; ++i)
	{
		os << XMVectorGetX(m.r[i]) << "\t";
		os << XMVectorGetY(m.r[i]) << "\t";
		os << XMVectorGetZ(m.r[i]) << "\t";
		os << XMVectorGetW(m.r[i]) << "\t";
		os << endl;
	}

	return os;
}

int main()
{
	if (!XMVerifyCPUSupport())
	{
		return 0;
	}

	XMMATRIX A(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 2.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 4.0f, 0.0f,
		1.0f, 2.0f, 3.0f, 1.0f);

	XMMATRIX B = XMMatrixIdentity();

	XMMATRIX C = A * B;

	XMMATRIX D = XMMatrixTranspose(A);

	//XMVECTOR det = XMMatrixDeterminant(A);
	XMVECTOR Det;
	XMMATRIX E = XMMatrixInverse(&Det, A);
	XMMATRIX F = XMMatrixInverse(nullptr, A);

	XMMATRIX G = A * E;

	cout << "A = " << endl << A << endl;
	cout << "B = " << endl << B << endl;
	cout << "C = A*B = " << endl << C << endl;
	cout << "D = Transpose(A) = " << endl <<  D << endl << endl;
	cout << "Det = Determinant(A) = " << Det << endl << endl;
	cout << "E = Inverse(A) = " << endl << E << endl;
	cout << "F = Inverse(A) = " << endl << F << endl;
	cout << "G = A*E = " << endl << G << endl;

	return 0;
}