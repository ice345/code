#include <iostream>

void moveTower(int height, char fromPole, char toPole, char withPole) 
{
    if (height >= 1) 
    {
        moveTower(height - 1, fromPole, withPole, toPole);
        std::cout << "Move disk from " << fromPole << " to " << toPole << std::endl;
        moveTower(height - 1, withPole, toPole, fromPole);
    }
}

void hanoi(int height) 
{
    moveTower(height, 'A', 'C', 'B');
}

int main() 
{
    int numDisks;
    std::cout << "Enter the number of disks: ";
    std::cin >> numDisks;

    hanoi(numDisks);

    return 0;
}
