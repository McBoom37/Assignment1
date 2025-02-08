//code 
#include<iostream>
#include<limits>
#include<cmath>



void quantum_numbers(int &n1, int &n2, int &z)
{
    std::cout<<"Enter the initial and final quantum numbers and the atomic number: ";
    std::cin>>n1>>n2>>z;


    while(true)
    {
        if (std::cin.fail())
        {
            std::cout<<"Invalid input (non-integer). Please enter your values again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cin>>n1>>n2>>z;
        }
        else if (n1<=0 || n2<=0 || z<=0)
        {
          std::cout<<"Invalid input (Negative/zero quantum numbers or atomic number). Please enter your values again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cin>>n1>>n2>>z; 
        }
        else if (n1<n2)
        {
            std::cout<<"Final quantum number greater than the initial quantum number. Please enter your values again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin>>n1>>n2>>z;

        }
        else
        {
            break;
        }
    }
}

double energy_levels(int nj, int ni, int z)
{
    double energy = 13.6*std::pow(z,2)*(std::pow(nj,-2) - std::pow(ni,-2));
    return energy;
}

double joules(double energy)
{
    return (energy)*1.6*(std::pow(10,-19));
}

void units(char& input1, double& energy)
{
    std::cout<<"Select the energy units: type 'j' for Joules and 'V' for electron volts: ";
    std::cin>>input1;


    while(true)
    {
        if (input1 != 'j' && input1 != 'V')
        {
            std::cout<<"Invalid input. Please choose your units again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin>>input1;
        }
        else if(std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cout<<"Invalid input. Please choose your units again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin>>input1;
        }
        else if (input1 == 'j')
        {
            double energy_joules =joules(energy);
            std::cout<<"The energy in Joules is: "<<energy_joules<<std::endl;
            return;
        }
        else if (input1 == 'V')
        {
            std::cout<<"The energy in electron volts is: "<<energy<<std::endl;
            return;
        }
    }
}

void repeat(char& input2)
{
    while(true)
    {
        if (input2 != 'y' && input2 != 'n')
        {
            std::cout<<"Would you like to repeat y/n?: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin>>input2;
        }
        else if(std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cout<<"Would you like to repeat y/n?: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin>>input2;
        }
        else
        {
            return;
        }
    }
}


int main()
{
    while(true)
    {
        int n1, n2, z;
        double energy;
        char i1, i2;

        quantum_numbers(n1, n2, z);
        energy = energy_levels(n1, n2, z);
        units(i1, energy);
        repeat(i2);
        if (i2 == 'n')
        {
            std::cout<<"Goodbye!"<<std::endl;
            break;
        }

    }
    return 0;
}