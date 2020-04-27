
// Huffman.cpp

// Tyler Manifold
// CSCI 48400
// Greedy Algorithms

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include "HuffmanTree.h"

int main(void)
{
	std::ifstream* freq_txt = new std::ifstream();

	// A vector of tuples. Weird.
	std::vector<std::tuple<std::string, int>>* data = new std::vector<std::tuple<std::string, int>>();

	std::string line;

	freq_txt->open("freq.txt", std::ifstream::in);

	if (freq_txt)
	{
		std::cout << "reading freqency file\n";
		while (freq_txt->good())
		{
			std::getline(*freq_txt, line, '\n');

			if (line[0] == ' ')
			{
				line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
				data->emplace_back(" ", std::stoi(line));
			}
			else
			{
				int sp = line.find(' ');

				data->emplace_back(line.substr(0, sp), std::stoi(line.substr(sp + 1, line.length() - 1)));
			}
		}
		std::cout << "\npresorting characters by frequency.\n";
		std::sort(data->begin(), data->end(),
			[](std::tuple<std::string, int> a, std::tuple<std::string, int> b) {
				return std::get<1>(a) < std::get<1>(b);
			});


		for (int i = 0; i < data->size(); i++)
		{
			std::cout << std::get<0>(data->at(i)) << " \t" << std::get<1>(data->at(i)) << std::endl;
		}

		// generate a new huffman tree

		HuffmanTree* tree = new HuffmanTree(data);

		std::ofstream* codetable = new std::ofstream("codetable.txt", std::ofstream::out);

		if (codetable)
		{
			std::cout << "\nwriting codetable to file.\n";
			// write the codetable to the codetable file.
			for (int i = 0; i < tree->codetable.size(); i++)
			{
				
				*codetable << std::get<0>(tree->codetable.at(i)) << " " << std::get<1>(tree->codetable.at(i)) << std::endl;
			}

			codetable->close();
		}
	}

	return 0;
}