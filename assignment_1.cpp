//Created by: 11011183 on 08/02/2025
/*This code is a program which generates values for the photon from electron transitions for atoms in the Bohr Model. The user is 
first asked to give the initial and final quantum numbers as well as the atomic number of the atom. The code then calcualtes the energy 
and asks the user to choose the units of energy, after which the energy is dispalyed in the chosen units. Finally the user is asked 
whether they wish to repeat the process.
*/

#include<iostream>
#include<limits>
#include<cmath>



void quantum_number_validation(int &n1, int &n2, int &z)
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

double energy_calculation(int nj, int ni, int z)
{
    double energy = 13.6*std::pow(z,2)*(std::pow(nj,-2) - std::pow(ni,-2));
    return energy;
}

double joules_conversion(double energy)
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
            double energyjoules =joules_conversion(energy);
            std::cout<<"The energy in Joules is: "<<energyjoules<<std::endl;
            return;
        }
        else if (input1 == 'V')
        {
            std::cout<<"The energy in electron volts is: "<<energy<<std::endl;
            return;
        }
    }
}

void repeat_process(char& input2)
{
    while(true)
    {
        std::cout<<"Would you like to repeat y/n?: ";
        std::cin>>input2;

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

        quantum_number_validation(n1, n2, z);
        energy = energy_calculation(n1, n2, z);
        units(i1, energy);
        repeat_process(i2);
        if (i2 == 'n')
        {
            std::cout<<"Goodbye!"<<std::endl;
            break;
        }

    }
    return 0;
}