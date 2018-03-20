#include "Programs/TTT.hpp"
#include <cstdio>
#include <algorithm>
#include <cmath>

double TTT::EvalState(const State s) const
{
    //add your implementation
    return 0;
}	


void TTT::BestMove(State   s, 
		   int     depth, 
		   int     remMoves, 
		   int     lastMove,
		   Value   player,
		   double *bestScore,
		   int    *bestMove) const
{
    //add your implementation
}


double TTT::NegaMax(State   s, 
		    int     depth, 
		    double  alpha, 
		    double  beta, 
		    int     remMoves, 
		    int     lastMove,
		    int     color) const
{
    //add your implementation
	//mine - Alpha - beta pruning
	double v = MaxValue(s, -999.0, 999.0, remMoves);

    return v;
    
}

double TTT::MaxValue(State s, double alpha, double beta, int remMoves) const
{
	if (remMoves == 0)
	{
		return 0.0; //utility of the set
	}
	double v = -999.0;
	for (int i = 0; i < remMoves; i++)
	{
		v = MaxNum(v, MinValue(/*Result(s,i)*/s, alpha, beta, i));
		if (v >= beta)
			return v;
		alpha = MaxNum(alpha, v);
	}
	return v;
}

double TTT::MinValue(State s, double alpha, double beta, int remMoves) const
{
	if (remMoves == 0)
	{
		return 0.0; //utility of the set
	}
	double v = 999.0;
	for (int i = 0; i < remMoves; i++)
	{
		v = MinNum(v, MaxValue(/*Result(s,i)*/s, alpha, beta, i));
		if (v <= alpha)
			return v;
		beta = MinNum(beta, v);
	}
	return v;
}

double TTT::MaxNum(double num1, double num2) const
{
	if (num1 >= num2)
		return num1;
	else
		return num2;
	return 0.0;
}

double TTT::MinNum(double num1, double num2) const
{
	if (num1 <= num2)
		return num1;
	else
		return num2;
	return 0.0;
}
//my code end

bool TTT::CheckWin(const State s, const int r, const int c) const
{
    const Value val  = GetValueState(s, r, c);
    int   cons = 0, end;
    
    //check row
    cons = 0; end = std::min(m_nrCols, c + m_nrToWin);
    for(int i = std::max(0, c - m_nrToWin); i < end; ++i)
	if(GetValueState(s, r, i) != val)
	    cons = 0;
	else if((++cons) >= m_nrToWin)
	    return true;
    
    //check column
    cons = 0; end = std::min(m_nrRows, r + m_nrToWin);
    for(int i = std::max(0, r - m_nrToWin); i < end; ++i)
	if(GetValueState(s, i, c) != val)
	    cons = 0;
	else if((++cons) >= m_nrToWin)
	    return true;
    
    //check diagonal
    cons = 0; end = 1 + std::min(m_nrToWin - 1, std::min(m_nrRows - r - 1, m_nrCols - c - 1));
    for(int i = std::max(-m_nrToWin + 1, std::max(-r, -c)); i < end; ++i)
	if(GetValueState(s, r + i, c + i) != val)
	    cons = 0;
	else if((++cons) >= m_nrToWin)
	    return true;
    
    //check anti-diagonal
    cons = 0; end = 1 + std::min(m_nrToWin - 1, std::min(r, m_nrCols - c - 1));
    for(int i = std::max(-m_nrToWin + 1, std::max(r - m_nrRows + 1, -c)); i < end; ++i)
    {
	if(GetValueState(s, r - i, c + i) != val)
	    cons = 0;
	else if((++cons) >= m_nrToWin)
	    return true;
    }
    
    
    return false;
    
    
}


