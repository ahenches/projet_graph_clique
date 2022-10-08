# include <iostream>

# include "graphe.hpp"
# include "sommet.hpp"

int main()
{
    Graphe g(true, 3);
    std::cout << g.print();
    g.ajouterArete(0, 1);
    std::cout << g.print();
    g.ajouterArc(0, 2);
    std::cout << g.print();
    std::cout << "Hello World" << std::endl;
    // std::cout << "main function\n";
    return 0;
}
