#include "World.h"
#include "attribute.h"
#include "Cell.h"
#include "stdlib.h"
#include <vector>
#include <exception>
#include <fstream>

bool odd(int n){
	return !(n%2);
}
bool even(int n){
	return (n%2)
}

void World::load(String world_file){
	ifstream wf;
	string line;
	wf.open(world_file, ios::in);
	if(wf.is_open()){
	    wf >> width >> length;
	} else {
		error("File not found.\n");
		exit(EXIT_FAILURE);
	}

	std::cout << "Width: " << width << std::endl;
	std::cout << "Length: " << length << std::endl;

	cell_container.resize(length);
	std::cout << "Mother vector has been resized" << std::endl;

	for (int i = 0; i < width; ++i) {
		cell_container[i].resize(width);
	}
	std::cout << "Child vectors have been resized" << std::endl;

	getline(wf, line);
	cout << line; //print line
	for (int j = 0; j < length; ++j) {
		getline(wf, line);
		//bit of tokenizing
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
		for (int d = 0; d < width; ++d) {
			Cell *new_cell = new Cell(line[w]);
			if(line[w] == '+'){
				Bug n_bug = (new_cell->getoccupant());
				n_bug.set_position(w, l);
				n_bug.set_color(1);
				n_bug.set_has_food(false);
				redbugs.push_back(&n_bug);
				std::cout << "Red bug base found, Creating red bug" << std::endl;
			}
			if(line[w] == '-'){
				Bug n_bug = (new_cell->get_occupant());
				n_bug.set_position(w, l);
				n_bug.set_color(0);
				n_bug.set_has_food(false);
				blackbugs.push_back(&n_bug);
				cout << "Black bug base found, Creating black bug" << std::endl;
			}
			cell_container[l][w] = new_cell;
		}
	}
	std::cout << "World initialized" << std::endl;
}

tposition World::adjacent(tdirection dir, tposition pos){
	int d = dir.d;
	tposition result;
	switch(d){
		case 0:
			result.x = pos.x + 1;
			result.y = pos.y;
			break;
		case 1:
			if(even(pos.y)){
				result.x = pos.x;
				result.y = pos.y+1;
			}
			else{
				result.x = pos.x+1;
				result.y = pos.y+1;
			}
			break;
		case 2:
			if(even(pos.y)){
				result.x = pos.x-1;
				result.y = pos.y+1;
			}
			else{
				result.x = pos.x;
				result.y = pos.y+1;
			}
			break;
		case 3:
			result.x = pos.x-1;
			result.y = pos.y;
			break;
		case 4:
			if(even(pos.y)){
				result.x = pos.x-1;
				result.y = pos.y-1;
			}
			else{
				result.x = pos.x;
				result.y = pos.y-1;
			}
			break;
		case 5:
			if(even(pos.y)){
				result.x = pos.x;
				result.y = pos.y-1;
			}
			else{
				result.x = pos.x+1;
				result.y = pos.y-1;
			}
			break;
		default:
			cout << "Error." << endl;
			result.x = -1;
			result.y = -1;
			break;
	}
	return res;
}

tcolor other_color(tcolor c){
	tcolor result;
	if(c.c){
		result.c = 0;
	} else {
		result.c = 1;
	}
	return result;
}

int World::red_food(){
	int count = 0;
	for (std::vector<Bug*>::iterator it = redbugs.begin(); it != redbugs.end(); it++){
		if((*it)->get_has_food()){
			count++;
		}
	}
	return count;
}

int World::black_food(){
	int count = 0;
	for (std::vector<Bug*>::iterator it = blackbugs.begin(); it != blackbugs.end(); it++){
			if((*it)->get_has_food()){
					count++;
			}
	}
	return count;
}

int World::red_count(){
	return redbugs.size();
}
int World::black_count(){
	return blackbugs.size();
}

void World::error(string msg){
	std::cout << msg << std::endl;
}

void World::log(string msg){
	ofstream logfile;
	logfile.open("log.txt", ios::out);
	if(logfile.is_open()){
		logfile << msg << std::endl;
		std::cout << "Log file written." << std::endl;
	} else {
		std::cout << "Error making logfile" << std::endl;
	}
	logfile.close();
}

void World::print_grid(){}
