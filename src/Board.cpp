#include "Board.h"
#include "Controller.h"
#include "Item.h"
#include "macro.h"

Board::Board(){}

void Board::loadingTheBoard()
{
	auto& control = Controller::getInstance();
	int hight, width, stones, firstTime;
	std::ifstream file;
	nextLevel(file);
	std::string str;
	std::getline(file, str);
	m_stream = std::istringstream(str);
	m_stream >> hight >> width >> stones >> firstTime;
	control.initTheData(hight, width, stones, firstTime);

	if (!file.eof())
	{
		for (int i = 0; i < hight; i++)
		{
			std::getline(file, str);			
			m_matrix.push_back(str);
		}
	}
	std::getline(file, str);
	control.initTheBoard();
}

void Board::nextLevel(std::ifstream& file)
{
	auto& control = Controller::getInstance();
	
	auto str = std::string("Board" + std::to_string(control.getLevel()) +".txt");	
	file.open(str);
	if (!file)
		control.wining();
	m_matrix.clear();
}

char Board::getItem(int i, int j) const
{
	return m_matrix[i][j];
}
