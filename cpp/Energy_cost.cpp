#include"Energy_cost.h"
double cost_calc(double Energy)
{
    double cost;
    Energy = round(Energy);
    if (Energy == 0)
    {
        cost = 9;
        return cost;
    }
    if (Energy >= 0 && Energy <= 50)
    {
        cost = Energy * 58 * 0.01 + 1;
        return cost;
    }
    else if (Energy >= 51 && Energy <= 100)
    {
        cost = (50*58+(Energy-50)*68)*0.01 + 2;
        return cost;
    }
    else if (Energy >= 101 && Energy <= 650)
    {
        if (Energy >= 351)
        {
            cost = (200 * 83 + 150 * 125 + (Energy - 350) * 140) * 0.01 + 15;
            return cost;
        }
        else if (Energy >= 201 && Energy <= 350)
        {
            cost = (200 * 83 + (Energy - 200) * 125) * 0.01 + 11;
            return cost;
        }
        else if (Energy <= 200)
        {
            cost = Energy * 83 * 0.01 + 6;
            return cost;
        }
    }
    else if (Energy > 650 && Energy <= 1000)
    {
        cost = Energy * 150 * 0.01 + 25;
        return cost;
    }
    else if (Energy > 1000)
    {
        cost = Energy * 165 * 0.01 + 40;
        return cost;
    }
}
