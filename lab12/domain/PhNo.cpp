/*
 * PhNo.cpp
 *
 *  Created on: May 25, 2012
 *      Author: blink
 */

#include "PhNo.h"

using namespace std;

PhNo::PhNo(string name,string no, string city){
	this->name = name;
	this->no = no;
	this->city = city;
}
PhNo::~PhNo(){
	this->name = "";
	this->no = "";
	this->city = "";
}

void PhNo::setName(string name){
	this->name = name;
}

void PhNo::setCity(string city){
	this->city = city;
}

void PhNo::setNo(string no){
	this->no = no;
}

string PhNo::getName(){
	return this->name;
}

string PhNo::getCity(){
	return this->city;
}

string PhNo::getNo(){
	return this->no;
}
