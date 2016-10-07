#include "mathLibrary.h"
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

/*

Functions belonging to the Colour class

*/

Colour::Colour(int r, int g, int b){
	this -> red = r;
	this-> green = g;
	this-> blue = b;
}

Colour::Colour(){
	this -> red =0;
	this-> green = 0;
	this-> blue = 0;
	cout<<"object created!!"<<endl;

};

void Colour::getValues(){
	cout << "red is " << this -> red << endl;
	cout << "green is " << this -> green << endl;
	cout << "blue is " << this -> blue << endl;
};



/*

Functions belonging to the Point2D class

*/

Point2D::Point2D(){
	this->x = 0;
	this->y = 0;

};

Point2D::Point2D(float xIn, float yIn){
	this->x = xIn;
	this->y = yIn;

};

void Point2D::getValues(){
	cout << "x is " << this -> x << endl;
	cout << "y is " << this -> y << endl;

};

float Point2D::getX(){
	return x;
};

float Point2D::getY(){
	return y;
};

float Point2D::distTo(Point2D* that){
	return sqrt(pow((that->x - this->x),2) + pow((that->y - this->y),2));

};


float Point2D::fastDistTo(Point2D* that){
	return pow((that->x - this->x),2) + pow((that->y - this->y),2);

};



Point2D* Point2D::movePoint(Vec2D* vector){
	float x = (vector->getX()+ this->getX()); 
	float y = (vector->getY() + this-> getY());
	Point2D* point = new Point2D(x,y);

	return point;

};



/*

Functions belonging to the Vec2D class

*/


Vec2D::Vec2D(){
	x=0.0; y=0.0; magnitude=0.0;


};


Vec2D::Vec2D(float xIn, float yIn){
	x=xIn; y=yIn; magnitude= sqrt(pow(xIn,2)+pow(yIn,2));;

};


Vec2D::Vec2D(float xIn, float yIn, float magIn){
	x=xIn; y=yIn; magnitude=magIn;

};

void Vec2D::getValues(){
	cout << "x is " << this -> x << endl;
	cout << "y is " << this -> y << endl;
	cout << "magnitude is " << this -> magnitude << endl;

};

float Vec2D::length(){
	this -> magnitude = sqrt(pow(this->x,2)+pow(this->y,2));
	/*return (sqrt(pow(this->x,2)+pow(this->y,2)));*/
	return magnitude;
};


Vec2D* Vec2D::normalize(){
/*	Vec2D normalized;*/
	if (this -> magnitude != 0){
		Vec2D* normalized = new Vec2D(this->x/this->magnitude, this->y/this->magnitude);

		return normalized;
	}

	else {
		
		Vec2D* notNorm;
		return notNorm;
	}

};


Vec2D* Vec2D::vectorMultiply(int s){
	Vec2D* scaled = new Vec2D(s*this->x,s*this->y);
	return scaled;
};


Vec2D* Vec2D::vectorMultiply(float s){
	Vec2D* scaled = new Vec2D(s*this->x,s*this->y);
	return scaled;
};

Vec2D* Vec2D::vectorMultiply(double s){
	Vec2D* scaled = new Vec2D(s*this->x,s*this->y);
	return scaled;
};

Vec2D* Vec2D::createVector(Point2D* a, Point2D* b){
	float x = (b->getX() - a->getX());
	float y = (b->getY() - a->getY());
	Vec2D* newVec = new Vec2D(x,y);
	//cout << b -> getY() <<endl;
	return newVec;

};

float Vec2D::getX(){
	return this->x;
};

float Vec2D::getY(){
	return this->y;
};


Vec2D* Vec2D::scale(float x){
	return scale(x,x);
}

Vec2D* Vec2D::scale(float x, float y){
		float scaleMatrix[3][3] = {
            {x,0.0,0.0},
            {0.0,y,0.0},
            {0.0,0.0,1.0}
            };
 

        float vecValues[3] = {this->x, this->y, this->magnitude};

		return matrixMultiplication(scaleMatrix,vecValues);
};


Vec2D* Vec2D::translate(Vec2D* v){
	float transMatrix[3][3] = {
            {1,0.0,v->getX()},
            {0.0,1,v->getY()},
            {0.0,0.0,1.0}
            };
    float vecMatrix[3] = {v->getX(), v->getY(), v-> magnitude};
	return matrixMultiplication(transMatrix,vecMatrix);
}

Vec2D* Vec2D::matrixMultiplication(float array1[3][3], float array2[3]){
	float newArr[3];
	float sum =0;

	for(int i=0;i<3; i++){
		for(int j=0;j<3;j++){
			sum += (array1[i][j] * array2[j]);
		}
		newArr[i] = sum;
		sum = 0;
	}

	Vec2D* newVec = new Vec2D(newArr[0],newArr[1]);
	return newVec;

};


Vec2D* Vec2D::rotate(float angle){
	float rotateMatrix[3][3] = {
		{cos(angle*(M_PI/180)),-sin(angle*(M_PI/180)),0.0},
		{sin(angle*(M_PI/180)), cos(angle*(M_PI/180)), 0.0},
		{0.0,0.0,1.0}};

	float vecMatrix[3] = {this->x, this->y, this->magnitude};
	return matrixMultiplication(rotateMatrix,vecMatrix);


};
