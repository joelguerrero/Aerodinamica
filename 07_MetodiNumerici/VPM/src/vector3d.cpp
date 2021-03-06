#include <iostream>

#include "vector3d.hpp"


using namespace std;


vector3d::vector3d()
{
	_data[0] = 0.0;
	_data[1] = 0.0;
	_data[2] = 0.0;
}

vector3d::vector3d(double a,double b,double c)
{
	_data[0] = a;
	_data[1] = b;
	_data[2] = c;
}

vector3d::vector3d(const vector3d& vec)
{
	_data[0] = vec[0];
	_data[1] = vec[1];
	_data[2] = vec[2];
}

/* index operator */

double vector3d::operator [] (int i) const
{
	assert(i < 3);
	return _data[i];
}

double& vector3d::operator [] (int i)
{
	assert(i < 3);
	return _data[i];
}

/* assignments */

void vector3d::operator = (const vector3d& vec)
{
	_data[0] = vec[0];
	_data[1] = vec[1];
	_data[2] = vec[2];
}

const vector3d& vector3d::operator = (const vector3d& vec) const {
    return vec;
}

void vector3d::operator = (const double val) {
    _data[0] = val;
    _data[1] = val;
    _data[2] = val;
}


/* norms and normalization */

double vector3d::squared_norm() const{
    return (_data[0]*_data[0] + _data[1]*_data[1] + _data[2]*_data[2]);
}

double vector3d::norm() const {
    return sqrt(squared_norm());
}

void vector3d::normalize(){
    double n = norm();
    _data[0] /= n;
    _data[1] /= n;
    _data[2] /= n;
}


int vector3d::size() const{
    return 3;
}

/* print functions */

void vector3d::print () {
    std::cout << _data[0] << "\t" << _data[1] << "\t" << _data[2] << std::endl;
}



/* basic scalar operations */

vector3d vector3d::operator * (const double& val) const {
    vector3d result;
    result[0] = _data[0] * val;
    result[1] = _data[1] * val;
    result[2] = _data[2] * val;
    return result;
}

vector3d vector3d::operator / (const double& val) const {
    vector3d result;
    result[0] = _data[0] / val;
    result[1] = _data[1] / val;
    result[2] = _data[2] / val;
    return result;
}

/* basic vector operations */

vector3d vector3d::operator + (const vector3d& vec) const {
    vector3d result;
    result[0] = _data[0] + vec[0];
    result[1] = _data[1] + vec[1];
    result[2] = _data[2] + vec[2];
    return result;
}

vector3d vector3d::operator - (const vector3d& vec) const {
    vector3d result;
    result[0] = _data[0] - vec[0];
    result[1] = _data[1] - vec[1];
    result[2] = _data[2] - vec[2];
    return result;
}

vector3d vector3d::operator - () const {
    vector3d result;
    result[0] = -_data[0];
    result[1] = -_data[1];
    result[2] = -_data[2];
    return result;
}


double vector3d::dot(const vector3d& vec){
    return (_data[0]*vec[0] + _data[1]*vec[1] + _data[2]*vec[2]);
}

vector3d vector3d::cross(const vector3d& vec) const {
    vector3d cross;
    cross[0] = _data[1]*vec[2] - _data[2]*vec[1];
    cross[1] = _data[2]*vec[0] - _data[0]*vec[2];
    cross[2] = _data[0]*vec[1] - _data[1]*vec[0];
    return cross;
}

/* member by member division */
vector3d vector3d::operator / (const vector3d& vec) const{
    vector3d result;
    result[0] = _data[0] / vec[0];
    result[1] = _data[1] / vec[1];
    result[2] = _data[2] / vec[2];
    return result;
}

/* operations and assignments */

void vector3d::operator += (const vector3d& vec) {
    _data[0] += vec[0];
    _data[1] += vec[1];
    _data[2] += vec[2];
}

void vector3d::operator -= (const vector3d& vec) {
    _data[0] -= vec[0];
    _data[1] -= vec[1];
    _data[2] -= vec[2];
}

void vector3d::operator *= (const double& x) {
    _data[0] *= x;
    _data[1] *= x;
    _data[2] *= x;
}

/* pointer */
double* vector3d::begin(){
    return _data;
}


