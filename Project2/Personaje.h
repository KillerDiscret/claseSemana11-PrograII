#pragma once
#include"String.h"
using namespace System::Drawing;
enum Direccion{Arriba,Abajo,Izquierda,Derecha,Ninguno};
class personaje
{
private:
	int x, y;
	int dx, dy;
	char*imagen;//nombre del archivo
	//String img;
	int W, H;
	int indiceW;
	int indiceH;
public:
	personaje(void);
	~personaje(void);
	void Cambiar_X(int nuevo);
	void Cambiar_Y(int nuevo);
	int Retornar_X();
	int Retornar_Y();
	int Retornar_dx();
	int Retornar_dy();
	int Retornar_H();
	int Retornar_W();
	void Cambiar_dx_dy(Direccion teclapulsada);
	void Cambiar_imagen(char*nuevo);
	void Mostrar(System::Drawing::Graphics^gr);
	void Mover(System::Drawing::Graphics^gr, Direccion teclapulsada);
};
personaje::personaje()
{
	//se inicializa las variables
	x = y = 0;
	dx = 0;
	dy = 1;
	indiceH = indiceW = 0;
	imagen = new char[50];
}
void personaje::Cambiar_X(int nuevo)
{
	x = nuevo;
}
void personaje::Cambiar_Y(int nuevo)
{
	y = nuevo;
}
int personaje::Retornar_X()
{
	return x;
}
int personaje::Retornar_Y()
{
	return y;
}
int personaje::Retornar_dx()
{
	return dx;
}
int personaje::Retornar_dy()
{
	return dy;
}
int personaje::Retornar_H()
{
	return H;
}
int personaje::Retornar_W()
{
	return W;
}
void personaje::Cambiar_dx_dy(Direccion teclapulsada)
{
	switch (teclapulsada)
	{
	case Arriba:
		dx = 0;
		dy = -1;
		break;
	case Abajo:
		dx = 0;
		dy = 1;
		break;
	case Izquierda:
		dx = -1;
		dy = 0;
		break;
	case Derecha:
		dx = 1;
		dy = 0;
		break;
	case Ninguno:
		dx = 0;
		dy = 0;
		break;
	default:
		break;
	}
}
void personaje::Cambiar_imagen(char*nuevo)
{
	strcpy(imagen, nuevo);//copia una cadena a otra
	//imagen tiene el nombre del archivo sprite
	Bitmap ^bmp = gcnew Bitmap(gcnew System::String(imagen));
	//carga la imagen
	W = bmp->Width / 3; //3 iamgenes x fila
	H = bmp->Height / 4; //4 imagenes x columna
	delete bmp;

}
void personaje::Mostrar(System::Drawing::Graphics^gr)
{
	//clase Bitmap para leer la imagen del archivo
	Bitmap ^bmp = gcnew Bitmap(gcnew System::String(imagen));
	//porcion que sera un cuadro del sprite
	Rectangle porcion = Rectangle(indiceW*W, indiceH*H, W, H);
	//zoom para que la imagen se mas grande que la original
	Rectangle zoom = Rectangle(x, y, W, H);
	//dibuja la imagen en el canvas
	gr->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
}
void personaje::Mover(Graphics^gr, Direccion teclapulsada)
{
	if (teclapulsada==Direccion::Abajo)
	{
		indiceH = 0;
	}
	if (teclapulsada == Direccion::Izquierda)
	{
		indiceH = 1;
	}
	if (teclapulsada == Direccion::Derecha)
	{
		indiceH = 2;
	}
	if (teclapulsada == Direccion::Arriba)
	{
		indiceH = 3;
	}
	indiceW++;
	if (indiceW>2)
	{
		indiceW = 0;
	}
	x = x + dx;
	y = y + dy;
	Mostrar(gr);
}


personaje::~personaje()
{

}