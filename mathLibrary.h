#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H

class Point2D;
class Vec2D;
class Colour;
class Matrix;

class Point2D {
	private:
		float x,y;

	public:
		Point2D();
		Point2D(float x, float y);
		void getValues();
		float distTo(Point2D* that);
		float fastDistTo(Point2D* that);
		float getX();
		float getY();
		Point2D* movePoint(Vec2D* vector);


};

class Vec2D {
	private:
		float x,y,magnitude;
		Vec2D* matrixMultiplication(float array1[3][3], float array2[3]);

	public:
		Vec2D();
		Vec2D(float x, float y);
		Vec2D(float x, float y, float mag);
		void getValues();
		float length();
		Vec2D* normalize();
		Vec2D* vectorMultiply(float s);
		Vec2D* vectorMultiply(double s);
		Vec2D* vectorMultiply(int s);
		Vec2D* createVector(Point2D* a, Point2D* b);
		float getX();
		float getY();
		Vec2D* scale(float x);
		Vec2D* scale(float x, float y);
		Vec2D* translate(Vec2D* v);
		Vec2D* rotate(float angle);


};

class Colour {

	public:
		Colour();
		Colour(int r,int g, int b);
		void getValues();


	private:
		int red, green, blue;	


};




#endif