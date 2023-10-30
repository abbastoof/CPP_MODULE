/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:20:29 by atoof             #+#    #+#             */
/*   Updated: 2023/10/30 11:13:53 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Sed.hpp"

bool replaceAndWriteFile(const std::string& inputFilename, const std::string& outputFilename, const std::string& s1, const std::string& s2)
{
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);
	char ch;
	std::string buffer;

    if (!inputFile)
	{
        std::cerr << "Error: Could not open input file " << inputFilename << std::endl;
        return false;
    }
    if (!outputFile)
	{
        std::cerr << "Error: Could not open output file " << outputFilename << std::endl;
        return false;
    }
	while (inputFile.get(ch))
	{
		if (ch == s1[0])
		{
			buffer += ch;
			for (size_t i = 1; i < s1.length(); i++)
			{
				inputFile >> ch;
				buffer += ch;
			}
			if (buffer == s1)
			{
				outputFile << s2;
				buffer = "";
			}
			else
			{
				outputFile << buffer;
				buffer = "";
			}
		}
		else
			outputFile << ch;
	}
	return true;
}

int main(int argc, char* argv[])
{
    if(argc != 4)
	{
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if(s1.empty())
	{
        std::cerr << "Error: The search string cannot be empty" << std::endl;
        return 1;
    }

    std::string outputFilename = filename + ".replace"; // append .replace to the input filename
    if(replaceAndWriteFile(filename, outputFilename, s1, s2))
	{
        std::cout << "Replacement complete! Output written to " << outputFilename << std::endl;
        return 0;
    }
	else
        return 1;
}
