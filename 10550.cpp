/*
* TODO
* 
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>

int main(int argc, char *argv[]) {
	int initPos, pos1, pos2, pos3, angle;
   
	while(std::cin >> initPos >> pos1 >> pos2 >> pos3, (initPos || pos1 || pos2 || pos3)) {
		angle  = 1080 + (((initPos - pos1) < 0 ? (40 + initPos - pos1) : (initPos - pos1)) * 9) + (((pos1 - pos2) > 0 ? (pos1 - pos2) : (40 + pos1 - pos2)) * 9) + (((pos2 - pos3) < 0 ? (40 + pos2 - pos3) : (pos2 - pos3)) * 9);
		std::cout << angle << std::endl;
	}
	return 0;
}