/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:20:29 by atoof             #+#    #+#             */
/*   Updated: 2023/10/30 12:09:31 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Sed.hpp"

bool replaceAndWriteFile(const std::string& inputFilename, const std::string& outputFilename, const std::string& s1, const std::string& s2)
{
    std::ifstream 		inputFile(inputFilename);
	std::ofstream 		outputFile(outputFilename);
	std::stringstream	bufferFile;
	std::string			read_buff;
	std::string			read_str;
	size_t				last_found = 0;
	size_t				prev_found = 0;
	// char ch;
	// std::string buffer;

    if (inputFile.fail())
	{
        std::cerr << "Error: Could not open input file " << inputFilename << std::endl;
        return false;
    }
    if (outputFile.fail())
	{
        std::cerr << "Error: Could not open output file " << outputFilename << std::endl;
        return false;
    }
	if (inputFile.is_open())
	{
		bufferFile << inputFile.rdbuf(); // read the file
		read_buff = bufferFile.str(); // read the file into a string
		last_found = read_buff.find(s1);
		while (last_found != std::string::npos)
		{
			read_str += read_buff.substr(prev_found, last_found - prev_found); // add the string from the last found to the current found
			read_str += s2; // add the replacement string
			prev_found = last_found + s1.length(); // set prev_found to the end of the string
			last_found = read_buff.find(s1, prev_found); // find next occurence
		}
		read_str += read_buff.substr(prev_found, last_found - prev_found); // add the rest of the string
	}
	outputFile << read_str; // write the string to the output file
	// while (inputFile.get(ch))
	// {
	// 	if (ch == s1[0])
	// 	{
	// 		buffer += ch;
	// 		for (size_t i = 1; i < s1.length(); i++)
	// 		{
	// 			inputFile >> ch;
	// 			buffer += ch;
	// 		}
	// 		if (buffer == s1)
	// 		{
	// 			outputFile << s2;
	// 			buffer = "";
	// 		}
	// 		else
	// 		{
	// 			outputFile << buffer;
	// 			buffer = "";
	// 		}
	// 	}
	// 	else
	// 		outputFile << ch;
	// }
	inputFile.close();
	outputFile.close();
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
