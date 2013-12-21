#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cctype>

std::map<std::string, long int > costByRecipe;

bool compareRecipes(std::string a, std::string b) {
	if (costByRecipe[a] != costByRecipe[b]) {
		return (costByRecipe[a] < costByRecipe[b]);
	}
	else {
		return (a < b);
	}
	
}

int main(int argc, char *argv[]) {
	int numBinders, numIngredients, numRecipes, ingredientCost, ingredientUnits;
	long int budget, recipeCost;
	std::string binderName, ingredientName, recipeName, input;
	std::map<std::string, int> costByIngredient;
	std::vector<std::string> recipes;

	std::stringstream ss;

	std::cin >> numBinders;
	std::getline(std::cin, input);
	while (numBinders > 0) {
		costByIngredient.clear();
		costByRecipe.clear();
		recipes.clear();

		std::getline(std::cin, binderName);
		std::cin >> numIngredients >> numRecipes >> budget;
		std::getline(std::cin, input);
		while (numIngredients > 0) {
			std::getline(std::cin, input);
			ss.clear();
			ss.str("");
			ss << input;
			ss >> ingredientName >> ingredientCost;
			costByIngredient[ingredientName] = ingredientCost;
			numIngredients--;
		}

		while (numRecipes > 0) {
			std::getline(std::cin, recipeName);
			std::cin >> numIngredients;
			std::getline(std::cin, input);
			recipeCost = 0;
			while (numIngredients > 0) {
				ss.clear();
				ss.str("");
				std::getline(std::cin, input);
				ss << input;
				ss >> ingredientName >> ingredientUnits;
				recipeCost += ingredientUnits * costByIngredient[ingredientName];
				numIngredients--;
			}
			recipes.push_back(recipeName);
			costByRecipe[recipeName] = recipeCost;
			numRecipes--;
		}
		std::transform(binderName.begin(), binderName.end(), binderName.begin(), toupper);
		std::cout << binderName << std::endl;
		bool flag = false;
		std::sort(recipes.begin(), recipes.end(), compareRecipes);
		for (std::vector<std::string>::iterator it = recipes.begin(); it != recipes.end(); it++) {
			recipeCost = costByRecipe[*it];
			if (recipeCost < budget) {
				std::cout << *it << std::endl;
				flag = true;
			}
		}
		if (!flag) {
			std::cout << "Too expensive!" << std::endl;
		}
		std::cout << std::endl;
		numBinders--;
	}
	//std::cin.ignore();
	//std::cin.ignore();
	return 0;
}