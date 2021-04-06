#pragma once
class Controller;
class Item;
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

class Board
{
public:
	Board();
	void loadingTheBoard();
	void nextLevel(std::ifstream& file);
	char getItem(int i, int j) const;

private:
	std::ifstream m_file;
	std::istringstream m_stream;
	std::vector<std::string> m_matrix;
};