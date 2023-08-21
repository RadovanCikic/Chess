
#include "ChessFigure.h"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(ChessFigure::FigureType type, std::string coord) : type(type),
currentCoord(coord)
{
}


ChessFigure::~ChessFigure()
{
}

bool ChessFigure::Move(string nextCoord)
{
	if (type == PAWN)
	{
		if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8')
		{
            if((nextCoord[1] == currentCoord[1] + 1) && (nextCoord[0] == currentCoord[0]))
                return true;
            else if (((nextCoord[1]) == currentCoord[1] + 2) && nextCoord[1] == '2')
                return true;
            else return false;
/*			if (nextCoord[0] != currentCoord[0] || nextCoord[1] <= currentCoord[1] || (nextCoord[1] - currentCoord[1] != 1 && (currentCoord[1] != '2' || nextCoord[1] != '4')))
				return false;
			else
				return true;*/
		}
		else return false;
	}

	else if (type == ROOK)
	{
        //there in second parenthesis we have condition which doesn't allow to figure to stay in same field as a valid
        // turn. For Pawn, e.g, we didn't have that because in inner {} if statement was adding coord. by 1 or 2.
    	if ((nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8') &&
                (nextCoord[0] != currentCoord[0] || nextCoord[1] != currentCoord[1]))
		{
            if(nextCoord[0] == currentCoord[0])
                return true;
            else if(nextCoord[1] == currentCoord[1])
                return true;
            else return false;
/*			if ((nextCoord[0] != currentCoord[0]) && (nextCoord[1] != currentCoord[1]) || ((nextCoord[0] == currentCoord[0]) && (nextCoord[1] == currentCoord[1])))
				return false;
			else
				return true;
*/
		}
		else return false;
	}
	else if (type == KNIGHT)
	{
		if (nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8')
		{
            if(((nextCoord[0] == currentCoord[0] + 1) || (nextCoord[0] == currentCoord[0] - 1))
            && ((nextCoord[1] == currentCoord[1] + 2) || (nextCoord[1] == currentCoord[1] - 2)))
                return true;
            else if (((nextCoord[0] == currentCoord[0] + 2) || (nextCoord[0] == currentCoord[0] - 2))
            && ((nextCoord[1] == currentCoord[1] + 1) || (nextCoord[1] == currentCoord[1] - 1)))
                return true;
            else return false;
/*			int dx, dy;
			dx = abs(nextCoord[0] - currentCoord[0]);
			dy = abs(nextCoord[1] - currentCoord[1]);
		    if (!(abs(nextCoord[0] - currentCoord[0]) == 1 && abs(nextCoord[1] - currentCoord[1]) == 2 || abs(nextCoord[0] - currentCoord[0]) == 2 && abs(nextCoord[1] - currentCoord[1]) == 1))
			  return false;
			else
			return true;*/
		}
		else return false;
	}

	else if (type == BISHOP)
	{
        //same condition and reason for it as for Rook, because abs(NC[0] - CC[0]) = abs(NC[1] - CC[1]) allows case
        // nextCoord to be C5 and currentCoord also to be C5
		if ((nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8') &&
            (nextCoord[0] != currentCoord[0] || nextCoord[1] != currentCoord[1]))
		{
			if (abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]))
				return true;
			else return false;
		}
		else return false;
	}

	else if (type == KING)
	{
        // same point there as for Rook and Bishop
		if ((nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8') &&
            (nextCoord[0] != currentCoord[0] || nextCoord[1] != currentCoord[1]))
		{
			if (abs(nextCoord[0] - currentCoord[0]) <= 1 && abs(nextCoord[1] - currentCoord[1]) <= 1)
				return true;
			else return false;
		}
		else return false;
	}
	else if (type == QUEEN)
	{
        // same point there as for Rook and Bishop
		if ((nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8') &&
        (nextCoord[0] != currentCoord[0] || nextCoord[1] != currentCoord[1]))
		{
            if(nextCoord[0] == currentCoord[0])
                return true;
            else if(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]))
                return true;
            else return false;
/*			if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]) || nextCoord[0] == currentCoord[0] || nextCoord[1] == currentCoord[1]))
				return false;
			else
				return true;*/
		}
		else return false;
	}
	else return false;
}
