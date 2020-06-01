#include"Evolution.cpp"

int main(int argc, char const *argv[])
{
	const std::string operand_x42("42");
	const std::string operand_x69("69");
	const std::string data("./binary_gene_expression_ACE2_tfs.csv");
	
	Node* g = new Node(NULL, NULL, operand_x42); // Niveau 2
	Node* d = new Node(NULL, NULL, operand_x69); // Niveau 2
	Node* racine = new Node(g, d, operator_and); // Niveau 1

	Evolution e(racine, data);

	std::cout << "Formule arbre de base :" << std::endl;
	std::cout << racine->node_formula() << std::endl;
	std::cout << std::endl;
	std::vector<float> fitness_progression;

	if(argc == 3)
	{
		std::stringstream argv_1;
		argv_1 << argv[1];
		int number_of_cycles;
		argv_1 >> number_of_cycles;

		std::stringstream argv_2;
		argv_2 << argv[2];
		int number_of_children;
		argv_2 >> number_of_children;
		
		if(number_of_cycles > 0 && number_of_children > 0)
		{
			fitness_progression = e.evolution(number_of_cycles, number_of_children);
		}
	}
	else
	{
		fitness_progression = e.evolution(80, 5); //10 cycles avec 5 enfants
	}

	std::cout << "Meilleure formule arbre après exécution :" << std::endl;
	std::cout << e.root()->node_formula() << std::endl;

	/*for (int i = 0; i < fitness_progression.size(); ++i)
	{
		std::cout << fitness_progression[i] << " ";
	}
	std::cout << std::endl;*/

	return 0;
};