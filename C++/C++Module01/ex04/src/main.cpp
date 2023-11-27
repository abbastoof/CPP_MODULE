/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:20:29 by atoof             #+#    #+#             */
/*   Updated: 2023/11/27 12:50:12 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Sed.hpp"

bool fileExists(const std::string& filename)
{
    struct stat fileStat;
    return stat(filename.c_str(), &fileStat) == 0 && !S_ISDIR(fileStat.st_mode);
}

bool openFile(const std::string& filename, std::ifstream& fileStream)
{
    fileStream.open(filename);
    if (!fileStream.is_open())
	{
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }
    return true;
}

bool createFile(const std::string& filename, std::ofstream& fileStream)
{
    fileStream.open(filename);
    if (!fileStream.is_open())
	{
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return false;
    }
    return true;
}

std::string replaceContent(const std::string& input, const std::string& toFind, const std::string& replaceWith)
{
    std::string modifiedContent;
    size_t lastFound = 0;
    size_t prevFound = 0;

    while ((lastFound = input.find(toFind, prevFound)) != std::string::npos) // find all occurrences of toFind in input string, prevFound is the starting position
	{
        modifiedContent += input.substr(prevFound, lastFound - prevFound);
        modifiedContent += replaceWith;
        prevFound = lastFound + toFind.length();
    }

    modifiedContent += input.substr(prevFound); // add the rest of the string after the last occurrence of toFind
    return modifiedContent;
}

bool replaceAndWriteFile(const std::string& inputFilename, const std::string& outputFilename,
                         const std::string& toFind, const std::string& replaceWith)
{
    if (!fileExists(inputFilename)) {
        std::cerr << "Error: Invalid input file." << std::endl;
        return false;
    }

    std::ifstream inputFile;
    if (!openFile(inputFilename, inputFile)) {
        return false;
    }

    std::ofstream outputFile;
    if (!createFile(outputFilename, outputFile)) {
        inputFile.close();
        return false;
    }

    std::stringstream bufferFile; // read the file into a buffer
    bufferFile << inputFile.rdbuf();
    std::string readBuff = bufferFile.str();

    std::string modifiedContent = replaceContent(readBuff, toFind, replaceWith);

    outputFile << modifiedContent;

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
    std::string outputFilename = filename + ".replace"; // append .replace to the filename
    if(replaceAndWriteFile(filename, outputFilename, s1, s2))
	{
        std::cout << "Replacement complete! Output written to " << outputFilename << std::endl;
        return 0;
    }
	else
        return 1;
}